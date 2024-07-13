#include "db_op.h"
#include "TimberSaw/db.h"
#include "TimberSaw/options.h"
#include "TimberSaw/slice.h"
#include "TimberSaw/status.h"
#include "TimberSaw/write_batch.h"
#include <cstdio>
#include <mutex>
#include <stdexcept>

namespace dlsmdb {

db *instance = nullptr;
std::mutex db::mtx;

db::db(int node_id) {
  printf("sssss, nodeid is is :%d", node_id);
  TimberSaw::RDMA_Manager::node_id = node_id;
  TimberSaw::Options options;
  options.create_if_missing = true;
  TimberSaw::DB *raw_db = nullptr;
  TimberSaw::Status status = TimberSaw::DB::Open(options, db_name, &raw_db);
  if (!status.ok()) {
    fprintf(stderr, "Unable to open/create test database '%s'\n", db_name);
    fprintf(stderr, "%s\n", status.ToString().c_str());
    throw std::runtime_error("Failed to initialize database");
  }

  db_.reset(raw_db);
  printf("Database '%s' opened successfully.\n", db_name);
};

db::~db() { closeDB(); }

db *db::getInstance(int node_id) {
  std::lock_guard<std::mutex> lock(mtx);
  if (instance == nullptr) {
    instance = new db(node_id);
  }
  return instance;
}

int db::closeDB() {
  std::lock_guard<std::mutex> lock(mtx);
  if (instance) {
    instance->db_.reset();
    delete instance;
    instance = nullptr;
    printf("Database '%s' closed successfully.\n", db_name);
  }
  return 0;
}

// deprecated
void db::initDB() {
  TimberSaw::Options options;
  options.create_if_missing = true;
  TimberSaw::DB *raw_db = nullptr;
  TimberSaw::Status status = TimberSaw::DB::Open(options, db_name, &raw_db);

  if (!status.ok()) {
    fprintf(stderr, "Unable to open/create test database '%s'\n", db_name);
    fprintf(stderr, "%s\n", status.ToString().c_str());
    throw std::runtime_error("Failed to initialize database");
  }

  db_.reset(raw_db);
  printf("Database '%s' opened successfully.\n", db_name);
}

int db::setKey(const std::string &key, const std::string &value) {
  if (!db_) {
    fprintf(stderr, "db hasn't been initialized.");
    return -1;
  }
  TimberSaw::WriteOptions write_options;
  TimberSaw::Status status = db_->Put(write_options, key, value);
  if (!status.ok()) {
    printf("Set operation failed: %s\n", status.ToString().c_str());
  }
  return status.ok() ? 0 : -1;
}

int db::getKey(const std::string &key, std::string &value) {
  if (!db_) {
    fprintf(stderr, "db hasn't been initialized.");
    return -1;
  }
  TimberSaw::ReadOptions read_options;
  TimberSaw::Status status = db_->Get(read_options, key, &value);
  if (!status.ok()) {
    // printf("Get failed: %s\n", status.ToString().c_str());
  }
  return status.ok() ? 0 : -1;
}

// dlsm 似乎并不支持batch insert，源代码中有限制 assert(kv_num == 1);
int db::writeBatch(std::vector<TimberSaw::Slice> key_list,
                   std::vector<TimberSaw::Slice> val_list) {
  if (!db_) {
    fprintf(stderr, "WriteBatch db hasn't been initialized.");
    return -1;
  }
  if (key_list.size() != val_list.size()) {
    fprintf(stderr, "WriteBatch params size not equal.");
    return -1;
  }
  int size = key_list.size();
  TimberSaw::WriteOptions writebatch_options;
  bool hasError = false;
  TimberSaw::Status status;
  for (int i = 0; i < size; i++) {
    TimberSaw::WriteBatch write_batch;
    write_batch.Put(key_list[i], val_list[i]);
    status = db_->Write(writebatch_options, &write_batch);
    if (!status.ok()) {
      printf("writeBatch failed: %s\n", status.ToString().c_str());
    }
  }

  // for (const auto &kv : kvpairs) {
  //   TimberSaw::Slice key(kv.key());
  //   TimberSaw::Slice value(kv.value());
  //   status = db_->Put(writebatch_options, key, value);
  //   if (!status.ok()) {
  //     printf("WriteBatch failed: %s\n", status.ToString().c_str());
  //   }
  // }
  return hasError ? -1 : 0;
}

} // namespace dlsmdb
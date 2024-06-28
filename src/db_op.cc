#include "db_op.h"
#include <cstdio>
#include <mutex>
#include <stdexcept>

namespace dlsmdb {

db *instance = nullptr;
std::mutex db::mtx;

db::db() {
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

db *db::getInstance() {
  std::lock_guard<std::mutex> lock(mtx);
  if (instance == nullptr) {
    instance = new db();
  }
  return instance;
}

int db::closeDB() {
  std::lock_guard<std::mutex> lock(mtx);
  db_.reset();
  delete instance;
  instance = nullptr;
  printf("Database '%s' closed successfully.\n", db_name);
  return 0;
}

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
  if (status.ok()) {
    printf("Set operation successful\n");
  } else {
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
  if (status.ok()) {
    printf("Get success, value: %s\n", value.c_str());
  } else {
    printf("Get failed: %s\n", status.ToString().c_str());
  }
  return status.ok() ? 0 : -1;
}

} // namespace dlsmdb
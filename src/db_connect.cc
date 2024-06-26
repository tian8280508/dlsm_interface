#include "TimberSaw/db.h"
#include <cstdio>
#include <memory>
#include <mutex>
#include <string>

namespace dlsmdb {

namespace {
std::unique_ptr<TimberSaw::DB> db = nullptr;
std::once_flag db_init_flag;
std::mutex db_mutex;
static std::string db_name = "testdb";
} // namespace

void InitDB() {
  TimberSaw::Options options;
  options.create_if_missing = true;
  TimberSaw::DB *raw_db = nullptr;
  TimberSaw::Status status = TimberSaw::DB::Open(options, db_name, &raw_db);

  if (!status.ok()) {
    fprintf(stderr, "Unable to open/create test database '%s'\n",
            db_name.c_str());
    fprintf(stderr, "%s\n", status.ToString().c_str());
    throw std::runtime_error("Failed to initialize database");
  }

  db.reset(raw_db);
  printf("Database '%s' opened successfully.\n", db_name.c_str());
}

TimberSaw::DB *GetDBInstance() {
  std::call_once(db_init_flag, InitDB);
  return db.get();
}

int CloseDB() {
  std::lock_guard<std::mutex> lock(db_mutex);
  db.reset();
  printf("Database '%s' closed successfully.\n", db_name.c_str());
  return 0;
}

int SetKey(std::string &key, std::string &value) {
  // TODO：应该不需要？
  // std::lock_guard<std::mutex> lock(db_mutex);
  if (!db) {
    fprintf(stderr, "db haven't been initialized.");
    return -1;
  }
  TimberSaw::WriteOptions write_options;
  TimberSaw::Status status = db->Put(write_options, key, value);
  if (status.ok()) {
    printf("Set operation successful");
  } else {
    printf("Set operation failed: %s", status.ToString().c_str());
  }
  return 0;
}

int GetKey(std::string &key, std::string &value) {
  // TODO：应该不需要？
  // std::lock_guard<std::mutex> lock(db_mutex);
  if (!db) {
    fprintf(stderr, "db haven't been initialized.");
    return -1;
  }
  TimberSaw::ReadOptions read_options;
  std::string res;
  TimberSaw::Status status = db->Get(read_options, key, &res);
  if (status.ok()) {
    printf("Get success, res: %s", res.c_str());
  } else {
    printf("Get failed: %s", status.ToString().c_str());
    return -1;
  }
  return 0;
}

} // namespace dlsmdb
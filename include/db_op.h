#ifndef DLSMDB_H
#define DLSMDB_H
#define FUCK_RDMA

#include "TimberSaw/db.h"
#include <string>

namespace dlsmdb {
class db {
private:
  db();
  ~db();
  static std::mutex mtx;
  std::unique_ptr<TimberSaw::DB> db_;
  static constexpr const char *db_name = "testdb";
  void initDB();

public:
  db(const db &) = delete;
  db &operator=(const db &) = delete;
  static db *getInstance();
  int closeDB();
  int setKey(const std::string &key, const std::string &value);
  int getKey(const std::string &key, std::string &value);
};
} // namespace dlsmdb

#endif
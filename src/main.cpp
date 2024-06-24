#include "TimberSaw/db.h"
#include <iostream>

int main() {
  std::cout << "main begin" << std::endl;
  // 设置数据库选项
  TimberSaw::Options options;
  std::cout << "main co 2" << std::endl;
  options.create_if_missing = true;
  // 数据库指针
  TimberSaw::DB *db;
  TimberSaw::Status status = TimberSaw::DB::Open(options, "testdb", &db);

  if (!status.ok()) {
    std::cerr << "Unable to open/create test database 'testdb'" << std::endl;
    std::cerr << status.ToString() << std::endl;
    return -1;
  }

  // 设置写选项
  TimberSaw::WriteOptions write_options;

  // 执行 Put 操作
  status = db->Put(write_options, "key", "value");

  if (status.ok()) {
    std::cout << "Put operation successful" << std::endl;
  } else {
    std::cerr << "Put operation failed: " << status.ToString() << std::endl;
  }

  // 关闭数据库
  delete db;
  return 0;
}

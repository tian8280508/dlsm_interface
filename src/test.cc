#include "db_op.h"
#include "dlsm_service.h"
#include <chrono>
#include <cstdio>
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

void testwritebranch(dlsmdb::db *db) {
  //记录开始时间
  auto start = std::chrono::system_clock::now();
  //读取键值对
  std::string filePath =
      "/home/tjz/go_workspace/src/paper_chain/writedata/data.txt";
  std::ifstream file(filePath);
  std::map<std::string, std::string> kvpairs;
  std::string line;
  std::string key_storage;
  std::string value_storage;
  TimberSaw::Slice key_list(key_storage);
  TimberSaw::Slice value_list(value_storage);
  while (std::getline(file, line)) {
    std::istringstream iss(line);
    std::string key, value;
    if (std::getline(iss, key, ':') && std::getline(iss, value)) {
      key.erase(0, key.find_first_not_of(" \t")); // Trim leading whitespace
      key.erase(key.find_last_not_of(" \t") + 1); // Trim trailing whitespace
      value.erase(0, value.find_first_not_of(" \t")); // Trim leading whitespace
      value.erase(value.find_last_not_of(" \t") +
                  1); // Trim trailing whitespace
      kvpairs[key] = value;
    }
  }
  file.close();
  //存到dlsm
  for (const auto &item : kvpairs) {
    const std::string &key = item.first;
    const std::string &value = item.second;
    key_storage.append(key);
    value_storage.append(value);
    key_list.Reset(key_storage.data(), key_storage.size());
    value_list.Reset(value_storage.data(), value_storage.size());
  }
  db->writeBatch(key_list, value_list);
  //记录结束时间
  auto end = std::chrono::high_resolution_clock::now();
  //计算并打印时间差值
  std::chrono::duration<double> duration = end - start;
  std::cout << "writebranch方法执行时间: " << duration.count() << " 秒"
            << std::endl;
}

void testset(dlsmdb::db *db) {
  //记录开始时间
  auto start = std::chrono::system_clock::now();
  //随机set
  db->setKey("key", "value");
  //记录结束时间
  auto end = std::chrono::high_resolution_clock::now();
  //计算并打印时间差值
  std::chrono::duration<double> duration = end - start;
  std::cout << "set方法执行时间: " << duration.count() << " 秒" << std::endl;
}

void testget(dlsmdb::db *db) {
  //记录开始时间
  auto start = std::chrono::system_clock::now();
  //随机get
  std::string value;
  db->getKey(
      "b2836fc87430140577d19a9510e7f6112c382cbc7aa93134e715a8feadf1d2782",
      value);
  //记录结束时间
  auto end = std::chrono::high_resolution_clock::now();
  //计算并打印时间差值
  std::chrono::duration<double> duration = end - start;
  std::cout << "get方法执行时间: " << duration.count() << " 秒" << std::endl;
}

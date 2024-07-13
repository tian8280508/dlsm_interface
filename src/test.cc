#include "TimberSaw/slice.h"
#include "db_op.h"
#include "dlsm_service.h"
#include <chrono>
#include <cstdio>
#include <ctime>
#include <fstream>
#include <iostream>
#include <random>
#include <string>

// void testwritebatch(dlsmdb::db *db) {
//   //记录开始时间
//   auto start = std::chrono::system_clock::now();
//   //读取键值对
//   std::string filePath =
//       "/home/tjz/go_workspace/src/paper_chain/writedata/data.txt";
//   std::ifstream file(filePath);
//   std::map<std::string, std::string> kvpairs;
//   std::string line;
//   std::string key_storage;
//   std::string value_storage;
//   TimberSaw::Slice key_list(key_storage);
//   TimberSaw::Slice value_list(value_storage);
//   while (std::getline(file, line)) {
//     std::istringstream iss(line);
//     std::string key, value;
//     if (std::getline(iss, key, ':') && std::getline(iss, value)) {
//       key.erase(0, key.find_first_not_of(" \t")); // Trim leading whitespace
//       key.erase(key.find_last_not_of(" \t") + 1); // Trim trailing whitespace
//       value.erase(0, value.find_first_not_of(" \t")); // Trim leading
//       whitespace value.erase(value.find_last_not_of(" \t") +
//                   1); // Trim trailing whitespace
//       kvpairs[key] = value;
//     }
//   }
//   file.close();
//   //存到dlsm
//   for (const auto &item : kvpairs) {
//     const std::string &key = item.first;
//     const std::string &value = item.second;
//     key_storage.append(key);
//     value_storage.append(value);
//     key_list.Reset(key_storage.data(), key_storage.size());
//     value_list.Reset(value_storage.data(), value_storage.size());
//   }
//   db->writeBatch(key_list, value_list);
//   //记录结束时间
//   auto end = std::chrono::high_resolution_clock::now();
//   //计算并打印时间差值
//   std::chrono::duration<double> duration = end - start;
//   std::cout << "writebranch方法执行时间: " << duration.count() << " 秒"
//             << std::endl;
// }

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

std::string generate_random_string(size_t length) {
  const char charset[] =
      "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  const size_t max_index = sizeof(charset) - 1;
  std::random_device rd;
  std::mt19937 generator(rd());
  std::uniform_int_distribution<> dist(0, max_index);

  std::string random_string;
  for (size_t i = 0; i < length; ++i) {
    random_string += charset[dist(generator)];
  }
  return random_string;
}

int test_shard(dlsmdb::db *db) {
  std::ofstream outfile("../test_data.txt");
  if (!outfile.is_open()) {
    std::cerr << "Failed to open the file." << std::endl;
    return 1;
  }

  const size_t num_entries = 100000;
  const size_t key_size = 10;
  const size_t value_size = 200;

  for (size_t i = 0; i < num_entries; ++i) {
    std::string key = generate_random_string(key_size);
    std::string value = generate_random_string(value_size);
    outfile << key << " " << value << "\n";
  }
  outfile.close();
  std::ifstream infile("../test_data.txt");
  if (!infile.is_open()) {
    std::cerr << "Failed to open the file." << std::endl;
    return 1;
  }

  auto start = std::chrono::system_clock::now();

  std::string key;
  std::string val;
  std::vector<TimberSaw::Slice> key_list;
  std::vector<TimberSaw::Slice> val_list;
  std::vector<std::unique_ptr<char[]>> storage;

  while (infile >> key >> val) {
    auto key_storage = std::make_unique<char[]>(key.size());
    auto value_storage = std::make_unique<char[]>(val.size());

    // 复制数据到持久化存储
    std::memcpy(key_storage.get(), key.data(), key.size());
    std::memcpy(value_storage.get(), val.data(), val.size());

    // 创建 Slice 对象并添加到列表中
    key_list.emplace_back(key_storage.get(), key.size());
    val_list.emplace_back(value_storage.get(), val.size());

    // 将存储移动到 storage 向量中
    storage.push_back(std::move(key_storage));
    storage.push_back(std::move(value_storage));
  }

  // printf("keys: ");
  // for (const auto &item : key_list) {
  //   printf("%s ", item.ToString().c_str());
  // }
  // printf("\n vals: ");
  // for (const auto &item : val_list) {
  //   printf("%s ", item.ToString().c_str());
  // }
  int code = db->writeBatch(key_list, val_list);
  if (code != 0) {
    printf("test_shard code not 0:%d", code);
  }
  auto end = std::chrono::high_resolution_clock::now();
  //计算并打印时间差值
  std::chrono::duration<double> duration = end - start;
  std::cerr << "writeBatch方法执行时间: " << duration.count() << " 秒"
            << std::endl;

  // test GetKey, and print time cost.
  start = std::chrono::system_clock::now();
  int idx = 9999;
  std::string get_val;
  code = db->getKey(key_list[idx].ToString(), get_val);
  if (code != 0) {
    printf("test_shard code not 0:%d", code);
  }
  end = std::chrono::high_resolution_clock::now();
  duration = end - start;
  std::cerr << "getkey 方法执行时间: " << duration.count() << " 秒"
            << std::endl;
  assert(get_val == val_list[idx].ToString());
  infile.close();
  return 0;
}

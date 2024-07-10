#include "db_op.h"
#include "dlsm_service.h"
#include <cstdio>




//stack message
// 在 main 函数中，调用 dlsmdb::db::getInstance() 获取数据库实例。
// db::getInstance() 内部会调用 db 类的构造函数，而构造函数中已经完成了数据库的初始化(db::initDB)
// 调用open函数，连接DLSM的Server端
// 如果成功获取数据库实例，打印 "ready to RunServer" 并调用 RunServer(db) 启动服务器。
// 服务器运行结束后，调用 db->closeDB() 关闭数据库。
int main() {
  dlsmdb::db *db = dlsmdb::db::getInstance();
  if (db == nullptr) {
    fprintf(stderr, "Failed to initialize database.");
    return -1;
  }
  RunServer(db);
  db->closeDB();
  return 0;
}

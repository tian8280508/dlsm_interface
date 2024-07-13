#include "db_op.h"
#include "dlsm_service.h"
#include "test.h"
#include <cstdio>
int main(int argc, char *argv[]) {
  int node_id = 1;
  if (argc == 2) {
    node_id = std::atoi(argv[1]);
  }
  dlsmdb::db *db = dlsmdb::db::getInstance(node_id);
  if (db == nullptr) {
    fprintf(stderr, "Failed to initialize database.");
    return -1;
  }
  // testwritebatch(db);
  // testset(db);
  // testget(db);
  test_shard(db);
  // RunServer(db);
  return 0;
}

#include "db_op.h"
#include "dlsm_service.h"
#include <cstdio>

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

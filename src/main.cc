#include "db_op.h"
#include "dlsm_service.h"

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

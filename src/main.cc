#include "TimberSaw/db.h"
#include "db_connect.h"

int main() {
  TimberSaw::DB *db = dlsmdb::GetDBInstance();
  if (db == nullptr) {
    fprintf(stderr, "Failed to initialize database.");
    return -1;
  }
  dlsmdb::CloseDB();
  return 0;
}

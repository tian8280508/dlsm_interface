#ifndef DLSMDB_H
#define DLSMDB_H

#include "TimberSaw/db.h"
#include <string>

namespace dlsmdb {
TimberSaw::DB *GetDBInstance();
int CloseDB();
int SetKey(const std::string &key, const std::string &value);
int GetKey(const std::string &key, const std::string &value);
} // namespace dlsmdb

#endif
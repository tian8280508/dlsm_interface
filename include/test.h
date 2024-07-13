#ifndef TEST_H
#define TEST_H

#include "db_op.h"

void testwritebatch(dlsmdb::db *db);
void testset(dlsmdb::db *db);
void testget(dlsmdb::db *db);
int test_shard(dlsmdb::db *db);
std::string generate_random_string(size_t length);

#endif // TEST_H
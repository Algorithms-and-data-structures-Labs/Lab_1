#include <table/OpenAddressingHashTable.h>

#include "gtest/gtest.h"

TEST(OpenAddrHashTable, InsertAndFind) {
  OpenAddrHashTable<string, int> table(5, 2);
  table.Insert("key1", 10);
  table.Insert("key2", 20);

  EXPECT_EQ(*table.Find("key1"), 10);
  EXPECT_EQ(*table.Find("key2"), 20);
}
TEST(OpenAddrHashTable, Delete) {
  OpenAddrHashTable<string, int> table(5, 2);
  table.Insert("key1", 100);
  table.Insert("key2", 200);

  table.Delete("key1");
  EXPECT_EQ(table.Find("key1"), nullptr);
}

TEST(OpenAddrHashTable, ResetAndGoNext) {
  OpenAddrHashTable<string, int> table(5, 2);
  table.Insert("key1", 100);
  table.Insert("key2", 200);

  table.Reset();
  EXPECT_EQ(table.GetKey(), "key1");

  table.GoNext();
  EXPECT_EQ(table.GetKey(), "key2");
}
TEST(OpenAddrHashTable, DeleteNonExistent) {
  OpenAddrHashTable<string, int> table(5, 2);
  table.Insert("key1", 100);
  table.Insert("key2", 200);

  table.Delete("key3");
  EXPECT_EQ(table.Find("key3"), nullptr);
}

TEST(OpenAddrHashTable, IsFull) {
  OpenAddrHashTable<string, int> table(2, 2);
  table.Insert("key1", 100);
  table.Insert("key2", 200);

  EXPECT_TRUE(table.IsFull());
}

TEST(OpenAddrHashTable, InsertDuplicate) {
  OpenAddrHashTable<string, int> table(5, 2);
  table.Insert("key1", 100);
  table.Insert("key2", 200);

  EXPECT_EQ(*table.Find("key1"), 100);
}

TEST(OpenAddrHashTable, IsTabEnded) {
  OpenAddrHashTable<string, int> table(2, 2);
  table.Insert("key1", 100);
  table.Insert("key2", 200);

  EXPECT_TRUE(table.IsTabEnded());
}

TEST(OpenAddrHashTable, GetKeyTest) {
  OpenAddrHashTable<string, int> table(5, 2);
  table.Insert("key1", 100);

  EXPECT_EQ(table.GetKey(), "key1");
}

TEST(OpenAddrHashTable, IsEmptyTest) {
  OpenAddrHashTable<string, int> table(5, 2);
  EXPECT_TRUE(table.IsEmpty());
}
TEST(OpenAddrHashTable, isempty_test2) {
  OpenAddrHashTable<string, int> table(5, 2);
  table.Insert("key1", 100);
  bool a = table.IsEmpty();
  ASSERT_EQ(0, a);
}
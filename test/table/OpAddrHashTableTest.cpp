#include <table/OpenAddressingHashTable.h>

#include "gtest/gtest.h"

TEST(OpenAddrHashTable, InsertAndFind) {
  OpenAddrHashTable<int, int> table(5, 2);
  table.Insert(1, 10);
  table.Insert(2, 20);

  EXPECT_EQ(*table.Find(1), 10);
  EXPECT_EQ(*table.Find(2), 20);
}
TEST(OpenAddrHashTable, Delete) {
  OpenAddrHashTable<int, int> table(5, 2);
  table.Insert(1, 100);
  table.Insert(2, 200);

  table.Delete(1);
  EXPECT_EQ(table.Find(1), nullptr);
}

TEST(OpenAddrHashTable, ResetAndGoNext) {
  OpenAddrHashTable<int, int> table(5, 2);
  table.Insert(1, 100);
  table.Insert(2, 200);

  table.Reset();
  EXPECT_EQ(table.GetKey(), 1);

  table.GoNext();
  EXPECT_EQ(table.GetKey(), 2);
}
TEST(OpenAddrHashTable, DeleteNonExistent) {
  OpenAddrHashTable<int, int> table(5, 2);
  table.Insert(1, 100);
  table.Insert(2, 200);

  table.Delete(3);
  EXPECT_EQ(table.Find(3), nullptr);
}

TEST(OpenAddrHashTable, IsFull) {
  OpenAddrHashTable<int, int> table(2, 2);
  table.Insert(1, 100);
  table.Insert(2, 200);

  EXPECT_TRUE(table.IsFull());
}

TEST(OpenAddrHashTable, InsertDuplicate) {
  OpenAddrHashTable<int, int> table(5, 2);
  table.Insert(1, 100);
  table.Insert(2, 200);

  EXPECT_EQ(*table.Find(1), 100);
}

TEST(OpenAddrHashTable, IsTabEnded) {
  OpenAddrHashTable<int, int> table(2, 2);
  table.Insert(1, 100);
  table.Insert(2, 200);

  EXPECT_TRUE(table.IsTabEnded());
}

TEST(OpenAddrHashTable, GetKeyTest) {
  OpenAddrHashTable<int, int> table(5, 2);
  table.Insert(1, 100);
  table.Insert(2, 200);
  EXPECT_EQ(table.GetKey(), 2);
}

TEST(OpenAddrHashTable, IsEmptyTest) {
  OpenAddrHashTable<int, int> table(5, 2);
  EXPECT_TRUE(table.IsEmpty());
}
TEST(OpenAddrHashTable, isempty_test2) {
  OpenAddrHashTable<int, int> table(5, 2);
  table.Insert(1, 100);
  bool a = table.IsEmpty();
  ASSERT_EQ(0, a);
}
#include <table/ListHashTable.h>

#include "gtest/gtest.h"
TEST(ListHashTable, InsertAndFind) {
  ListHashTable<int, int> hashTable(25);
  hashTable.Insert(1, 10);
  hashTable.Insert(2, 20);
  EXPECT_EQ(10, *(hashTable.Find(1)));
  EXPECT_EQ(20, *(hashTable.Find(2)));
}

TEST(ListHashTable, Delete) {
  ListHashTable<int, int> hashTable(25);
  hashTable.Insert(1, 10);
  hashTable.Insert(2, 20);
  hashTable.Delete(1);
  EXPECT_EQ(nullptr, hashTable.Find(1));
}

TEST(ListHashTable, DeleteNonExistent) {
  ListHashTable<int, int> table(25);
  table.Insert(1, 100);
  table.Insert(2, 200);
  table.Delete(3);
  EXPECT_EQ(table.Find(3), nullptr);
}

TEST(ListHashTable, IsFull) {
  ListHashTable<int, int> table(2);
  EXPECT_FALSE(table.IsFull());
}

TEST(ListHashTable, InsertDuplicate) {
  ListHashTable<int, int> table(25);
  table.Insert(1, 100);
  table.Insert(2, 200);
  EXPECT_EQ(*table.Find(1), 100);
}

TEST(ListHashTable, isempty_test) {
  ListHashTable<int, int> table(25);
  table.Insert(1, 100);
  bool a = table.IsEmpty();
  ASSERT_EQ(0, a);
}

TEST(ListHashTable, IsTabEnded) {
  ListHashTable<int, int> table(2);
  table.Insert(1, 100);
  table.Insert(2, 200);
  EXPECT_FALSE(table.IsTabEnded());
}

TEST(ListHashTable, GetValueTest) {
  ListHashTable<int, int> table(2);
  table.Insert(1, 100);
  table.Insert(2, 200);
  EXPECT_EQ(200, table.GetValuePtr());
}

TEST(ListHashTable, GetKeyTest) {
  ListHashTable<int, int> table(2);
  table.Insert(1, 20);
  table.Insert(2, 100);
  EXPECT_EQ(2, table.GetKey());
}

TEST(ListHashTable, ResetAndGoNext) {
  ListHashTable<int, int> table(2);
  table.Insert(2, 20);
  table.Insert(1, 100);
  table.Reset();
  EXPECT_EQ(2, table.GetKey());
  table.GoNext();
  EXPECT_EQ(1, table.GetKey());
}

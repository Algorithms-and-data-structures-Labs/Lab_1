#include <table/ListHashTable.h>

#include "gtest/gtest.h"
TEST(ListHashTable, InsertAndFind) {
  ListHashTable<string, int> hashTable(25);
  hashTable.Insert("abc", 10);
  hashTable.Insert("def", 20);

  EXPECT_EQ(10, *(hashTable.Find("abc")));
  EXPECT_EQ(20, *(hashTable.Find("def")));
}

TEST(ListHashTable, Delete) {
  ListHashTable<string, int> hashTable(25);
  hashTable.Insert("abc", 10);
  hashTable.Insert("def", 20);

  hashTable.Delete("abc");

  EXPECT_EQ(nullptr, hashTable.Find("abc"));
}


TEST(ListHashTable, DeleteNonExistent) {
  ListHashTable<string, int> table(25);
  table.Insert("key1", 100);
  table.Insert("key2", 200);

  table.Delete("key3");
  EXPECT_EQ(table.Find("key3"), nullptr);
}

TEST(ListHashTable, IsFull) {
  ListHashTable<string, int> table(2);
  EXPECT_FALSE(table.IsFull());
}

TEST(ListHashTable, InsertDuplicate) {
  ListHashTable<string, int> table(25);
  table.Insert("key1", 100);
  table.Insert("key2", 200);

  EXPECT_EQ(*table.Find("key1"), 100);
}

TEST(ListHashTable, isempty_test) {
  ListHashTable<string, int> table(25);
  table.Insert("key1", 100);
  bool a = table.IsEmpty();
  ASSERT_EQ(0, a);
}

 TEST(ListHashTable, IsTabEnded) {
  ListHashTable<string, int> table(2);
  table.Insert("key1", 100);
  table.Insert("key2", 200);
  EXPECT_FALSE(table.IsTabEnded());
 }

 TEST(ListHashTable, GetValueTest) {
  ListHashTable<string, int> table(2);
  table.Insert("abc", 100);
  EXPECT_EQ(100, table.GetValuePtr());   
 }
 TEST(ListHashTable, GetKeyTest) {
  ListHashTable<string, int> table(2);
  table.Insert("def", 20);
  table.Insert("abc", 100);
  EXPECT_EQ("abc", table.GetKey());
 }

 TEST(ListHashTable, ResetAndGoNext) {
  ListHashTable<string, int> hashTable(3);
  hashTable.Insert("abc", 10);
  hashTable.Insert("def", 20);
  hashTable.Insert("ghi", 30);
  hashTable.Reset();
  EXPECT_EQ("abc", hashTable.GetKey());
  hashTable.GoNext();
  hashTable.GoNext();
  EXPECT_EQ("ghi", hashTable.GetKey());
 }
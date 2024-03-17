#include <table/TreeTable.h>

#include "gtest/gtest.h"

TEST(TreeTable, InsertAndFind) {
  TreeTable<int, int> treeTable;

  treeTable.Insert(1, 1);
  treeTable.Insert(2, 2);

  EXPECT_EQ(*treeTable.Find(1), 1);
  EXPECT_EQ(*treeTable.Find(2), 2);
}
TEST(TreeTable, isempty_test1) {
  TreeTable<int, int> arrtab;
  bool a = arrtab.IsEmpty();
  ASSERT_EQ(1, a);
}
TEST(TreeTable, isempty_test2) {
  TreeTable<int, int> arrtab;
  arrtab.Insert(1, 1);
  bool a = arrtab.IsEmpty();
  ASSERT_EQ(0, a);
}
TEST(TreeTable, ResetAndGoNext) {
  TreeTable<int, int> table;

  table.Insert(5, 50);
  table.Insert(3, 30);
  table.Insert(7, 70);

  table.Reset();
  ASSERT_EQ(table.GetKey(), 3);

  table.GoNext();
  ASSERT_EQ(table.GetKey(), 5);

  table.GoNext();
  ASSERT_EQ(table.GetKey(), 7);
}

TEST(TreeTable, DeleteNonExistent) {
  TreeTable<int, int> treeTable;

  treeTable.Insert(1, 10);
  treeTable.Insert(2, 20);
  treeTable.Delete(3);
  EXPECT_EQ(*(treeTable.Find(1)), 10);
  EXPECT_EQ(*(treeTable.Find(2)), 20);
}

TEST(TreeTable, Delete) {
  TreeTable<int, int> treeTable;

  treeTable.Insert(1, 1);
  treeTable.Insert(2, 2);

  treeTable.Delete(1);

  EXPECT_EQ(treeTable.Find(1), nullptr);
  EXPECT_EQ(*treeTable.Find(2), 2);
}

TEST(TreeTable, IsFull) {
  TreeTable<int, int> treeTable;
  EXPECT_FALSE(treeTable.IsFull());
}

TEST(TreeTable, InsertDuplicate) {
  TreeTable<int, int> treeTable;

  treeTable.Insert(1, 1);
  treeTable.Insert(1, 2);

  EXPECT_EQ(*treeTable.Find(1), 1);
}

TEST(TreeTable, IsTabEnded) {
  TreeTable<int, int> table;

  ASSERT_EQ(table.IsTabEnded(), 1);

  table.Insert(5, 50);
  ASSERT_EQ(table.IsTabEnded(), 0);

  table.Reset();
  ASSERT_EQ(table.IsTabEnded(), 0);

  table.GoNext();
  ASSERT_EQ(table.IsTabEnded(), 1);
}

TEST(TreeTable, getkey_test) {
  TreeTable<int, int> arrtab;
  arrtab.Insert(1, 1);
  arrtab.Insert(2, 2);
  int a = 0;
  for (arrtab.Reset(); !arrtab.IsTabEnded(); arrtab.GoNext()) {
    a += arrtab.GetKey();
  }
  ASSERT_EQ(3, a);
}

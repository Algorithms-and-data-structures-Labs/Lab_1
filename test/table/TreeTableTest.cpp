#include <table/TreeTable.h>

#include "gtest/gtest.h"

TEST(TreeTable, InsertAndFind) {
  TreeTable<int, int> treeTable;

  treeTable.Insert(1, 1);
  treeTable.Insert(2, 2);

  EXPECT_EQ(*treeTable.Find(1), 1);
  EXPECT_EQ(*treeTable.Find(2), 2);
}


 //Тест проверки корректного перебора элементов

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

// Тест на удаление несуществующего элемента
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

  EXPECT_EQ(*treeTable.Find(1), 2);
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

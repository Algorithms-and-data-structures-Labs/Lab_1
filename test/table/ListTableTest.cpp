#include <table/ListTable.h>

#include "gtest/gtest.h"

TEST(ListTable, find_test) {
  ListTable<int, int> listtab;
  listtab.Insert(1, 1);
  listtab.Insert(2, 2);
  listtab.Insert(3, 2);
  int a = *listtab.Find(1);
  ASSERT_EQ(1, a);
}

TEST(ListTable, find_test_not_found) {
  ListTable<int, int> listtab;
  listtab.Insert(1, 1);
  listtab.Insert(2, 2);
  listtab.Insert(4, 2);
  ASSERT_EQ(nullptr, listtab.Find(3));
}

TEST(ListTable, insert_test) {
  ListTable<int, int> listtab;
  listtab.Insert(1, 1);
  int a = *listtab.Find(1);
  ASSERT_EQ(1, a);
}

TEST(ListTable, full_test) {
  ListTable<int, int> listtab;
  listtab.Insert(1, 1);
  listtab.Insert(2, 2);
  listtab.Insert(3, 2);
  listtab.Insert(200, 100);
  ASSERT_EQ(false, listtab.IsFull());
}

TEST(ListTable, delete_test) {
  ListTable<int, int> listtab;
  listtab.Insert(1, 1);
  listtab.Insert(2, 2);
  listtab.Insert(3, 2);
  listtab.Insert(200, 100);
  listtab.Delete(2);
  ASSERT_EQ(nullptr, listtab.Find(2));
}

TEST(ListTable, Is_Ended) {
  ListTable<int, int> listtab;
  listtab.Insert(1, 1);
  listtab.Insert(2, 2);
  listtab.GoNext();
  listtab.GoNext();
  ASSERT_EQ(true, listtab.IsTabEnded());
}

TEST(ListTable, GoNext) {
  ListTable<int, int> listtab;
  listtab.Insert(1, 1);
  listtab.Insert(2, 2);
  listtab.GoNext();
  ASSERT_EQ(1, listtab.GetKey());
}

TEST(ListTable, GetKey_1) {
  ListTable<int, int> listtab;
  listtab.Insert(1, 1);
  listtab.Insert(2, 2);
  ASSERT_EQ(2, listtab.GetKey());
}

TEST(ListTable, GetKey_2) {
  ListTable<int, int> listtab;
  listtab.Insert(1, 1);
  listtab.Insert(2, 2);
  listtab.GoNext();
  ASSERT_EQ(1, listtab.GetKey());
}

TEST(ListTable, GetValue_1) {
  ListTable<int, int> listtab;
  listtab.Insert(1, 1);
  listtab.Insert(2, 2);
  ASSERT_EQ(2, listtab.GetKey());
}

TEST(ListTable, GetValue_2) {
  ListTable<int, int> listtab;
  listtab.Insert(1, 1);
  listtab.Insert(2, 2);
  listtab.GoNext();
  ASSERT_EQ(1, listtab.GetKey());
}

TEST(ListTable, insert_test_double) {
  ListTable<int, double> listtab;
  listtab.Insert(1, 1.0);
  int a = *listtab.Find(1);
  ASSERT_EQ(1.0, a);
}

TEST(ListTable, insert_test_string) {
  ListTable<int, string> listtab;
  listtab.Insert(1, "Vasya");
  string a = *listtab.Find(1);
  ASSERT_EQ("Vasya", a);
}

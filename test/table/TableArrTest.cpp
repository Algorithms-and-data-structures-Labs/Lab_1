#include <table/tablearr.h>

#include "gtest/gtest.h"

TEST(TableArray, find_test1) {
  ArrayTable<int, int> arrtab;
  arrtab.Insert(1, 1);
  int a = *arrtab.Find(1);
  ASSERT_EQ(1, a);
}

TEST(TableArray, find_test2) {
  ArrayTable<int, int> arrtab;
  arrtab.Insert(1, 2);
  int a = *arrtab.Find(1);
  ASSERT_EQ(2, a);
}
TEST(TableArray, find_test3) {
  ArrayTable<int, int> arrtab;
  arrtab.Insert(2, 1);
  int a = *arrtab.Find(2);
  ASSERT_EQ(1, a);
}
TEST(TableArray, delete_test) {
  ArrayTable<int, int> arrtab;
  arrtab.Insert(1, 1);
  arrtab.Insert(2, 2);
  arrtab.Delete(2);
  arrtab.Insert(2, 2);
  int a = *arrtab.Find(2);
  ASSERT_EQ(2, a);
}
TEST(TableArray, isfull_test1) {
  ArrayTable<int, int> arrtab;
  for (int i = 0; i < 100; i++) arrtab.Insert(i, i);
  bool a = arrtab.IsFull();
  ASSERT_EQ(1, a);
}
TEST(TableArray, isfull_test2) {
  ArrayTable<int, int> arrtab;
  for (int i = 0; i < 99; i++) arrtab.Insert(i, i);
  bool a = arrtab.IsFull();
  ASSERT_EQ(0, a);
}
TEST(TableArray, isempty_test1) {
  ArrayTable<int, int> arrtab;
  bool a = arrtab.IsEmpty();
  ASSERT_EQ(1, a);
}
TEST(TableArray, isempty_test2) {
  ArrayTable<int, int> arrtab;
  arrtab.Insert(1, 1);
  bool a = arrtab.IsEmpty();
  ASSERT_EQ(0, a);
}
TEST(TableArray, getvalueptr_test1) {
  ArrayTable<int, int> arrtab;
  arrtab.Insert(1, 1);
  arrtab.Insert(2, 3);
  arrtab.Insert(3, 5);
  int a = 0;
  arrtab.Reset();
  a = arrtab.GetValuePtr();
  int b = 0;
  arrtab.GoNext();
  b = arrtab.GetValuePtr();
  int c = 0;
  arrtab.GoNext();
  c = arrtab.GetValuePtr();
  ASSERT_EQ(1, a);
  ASSERT_EQ(3, b);
  ASSERT_EQ(5, c);
}
TEST(TableArray, getvalueptr_test2) {
  ArrayTable<int, int> arrtab;
  arrtab.Insert(1, 2);
  arrtab.Insert(2, 4);
  arrtab.Insert(3, 6);
  int a = 0;
  for (arrtab.Reset(); !arrtab.IsTabEnded(); arrtab.GoNext()) {
    a += arrtab.GetValuePtr();
  }
  ASSERT_EQ(12, a);
}
TEST(TableArray, getkey_test1) {
  ArrayTable<int, int> arrtab;
  arrtab.Insert(1, 1);
  arrtab.Insert(2, 2);
  int a = 0;
  for (arrtab.Reset(); !arrtab.IsTabEnded(); arrtab.GoNext()) {
    a += arrtab.GetKey();
  }
  ASSERT_EQ(3, a);
}
TEST(TableArray, getkey_test2) {
  ArrayTable<int, int> arrtab;
  arrtab.Insert(2, 2);
  arrtab.Insert(3, 3);
  int a = 0;
  for (arrtab.Reset(); !arrtab.IsTabEnded(); arrtab.GoNext()) {
    a += arrtab.GetKey();
  }
  ASSERT_EQ(5, a);
}

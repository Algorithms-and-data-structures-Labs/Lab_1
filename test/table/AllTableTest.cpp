#include <table/alltable.h>

#include "gtest/gtest.h"

TEST(TableAll, find_test1) {
  AllTable<int, int> tab;
  tab.Insert(1, 1);
  std::vector<int> vecOfOnes(6, 1);
  std::vector<int*> a = tab.Find(1);
  std::vector<int> b;
  for (int i = 0; i < 6; i++) b.push_back(*a[i]);
  ASSERT_EQ(vecOfOnes, b);
}
TEST(TableAll, find_test2) {
  AllTable<int, int> tab;
  tab.Insert(1, 2);
  std::vector<int> vecOfOnes(6, 2);
  std::vector<int*> a = tab.Find(1);
  std::vector<int> b;
  for (int i = 0; i < 6; i++) b.push_back(*a[i]);
  ASSERT_EQ(vecOfOnes, b);
}
TEST(TableAll, find_test3) {
  AllTable<int, int> tab;
  tab.Insert(2, 1);
  std::vector<int> vecOfOnes(6, 1);
  std::vector<int*> a = tab.Find(2);
  std::vector<int> b;
  for (int i = 0; i < 6; i++) b.push_back(*a[i]);
  ASSERT_EQ(vecOfOnes, b);
}
TEST(TableAll, delete_test) {
  AllTable<int, int> tab;
  tab.Insert(1, 1);
  tab.Insert(1, 2);
  tab.Delete(2);
  tab.Insert(2, 2);
  std::vector<int> vecOfOnes(6, 2);
  std::vector<int*> a = tab.Find(2);
  std::vector<int> b;
  for (int i = 0; i < 6; i++) b.push_back(*a[i]);
  ASSERT_EQ(vecOfOnes, b);
}
TEST(TableAll, isfull_test1) {
  AllTable<int, int> tab;
  for (int i = 0; i < 100; i++) tab.Insert(i, i);
  bool a = tab.IsFull();
  ASSERT_EQ(1, a);
}
TEST(TableAll, isfull_test2) {
  AllTable<int, int> tab;
  for (int i = 0; i < 99; i++) tab.Insert(i, i);
  bool a = tab.IsFull();
  ASSERT_EQ(0, a);
}
TEST(TableAll, isempty_test1) {
  AllTable<int, int> tab;
  bool a = tab.IsEmpty();
  ASSERT_EQ(1, a);
}
TEST(TableAll, isempty_test2) {
  AllTable<int, int> tab;
  tab.Insert(1, 1);
  bool a = tab.IsEmpty();
  ASSERT_EQ(0, a);
}
TEST(TableAll, getvalueptr_test1) {
  AllTable<int, int> tab;
  tab.Insert(1, 1);
  tab.Insert(2, 3);
  tab.Insert(3, 5);
  std::vector<int> a;
  tab.Reset();
  a = tab.GetValuePtr();
  std::vector<int> b;
  tab.GoNext();
  b = tab.GetValuePtr();
  std::vector<int> c;
  tab.GoNext();
  c = tab.GetValuePtr();
  std::vector<int> vec1 = {1, 5, 5, 5, 5, 5};
  std::vector<int> vec2(6, 3);
  std::vector<int> vec3 = {5, 1, 1, 1, 1, 1};
  ASSERT_EQ(vec1, a);
  ASSERT_EQ(vec2, b);
  ASSERT_EQ(vec3, c);
}
TEST(TableAll, getvalueptr_test2) {
  AllTable<int, int> tab;
  tab.Insert(1, 2);
  tab.Insert(2, 4);
  tab.Insert(3, 6);
  std::vector<int> a;
  tab.Reset();
  a = tab.GetValuePtr();
  std::vector<int> b;
  tab.GoNext();
  b = tab.GetValuePtr();
  std::vector<int> c;
  tab.GoNext();
  c = tab.GetValuePtr();
  std::vector<int> vec1 = {2, 6, 6, 6, 6, 6};
  std::vector<int> vec2(6, 4);
  std::vector<int> vec3 = {6, 2, 2, 2, 2, 2};
  ASSERT_EQ(vec1, a);
  ASSERT_EQ(vec2, b);
  ASSERT_EQ(vec3, c);
}
TEST(TableAll, getkey_test1) {
  AllTable<int, int> tab;
  tab.Insert(1, 2);
  tab.Insert(2, 4);
  tab.Insert(3, 6);
  std::vector<int> a;
  tab.Reset();
  a = tab.GetKey();
  std::vector<int> b;
  tab.GoNext();
  b = tab.GetKey();
  std::vector<int> c;
  tab.GoNext();
  c = tab.GetKey();
  std::vector<int> vec1 = {1, 3, 3, 3, 3, 3};
  std::vector<int> vec2(6, 2);
  std::vector<int> vec3 = {3, 1, 1, 1, 1, 1};
  ASSERT_EQ(vec1, a);
  ASSERT_EQ(vec2, b);
  ASSERT_EQ(vec3, c);
}
TEST(TableAll, getkey_test2) {
  AllTable<int, int> tab;
  tab.Insert(3, 2);
  tab.Insert(8, 4);
  tab.Insert(10, 6);
  std::vector<int> a;
  tab.Reset();
  a = tab.GetKey();
  std::vector<int> b;
  tab.GoNext();
  b = tab.GetKey();
  std::vector<int> c;
  tab.GoNext();
  c = tab.GetKey();
  std::vector<int> vec1 = {3, 10, 10, 10, 10, 10};
  std::vector<int> vec2(6, 8);
  std::vector<int> vec3 = {10, 3, 3, 3, 3, 3};
  ASSERT_EQ(vec1, a);
  ASSERT_EQ(vec2, b);
  ASSERT_EQ(vec3, c);
}

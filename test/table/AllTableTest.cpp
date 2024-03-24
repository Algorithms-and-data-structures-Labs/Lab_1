#include <table/alltable.h>

#include "gtest/gtest.h"

TEST(TableAll, find_test1) {
  AllTable<string, int> tab;
  tab.Insert("key1", 1);
  std::vector<int> vecOfOnes(6, 1);
  std::vector<int*> a = tab.Find("key1");
  std::vector<int> b;
  for (int i = 0; i < 6; i++) b.push_back(*a[i]);
  ASSERT_EQ(vecOfOnes, b);
}
TEST(TableAll, find_test2) {
  AllTable<string, int> tab;
  tab.Insert("key1", 2);
  std::vector<int> vecOfOnes(6, 2);
  std::vector<int*> a = tab.Find("key1");
  std::vector<int> b;
  for (int i = 0; i < 6; i++) b.push_back(*a[i]);
  ASSERT_EQ(vecOfOnes, b);
}
TEST(TableAll, find_test3) {
  AllTable<string, int> tab;
  tab.Insert("key2", 1);
  std::vector<int> vecOfOnes(6, 1);
  std::vector<int*> a = tab.Find("key2");
  std::vector<int> b;
  for (int i = 0; i < 6; i++) b.push_back(*a[i]);
  ASSERT_EQ(vecOfOnes, b);
}
TEST(TableAll, delete_test) {
  AllTable<string, int> tab;
  tab.Insert("key1", 1);
  tab.Insert("key2", 3);
  tab.Delete("key2");
  tab.Insert("key2", 2);
  std::vector<int> vecOfOnes(6, 2);
  std::vector<int*> a = tab.Find("key2");
  std::vector<int> b;
  for (int i = 0; i < 6; i++) b.push_back(*a[i]);
  ASSERT_EQ(vecOfOnes, b);
}
TEST(TableAll, isfull_test1) {
  AllTable<string, int> tab;
  for (int i = 0; i < 100; i++) tab.Insert("key" + (char)i, i);
  bool a = tab.IsFull();
  ASSERT_EQ(1, a);
}
TEST(TableAll, isfull_test2) {
  AllTable<string, int> tab;
  for (int i = 0; i < 99; i++) tab.Insert("key" + (char)i, i);
  bool a = tab.IsFull();
  ASSERT_EQ(0, a);
}
TEST(TableAll, isempty_test1) {
  AllTable<string, int> tab;
  bool a = tab.IsEmpty();
  ASSERT_EQ(1, a);
}
TEST(TableAll, isempty_test2) {
  AllTable<string, int> tab;
  tab.Insert("key1", 1);
  bool a = tab.IsEmpty();
  ASSERT_EQ(0, a);
}
TEST(TableAll, getvalueptr_test1) {
  AllTable<string, int> tab;
  tab.Insert("key1", 1);
  tab.Insert("key2", 3);
  tab.Insert("key3", 5);
  std::vector<int> a;
  tab.Reset();
  a = tab.GetValuePtr();
  std::vector<int> b;
  tab.GoNext();
  b = tab.GetValuePtr();
  std::vector<int> c;
  tab.GoNext();
  c = tab.GetValuePtr();
  std::vector<int> vec1 = {1, 5, 1, 1, 1, 1};
  std::vector<int> vec2(6, 3);
  std::vector<int> vec3 = {5, 1, 5, 5, 5, 5};
  ASSERT_EQ(vec1, a);
  ASSERT_EQ(vec2, b);
  ASSERT_EQ(vec3, c);
}
TEST(TableAll, getvalueptr_test2) {
  AllTable<string, int> tab;
  tab.Insert("key1", 2);
  tab.Insert("key2", 4);
  tab.Insert("key3", 6);
  std::vector<int> a;
  tab.Reset();
  a = tab.GetValuePtr();
  std::vector<int> b;
  tab.GoNext();
  b = tab.GetValuePtr();
  std::vector<int> c;
  tab.GoNext();
  c = tab.GetValuePtr();
  std::vector<int> vec1 = {2, 6, 2, 2, 2, 2};
  std::vector<int> vec2(6, 4);
  std::vector<int> vec3 = {6, 2, 6, 6, 6, 6};
  ASSERT_EQ(vec1, a);
  ASSERT_EQ(vec2, b);
  ASSERT_EQ(vec3, c);
}
TEST(TableAll, getkey_test1) {
  AllTable<string, int> tab;
  tab.Insert("key1", 2);
  tab.Insert("key2", 4);
  tab.Insert("key3", 6);
  std::vector<string> a;
  tab.Reset();
  a = tab.GetKey();
  std::vector<string> b;
  tab.GoNext();
  b = tab.GetKey();
  std::vector<string> c;
  tab.GoNext();
  c = tab.GetKey();
  std::vector<string> vec1 = {"key1", "key3", "key1", "key1", "key1", "key1"};
  std::vector<string> vec2(6, "key2");
  std::vector<string> vec3 = {"key3", "key1", "key3", "key3", "key3", "key3"};
  ASSERT_EQ(vec1, a);
  ASSERT_EQ(vec2, b);
  ASSERT_EQ(vec3, c);
}
TEST(TableAll, getkey_test2) {
  AllTable<string, int> tab;
  tab.Insert("key3", 2);
  tab.Insert("key8", 4);
  tab.Insert("key10", 6);
  std::vector<string> a;
  tab.Reset();
  a = tab.GetKey();
  std::vector<string> b;
  tab.GoNext();
  b = tab.GetKey();
  std::vector<string> c;
  tab.GoNext();
  c = tab.GetKey();
  std::vector<string> vec1 = {"key3", "key10", "key3", "key3", "key10", "key3"};
  std::vector<string> vec2 = {"key8", "key8", "key10", "key10", "key3", "key8"};
  std::vector<string> vec3 = {"key10", "key3", "key8", "key8", "key8", ""};
  ASSERT_EQ(vec1, a);
  ASSERT_EQ(vec2, b);
  ASSERT_EQ(vec3, c);
}

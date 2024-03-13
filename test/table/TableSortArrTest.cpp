#include <table/tablearrsort.h>

#include "gtest/gtest.h"

TEST(SortArrayTable, basic_test1) {
  SortArrayTable<int, int> arrtab;
  arrtab.Insert(1, 1);
  int a = *arrtab.Find(1);
  ASSERT_EQ(1, a);
}
TEST(SortArrayTable, basic_test2) {
  SortArrayTable<int, int> arrtab;
  arrtab.Insert(1, 2);
  int a = *arrtab.Find(1);
  ASSERT_EQ(2, a);
}
TEST(SortArrayTable, insert_and_find_multiple_elements) {
  SortArrayTable<int, int> arrtab;
  arrtab.Insert(3, 30);
  arrtab.Insert(1, 10);
  arrtab.Insert(4, 40);
  arrtab.Insert(2, 20);

  int a = *arrtab.Find(1);
  ASSERT_EQ(10, a);

  a = *arrtab.Find(2);
  ASSERT_EQ(20, a);

  a = *arrtab.Find(3);
  ASSERT_EQ(30, a);

  a = *arrtab.Find(4);
  ASSERT_EQ(40, a);
}

TEST(SortArrayTable, insert_and_remove_element) {
  SortArrayTable<int, int> arrtab;
  arrtab.Insert(3, 30);
  arrtab.Insert(1, 10);
  arrtab.Insert(4, 40);
  arrtab.Insert(2, 20);

  arrtab.Delete(3);

  ASSERT_TRUE(arrtab.Find(3) == nullptr);
}

TEST(SortArrayTable, find_nonexistent_key) {
  SortArrayTable<int, int> arrtab;
  arrtab.Insert(3, 30);
  arrtab.Insert(1, 10);

  ASSERT_TRUE(arrtab.Find(2) == nullptr);  
}

TEST(SortArrayTable, insert_duplicate_key) {
  SortArrayTable<int, int> arrtab;
  arrtab.Insert(3, 30);
  arrtab.Insert(3, 300);

  int a = *arrtab.Find(3);
  ASSERT_EQ(30, a);  
}
TEST(SortArrayTable, remove_all_elements) {
  SortArrayTable<int, int> arrtab;
  const int num_elements = 100;

  for (int i = 0; i < num_elements; ++i) {
    arrtab.Insert(i, i * 10);
  }

  for (int i = 0; i < num_elements; ++i) {
    arrtab.Delete(i);
    ASSERT_TRUE(arrtab.Find(i) == nullptr);
  }
}
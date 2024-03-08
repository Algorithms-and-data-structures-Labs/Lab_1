#include <table/tablearr.h>

#include "gtest/gtest.h"

TEST(TableArray, basic_test1) {
  ArrayTable<int, int> arrtab;
  arrtab.Insert(1, 1);
  int a = *arrtab.Find(1);
  ASSERT_EQ(1, a);
}
TEST(TableArray, basic_test2) {
  ArrayTable<int, int> arrtab;
  arrtab.Insert(1, 2);
  int a = *arrtab.Find(1);
  ASSERT_EQ(2, a);
}
TEST(TableArray, basic_test3) {
  ArrayTable<int, int> arrtab;
  arrtab.Insert(2, 1);
  int a = *arrtab.Find(2);
  ASSERT_EQ(1, a);
}

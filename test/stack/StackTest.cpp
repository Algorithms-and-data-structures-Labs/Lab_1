#include "Stack/stack.h"
#include "gtest/gtest.h"

// ASSERT_NO_THROW(TDynamicMatrix<int> m(5));
TEST(TStack, can_get_size) {
  TStack<int> a(5);
  EXPECT_EQ(5, a.GetSize());
}
TEST(TStack, can_get_push) {
  TStack<int> a(5);
  a.Push(2);
  EXPECT_EQ(2, a.Get());
}
TEST(TStack, can_get_push2) {
  TStack<int> a(5);
  a.Push(2);
  a.Push(3);
  EXPECT_EQ(3, a.Get());
}
TEST(TStack, can_get_print) {
  TStack<int> a(5);
  ASSERT_NO_THROW(a.printstack());
}
TEST(TStack, can_get_with_negative) { ASSERT_ANY_THROW(TStack<int> a(-1)); }
TEST(TStack, can_get_full) {
  TStack<int> a(1);
  a.Push(2);
  ASSERT_ANY_THROW(a.Push(2));
}
TEST(TStack, can_get_IsEmpty) {
  TStack<int> a(1);
  ASSERT_ANY_THROW(a.Get());
}

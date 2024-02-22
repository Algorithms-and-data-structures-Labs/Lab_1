#include "Polinom/TPolinom.h"
#include "gtest/gtest.h"

TEST(Polinom, Created_polinom_is_empty) {
  TPolinom polinom;
  EXPECT_EQ(0, polinom.GetLength());
}

TEST(Polinom, Created_polinom_with_one_monom_is_not_empty) {
  vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8};
  TPolinom polinom(a);
  EXPECT_EQ(2, polinom.GetLength());
}

TEST(Polinom, Coefficients_add_up_if_degrees_are_equal) {
  vector<int> a = {1, 1, 1, 1, 5, 1, 1, 1};
  TPolinom polinom(a);
  EXPECT_EQ(6111, polinom.GetCurrentItem().checkMonom());
}

TEST(Polinom, Can_not_get_monom_from_empty_polinom) {
  TPolinom polinom;
  EXPECT_ANY_THROW(polinom.GetCurrentItem());
}

TEST(Polinom, Copied_polinom_is_equal_copiable) {
  vector<int> a = {1, 2, 3, 4, 2, 3, 4, 5, 4, 5, 6, 7, 3, 4, 5, 6};
  TPolinom pol(a);
  TPolinom pol1(pol);
  EXPECT_EQ(1, pol == pol1);
}

TEST(Polinom, Assigned_polinom_is_equal_assignable1) {
  vector<int> a = {1, 2, 3, 4, 2, 3, 4, 5, 4, 5, 6, 7, 3, 4, 5, 6};
  TPolinom pol(a);
  vector<int> b = {1, 2, 3, 4, 2, 3, 4, 5, 3, 4, 5, 6};
  TPolinom pol2(b);
  EXPECT_FALSE(pol == pol2);
}

TEST(Polinom, Assigned_polinom_is_equal_assignable2) {
  vector<int> a = {1, 2, 3, 4, 2, 3, 4, 5, 4, 5, 6, 7, 3, 4, 5, 6};
  TPolinom pol(a);
  vector<int> b = {1, 2, 3, 4, 2, 3, 4, 5, 3, 4, 5, 6};
  TPolinom pol2(b);
  pol = pol2;
  EXPECT_TRUE(pol == pol2);
}

TEST(Polinom, Correct_adding_operator) {
  vector<int> a = {1, 2, 3, 4, 2, 3, 4, 5, 4, 5, 6, 7, 3, 4, 5, 6};
  TPolinom pol(a);
  vector<int> b = {1, 2, 3, 4, 2, 3, 4, 5, 3, 4, 5, 6};
  TPolinom pol2(b);
  TPolinom pol3(a);
  pol3 = pol.AddPolinom(pol2);
  EXPECT_EQ(pol3.ToString(), "4X5Y6Z7 + 6X4Y5Z6 + 4X3Y4Z5 + 2X2Y3Z4");
}

TEST(Polinom, Correct_polinom_enter) {
  vector<int> a = {1, 2, 3, 4, 2, 3, 4, 5, 4, 5, 6, 7, 3, 4, 5, 6};
  TPolinom pol(a);
  EXPECT_EQ(pol.ToString(), "4X5Y6Z7 + 3X4Y5Z6 + 2X3Y4Z5 + 1X2Y3Z4");
}

TEST(Polinom, Adding_Monom) {
  vector<int> a = {1, 2, 3, 4, 2, 3, 4, 5, 4, 5, 6, 7, 3, 4, 5, 6};
  TPolinom pol(a);
  TMonom mon(1, 2, 3, 5);
  pol.AddMonom(mon);
  EXPECT_EQ(pol.ToString(), "4X5Y6Z7 + 3X4Y5Z6 + 2X3Y4Z5 + 1X2Y3Z5 + 1X2Y3Z4");
}

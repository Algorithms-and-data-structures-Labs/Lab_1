#include "Polinom/TPolinom.h"

#include "gtest/gtest.h"

TEST(Polinom, Created_polinom_is_empty) {
	TPolinom polinom;
	EXPECT_EQ(0, polinom.GetLength());
}

TEST(Polinom, Created_polinom_with_one_monom_is_not_empty) {
	vector<int> a = { 1,234 };
	TPolinom polinom(a);

	EXPECT_EQ(1, polinom.GetLength());
}

TEST(Polinom, Coefficients_add_up_if_degrees_are_equal) {
	vector<int> a = { 1,111,3,111 };
	TPolinom polinom(a);
	EXPECT_EQ(4111, polinom.GetCurrentItem().IMonom());
}

TEST(Polinom, Coefficients_dont_add_up_if_degrees_are_different) {
	vector<int> a = { 1,111,2,211,3,311};
	TPolinom polinom(a);
	EXPECT_EQ(3, polinom.GetLength());
}

TEST(Polinom, Copied_polinom_is_equal_copiable) {
	vector<int> a = { 1,234,2,345,4,567,3,456 };
	TPolinom pol(a);
	TPolinom pol1(pol);
	EXPECT_EQ(1, pol == pol1);
}

TEST(Polinom, Can_not_get_monom_from_empty_polinom) {
	TPolinom polinom;
	EXPECT_ANY_THROW(polinom.GetCurrentItem());
}

TEST(Polinom, Assigned_polinom_is_equal_assignable) {
	vector<int> a = { 1,234,2,345,4,567,3,456 };
	TPolinom pol(a);
	vector<int> b = { 1,234,2,345,3,456 };
	TPolinom pol2(b);
	pol = pol2;
	EXPECT_TRUE(pol == pol2);
}

TEST(Polinom, Correct_adding_operator) {
	vector<int> a = { 1,234,2,345,4,567,3,456 };
	TPolinom pol(a);
	vector<int> b = { 1,234,2,345,3,456 };
	TPolinom pol2(b);
	TPolinom pol3(a);
	pol3 = pol.AddPolinom(pol2);
	EXPECT_EQ(pol3.ToString(), "4x^5y^6z^7 + 6x^4y^5z^6 + 4x^3y^4z^5 + 2x^2y^3z^4");
}

TEST(Polinom, Correct_polinom_enter) {
	vector<int> a = { 1,234,2,345,4,567,3,456 };
	TPolinom pol(a);
	EXPECT_EQ(pol.ToString(), "4x^5y^6z^7 + 3x^4y^5z^6 + 2x^3y^4z^5 + 1x^2y^3z^4");
}

TEST(Polinom, Adding_Monom) {
	vector<int> a = { 1,234,2,345,4,567,3,456 };
	TPolinom pol(a);
	TMonom mon(1, 235);
	pol.AddMonom(mon);
	EXPECT_EQ(pol.ToString(), "4x^5y^6z^7 + 3x^4y^5z^6 + 2x^3y^4z^5 + 1x^2y^3z^5 + 1x^2y^3z^4");
}
TEST(Polinom, Mult) {
	vector<int> a = { 1,234,2,345,4,567,3,456 };
	TPolinom pol(a);
	TPolinom pol3(a);
	pol3 =  pol * 2;
	EXPECT_EQ(pol.ToString(), "8x^5y^6z^7 + 6x^4y^5z^6 + 4x^3y^4z^5 + 2x^2y^3z^4");
}

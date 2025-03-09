#include "polinom.h"
#include <gtest.h>

TEST(Polinomial, _polinomial)
{
	
}

TEST(Polinomial, can_create_polinomial)
{
	ASSERT_NO_THROW(Polinomial p);
}

TEST(Polinomial, comparison_polinomials)
{
	Polinomial p1("x^2+y");
	Polinomial p2("x^2+y");
	EXPECT_EQ(p1, p2);
}

TEST(Polinomial, addition_of_polinomials)
{
	Polinomial p1("x^2+y");
	Polinomial p2("x^2+xyz");
	Polinomial p3("2x^2+y+xyz");
	EXPECT_EQ(p3, p1+p2);
}

TEST(Polinomial, subtraction_polinomials)
{
	Polinomial p1("x^2+y");
	Polinomial p2("x^2+xyz");
	Polinomial p3("y-xyz");
	EXPECT_EQ(p3, p1 - p2);
}

TEST(Polinomial, mul_of_polinomials)
{
	Polinomial p1("x^2+y");
	Polinomial p2("x^2");
	Polinomial p3("x^4+x^2y");
	EXPECT_EQ(p3, p1 * p2);
}

TEST(Polinomial, addition_const_to_polinomials)
{
	Polinomial p1("x^2+y");
	Polinomial p3("x^2+y+2");
	EXPECT_EQ(p3, p1 + 2);
}

TEST(Polinomial, sub_const_to_polinomials)
{
	Polinomial p1("x^2+y+2");
	Polinomial p3("x^2+y");
	EXPECT_EQ(p3, p1 - 2);
}

TEST(Polinomial, multiplication_of_the_polynomial_by_a_constant)
{
	Polinomial p1("x^2+y");
	Polinomial p2("2x^2+2y");
	EXPECT_EQ(p2, p1 * 2);
}

TEST(Polinomial, polynomial_calculation)
{
	Polinomial p1("x^2+y");
	EXPECT_EQ(50, p1(7, 1, 0));
}
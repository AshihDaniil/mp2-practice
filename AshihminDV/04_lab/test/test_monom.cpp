#include "monom.h"
#include <gtest.h>

TEST(Monomial, can_create_monomial)
{
	ASSERT_NO_THROW(Monomial m);
}

TEST(Monomial, create_a_monomial_with_the_parameter_map)
{
	std::map<char, int> kon;
	kon['x'] = 1;
	kon['z'] = 2;
	kon['y'] = 3;
	Monomial m(163, kon);
	EXPECT_EQ(kon, m.getVariables());
	EXPECT_EQ(163, m.getCoefficient());
}

TEST(Monomial, seter_monomial)
{
	std::map<char, int> kon;
	kon['x'] = 1;
	kon['z'] = 2;
	kon['y'] = 3;
	Monomial m(163, kon);
	m.setCoefficient(4);
	std::map<char, int> kon2;
	kon2['x'] = 3;
	kon2['z'] = 3;
	kon2['y'] = 3;
	m.setVariables(kon2);
	EXPECT_EQ(4, m.getCoefficient());
	EXPECT_EQ(kon2, m.getVariables());
}

TEST(Monomial, monomial_comparison_operator)
{
	std::map<char, int> kon;
	kon['x'] = 1;
	kon['z'] = 2;
	kon['y'] = 3;
	Monomial m1(163, kon);
	Monomial m2(163, kon);
	EXPECT_TRUE(m1 == m2);
}

TEST(Monomial, create_a_monomial_with_the_parameter_str)
{
	std::map<char, int> kon;
	kon['x'] = 1;
	kon['z'] = 2;
	kon['y'] = 3;
	Monomial m1(163, kon);
	Monomial m2("163xy^3z^2");
	EXPECT_EQ(m1, m2);
}

TEST(Monomial, monomial_copy_constructor)
{
	Monomial m1("163xy^3z^2");
	Monomial m2(m1);
	EXPECT_EQ(m1, m2);
}

TEST(Monomial, monomial_add_operator)
{
	Monomial m1("163xy^3z^2");
	Monomial m2("163xy^3z^2");
	Monomial m3("326xy^3z^2");

	EXPECT_EQ(m3, m1 + m2);
}

TEST(Monomial, cant_add_monomials_with_diff_power)
{
	Monomial m1("163x");
	Monomial m2("163x^2");

	ASSERT_ANY_THROW(m1 + m2);
}

TEST(Monomial, monomial_mul_operator)
{
	Monomial m1("x^2y");
	Monomial m2("x^8y^3");
	Monomial m3("x^10^y^4");

	EXPECT_EQ(m3, m1 * m2);
}


TEST(Monomial, monomial_assignment_operator)
{
	Monomial m1("x^2y");
	Monomial m2;
	m2 = m1;

	EXPECT_EQ(m1, m2);
}

TEST(Monomial, monomial_calculation)
{
	Monomial m1("x^2y");

	EXPECT_EQ(300, m1(10, 3, 0));
}
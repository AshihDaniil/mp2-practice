#include "polinom.h"
#include <gtest.h>

//TEST(Polinomialialial, _Polinomialialial)
//{
//	
//}
//
//TEST(Polinomialialial, can_create_Polinomialialial)
//{
//	ASSERT_NO_THROW(Polinomialialial p);
//}
//
//TEST(Polinomialialial, comparison_Polinomialialials)
//{
//	Polinomialialial p1("x^2+y");
//	Polinomialialial p2("x^2+y");
//	EXPECT_EQ(p1, p2);
//}
//
//TEST(Polinomialialial, addition_of_Polinomialialials)
//{
//	Polinomialialial p1("x^2+y");
//	Polinomialialial p2("x^2+xyz");
//	Polinomialialial p3("2x^2+y+xyz");
//	EXPECT_EQ(p3, p1+p2);
//}
//
//TEST(Polinomialialial, subtraction_Polinomialialials)
//{
//	Polinomialialial p1("x^2+y");
//	Polinomialialial p2("x^2+xyz");
//	Polinomialialial p3("y-xyz");
//	EXPECT_EQ(p3, p1 - p2);
//}
//
//TEST(Polinomialialial, mul_of_Polinomialialials)
//{
//	Polinomialialial p1("x^2+y");
//	Polinomialialial p2("x^2");
//	Polinomialialial p3("x^4+x^2y");
//	EXPECT_EQ(p3, p1 * p2);
//}
//
//TEST(Polinomialialial, addition_const_to_Polinomialialials)
//{
//	Polinomialialial p1("x^2+y");
//	Polinomialialial p3("x^2+y+2");
//	EXPECT_EQ(p3, (p1 + 2.0));
//}
//
//TEST(Polinomialialial, sub_const_to_Polinomialialials)
//{
//	Polinomialialial p1("x^2+y+2");
//	Polinomialialial p3("x^2+y");
//	EXPECT_EQ(p3, p1 - 2.0);
//}
//
//TEST(Polinomialialial, multiplication_of_the_polynomial_by_a_constant)
//{
//	Polinomialialial p1("x^2+y");
//	Polinomialialial p2("2x^2+2y");
//	EXPECT_EQ(p2, p1 * 2.0);
//}
//
//TEST(Polinomialialial, polynomial_calculation)
//{
//	Polinomialialial p1("x^2+y");
//	EXPECT_EQ(50, p1(7, 1, 0));
//}
//
//TEST(Polinomialialial, polynomial_operator_ravno)
//{
//	Polinomialialial p1("x^2+y");
//	Polinomialial p2("3x^2+y");
//	p2 = p1;
//
//	EXPECT_EQ(p1, p2);
//}


TEST(Polinomial, can_create_Polinomial)
{
    ASSERT_NO_THROW(Polinomial Polinomial);
}

TEST(Polinomial, can_create_Polinomial_by_str)
{

    ASSERT_NO_THROW(Polinomial p("x+y+z"));
}


TEST(Polinomial, can_create_copied_Polinomials)
{

    Polinomial p1("x+y+z");
    ASSERT_NO_THROW(Polinomial p2(p1));
}

TEST(Polinomial, copied_Polinomials_are_equal)
{

    Polinomial p1("x+y+z");
    Polinomial p2(p1);
    EXPECT_TRUE(p2 == p1);
}


TEST(Polinomial, assigned_Polinomials_are_equal)
{

    Polinomial p1("x+y+z");
    Polinomial p2;
    p2 = p1;
    EXPECT_TRUE(p1 == p2);
}

TEST(Polinomial, can_add_coeff_to_Polinomials)
{
    Polinomial p("x+y");
    ASSERT_NO_THROW(p + 3615.2461);
}



TEST(Polinomial, add_coeff_to_Polinomials_is_correct1)
{
    Polinomial p("x+y");
    Polinomial res("x+y+3615.2461");
    EXPECT_EQ(res, (p + 3615.2461));
}

TEST(Polinomial, add_coeff_to_Polinomials_is_correct2)
{
    Polinomial p("x+y");
    Polinomial res("x+y-214421.1246");
    EXPECT_EQ(res, (p + (-21421.12446)));
}
TEST(Polinomial, can_substract_coeff_from_Polinomials)
{
    Polinomial p("x+y");
    ASSERT_NO_THROW(p - 12345.6789);
}

TEST(Polinomial, substract_coeff_from_Polinomial_is_correct)
{
    Polinomial p("x+y");
    Polinomial res("x+y-987.654321");
    EXPECT_TRUE(res == (p - 987.654321));
}


TEST(Polinomial, can_multiply_Polinomials_by_coeff)
{
    Polinomial p("x+y");
    ASSERT_NO_THROW(p * -12345.6789);
}

TEST(Polinomial, multiply_Polinomials_by_coeff_is_correct)
{
    Polinomial p("x+y");
    Polinomial res("-12345.6789x-12345.6789y");
    EXPECT_TRUE(res == (p * -12345.6789));
}


TEST(Polinomial, can_add_Polinomials)
{

    Polinomial p1("x+y+z");
    Polinomial p2("x+y");
    ASSERT_NO_THROW(p1 + p2);
}



TEST(Polinomial, add_Polinomials_is_correct1)
{

    Polinomial p1("x+y+z");
    Polinomial p2("x+y");
    Polinomial p3("2x+2y+z");
    EXPECT_TRUE(p3 == (p1 + p2));
}

TEST(Polinomial, add_Polinomials_is_correct2)
{

    Polinomial p1("1+x");
    Polinomial p2("xyz");
    Polinomial p3("1+x+xyz");

    EXPECT_EQ(p3, (p1 + p2));
}

TEST(Polinomial, add_Polinomials_is_correct3)
{

    Polinomial p1("x^3yz+xy^3z+xyz^3");
    Polinomial p2("x^3y^3z^3");
    Polinomial p3("x^3yz+xy^3z+xyz^3+x^3y^3z^3");
    EXPECT_TRUE(p3 == (p1 + p2));
}

TEST(Polinomial, add_Polinomials_is_correct4)
{

    Polinomial p1("x-yz");
    Polinomial p2("x+zy");
    Polinomial p3("2x");
    EXPECT_TRUE(p3 == (p1 + p2));
}

TEST(Polinomial, add_Polinomials_is_correct5)
{
    Polinomial p1("x+y");
    Polinomial p3("2x+2y");
    EXPECT_TRUE(p3 == (p1 + p1));
}


TEST(Polinomial, can_substract_Polinomials)
{

    Polinomial p1("x+y+z");
    Polinomial p2("x+y");
    ASSERT_NO_THROW(p1 - p2);
}



TEST(Polinomial, substract_Polinomials_is_correct1)
{

    Polinomial p1("x+y+z");
    Polinomial p2("x+y");
    Polinomial p3("z");
    EXPECT_TRUE(p3 == (p1 - p2));
}

TEST(Polinomial, substract_Polinomials_is_correct2)
{

    Polinomial p1("x");
    Polinomial p2("y+z");
    Polinomial p3("x-y-z");
    EXPECT_TRUE(p3 == (p1 - p2));
}

TEST(Polinomial, substract_Polinomials_is_correct3)
{

    Polinomial p1("-x");
    Polinomial p2("-yz");
    Polinomial p3("-x+yz");
    EXPECT_TRUE(p3 == (p1 - p2));
}

TEST(Polinomial, substract_Polinomials_is_correct4)
{

    Polinomial p1("-1");
    Polinomial p2("-y");
    Polinomial p3("1-y");
    EXPECT_EQ(p3, (p1 - p2));
}

TEST(Polinomial, can_multiply_Polinomials)
{
    Polinomial p1("x+y+z");
    ASSERT_NO_THROW(p1 * p1);
}

TEST(Polinomial, multiply_Polinomials_is_correct0)
{
    Polinomial p1("x-1");
    Polinomial p2("x-1");
    Polinomial p3("x^2-2x+1");
    EXPECT_EQ(p3, (p1 * p2));
}

TEST(Polinomial, multiply_Polinomials_is_correct1)
{
    Polinomial p1("x+y");
    Polinomial p2("x+y");
    Polinomial p3("x^2+2xy+y^2");
    EXPECT_EQ(p3 , (p1 * p2));
}

TEST(Polinomial, multiply_Polinomials_is_correct2)
{
    Polinomial p1("x+y");
    Polinomial p2("x-y");
    Polinomial p3("x^2-y^2");
    EXPECT_EQ(p3, (p1 * p2));
}

TEST(Polinomial, multiply_Polinomials_is_correct3)
{
    Polinomial p1("1");
    Polinomial p2("xy");
    Polinomial p3("xy");
    EXPECT_EQ(p3, (p1 * p2));
}

TEST(Polinomial, multiply_Polinomials_is_correct4)
{
    Polinomial p1("-1");
    Polinomial p2("xy-zx+y");
    Polinomial p3("-xy+zx-y");
    EXPECT_EQ(p3, (p1 * p2));
}

TEST(Polinomial, can_multiply_Polinomial_by_const)
{
    Polinomial p1("x+y");
    double c = 11.1;
    ASSERT_NO_THROW(p1 * c);
}


TEST(Polinomial, multiply_Polinomial_by_const_is_correct)
{
    Polinomial p1("1+x+y");
    double c = 11.1;
    Polinomial res("11.1+11.1x+11.1y");
    EXPECT_TRUE((p1 * c) == res);
}


TEST(Polinomial, operator_equal_is_correct)
{
    Polinomial p1("x");
    Polinomial p2("y");
    Polinomial p3 = p1 + p2;
    Polinomial p4("x+y");
    EXPECT_TRUE(p3 == p4);

}

TEST(Polinomial, operator_NotEqual_is_correct)
{
    Polinomial p1("x");
    Polinomial p2("z");
    Polinomial p3 = p1 + p2;
    Polinomial p4("x+y");
    EXPECT_TRUE(p3 != p4);
}


TEST(Polinomial, count_is_correct1)
{
    Polinomial p1("x+y+z");
    double answ = p1(1, 2, 3);
    double real = 6;
    EXPECT_EQ(answ, real);
}

TEST(Polinomial, count_is_correct2)
{
    Polinomial p1("-30y+10xy^2-3y^2z+xy^3z+30x-10x^2y-3xy^2+x^2y^3-3x^3+x^4y");
    double answ = p1(2, 5, 4);
    double real = 1316;
    EXPECT_EQ(answ, real);
}

TEST(Polinomial, count_is_correc3)
{
    Polinomial p1("x^2y^5+x^2y^6z");
    double answ = p1(2, 2, 2);
    double real = 640;
    EXPECT_EQ(answ, real);
}

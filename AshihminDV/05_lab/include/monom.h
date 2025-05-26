#pragma once

#include <map>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;


class Monomial
{
private:
	double coefficent;
	int degree;
public:
	Monomial() : coefficent(1.0){}
	explicit Monomial(double coef) : coefficent(coef), degree(000) {}

	Monomial(const std::string& str);
	Monomial(double coef, const int degree) : coefficent(coef), degree(degree) {}

	Monomial(const Monomial& m2);

	//metods

	double getCoefficient() const { return coefficent; }
	void setCoefficient(double coeff) { coefficent = coeff; }

	int getDegree() const { return degree; }
	void setDegree(const int degree2) { degree = degree2; }

	bool operator==(const Monomial& monom2) const { 
		return degree == monom2.degree;}

	bool operator!=(const Monomial& monom2) const { 
		return !(*this == monom2); }

	bool operator>(const Monomial& monom2) const {
		return degree>monom2.degree;
	}
	bool operator<(const Monomial& monom2) const {
		return degree < monom2.degree;
	}


	Monomial operator*(const Monomial& monom2) const;
	Monomial& operator*=(const Monomial& monom2);
	Monomial operator+(const Monomial& monom2) const;
	Monomial& operator+=(const Monomial& other);
	const Monomial& operator=(const Monomial& monom2);

	bool isEq(const Monomial& monom2) const {
		return coefficent == monom2.coefficent && degree == monom2.degree;
	}

	Monomial operator*(double num) const;

	double operator()(double x, double y, double z) const;

	friend ostream& operator<<(ostream& ostr, const Monomial& m)
	{
		if (m.coefficent == 0.0) return ostr << "0";

		if (m.degree == 000)
		{
			if (m.coefficent > 0) ostr << '+';
			ostr << m.coefficent;
		}
		else {
			if (m.coefficent > 0) ostr << '+';
			if (m.coefficent != 1.0 && m.coefficent != -1.0)
			{
				ostr << m.coefficent;
			}
			if (m.coefficent == -1.0)
			{
				ostr << '-';
			}

			if (m.degree / 100 != 0)
			{
				if (m.degree / 100 > 1)
				{
					std::cout << "x^" << m.degree / 100;
				}
				else
				{
					std::cout << "x";
				}
			}
			if ((m.degree / 10) % 10 != 0)
			{
				if (m.degree / 10 % 10 > 1)
				{
					std::cout << "y^" << m.degree / 10 % 10;
				}
				else
				{
					std::cout << "y";
				}
			}
			if (m.degree % 10 != 0)
			{
				if (m.degree % 10 > 1)
				{
					std::cout << "z^" << m.degree % 10;
				}
				else
				{
					std::cout << "z";
				}
			}
		}
		return ostr;
	}
};
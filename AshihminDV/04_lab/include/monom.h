#pragma once

#include <map>
#include <string>
#include <iostream>

using namespace std;


class Monomial
{
private:
	double coefficent;
	std::map<char, int> variables;
public:
	Monomial() : coefficent(1.0){}
	Monomial(double coef) : coefficent(coef) {}
	Monomial(double coef, const std::map<char, int>& vars) : coefficent(coef), variables(vars) {}
	Monomial(const std::string& str);
	Monomial(const Monomial& m2);

	double getCoefficient() const { return coefficent; }
	void setCoefficient(double coeff) { coefficent = coeff; }

	std::map<char, int> getVariables() const { return variables; }
	void setVariables(std::map<char, int> v2) { variables=v2; }

	bool operator==(const Monomial& monom2) const { 
		return variables == monom2.variables;}
	bool operator!=(const Monomial& monom2) const { 
		return !(*this == monom2); }

	Monomial operator*(const Monomial& monom2) const;
	Monomial& operator*=(const Monomial& monom2);
	Monomial operator+(const Monomial& monom2) const;
	Monomial& operator+=(const Monomial& other);
	const Monomial& operator=(const Monomial& monom2);

	bool isEq(const Monomial& monom2) const {
		return coefficent ==monom2.coefficent && variables == monom2.variables;
	}

	Monomial operator*(double num) const;

	double operator()(double x, double y, double z) const;

	friend ostream& operator<<(ostream& ostr, const Monomial& m)
	{
		if (m.coefficent == 0.0) return ostr << "0";

		if (m.variables.empty())
		{
			if (m.coefficent > 0) ostr << '+';
			ostr << m.coefficent;
		}
		else{
			if (m.coefficent > 0) ostr << '+';
			if (m.coefficent != 1.0 && m.coefficent != -1.0)
			{
				ostr << m.coefficent;
			}
			if (m.coefficent == -1.0)
			{
				ostr << '-';
			}

			for (const auto& p : m.variables) {
				char var = p.first;
				int exp = p.second;
				ostr << var;
				if (exp != 1) ostr << "^" << exp;
			}
		}
		return ostr;
	}
};
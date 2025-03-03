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

	double getCoefficient() const { return coefficent; }
	void setCoefficient(double coeff) { coefficent = coeff; }

	const std::map<char, int>& getVariables() const { return variables; }

	bool operator==(const Monomial& monom2) const
	{
		return coefficent == monom2.coefficent && variables == monom2.variables;
	}
	bool operator!=(const Monomial& monom2) const
	{
		return !(*this == monom2);
	}

	Monomial operator*(const Monomial& monom2) const
	{
		Monomial result;
		result.coefficent = this->coefficent * monom2.coefficent;
		result.variables = this->variables;
		//for (const auto& [var, exp] :monom2.variables) {
		for (const auto& p : monom2.variables) {
			char var = p.first;
			char exp = p.second;
			result.variables[var] += exp;
			if (result.variables[var] == 0) {
				result.variables.erase(var);
			}
		}
		return result;
	}

	Monomial operator+(const Monomial& monom2) const
	{
		Monomial result;
		if(monom2.variables == this->variables)
		{
			result.coefficent = this->coefficent + monom2.coefficent;
		}
		else
		{
			throw "Power!";
		}

		return result;
	}

	bool isSimilar(const Monomial& other) const {
		return variables == other.variables;
	}

	Monomial& operator+=(const Monomial& other) {
		if (!isSimilar(other)) {
			throw "POWER";
		}
		coefficent += other.coefficent;
		return *this;
	}

	Monomial operator*(double num) const {
		Monomial result;
		result.variables = this->variables;
		result.coefficent *= num;
		return result;
	}

	double operator()(double x, double y, double z) const {
		double result = this->coefficent;
		for (const auto& p : this->variables) {
			char var = p.first;
			char exp = p.second;
			double value = 0;
			switch (var) {
			case 'x': value = x; break;
			case 'y': value = y; break;
			case 'z': value = z; break;
			default: break;
			}
			result *= pow(value, exp);
		}
		return result;
	}

	friend ostream& operator<<(ostream& ostr, const Monomial& m)
	{
		if (m.coefficent == 0.0) return ostr << "0";

		for (const auto& p : m.variables) {
			if (m.coefficent < 0) ostr << '-';
			else ostr << '+';
			if (m.coefficent != 1.0)
			{
				ostr << m.coefficent;
			}
			char var = p.first;
			int exp = p.second;
			ostr << var;
			if (exp != 1) ostr << "^" << exp;
		}
		return ostr;
	}
};
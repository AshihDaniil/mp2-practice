#include "monom.h"

Monomial::Monomial(const std::string& str)
{
	int pos = 0;
	double coef = 1.0;
	bool is_negative = false;

	if (str[pos] == '+' || str[pos] == '-')
	{
		is_negative = (str[pos] == '-');
		pos++;
	}

	if (pos >= str.size() || (!isdigit(str[pos]) && str[pos] != '.'))
	{
		coefficent = is_negative ? -1.0 : 1.0;
	}
	else {
		std::string coef_str;
		while (pos < str.size() && (isdigit(str[pos]) || str[pos] == '.'))
		{
			coef_str += str[pos];
			pos++;
		}
		try
		{
			coefficent = std::stod(coef_str);
		}
		catch (...)
		{
			throw "Invalid coef format";
		}
		coefficent *= is_negative ? -1.0 : 1.0;
	}
	while (pos < str.size()) {
		if (isalpha(str[pos])) {
			char var = str[pos];
			int exponent = 1;
			pos++;

			if (pos < str.size() && str[pos] == '^') {
				pos++;
				if (pos >= str.size() || !isdigit(str[pos])) {
					throw "Invalid exponent after ^";
				}
				exponent = 0;
				while (pos < str.size() && isdigit(str[pos])) {
					exponent = exponent * 10 + (str[pos] - '0');
					pos++;
				}
			}

			variables[var] = exponent;
		}
		else {
			pos++;
		}
	}
}

Monomial Monomial::operator*(const Monomial& monom2) const
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

Monomial Monomial::operator+(const Monomial& monom2) const
{
	Monomial result;
	if (monom2.variables == this->variables)
	{
		result.coefficent = this->coefficent + monom2.coefficent;
		result.variables = this->variables;
	}
	else
	{
		throw "Power!";
	}

	return result;
}

Monomial& Monomial::operator+=(const Monomial& other) {
	if (!isSimilar(other)) {
		throw "POWER";
	}
	coefficent += other.coefficent;
	return *this;
}

Monomial Monomial::operator*(double num) const {
	Monomial result;
	result.variables = this->variables;
	result.coefficent = this->coefficent;
	result.coefficent *= num;
	return result;
}

double Monomial::operator()(double x, double y, double z) const {
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
#include "monom.h"

Monomial::Monomial(const Monomial& m2)
{
	coefficent = m2.coefficent;
	degree = m2.degree;
}

Monomial::Monomial(const std::string& str)
{
	coefficent = 1.0;
	degree = 0;
	size_t pos = 0;
	bool is_negative = false;

	if (pos < str.size() && (str[pos] == '+' || str[pos] == '-')) {
		is_negative = (str[pos] == '-');
		pos++;
	}

	bool has_coefficient = false;
	std::string coef_str;
	while (pos < str.size() && (isdigit(str[pos]) || str[pos] == '.')) {
		coef_str += str[pos];
		pos++;
		has_coefficient = true;
	}

	if (has_coefficient) {
		try {
			coefficent = std::stod(coef_str);
		}
		catch (...) {
			throw std::invalid_argument("Invalid coefficient format");
		}
	}
	else if (pos < str.size() && (str[pos] == 'x' || str[pos] == 'y' || str[pos] == 'z')) {
		coefficent = 1.0;
	}

	coefficent *= is_negative ? -1.0 : 1.0;

	while (pos < str.size()) {
		if (str[pos] == 'x' || str[pos] == 'y' || str[pos] == 'z') {
			char var = str[pos];
			pos++;
			int exp = 1;

			if (pos < str.size() && str[pos] == '^') {
				pos++;
				exp = 0;
				while (pos < str.size() && isdigit(str[pos])) {
					exp = exp * 10 + (str[pos] - '0');
					pos++;
				}
			}
			switch (var) {
			case 'x': degree += exp * 100; break;
			case 'y': degree += exp * 10;  break;
			case 'z': degree += exp;        break;
			}
		}
		else {
			pos++;
		}
	}

	if ((degree / 100) > 9 || ((degree / 10) % 10) > 9 || (degree % 10) > 9) {
		throw std::invalid_argument("Degree components must be 0-9");
	}
}

Monomial Monomial::operator*(const Monomial& monom2) const
{
	Monomial result;
	int x_deg = (degree / 100) + (monom2.degree / 100);
	int y_deg = ((degree / 10) % 10) + ((monom2.degree / 10) % 10);
	int z_deg = (degree % 10) + (monom2.degree % 10);

	if (x_deg > 9 || y_deg > 9 || z_deg > 9) {
		throw std::invalid_argument("Degree overflow");
	}

	return Monomial(
		coefficent * monom2.coefficent,
		x_deg * 100 + y_deg * 10 + z_deg
	);
}

Monomial Monomial::operator+(const Monomial& monom2) const
{
	Monomial result;
	if (this->degree == monom2.degree)
	{
		result.coefficent = this->coefficent + monom2.coefficent;
		result.degree = this->degree;
	}
	else
	{
		throw "Power!";
	}

	return result;
}

const Monomial& Monomial::operator=(const Monomial& monom2)
{
	if (this != &monom2)
	{
		coefficent = monom2.coefficent;

		degree = monom2.degree;
	}
	return *this;
}


Monomial& Monomial::operator*=(const Monomial& monom2)
{
	coefficent *= monom2.coefficent;
	
	degree += monom2.degree;
	
	return *this;
}

Monomial& Monomial::operator+=(const Monomial& other) {
	if (!(other==*this)) {
		throw "POWER";
	}
	coefficent += other.coefficent;
	return *this;
}

Monomial Monomial::operator*(double num) const {
	Monomial result;
	
	result.degree = this->degree;

	result.coefficent = this->coefficent;
	result.coefficent *= num;
	return result;
}

double Monomial::operator()(double x, double y, double z) const {
	double result = this->coefficent;
	result = result * pow(x, this->degree / 100) * pow(y, this->degree / 10 % 10) * pow(z, this->degree % 10);
	
	return result;
}
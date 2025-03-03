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
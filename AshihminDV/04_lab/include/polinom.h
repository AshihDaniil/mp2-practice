#pragma once

#include "monom.h"
#include "list.h"

using namespace std;

class Polinomial
{
private:
	TList<Monomial> monoms;
	void bringing();

public: 
	Polinomial();
	Polinomial(const std::string& str);


	void printt()
	{
		monoms.set_curr();
		while (monoms.get_curr() != nullptr)
		{
			if (monoms.get_curr()->next == nullptr)
			{
				break;
			}
			std::cout << monoms.get_curr()->val;
			monoms.Next();
		}
		std::cout << monoms.get_curr()->val;
	}
};
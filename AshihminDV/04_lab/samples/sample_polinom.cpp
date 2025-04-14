#include "Other.h"


int main()
{

	//mainMenu();

	//std::string s("x^2y+2");

	//Polinomial p1(s);

	//std::cout << p1 << std::endl;

	//Monomial m1("5xy");
	//std::cout << m1 << std::endl;

	std::string s1("x+y+z");

	Polinomial p1(s1);
	std::cout << p1 << std::endl;

	std::string s2("x-y");

	Polinomial p2(s2);
	std::cout << p2 << std::endl;

	Polinomial p3;
	p3 = p1 * p2;

	std::cout << p3;
	////std::cout << p1 - p2 << std::endl;

	//double d(10);
	//std::cout << p1 + d << std::endl;





	return 0;
}
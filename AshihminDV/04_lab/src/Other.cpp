#include "Other.h"

void mainMenu()
{
	char a('y');
	Polinomial p1;
	while (a != 'n')
	{
		if (p1.isEmpty())
		{
			std::cout << "Input Polinomial " << std::endl;
			std::cin >> p1;
		}

		std::cout << "---Polinomial menu---" << std::endl <<
			"1. Input Polinomial" << std::endl <<
			"2. Operations on polynomials" << std::endl <<
			"3. Operations on polynomial and constant" << std::endl <<
			"4. Calculate the value of the polynomial" << std::endl <<
			"5. Exit" << std::endl << std::endl <<
			"Current polynomial = " << p1 << std::endl << std::endl <<
			"Select the mode: ";

		int choice1;

		cin >> choice1;
		cin.ignore();

		switch (choice1) {
		case 1: {
			std::cout << "1. Input Polinomial " << std::endl;
			std::cin >> p1;
			break;
		}
		case 2: {
			int choice2 = 1;

			while (choice2 != 4)
			{
				std::cout << "---Operations on polynomials menu---" << std::endl <<
					"1. Polynomial addition" << std::endl <<
					"2. Subtraction of polynomials" << std::endl <<
					"3. Multiplication of polynomials" << std::endl <<
					"4. Exit" << std::endl << "Select the mode: ";
				std::cin >> choice2;
				std::cin.ignore();
				switch (choice2)
				{
				case 1:
				{
					std::cout << "Enter the second polynomial: ";
					Polinomial p2;
					std::cin >> p2;
					std::cout << "Result: " << p1 + p2 << std::endl;
					break;
				}
				case 2:
				{
					std::cout << "Enter the second polynomial: ";
					Polinomial p2;
					std::cin >> p2;
					std::cout << "Result: " << p1 - p2 << std::endl;
					break;
				}
				case 3:
				{
					std::cout << "Enter the second polynomial: ";
					Polinomial p2;
					std::cin >> p2;
					std::cout << "Result: " << p1 * p2 << std::endl;
					break;
				}
				case 4:
				{
					break;
				}
				default:
					break;
				}

			}
			break;

		}
		case 3: {
			int choice2 = 1;

			while (choice2 != 4)
			{
				std::cout << "---Operations on polynomial and constant menu---" << std::endl <<
					"1. Polynomial and constant addition" << std::endl <<
					"2. Subtraction of polynomial and constant" << std::endl <<
					"3. Multiplication of polynomial and constant" << std::endl <<
					"4. Exit" << std::endl << "Select the mode: ";
				std::cin >> choice2;
				std::cin.ignore();
				switch (choice2)
				{
				case 1:
				{
					std::cout << "Enter a constant: ";
					double p2;
					std::cin >> p2;
					std::cout << "Result: " << p1 + p2 << std::endl;
					break;
				}
				case 2:
				{
					std::cout << "Enter a constant: ";
					double p2;
					std::cin >> p2;
					std::cout << "Result: " << p1 - p2 << std::endl;
					break;
				}
				case 3:
				{
					std::cout << "Enter a constant: ";
					double p2;
					std::cin >> p2;
					std::cout << "Result: " << p1 * p2 << std::endl;
					break;
				}
				case 4:
				{
					break;
				}
				default:
					break;
				}

			}
			break;
		}
		case 4: {
			double x, y, z;
			std::cout << "---Calculating the value of the polynomial---" << std::endl <<
				"Current polynomial = " << p1 << std::endl <<
				"Enter the value of x, y, z" << std::endl;
			std::cin >> x >> y >> z;
			std::cout << "Result: " << p1(x, y, z) << std::endl;
			break;
		}
		case 5: {
			a = 'n';
			break;
		}
		default:
		{
			break;
		}
		};
	}
}
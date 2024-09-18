#include "tvector.h"
int main()
{
	TVector v1, v2;
	double norma_v1, norma_v2;
	TVector v3;
	double res;

	int mode;
	double cons;


	std::cout << "Choose mode:" << std::endl;
	std::cout << "1 - + vectors" << std::endl << "2 - - vectors" << std::endl << "3 - * vectors" << std::endl << "4 - len of vector"
		<< std::endl << "5 - vector + const" << std::endl << "6 - vector - const " << std::endl << "7 - vector * const " << std::endl;
	std::cin >> mode;

	switch (mode)
	{	
	case 1:
		std::cin >> v1;
		std::cin >> v2;
		try
		{
			v3 = v1 + v2;
			std::cout << "SUMMA v-ov = " << v3 << std::endl;
		}
		catch (const std::exception& error_message)
		{
			std::cout << "vectors of different lengths" << std::endl;
		}
		break;
	case 2:
		std::cin >> v1;
		std::cin >> v2;
		try
		{
			v3 = v1 - v2;
			std::cout << "Razn v-ov = " << v3 << std::endl;
		}
		catch (const std::exception&)
		{
			std::cout << "vectors of different lengths" << std::endl;
		}
		break;

	case 3:
		std::cin >> v1;
		std::cin >> v2;
		try
		{
			res = v1 * v2;
			std::cout << "Skal proizv v-ov = " << res << std::endl << std::endl;
		}
		catch (const std::exception&)
		{
			std::cout << "vectors of different lengths" << std::endl;
		}
		break;
	case 4:
		std::cin >> v1;
		try
		{
		norma_v1 = v1.Norma_Vectora();
		}
		catch (const std::exception&)
		{
			std::cout << "vector does not exist" << std::endl;
		}
		break;
	case 5:
		std::cin >> v1;
		std::cout << "Vvedite constanty = ";
		std::cin >> cons;
		try
		{
			v3 = v1 + cons;
			std::cout << "vector + const = " << v3;
		}
		catch (const std::exception& error_message)
		{
			std::cout << "Different len of vector" << std::endl;
		}
		break;
	case 6:
		std::cin >> v1;
		std::cout << "Vvedite constanty = ";
		std::cin >> cons;
		try
		{
			v3 = v1 - cons;
			std::cout << "vector - const = " << v3;
		}
		catch (const std::exception& error_message)
		{
			std::cout << "Different len of vector" << std::endl;
		}
		break;
	case 7:
		std::cin >> v1;
		std::cout << "Vvedite constanty = ";
		std::cin >> cons;
		try
		{
			v3 = v1 * cons;
			std::cout << "vector * const = " << v3;
		}
		catch (const std::exception& error_message)
		{
			std::cout << "Different len of vector" << std::endl;
		}
		catch (int x)
		{
			std::cout << "ERROR: Const == 0" << std::endl;
		}
		break;

	default:
		break;
	}
	return 0;
}
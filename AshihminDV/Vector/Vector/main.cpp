#include "tvector.h"
void main()
{
	TVector v1, v2;
	double norma_v1, norma_v2;

	std::cin >> v1;
	std::cin >> v2;
	std::cout << v1 << v2;
	norma_v1 = v1.Norma_Vectora();
	norma_v2 = v2.Norma_Vectora();
	std::cout << "Norma v1 = " << norma_v1 << std::endl << "Norma v2 = " << norma_v2 << std::endl;

	TVector v3;
	double res;
	v3 = v1 + v2;
	std::cout << "SUMMA v-ov = " << v3 << std::endl;
	v3 = v1 - v2;
	std::cout << "RAZN v-ov = " << v3 << std::endl;
	res = v1 * v2;
	std::cout << "Skal proizv v-ov = " << res << std::endl << std::endl;
	double cons;
	std::cout << "Vvedite constanty = ";
	std::cin >> cons;
	std::cout << "const +/-/* v1 =" << std::endl << v1 + cons << std::endl << v1 - cons << std::endl
		<< v1 * cons << std::endl;

}
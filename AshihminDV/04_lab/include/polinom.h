#pragma once

#include "monom.h"
#include "headlist.h"

using namespace std;

class Polinomial
{
private:
	HeadList<Monomial> monoms; // must be storted(((
public:
	Polinomial() = default;
	Polinomial(const std::string& str);
	Polinomial(const Polinomial& p2);

	Polinomial operator+(const Polinomial& polinom2);
	Polinomial operator-(const Polinomial& polinom2);
	Polinomial operator*(const Polinomial& polinom2);

	Polinomial operator+(const Monomial& monom);
	Polinomial operator-(const Monomial& monom);
	Polinomial operator*(const Monomial& monom);
	
	Polinomial operator+(const double& x) const;
	Polinomial operator-(const double& x) const;
	Polinomial operator*(const double& x) const;

	Polinomial& operator+=(const double& x);
	Polinomial& operator-=(const double& x);
	Polinomial& operator*=(const double& x);

	const Polinomial& operator=(const Polinomial& polinom2);

	bool operator==(const Polinomial& polinom2) const
	{
		return this->monoms == polinom2.monoms;
	}

	bool operator!=(const Polinomial& polinom2) const
	{
		return !(*this == polinom2);
	}

	double operator()(const double x, const double y, const double z);

	friend std::ostream& operator<<(std::ostream& os, const Polinomial& p) {
		if (p.monoms.size() == 0) {
			return os << "0";
		}

		//const ListNode<Monomial>* current = p.monoms.get_head();

		/*while (current != nullptr) {
			const Monomial& m = current->val;
			os << m;
			current = current->next;
		}*/

		Polinomial copy(p);

		while (!copy.monoms.is_end())
		{
			const Monomial& m = copy.monoms.get_curr()->val;
			os << m;
			copy.monoms.Next();
		}

		return os;
	}

	friend std::istream& operator>>(std::istream& is, Polinomial& p)
	{
		std::string str;
		std::getline(is, str);

		Polinomial p1(str);

		p = p1;
		//обработка ошибки!!

		return is;
	}
};
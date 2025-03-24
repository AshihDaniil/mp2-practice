#pragma once

#include "monom.h"
#include "list.h"

using namespace std;

class Polinomial
{
private:
	TList<Monomial> monoms; // TODO: список с головой или цикл. список с головой
	void bringing();

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

	double operator()(const double x, const double y, const double z) const;

	bool isEmpty() // TODO: удалить
	{
		return (monoms.get_head() == nullptr) ? true :false;
	}

	friend std::ostream& operator<<(std::ostream& os, const Polinomial& p) {
		if (p.monoms.size() == 0) {
			return os << "0";
		}

		ListNode<Monomial>* current = p.monoms.get_head();



		while (current != nullptr) {
			const Monomial& m = current->val;

			os << m;

			current = current->next;
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
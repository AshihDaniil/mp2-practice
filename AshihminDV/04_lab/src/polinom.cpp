#include "polinom.h"

Polinomial::Polinomial(const std::string& str)
{
	int pos = 0;

	while (pos < str.length())
	{
		string member;
		if(str[pos]=='-' || str[pos] == '+') member += str[pos++];
		while (str[pos] != '+' && str[pos]!='-' && pos <str.length())
		{
			member += str[pos++];
		}
		if (!member.empty())
		{
			Monomial m1(member); //конструктор из строки переделать
			if (monoms.search(m1))
			{
				monoms.get_curr()->val += m1;

			}
			else {
				insert_elem(m1);
			}
		}
	}
	//pCurr = pFirst | pPrev = pStop
}

Polinomial::Polinomial(const Polinomial& p2) : monoms(p2.monoms) {};

void Polinomial::insert_elem(const Monomial& monom)
{
	if (monom.getCoefficient() == 0) return;

	monoms.reset();
	ListNode<Monomial>* newNode = new ListNode<Monomial>(monom);

	while (!monoms.is_end()) {
		Monomial& curr = monoms.get_curr()->val;

		if (curr.getDegree() == monom.getDegree()) {
			curr += monom;
			if (curr.getCoefficient() == 0) {
				monoms.remove(curr);

			}
			delete newNode;
			return;
		}

		if (monom.getDegree() > curr.getDegree()) {
			monoms.insert_Before(newNode, curr);

			return;
		}

		monoms.Next();
	}

	monoms.insert_Back(newNode);

	monoms.reset();

	std::cout <<  "Monoms ";
	while (!monoms.is_end()) {
		std::cout << monoms.get_curr()->val;
		monoms.Next();
	}
	std::cout << std::endl;
}

Polinomial Polinomial::operator+(const Monomial& monom)
{
	Polinomial result(*this);
	if (result.monoms.search(monom))
	{
		result.monoms.get_curr()->val += monom;
		if (result.monoms.get_curr()->val.getCoefficient() == 0)
		{
			result.monoms.remove(result.monoms.get_curr()->val);
		}
	}
	else
	{
		ListNode<Monomial>* temp = new ListNode<Monomial>(monom);
		result.monoms.insert_Back(temp);
	}
	return result;
}

Polinomial Polinomial::operator-(const Monomial& monom)
{
	return *this + (monom * -1.0);
}

Polinomial Polinomial::operator*(const Monomial& monom)
{
	Polinomial result;
	monoms.reset();

	while (!monoms.is_end()) {
		Monomial product = monoms.get_curr()->val * monom;
		std::cout << "product p*m " << product << std::endl;
		result.insert_elem(product);
		monoms.Next();
	}

	return result;
}

Polinomial Polinomial::operator+(const Polinomial& polinom2)
{
	Polinomial result(*this);
	Polinomial p2(polinom2);

	p2.monoms.reset();
	while (!p2.monoms.is_end()) {
		Monomial m1 = p2.monoms.get_curr()->val;

		result.insert_elem(m1);
		std::cout << result << std::endl;
		p2.monoms.Next();
	}

	return result;
}

Polinomial Polinomial::operator-(const Polinomial& polinom2)
{
	Polinomial result(*this);
	result = result + (polinom2 * (-1.0));
    return result;
}

Polinomial Polinomial::operator*(const Polinomial& polinom2)
{
    Polinomial result;
    Polinomial p2_copy = polinom2;

    p2_copy.monoms.reset();
    while (!p2_copy.monoms.is_end()) {
        const Monomial& current = p2_copy.monoms.get_curr()->val;
        Polinomial temp = *this * current;
		std::cout << "temp " << temp << std::endl;
        result = result + temp;
		std::cout << "result " << result << std::endl;
        p2_copy.monoms.Next();
    }

    return result;
}

Polinomial Polinomial::operator+(const double& x) const
{
    Polinomial result = *this;
    result += x;
    return result;
}

Polinomial& Polinomial::operator+=(const double& x)
{
    Monomial constant(x);
	*this = *this + constant;
    return *this;
}


Polinomial Polinomial::operator-(const double& x) const
{
    Polinomial result = *this;
    result -= x;
    return result;
}

Polinomial& Polinomial::operator-=(const double& x)
{
    *this += (-x);
    return *this;
}

Polinomial Polinomial::operator*(const double& x) const
{
	Polinomial result(*this);
    result *= x;
    return result;
}

Polinomial& Polinomial::operator*=(const double& x)
{
	monoms.reset();
    while (!monoms.is_end())
    {
		monoms.get_curr()->val = monoms.get_curr()->val * x;
        monoms.Next();
    }
	
    return *this;
}

const Polinomial& Polinomial::operator=(const Polinomial& polinom2)
{

    if (this != &polinom2) {
		monoms.reset();
        while (!monoms.is_end()) {
			monoms.remove_First();
        }
		TList<Monomial> res_list(polinom2.monoms);
        while (!res_list.is_end())
        {
            monoms.insert_Back(new ListNode<Monomial>(res_list.get_curr()->val));
            res_list.Next();
        }

    }
    return *this;
}

double Polinomial::operator()(const double x, const double y, const double z) //const
{
    double result = 0.0;

    monoms.reset();
    while (!this->monoms.is_end())
    {
        Monomial curr = monoms.get_curr()->val;
        result += curr(x, y, z);
        monoms.Next();

    }

    return result;
}
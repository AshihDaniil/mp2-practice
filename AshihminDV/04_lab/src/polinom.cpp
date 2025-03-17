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
			ListNode<Monomial>* temp = new ListNode<Monomial>(member);
			monoms.insert_Back(temp);
		}
	}
	bringing();
}

Polinomial::Polinomial(const Polinomial& p2)
{
    ListNode<Monomial>* current = p2.monoms.get_head();
    while (current != nullptr)
    {
        ListNode<Monomial>* newNode = new ListNode<Monomial>(current->val);
        monoms.insert_Back(newNode);
        current = current->next;
    }
}

void Polinomial::bringing()
{
    ListNode<Monomial>* current = monoms.get_head();
    ListNode<Monomial>* prev = nullptr;

    while (current != nullptr) {
        ListNode<Monomial>* runnerPrev = current;
        ListNode<Monomial>* runner = current->next;

        while (runner != nullptr) {
            if (current->val.isSimilar(runner->val)) {
                current->val += runner->val;
                runnerPrev->next = runner->next;
                if (runner == monoms.get_end()) {
                    monoms.insert_Back(runnerPrev);
                }
                delete runner;
                runner = runnerPrev->next;
            }
            else {
                runnerPrev = runner;
                runner = runner->next;
            }
        }

        if (current->val.getCoefficient() == 0) {
            if (prev == nullptr) {
                monoms.Remove_First();
                current = monoms.get_head();
            }
            else {
                prev->next = current->next;
                if (current == monoms.get_end()) {
                    monoms.insert_Back(prev);
                }
                delete current;
                current = prev->next;
            }
        }
        else {
            prev = current;
            current = current->next;
        }
    }
}

Polinomial Polinomial::operator+(const Polinomial& polinom2) const
{
    Polinomial result;

    /*ListNode<Monomial>* current = this->monoms.get_head();
    while (current != nullptr) {
        result.monoms.insert_Back(new ListNode<Monomial>(current->val));
        current = current->next;
    }

    current = polinom2.monoms.get_head();
    while (current != nullptr) {
        result.monoms.insert_Back(new ListNode<Monomial>(current->val));
        current = current->next;
    }*/

    TList<Monomial> res_list = this->monoms;
    res_list.set_curr();
    bool flag = 1;
    while (flag)
    {
        result.monoms.insert_Back(new ListNode<Monomial>(res_list.get_curr()->val));
        flag = res_list.Next();
    }
    flag = 1;
    res_list = polinom2.monoms;
    res_list.set_curr();
    while (flag)
    {
        result.monoms.insert_Back(new ListNode<Monomial>(res_list.get_curr()->val));
        flag = res_list.Next();
    }

    result.bringing();
    return result;
}

Polinomial Polinomial::operator-(const Polinomial& polinom2) const
{
    Polinomial result;

    ListNode<Monomial>* current = this->monoms.get_head();
    while (current != nullptr) {
        result.monoms.insert_Back(new ListNode<Monomial>(current->val));
        current = current->next;
    }

    current = polinom2.monoms.get_head();
    while (current != nullptr) {
        Monomial inverted = current->val * (-1.0);
        result.monoms.insert_Back(new ListNode<Monomial>(inverted));
        current = current->next;
    }

    result.bringing();
    return result;
}

Polinomial Polinomial::operator*(const Polinomial& polinom2) const
{
    Polinomial result;

    ListNode<Monomial>* currentThis = monoms.get_head();
    while (currentThis != nullptr) {
        ListNode<Monomial>* currentOther = polinom2.monoms.get_head();
        while (currentOther != nullptr) {

            Monomial product = currentThis->val * currentOther->val;

            if (product.getCoefficient() != 0.0) {
                result.monoms.insert_Back(new ListNode<Monomial>(product));
            }
            currentOther = currentOther->next;
        }
        currentThis = currentThis->next;
    }
    result.bringing();

    return result;
}

Polinomial Polinomial::operator+(const double& x) const
{
    Polinomial result = *this;
    result += x;
    return result;
}
Polinomial Polinomial::operator+=(const double& x)
{
    Monomial constant(x);
    monoms.insert_Back(new ListNode<Monomial>(constant));
    this->bringing();
    return *this;
}
Polinomial Polinomial::operator-(const double& x) const
{
    Polinomial result = *this;
    result -= x;
    return result;
}
Polinomial Polinomial::operator-=(const double& x)
{
    *this += (-x);
    return *this;
}
Polinomial Polinomial::operator*(const double& x) const
{
    Polinomial result = *this;
    result *= x;
    return result;
}
Polinomial Polinomial::operator*=(const double& x)
{
    ListNode<Monomial>* current = monoms.get_head();
    while (current != nullptr) {
        current->val = current->val * x; // Умножаем каждый моном
        current = current->next;
    }
    this->bringing();
    return *this;
}


Polinomial& Polinomial::operator=(const Polinomial& polinom2)
{
    if (this != &polinom2) {
        while (monoms.get_head() != nullptr) {
            monoms.Remove_First();
        }

        ListNode<Monomial>* current = polinom2.monoms.get_head();
        while (current != nullptr) {
            monoms.insert_Back(new ListNode<Monomial>(current->val));
            current = current->next;
        }
    }
    return *this;
}

double Polinomial::operator()(const double x, const double y, const double z)
{
    double result = 0.0;

    ListNode<Monomial>* curr = monoms.get_head();
    while (curr != nullptr)
    {
        result += curr->val(x, y, z);
        curr = curr->next;
    }

    return result;
}
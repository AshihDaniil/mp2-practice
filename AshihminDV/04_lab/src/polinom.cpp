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
			Monomial m1(member);
			if (monoms.search(m1))
			{
				/*m1 += monoms.get_curr()->val;
				monoms.remove(monoms.get_curr()->val);
				ListNode<Monomial>* temp = new ListNode<Monomial>(m1);
				monoms.insert_Back(temp);*/
				monoms.get_curr()->val += m1;

			}
			else {
				ListNode<Monomial>* temp = new ListNode<Monomial>(m1);
				monoms.insert_Back(temp);
			}
		}
	}
	//pCurr = pFirst | pPrev = pStop
}

Polinomial::Polinomial(const Polinomial& p2) : monoms(p2.monoms) {};

Polinomial Polinomial::operator+(const Monomial& monom)
{
	Polinomial result(*this);
	if (result.monoms.search(monom))
	{
		result.monoms.get_curr()->val += monom;
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
//	Polinomial result(*this);
//	result = result - monom * (-1.0);
//	return result;
	return *this + (monom * -1.0);
}

Polinomial Polinomial::operator*(const Monomial& monom)
{
	Polinomial result(*this);
	while (!result.monoms.is_end())
	{
		result.monoms.get_curr()->val*=monom;
		result.monoms.Next();
	}
	return result;
}

//Polinomial Polinomial::operator+(Polinomial& polinom2)
//{
//    Polinomial result;
//
//    monoms.set_curr();
//    while (!monoms.is_end()) {
//        result.monoms.insert_Back(new ListNode<Monomial>(monoms.getCurr()));
//        monoms.Next();
//    }
//
//    polinom2.monoms.set_curr();
//    while (!polinom2.monoms.is_end()) {
//        result.monoms.insert_Back(new ListNode<Monomial>(polinom2.monoms.getCurr()));
//        polinom2.monoms.Next();
//    }
//    //result.bringing();
//    return result;
//}
//
//Polinomial Polinomial::operator-(Polinomial& polinom2)
//{
//    Polinomial result;
//
//    monoms.set_curr();
//    while (!monoms.is_end()) {
//        result.monoms.insert_Back(new ListNode<Monomial>(monoms.getCurr()));
//        monoms.Next();
//    }
//
//    polinom2.monoms.set_curr();
//    while (!polinom2.monoms.is_end()) {
//        Monomial inverted = polinom2.monoms.getCurr() * (-1.0);
//        result.monoms.insert_Back(new ListNode<Monomial>(inverted));
//        polinom2.monoms.Next();
//    }
//
//    result.bringing();
//    return result;
//}
//
//Polinomial Polinomial::operator*(const Polinomial& polinom2) const
//{
//    Polinomial result;
//
//    TList<Monomial> list1 = this->monoms;
//    list1.set_curr();
//    TList<Monomial> list2 = polinom2.monoms;
//    
//    while (!list1.is_end())
//    {
//        list2.set_curr();
//        Monomial m1 = list1.getCurr();
//
//        while (!list2.is_end())
//        {
//            Monomial product = m1 * list2.getCurr();
//            if (product.getCoefficient() != 0.0) {
//                result.monoms.insert_Back(new ListNode<Monomial>(product));
//            }
//            list2.Next();
//        }
//        list1.Next();
//    }
//    result.bringing();
//
//    return result;
//}
//
//Polinomial Polinomial::operator+(const double& x) const
//{
//    Polinomial result = *this;
//    result += x;
//    return result;
//}
//
//Polinomial Polinomial::operator+=(const double& x)
//{
//    Monomial constant(x);
//    monoms.insert_Back(new ListNode<Monomial>(constant));
//    this->bringing();
//    return *this;
//}
//
//Polinomial Polinomial::operator-(const double& x) const
//{
//    Polinomial result = *this;
//    result -= x;
//    return result;
//}
//
//Polinomial Polinomial::operator-=(const double& x)
//{
//    *this += (-x);
//    return *this;
//}
//
//Polinomial Polinomial::operator*(const double& x) const
//{
//    Polinomial result = *this;
//    result *= x;
//    return result;
//}
//
//Polinomial Polinomial::operator*=(const double& x)
//{
//    monoms.set_curr();
//    while (!monoms.is_end())
//    {
//        monoms.set_curr_value(monoms.getCurr()*x);
//        monoms.Next();
//    }
//
//    this->bringing();
//
//    return *this;
//}
//
//
//Polinomial& Polinomial::operator=(const Polinomial& polinom2)
//{
//    if (this != &polinom2) {
//        while (monoms.get_head() != nullptr) {
//            monoms.Remove_First();
//        }
//
//        TList<Monomial> res_list = polinom2.monoms;
//        res_list.set_curr();
//        while (!res_list.is_end())
//        {
//            monoms.insert_Back(new ListNode<Monomial>(res_list.getCurr()));
//            res_list.Next();
//        }
//        //while(polinom2.monoms.is_end()){}
//
//    }
//    return *this;
//}
//
//double Polinomial::operator()(const double x, const double y, const double z)
//{
//    double result = 0.0;
//
//    monoms.set_curr();
//    while (!this->monoms.is_end())
//    {
//        Monomial curr = monoms.getCurr();
//        result += curr(x, y, z);
//        monoms.Next();
//
//    }
//
//    return result;
//}

//void Polinomial::bringing()
//{
//    ListNode<Monomial>* current = monoms.get_head();
//    ListNode<Monomial>* prev = nullptr;
//
//    while (current != nullptr) {
//        ListNode<Monomial>* runnerPrev = current;
//        ListNode<Monomial>* runner = current->next;
//
//        while (runner != nullptr) {
//            if (current->val.isSimilar(runner->val)) {
//                current->val += runner->val;
//                runnerPrev->next = runner->next;
//                if (runner == monoms.get_end()) {
//                    monoms.insert_Back(runnerPrev);
//                }
//                delete runner;
//                runner = runnerPrev->next;
//            }
//            else {
//                runnerPrev = runner;
//                runner = runner->next;
//            }
//        }
//
//        if (current->val.getCoefficient() == 0) {
//            if (prev == nullptr) {
//                monoms.Remove_First();
//                current = monoms.get_head();
//            }
//            else {
//                prev->next = current->next;
//                if (current == monoms.get_end()) {
//                    monoms.insert_Back(prev);
//                }
//                delete current;
//                current = prev->next;
//            }
//        }
//        else {
//            prev = current;
//            current = current->next;
//        }
//    }
//}
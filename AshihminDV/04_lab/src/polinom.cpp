#include "polinom.h"

Polinomial::Polinomial(const std::string& str)
{
	string ss(str);

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
		std::cout << pos << std::endl;
		this->printt();
		std::cout << endl;
	}
	bringing();
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
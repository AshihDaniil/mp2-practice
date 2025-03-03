#include <iostream>

#include <iomanip>
#include "list_stack.h"
#include "string"
#include <map>
#include <vector>
using namespace std;


class TArithmeticExpression
{
	std::string infix;
	std::string postfix;
	std::vector<std::string> postfixx;
	std::map<char, int> priority;
	std::map<std::string, double> operands;
	void ToPostfix();
	void allocation_operand(int& i, char item);
	void input_value();
	void input_value(map<std::string, double>);
public:

	TArithmeticExpression(const std::string& infx);

	std::string GetInfix() const
	{
		return infix;
	}

	std::string GetPostfix() const
	{
		return postfix;
	}

	vector<string> GetPostfixVector() const
	{
		return postfixx;
	}

	friend ostream& operator<<(ostream& ostr, const TArithmeticExpression& AE)
	{
		std::cout << "infix form = " << AE.infix << std::endl;
		std::cout << std::endl << "postfix form = ";
		for (int i = 0; i < AE.postfixx.size(); i++)
		{
			std::cout << AE.postfixx[i] << " ";
		}
		std::cout << std::endl;
		return ostr;
	}


	double Calculate();
	//double Calculate(const map<std::string, double>&);
};
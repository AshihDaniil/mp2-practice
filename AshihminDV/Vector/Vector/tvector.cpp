#include "tvector.h"

TVector::TVector()
{
	this->n = 0;
	this->x = nullptr;
}

TVector::TVector(int n) {
	this->n = n;
	this->x = new double[this->n];
	for (int i = 0; i < this->n; i++)
	{
		this->x[i] = 0.0;
	}
}

TVector::TVector(int n, double* x)
{
	this->n = n; 
	this->x = new double[n];
	for (int i = 0; i < n; i++)
	{
		this->x[i] = x[i];
	}
}

TVector::TVector(const TVector& a)
{
	this->n = a.n;
	this->x = new double[this->n];
	for (int i = 0; i < this->n; i++)
	{
		this->x[i] = a[i];
	}
}

TVector::~TVector()
{
	delete[] x;
}

TVector TVector::operator+(const TVector& a)
{
	if (this->n != a.n)
	{
		throw std::exception("different len");
	}
	TVector res(this->n);
	for (int i = 0; i < this->n; i++)
	{
		res[i] = this->x[i] + a[i];
	}
	return res;
}

TVector TVector::operator-(const TVector& a)
{
	if (this->n != a.n)
	{
		throw std::exception("different len");
	}
	TVector res(this->n);
	for (int i = 0; i < this->n; i++)
	{
		res[i] = this->x[i] - a[i];
	}
	return res;
}

double TVector::operator*(const TVector& a)
{
	if (this->n != a.n)
	{
		throw std::exception("different len");
	}
	double res = 0.0;
	for (int i = 0; i < this->n; i++)
	{
		res += this->x[i] * a[i];
	}
	return res;
}

TVector TVector::operator+(const double a)
{
	if (this->n <= 0)
	{
		throw std::exception("different len");
	}
	TVector res(this->n);
	for (int i = 0; i < this->n; i++)
	{
		res[i] = this->x[i] + a;
	}
	return res;
}

TVector TVector::operator-(const double a)
{
	if (this->n <= 0)
	{
		throw std::exception("different len");
	}
	TVector res(this->n);
	for (int i = 0; i < this->n; i++)
	{
		res[i] = this->x[i] - a;
	}
	return res;
}

TVector TVector::operator*(const double a)
{
	if (this->n <= 0)
	{
		throw std::exception("different len");
	}
	if (a == 0)
	{
		throw std::exception("a=0");
	}
	TVector res(this->n);
	for (int i = 0; i < this->n; i++)
	{
		res[i] = this->x[i] * a;
	}
	return res;
}

const TVector& TVector::operator=(const TVector& a)
{
	this->n = a.n;
	this->x = new double[this->n];
	for (int i = 0; i < this->n; i++)
	{
		this->x[i] = a.n;
	}
	return *this;
}

std::istream& operator>>(std::istream& in, TVector& v)
{
	std::cout << "Input n: ";
	in >> v.n;
	std::cout << "Input x: ";
	if (v.x != nullptr) {
		delete[] v.x;
	}
	v.x = new double[v.n];
	for (int i = 0; i < v.n; i++)
	{
		in >> v[i];
	}
	return in;
}

std::ostream& operator<<(std::ostream& out,const TVector& v)
{
	std::cout << "Vector :";

	for (int i = 0; i < v.n; i++)
	{
		out << v[i] << " ";
	}
	std::cout << std::endl;
	return out;
}

double TVector::operator[](const int idx) const
{
	if(idx>=0 || idx < this->n)
	{
		return this->x[idx];
	}
	throw std::exception("idx out of range");
}

double& TVector::operator[](const int idx)
{
	if (idx >= 0 || idx < this->n)
	{
		return this->x[idx];
	}
	throw std::exception("idx out of range");
}

double TVector::Norma_Vectora()
{
	if (this->n <= 0)
	{
		throw std::exception("0 len of tvector");
	}
	double norma = 0.0;
	for (int i = 0; i < this->n; i++)
	{
		norma += this->x[i] * this->x[i];
	}
	return sqrt(norma);
}
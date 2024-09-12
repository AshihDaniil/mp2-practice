#pragma once
#include "iostream"

class TVector
{
private:
	int n;
	double* x;
public:
	TVector();
	TVector(int n);
	TVector(int n, double* x);
	TVector(const TVector&);
	~TVector();

	double operator[](const int) const;
	double& operator[](const int);

	TVector operator+ (const TVector&);
	TVector operator- (const TVector&);
	double operator* (const TVector&);

	TVector operator+ (const double);
	TVector operator- (const double);
	TVector operator* (const double);

	const TVector& operator = (const TVector&);
	friend std::istream& operator>>(std::istream&, TVector&);
	friend std::ostream& operator<<(std::ostream&, const TVector&);

	double Norma_Vectora();


};

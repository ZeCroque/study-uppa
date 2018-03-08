#include <iostream>
#include <cstdlib>
#include "integrationformula.h"
using namespace std;

IntegrationFormula::IntegrationFormula()
{
	_a=0;
	_b=0;
	_n=0;
}

IntegrationFormula::IntegrationFormula(double a, double b, int n)
{
	_a=a;
	_b=b;
	_n=n;
}

double IntegrationFormula::getA() const
{
	return _a;
}

double IntegrationFormula::getB() const
{
	return _b;
}

int IntegrationFormula::getN() const
{
	return _n;
}

void IntegrationFormula::setABN(double a, double b, int n)
{
	_a=a;
	_b=b;
	_n=n;
}

double IntegrationFormula::computePointsMilieu(double (*f) (double)) const
{
	double h=(_b-_a)/_n;
	double x0=_a;
	double x1;
	double v=0.0;

	for(int i=0; i<_n; i++)
	{
		x1=x0+h;
		v+=f((x0+x1)/2.0);
		x0=x1;
	}
	v*=h;
	return v;
}

double IntegrationFormula::computeTrapeze(double (*f) (double)) const
{
	double h=(_b-_a)/_n;
	double x0=_a;
	double x1;
	double v=0.0;

	for(int i=0; i<_n; i++)
	{
		x1=x0+h;
		v+=f(x0)+f(x1);
		x0=x1;
	}
	v*=(h/2);
	return v;
}

double IntegrationFormula::computeSimpson(double (*f) (double)) const
{
	double h=(_b-_a)/_n;
	double x0=_a;
	double x1;
	double v=0.0;
	for(int i=0; i<_n; i++)
	{
		x1=x0+h;
		v+=(1.0/6.0)*f(x0)+(1.0/6.0)*f(x1)+(2.0/3.0)*f((x0+x1)/2.0);
		x0=x1;
	}
	v*=h;
	return v;
}

void IntegrationFormula::computeErrors(double (*f) (double), double exact_value) const
{
	double pointmilieu = (*this).computePointsMilieu(f);
	double trapeze = (*this).computeTrapeze(f);
	double simpson = (*this).computeSimpson(f);
	cout<<"Delta Points Milieu : "<<exact_value-pointmilieu<<endl<<"Delta Trapeze : "<<exact_value-trapeze<<endl<<"Delta Simpson : "<<exact_value-simpson<<endl;
}

ostream & operator << (ostream& os, const IntegrationFormula& P)
{
	os<<P.getA()<<'\n'<<P.getB()<<'\n'<<P.getN()<<'\n';
}

istream & operator >> (istream& is, IntegrationFormula& P)
{
	double A,B;
	int N;

	is>>A>>B>>N;
	P.setABN(A,B,N);
}

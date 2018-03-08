#ifndef __IntegrationFormula_h
#define __IntegrationFormula_h

#include <iostream>
#include <cstdlib>
using namespace std;

class IntegrationFormula
{
	private:
		double _a;
		double _b;
		int _n;

	public:
		IntegrationFormula();
		IntegrationFormula(double a, double b, int n);
		double getA() const;
		double getB() const;
		int getN() const;
		void setABN(double a, double b, int n);
		double computePointsMilieu(double (*f) (double)) const;
		double computeTrapeze(double (*f) (double)) const;
		double computeSimpson(double (*f) (double)) const;
		void computeErrors(double (*f) (double), double exact_value) const;


};
ostream & operator << (ostream& os, const IntegrationFormula& P);
istream & operator >> (istream& is, const IntegrationFormula& P);
#endif

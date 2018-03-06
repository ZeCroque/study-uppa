#include <iostream>
#include <cstdlib>
#include <cmath>
#include "function.h"

double f0(double x)
{
	return 0;
}

function::function()
{
	this->f=f0;
}

function::function(double (*f)(double))
{
	this->f=f;
}

double function::secante(double a, double b, const double epsilon)
{
	do
	{
		a-=(this->f(a)*(b-a))/(this->f(b)-this->f(a));
	} while (fabs(this->f(a))>epsilon);

	return a;
}

double function::dichotomie(double a, double b, const double epsilon)
{
	double m = 0.0;

	do
	{ 
		m = (a+b)/2.0;

		if (this->f(m)*this->f(a)<0.0)
			b=m;
		else if (this->f(m)*this->f(b)<0.0)
			a=m;		
	} while (fabs(this->f(m))>epsilon);

	return m;
}

double function::calculate(double x)
{
	return this->f(x);
}

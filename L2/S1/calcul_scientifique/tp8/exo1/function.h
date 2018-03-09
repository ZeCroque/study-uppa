#ifndef __funtion_h
#define __function_h

#include <iostream>
#include <cstdlib>

class function
{
	private:
		double (*f)(double);

	public:
		function();
		function(double (*f)(double));
		double secante(double a, double b, const double epsilon);
		double dichotomie(double a, double b, const double epsilon);
		double calculate(double x);
};

#endif

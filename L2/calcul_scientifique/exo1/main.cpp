#include <iostream>
#include <cstdlib>
#include <cmath>
#include "function.h"

double f1(double x)
{
	return x*x*x+2*x-2;
}

double f2(double x)
{
	return (1.0/2.0*x*x-sin(x));
}

int  main()
{
	function func1(f1);
	function func2(f2);


	std::cout<<"F1 par dichotomie : "<<func1.dichotomie(0.0,1.0,0.00000001)<<std::endl<<"F2 par sécante : "<<func2.secante(1.5,2.0,0.00000001)<<std::endl;

	return 0;
}

#include <iostream>
#include <math.h>
#include "integrationformula.h"

int main()
{
	IntegrationFormula form(0.0,M_PI,20);
	cout<<"Points Milieu : "<<form.computePointsMilieu(sin)<<endl<<"Trapeze : "<<form.computeTrapeze(sin)<<endl<<"Simpson : "<<form.computeSimpson(sin)<<endl;
	form.computeErrors(sin,2);
	form.setABN(0.0,M_PI,40);
	form.computeErrors(sin,2);

	return 0;
}

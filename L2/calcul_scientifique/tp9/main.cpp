#include "Polynom.h"

using namespace L2Info;

int main()
{
	double* coeff1=new double[2];
	coeff1[0]=1;
	coeff1[1]=-1;
	Polynom p1(1, coeff1);

	double* coeff2=new double[3];
	coeff2[0]=2;
	coeff2[1]=2;
	coeff2[2]=2;
	Polynom p2(2, coeff2);
	
	cout<<"p1 : "<<p1<<endl<<"p2 : "<<p2<<endl;

	p1*=p2;
	cout<<"p1*=p2 : "<<p1<<endl;
	
	p1+=p2;
	cout<<"p1+=p2 : "<<p1<<endl;

	p1*=2;
	cout<<"p1*=2 : "<<p1<<endl;
	
	double* coeff3=new double[4];
	coeff3[0]=1;
	coeff3[1]=3;
	coeff3[2]=4;
	coeff3[3]=2;

	Polynom p3(3, coeff3);
	cout<<"p3 : "<<p3<<endl<<"p3(2) avec la méthode de Hörner : "<<p3(2)<<endl;
		
	return 0;
}

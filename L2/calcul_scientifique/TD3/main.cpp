#include "matrix.h"
/*---------------------------------------------------------*/
int main()
{	
	std::vector<double> b;
	std::vector<double> x;
	b.reserve(5);
	b.resize(5);
	x.reserve(5);
	x.resize(5);

	Matrix M;
	M.reDim(5,5);
	M(0,0)=3;
	M(0,1)=-1;
	M(0,2)=0;
	M(0,3)=0;
	M(0,4)=0;
	M(1,0)=-1;
	M(1,1)=3;
	M(1,2)=-1;
	M(1,3)=0;
	M(1,4)=0;
	M(2,0)=0;
	M(2,1)=-1;
	M(2,2)=3;
	M(2,3)=-1;
	M(2,4)=0;
	M(3,0)=0;
	M(3,1)=0;
	M(3,2)=-1;
	M(3,3)=3;
	M(3,4)=-1;
	M(4,0)=0;
	M(4,1)=0;
	M(4,2)=0;
	M(4,3)=-1;
	M(4,4)=3;

	x[0]=0;
	x[1]=0;
	x[2]=0;
	x[3]=0;
	x[4]=0;

	b[0]=2;
	b[1]=1;
	b[2]=1;
	b[3]=1;
	b[4]=2;

	M.solveJacobi(b, x, 1, 100);
	for(int i=0; i<x.size(); i++)
	{
		std::cout<<x[i]<<std::endl;
	}
	
	
	return 0;

}

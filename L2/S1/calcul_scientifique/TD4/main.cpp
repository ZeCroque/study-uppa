#include "matrix.h"
/*---------------------------------------------------------*/
//Xavier Dufillon & Gaëtan Croquefer

int main()
{	
	Matrix M;
	M.reDim(5,5);
	M(0,0)=6;
	M(0,1)=1;
	M(0,2)=1;
	M(0,3)=1;
	M(0,4)=1;
	M(1,0)=1;
	M(1,1)=7;
	M(1,2)=1;
	M(1,3)=1;
	M(1,4)=1;
	M(2,0)=1;
	M(2,1)=1;
	M(2,2)=8;
	M(2,3)=1;
	M(2,4)=1;
	M(3,0)=1;
	M(3,1)=1;
	M(3,2)=1;
	M(3,3)=9;
	M(3,4)=1;
	M(4,0)=1;
	M(4,1)=1;
	M(4,2)=1;
	M(4,3)=1;
	M(4,4)=10;

	Matrix B;

	std::vector<double> b;
	b.resize(5);
	b[0]=10;
	b[1]=11;
	b[2]=12;
	b[3]=13;
	b[4]=14;

	std::vector<double> x;

	M.solveCholesky(b,x);

	for(int i=0; i<M.getN(); i++)
		std::cout<<x[i]<<std::endl;

	/*M.factoCholesky(B);
	std::cout<<B<<std::endl;*/
	
	
	return 0;

}

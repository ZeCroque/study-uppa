#include "matrix.h"
#include <iostream>
using namespace std;
/*---------------------------------------------------------*/
void read(Matrix M)
{
		int i,j;

	for(i=0; i<M.getN(); i++)
	{
		for(j=0; j<M.getM(); j++)
			cout<<" "<<M(i,j)<<" ";
		cout<<"\n";
	}

}

int main()
{



  Matrix M;
 Matrix A;
Matrix B;

  M.reDim(3,3);

	M.zero();
	read(M);
	M.identity(3);
	read(M);
	  M(0,1)=3.5;
	M(1,0)=3.5;
	
	read(M);
	cout<<"Symétrie : "<<M.symmetrical()<<endl;

	M(0,1)=3.4;
	M(1,0)=3.5;
	
	read(M);
	cout<<"Symétrie : "<<M.symmetrical()<<endl;

	A.reDim(3,1);
	A.zero();
	A(0,0)=3;
	A(1,0)=3;
	A(2,0)=3;

	read(A);
	cout<<endl;
	B.zero();
	B.reDim(3,3);
	B(0,0)=3;
	B(0,1)=3;
	B(0,2)=3;
	B(1,0)=3;
	B(1,1)=3;
	B(1,2)=3;
	B(2,0)=3;
	B(2,1)=3;
	B(2,2)=3;
	read(B);
		cout<<endl;
	M.linearCombi(2.0, A, 2.0, B);
	read(M);
	M.zero();
	cout<<endl;
	M.productMatrix(A,B);
	read(M);

}

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


}

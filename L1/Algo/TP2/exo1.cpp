#include <iostream>
using namespace std;

int main()
{
	int j,u,v,k=0;

	for (j=0; j<5; j++)
	{
		if (j%2)
		{
			u=j;
			while(u>0)
			{
				k++;
				u/=2;
			}
		}
		else		
			for (v=-1; v<j; v++)
				k+=2;		
	}
	cout<<k<<endl;
	return 0;
}


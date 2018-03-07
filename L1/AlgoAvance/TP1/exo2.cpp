#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int i,j,k,n,m;
	bool a=false;

	do
	{
		if(!a)
			a=true;
		else
			cout<<"vtf"<<endl;

		cout<<"Entrez la valeur limite"<<endl;
		cin>>n;
	} while(n>5000);
	

	n--;

	m=n;

	int tab[n];

	for(i=0;i<n;i++)
		tab[i]=i+2;

	for(i=0;i<sqrt(n);i++)
		for(j=i+1; j<n; j++)
			if (tab[j]%tab[i]==0)
			{
				for(k=j; k<n-1; k++)
					tab[k]=tab[k+1];
			}		


	for(i=0;i<m;i++)
		cout<<tab[i]<<endl;
	


	
	return 0;
}

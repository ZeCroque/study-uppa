#include <iostream>
using namespace std;

int main()
{
	int a=0,i,j;

	do
	{
		cout<<"Entrez le max"<<endl;
		cin>>a;
	}while (a<1);
	
	int tab[a];

	for (i=1; i<a+1; i++)
	{	
		tab[i]=0;
		for (j=1; j<i+1; j++)	
			if (i%j==0)
				tab[i]+=j;
						
		for (j=0; j<i; j++)
			if (tab[j]==tab[i] && tab[j]==i+j)
				cout<<j<<" et "<<i<<" sont des nombres amis"<<endl;
	}

	return 0;
}

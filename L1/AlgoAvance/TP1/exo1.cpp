#include <iostream>
using namespace std;

void lireVecteur(int v[])
{
	int i;

	for(i=0;i<10;i++)
	{
		cout<<"Entrez la "<<i+1<<"eme valeur."<<endl;
		cin>>v[i];
	}
}

void trierVecteur(int v[])
{
	int i,j,tmp;

	for(i=1;i<10;i++)
	{
		j=i-1;
		tmp=v[i];
		
		while(v[j]>tmp && j>=0)
		{
			v[j+1]=v[j];
			j--;
		}
		v[j+1]=tmp;
	}

}

int main()
{
	int v[10];
	int i;

	lireVecteur(v);
	trierVecteur(v);

	for(i=0;i<10;i++)
		cout<<v[i]<<endl;

	return 0;
}

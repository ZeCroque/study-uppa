#include <iostream>
using namespace std;

int main()
{
	int tab[50]={0};
	char mot[]="ere";
	int i,x=0,moy=0,t=0,min=-1,max=0;

	for (i=0; i<50 && tab[i-1]!=-1; i++)
	{
		if (i==1)
			mot[1]='m';
		cout<<"Entrez la "<<i+1<<" "<<mot<<" valeur ou entrez -1 pour arrêter"<<endl;
		cin>>tab[i];
		if (tab[i]!=-1)
		{
			t++;
			moy+=tab[i];
			if (min==-1)
				min=tab[0];
			if (tab[i]<min)
				min=tab[i];
			if (tab[i]>max)
				max=tab[i];
				
		}
	} 
	moy/=t;
	cout<<"La moyenne est de "<<moy<<"\nLe min est de "<<min<<"\nLe max est de "<<max<<endl;

	do
	{
		cout<<"Entrez la valeur de x"<<endl;
		cin>>x;
	} while (x<0);

	for (i=0, t=0; tab[i]!=-1 && x>=t; i++)
		if (tab[i]<moy)		
			t++;

	if (t>=x)
		cout<<"Oui il y a plus de "<<x<<" valeurs au dessous de la moyenne"<<endl;
	else
		cout<<"Non il n'y a pas plus de "<<x<<" valeurs au dessous de la moyenne"<<endl;
	
	return 0;
}

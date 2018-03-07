#include <iostream>
using namespace std;

void inverseVecteur(char tab[], char tabR[], int n, int i)
{
	if (i!=n && tab[i]!='\n' && tab[i]!='\0')
	{
		tabR[i]=tab[i];
		tabR[n+i]=tab[n-i-1];
		inverseVecteur(tab, tabR, n, i+1);
	}

}

int main()
{
	int n;
	
	cin>>n;
	char tab[n];
	char tabR[n*2];
	for (int i=0; i<n*2+2;i++)
		tabR[i]=' ';
	cin>>tab;
	
	inverseVecteur(tab, tabR, sizeof tab, 0);
	cout<<tabR;


	return 0;	

}

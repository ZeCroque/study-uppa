#include <iostream>
using namespace std;

void Rec_Inser(int tab[], int val, int iInf, int iSup, int n)
{
	int tmp;
	if (iSup<n+2)
	{
		tmp=tab[iInf+1];
		tab[iInf+1]=val;
		val=tmp;
		Rec_Inser(tab, val, iInf+1, iSup+1, n);
	}
}


int main()
{
	int tab[11]={8,6,12,4,18,24,9,14,74,4};
	int val,iInf,iSup;



	
	Rec_Inser(tab, val, iInf, iSup, 10);
	
	for(int i=0; i<11; i++)
		cout<<tab[i]<<endl;
	
	return 0;
}

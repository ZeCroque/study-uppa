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
	int tab[11]={0,1,2,3,4,5,6,7,8,9};
	int val,iInf,iSup;

	cout<<"val?"<<endl;
	cin>>val;
	do
	{
		cout<<"iInf?"<<endl;
		cin>>iInf;
		cout<<"iSup?"<<endl;
		cin>>iSup;	
	} while (iSup-iInf!=2 || iInf>7);

	
	Rec_Inser(tab, val, iInf, iSup, 10);
	
	for(int i=0; i<11; i++)
		cout<<tab[i]<<endl;
	
	return 0;
}

#include <iostream>
using namespace std;

int main()
{
	int h,l,L=0;

	do
	{
		cout<<"Entrez la longueur"<<endl;
		cin>>l;
		cout<<"Entrez la largeur"<<endl;
		cin>>L;
		cout<<"Entrez la hauteur"<<endl;
		cin>>h;
	} while (l<0 || L<0 || h<0);

	if (((l>h && l>L && l<61) || (h>l && h>L && h<61) || (L>l && L>h && L<61)) && ((h>6 && l>9) || (h>9 && l>6) || (h>6 && L>9) || (h>9 && L>6) || (l>6 && L>9) || (L<9 && l>6)) && L+l+h<101)
		cout<<"Accepté"<<endl;
	else
		cout<<"Refusé"<<endl;
	return 0; 
}

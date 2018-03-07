#include <iostream>
using namespace std;

int main()
{
	int an=0;

	do
	{
		cout<<"Entrez l'année"<<endl;
		cin>>an;
	} while (an < 1);

	cout <<22 + (19*(an%19)+24)%30 + (2*(an%4)+4*(an%7)+6*((19*(an%19)+24)%30)+5)%7-31<<" Avril"<<endl;
}


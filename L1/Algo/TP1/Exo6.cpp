#include <iostream>
using namespace std;

int main()
{
	int nbrBoite,G,g,n,p=0;
	do
	{
	cout<<"Entrez le nombre de boîtes"<<endl;
	cin>>nbrBoite;
	} while (nbrBoite%10!=0);

	G=nbrBoite/300;
	nbrBoite-=G*300;
	g=nbrBoite/100;
	nbrBoite-=g*100;
	n=nbrBoite/50;
	nbrBoite-=n*50;
	p=nbrBoite/10;
	nbrBoite-=p*10;
	cout<<G<<" Géante(s) boite(s),"<<g<<" Grande(s) boite(s),"<<n<<" Boite(s) normale(s),"<<p<<" Petite(s) boite(s),"<<endl;												
	
	return 0;
}
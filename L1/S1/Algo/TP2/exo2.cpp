#include <iostream>
using namespace std;

int main()
{	
	int a=0, c=0, m=0, s=0,t;

	cout<<"Entrez le nombre d'Albatros"<<endl;
	cin>>a;
	cout<<"Entrez le nombre de Mouettes"<<endl;
	cin>>m;
	cout<<"Entrez le nombre de Cormorans"<<endl;
	cin>>c;
	cout<<"Entrez le nombre de Sternes"<<endl;
	cin>>s;
	t=a+m+c+s;
	cout<<a<<" Albatros, soit "<<(float)(100*a)/t<<"%\n"<<m<<" Mouettes, soit "<<(float)(100*m)/t<<"%\n"<<c<<" Cormorans, soit "<<(float)(100*c)/t<<"%\n"<<s<<" Sternes, soit "<<(float)(100*s)/t<<"%\n"<<"Pour un total de "<<t<<" oiseaux"<<endl;
}

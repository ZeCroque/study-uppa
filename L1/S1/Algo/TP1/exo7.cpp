#include <iostream>
using namespace std;

int main()
{
	int km,i=0;
	cout<<"Entrez les Km :";
	cin>>km;
	cout<<"Km	Miles"<<endl;
	for (i=1; i<km+1; i++)
		cout<<i<<"	"<<(float)i/1.610<<endl;
	return 0;
}

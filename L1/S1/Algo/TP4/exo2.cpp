#include <iostream>
using namespace std;

void tables(int n)
{
	int i;
	
	cout << "Table de " << n << endl;
	for (i=1; i<11 ; i++)
		cout << n << " x " << i <<" = "<<n*i<<endl;
}

int main()
{
	int n;

	for (n=1; n<11; n++)
		tables(n);


	return 0;
}

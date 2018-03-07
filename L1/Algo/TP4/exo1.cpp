#include <iostream>
using namespace std;

int howManyDay (int m, int a)
{
	if (m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)
		return 31; 	
	else if (m==2 && ((a%4==0 && a%100!=0) || a%400 == 0))
		return 29;
	else if (m==4 || m==6 || m==9 || m==11)
		return 30;
	else
		return 28;
	return 0;
}

int main()
{
	int j,m,a,jlim;
	
	cout << "Entrez l'année" <<endl;
	cin >> a;
	do
	{
		cout << "Entrez le mois" << endl;
		cin >> m;

	} while (m<0 || m>12);

	jlim=howManyDay (m, a);
	
	do
	{
		cout << "Entrez le jour" << endl;
		cin >> j;
	} while (j>jlim);

	if (j==jlim)
	{
		j=1;
		if (m<12)
			m++;
		else
		{
			m=1;
			a++;
		}
	}
	else
		j++;
	
	cout << j << " " << m << " " << a<<endl;

	return 0;
}


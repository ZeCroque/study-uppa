#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	srand(time(NULL));
	int nbr=rand()%10;
	int a=-1, tries=0, i=0,j;
	int mem[10]={-1};

	while (nbr!=a)
	{	
		do
		{
			cout<<"Entrez un nombre entre 0 et 9"<<endl;
			cin>>a;
			for (j=0; j<10 && mem[j]!=-1; j++)
				if (mem[j]==a)
					a=10;		
		} while (a<0 || a>9);
				
		mem[i]=a;
		i++;
		tries++;
		
		if (a<nbr)
			cout<<"Plus"<<endl;
			else if (a>nbr)
				cout<<"Moins"<<endl;
				else
					cout<<"Bien ouej, trouvé en "<<tries<<" essais!"<<endl;
	}
	return 0;
}

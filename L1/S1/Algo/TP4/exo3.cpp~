#include <iostream>
using namespace std;

int main()
{
	int i,j, size, loop=1, choice, tmp;
	
	cout << "Quelle taille fera le tableau?" << endl;
	cin >> size;
	int tab[size];
	for (i=0; i<size ; i++)
		tab[i]=0;

	while (loop)
	{
		i=0;
		do
		{
			if (i==0)
				cout << "Que voulez vous faire?\n\t1:Remplir le tableau\n\t2:Afficher le tableau\n\t3:Inverser l'ordre\n\t4:Supprimer les éléments supérieurs à...\n\t5:Quitter" << endl;
			else
				cout << "Valeur incorrecte, veuillez saisir à nouveau."<<endl;
			cin>>choice;
			i++;
			
		} while (choice<1 || choice > 5);

		switch(choice)
		{
			case 1:
				cout<<"Entrez les valeurs du tableau"<<endl;
				for(i=0;i<size;i++)
					cin>>tab[i];
			break;
			case 2:
				cout<<"Tableau:"<<endl;
				for(i=0;i<size;i++)
					cout<<tab[i]<<endl;
			break;
			case 3:
				for(i=0;i<size/2;i++)
				{
					tmp=tab[i];
					tab[i]=tab[size-i-1];
					tab[size-i-1]=tmp;
				}
			break;
			case 4:
				cout<<"Entrez la valeur seuil"<<endl;
					cin>>tmp;
				for(i=0, j=0;i<size-1;i++)
					if(tab[i]>tmp)
					{
						tab[i]=tab[i+1];
						i++;
					}
					
			break;
			default :
				loop=0;
			break;
		}
	}

	return 0;
}

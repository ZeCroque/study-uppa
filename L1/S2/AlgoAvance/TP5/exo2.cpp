#include <iostream>
#include <stdio.h>
using namespace std;

typedef struct
{
	char nom[20];
	char prenom[20];
	int numero[10];
} personne;

int main()
{
	FILE * annuaire;
	char repeat;
	personne tmp;
	int i;	
	
	annuaire=fopen("annuaire.txt", "w");


	do
	{
		
		cout<<"Entrez le nom d'une personne"<<endl;
		cin>>tmp.nom;
		cout<<"Entrez son prénom"<<endl;
		cin>>tmp.prenom;
		for(i=0; i<10; i++)
		{
			cout<<"Entrez le "<<i+1<<" chiffre de son numéro de téléphone"<<endl;
			cin>>tmp.numero[i];
		}
		cout<<"Renseigner une autre personnes? Oui:'o' Non: N'importe quoi d'autre"<<endl;
		cin>>repeat;
		fwrite(&tmp,sizeof(personne),1,annuaire);
	} while(repeat=='o');
	
	fclose(annuaire);
	annuaire=fopen("annuaire.txt", "r");

	do
	{
		fread(&tmp,sizeof(personne),1,annuaire);
		if(!feof(annuaire))
		{
			cout<<"Nom : "<<tmp.nom<<endl;
			cout<<"Prénom : "<<tmp.prenom<<endl;
			cout<<"Numéro :";		
			for(i=0; i<10; i++)
			{
				cout<<tmp.numero[i];
			}
			cout<<endl;
		}
	} while(!feof(annuaire));

	fclose(annuaire);

	return 0;
}

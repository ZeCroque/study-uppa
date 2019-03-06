#include<stdio.h>

#define N 5

void saisieTab(int tab[])
{
	int i;

	for (i=0; i<N; i++)
	{
		printf("Entrez un élément et validez avec entrée\n");
		scanf("%d", &tab[i]);
	}
}

void afficherTab(int tab[])
{
	int i;

	for (i=0; i<N; i++)
	{
		printf("%d\n", tab[i]);
	}
}

void afficherElt(int tab[])
{
	int i;

	printf("Entrez l'index de l'élément que vous souhaitez afficher\n");
	scanf("%d", &i);
	
	printf("%d\n", tab[i]);
}

void rechercherElt(int tab[])
{
	int elt=0,i=0;
	printf("Entrez l'élément recherché\n");
	scanf("%d", &elt);

	for (i=0; i<N; i++)
	{
		if (tab[i]==elt)
		printf("L'élément se trouve à l'index %d\n", i);
	}
}

void trierTab(int tab[])
{
	//flemme
}

int main()
{
	int tab [N];
	int choice=0;

	saisieTab(tab);
	do
	{
		printf("[0]Saisir un nouveau tableau\n[1]Afficher le tableau\n[2]Afficher un élément\n[3]Rechercher un élément\n[4]Trier par ordre croissant\n");
		scanf("%d", &choice);
		switch (choice)
		{
			case 0 :
				saisieTab(tab);
				break;
			case 1 :
				afficherTab(tab);
				break;
			case 2 :
				afficherElt(tab);
				break;
			case 3 :
				rechercherElt(tab);
				break;
			case 4 :
				trierTab(tab);
				break;
		}

	} while (choice>-1 && choice <5);

	
}

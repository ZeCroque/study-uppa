#include <stdio.h>

int main() 
{

	int nbe=0;
	int x=0;
	int i=0;
	printf("combien de nombres voulez vous entrer?\n");
	scanf("%d",&nbe);
	int tab[nbe];
	for (i=0; i<nbe; i++)
	{
		printf("donnez un nombre\n");
		scanf("%d",&x);
		tab[i]=x;
 	}
	i=0;
	while (tab[i]>=0 && tab[i]<=20 && i<nbe)
	{
		
		i++;
	}
	if (i==nbe)
	{
		printf("vos nombres sont bien compris entre 0 et 20, barvo!!!!!\n");
	}
	else 
	{
		printf("arretes de faire de la merde, tes nombres ne sont pas entre 0 et 20\n");
	}	
	return 0;

}
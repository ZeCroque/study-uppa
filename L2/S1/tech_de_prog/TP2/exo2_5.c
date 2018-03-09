#include<stdio.h>

#define usd 1.19978
#define cad 1.41748
#define chf 1.54901
#define jye 137.650
#define frf 6.55957
#define mxn 13.1130

int main()
{
	float somme=0.0;
	float taux=frf;
	char devise='f';

	do
	{
		printf("Saisissez la somme suivi de la devise (SANS ESPACE):\nu: US Dollar\nc: Canadian Dollar\nh: Livre Sterling\nj: Yen Japonais\nf: Franc Français\nm: Peso Mexicain\n\nPour quitter, entrez \"0q\"\n");
		scanf("%f%c%*c",&somme, &devise);
		switch(devise)
		{
			case 'u':
				taux=usd;
				break;
			case 'c':
				taux=cad;
				break;
			case 'h':
				taux=chf;
				break;
			case 'j':
				taux=jye;
				break;
			case 'm':
				taux=mxn;
				break;
			default:
				devise='f';
				taux=frf;
				break;
		}

		if (somme!=0 && devise!='q')
			printf("\n************%f euros font %f%c.************\n\n",somme,somme*taux,devise);		
	}while(somme!=0 && devise!='q');


	

	return 0;
}

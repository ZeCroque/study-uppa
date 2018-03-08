#include<stdio.h>

int main()
{
	int dividande=0;
	int diviseur=0;
	int kresult=0;
	int lmodulo=0;
	int m=0;
	int n=0;

	printf("entrez les valeurs:");
	scanf("%d%*c",&dividande);
	scanf("%d%*c",&diviseur);

	if(dividande>diviseur)
	{
		lmodulo=n=dividande;
		m=diviseur;
	}
	else
	{
		lmodulo=n=diviseur;
		m=dividande;
	}

	while(lmodulo>=m)
	{
		kresult++;
		lmodulo-=m;
	}
	printf("Resultat %d %d %d %d", dividande, diviseur, kresult, lmodulo);
}

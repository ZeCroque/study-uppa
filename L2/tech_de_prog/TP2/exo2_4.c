#include<stdio.h>

int main()
{
	int x=0;
	int y=0;
	int cpt=0;
	int resultat=0;

	printf("saisie de x :\n");
	scanf("%d%*c",&x);
	printf("saisie de y :\n");
	scanf("%d%*c",&y);

	if (y==0)
		resultat=1;
	else if (y==1)
		resultat=x;
	else
	{
		resultat=x;
		cpt=0;

		while(cpt<(y-1))
		{
			resultat*=x;
			cpt++;
		}
	}
	printf("La valeur de %d puissance %d est: %d\n", x, y, resultat);

	return 0;
}

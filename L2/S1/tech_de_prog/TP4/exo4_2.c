#include<stdio.h>
#include<stdlib.h>


int permuter(int* a,int* b)
{
	int aux;
	aux=*a;
	*a=*b;
	*b=aux;
}

int triBulle(int* tab, int n)
{

	int ordered=0;
	int i=0;

	while(!ordered)
	{
		ordered=1;
		for(i=0; i<n-1; i++)
		{
			if (tab[i]>tab[i+1])
			{
				permuter(&tab[i], &tab[i+1]);
				ordered=0;
			}
		}
	}
}


int main()
{
	int n=0,i=0;
		
	scanf("%d%*c", &n);
	int* tab;

	tab=malloc(n*sizeof(int));

	for(i=0; i<n; i++)
	{
	
		printf("Entrez la valeur %d\n", i+1);
		scanf("%d%*c", &tab[i]);
	}

	triBulle(tab, n);
	for (i=0; i<n; i++)
		printf("%d\n", tab[i]);
	free(tab);
    tab=NULL;
	return 0;
}

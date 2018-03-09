#include<stdio.h>
#define NBMAX 10

int main(void)
{

	int * tab;
	int i,j;
	int tableau[NBMAX];

	tab = (int*) malloc (NBMAX*sizeof(int));

	i = 0;
	
	while (i<NBMAX){
		tab[i] = i+1;
		i++;
	}

	for (j=0; j<NBMAX;j++)
	{
		tableau[j]=tab[j];
	}

	
	free (tab);

  return 0;
}

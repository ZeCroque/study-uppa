#include<stdio.h>
#define NBMAX 10

int main(void)
{
	int * tab;
	int i,j;
	int tableau[NBMAX];

	while (i<NBMAX){
		tab[i] = i+1;
	}

	for (j=0; j<NBMAX;j++)
	{
		tableau[j]=tab[j];
	}

  return 0;
}

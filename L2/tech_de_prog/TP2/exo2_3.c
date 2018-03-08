#include<stdio.h>

int main()
{
	int val=0;
	int div=1;
	printf("entrez une valeur\n");
	scanf("%d",&val);
	do
	{
		if (val%div==0)
			printf("%d est un diviseur de %d\n",div, val);
		div++;
	} while (div <= val);



	
	return 0;

}

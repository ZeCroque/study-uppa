#include <stdio.h>

int main()
{
	int i;
	int* pi;

	printf("Entrez une valeur\n");
	scanf("%d",&i);
	pi=&i;
	printf("%d\n%d\n",i,*pi);
	*pi=18;
	printf("%d\n",i);
	
}

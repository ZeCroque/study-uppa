#include<stdio.h>

int main()
{
	int val=0, min, max;
	
	printf("entrez une valeur\n");
	scanf("%d",&val);
	min=max=val;

	do
	{
		printf("entrez une valeur, -1 pour terminer\n");
		scanf("%d",&val);
		if (val>max)
			max=val;
		else if (val<min && val!=-1)
			min=val;
	} while(val!=-1);

	printf("Le minimum est de : %d\nLe maximum est de : %d\n", min, max);



	
	return 0;

}

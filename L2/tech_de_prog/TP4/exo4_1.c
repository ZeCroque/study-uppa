#include<stdio.h>


int premuter(int* a,int* b)
{
	int aux;
	aux=*a;
	*a=*b;
	*b=aux;
}

int main()
{
	int a;
	int b;
	printf("donnez une premiere valeur\n");
	scanf("%d",&a);
	printf("donnez une deuxieme valeur\n");
	scanf("%d",&b);
	premuter(&a,&b);
	printf("%d %d\n",a ,b);
	return 0;
}

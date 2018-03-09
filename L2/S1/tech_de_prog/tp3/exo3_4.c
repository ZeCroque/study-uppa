#include<stdio.h>

int main ()
{
	int i=5;
	int* pi=&i;
	printf("%d %d\n",i,*pi);
	*pi=7;
	printf("%d\n",i);
	return 0;
}

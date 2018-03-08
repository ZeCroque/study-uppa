#include<stdio.h>
#include<time.h>

#define N 5

int main()
{
	int tab [N];
	int i=0;

	srand(time(NULL));

	
	for (i=0; i<N; i++)
	{
		tab [i]=rand();
	}

}

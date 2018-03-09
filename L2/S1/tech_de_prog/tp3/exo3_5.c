#include<stdio.h>
#define N 10

int main ()
{
	int i;
	float T1[N]={3,-21,64,-1.6,5.6,21,3,54,-3,0};
	float T2[N];
	for (i=0; i<N; i++)
	{
		if (T1[i]>0)
			T2[i]=T1[i];
		else
			T2[i]=0;
		printf("%1.1f ",T2[i]);
	}
	
	return 0;
}

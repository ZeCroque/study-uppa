#include<stdio.h>
#include<stdlib.h>

#define N 10

int longueur_chaine1(char cTab1[])
{
	int i=0;
	while(cTab1[i]!='\0')
	{
		i++;
	}
	return (i);
}

int longueur_chaine2(char* cTab2)
{
	int i=0;
	while(cTab2[i]!='\0')
	{
		i++;
	}
	return (i);
}

int main()
{
	char cTab1[N]={'c','t','y','"',',','*','^','!','%','\0'};
	char* cTab2;
	cTab2=malloc(N*sizeof(char));
	
	cTab2[0]='E';
	cTab2[1]='$';
	cTab2[2]='+';
	cTab2[3]='g';
	cTab2[4]='g';
	cTab2[5]='o';
	cTab2[6]='^';
	cTab2[7]='{';
	cTab2[8]='p';
	cTab2[9]='\0';
	printf("%d\n%d\n",longueur_chaine1(cTab1),longueur_chaine2(cTab2));
	return 0;
}

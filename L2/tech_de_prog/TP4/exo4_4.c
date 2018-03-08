#include<stdio.h>
#include<stdlib.h>

int saisir(char** cTab)
{
	char tmp;
	int i=1;
	
	do
	{
		tmp=getchar();
		if (tmp!='\n' && tmp!='\0' && tmp!=EOF)
		{
			*cTab=realloc(*cTab, i*sizeof(char));
			if(*cTab==NULL)
			{
				printf("Erreur allocation\n");
				exit(-1);
			}
			(*cTab)[i-1]=tmp;
		}
		i++;
	} while(tmp!='\n' && tmp!='\0'&& tmp!=EOF);
	return i-2;	
}

void afficher(char* cTab, int size)
{
	int i;
	for(i=0; i<size; i++)
		printf("%c",cTab[i]);
	printf("\n");
}

void inverser(char *cTab, int size)
{
	int i=0;
	char tmp=' ';

	for (i=0; i<(size/2); i++)
	{
		tmp=cTab[i];
		cTab[i]=cTab[size-i-1];
		cTab[size-i-1]=tmp;
	}
}

void mot(char *cTab, int size)
{
	int i;
	int a=0;

	for (i=0; i<size; i++)
	{
		if(cTab[i]==' ')
			a++;
	}
	a++;
	printf("il y a %d mots dans cette chaine de caractère\n",a);
}

int main()
{
	char* cTab=NULL;
	int size=0;
	int choix;
	printf("\t*************************\n");
	printf("\t**        Menu         **\n");
	printf("\t*************************\n");
	printf("\t**  1/Saisir           **\n");
	printf("\t**  2/Afficher         **\n");
	printf("\t**  3/Inverser         **\n");
	printf("\t**  4/Compter          **\n");
	printf("\t**  5/Quitter          **\n");
	printf("\t*************************\n");

	printf("Votre choix ? : \n");
	scanf("%d" , choix);

	switch(choix)

	case 1 :
		size=saisir(&cTab);
		break;
	case 2 :
		afficher(cTab,size);
		break;
	case 3 : 	
		inverser(cTab, size);
		afficher(cTab,size);
		break;
	case 4 :	
		mot(cTab,size);
		break;
	default :
			break;
	
		free(cTab);
		cTab=NULL;
	return 0;
}

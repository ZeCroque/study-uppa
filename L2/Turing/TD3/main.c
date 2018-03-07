#include <stdio.h>
#include <stdlib.h>


int lireChaineCaractere(char** str)
{
	char cTmp;
	int i=1;

	*str=malloc(sizeof(char));
	do
	{
		cTmp=getchar();
		*str=realloc(*str, i*sizeof(char));
		if(*str==NULL)
		{
			printf("Erreur allocation\n");
			exit(-1);
		}

		if (cTmp=='\n' || cTmp==EOF)
		{
			(*str)[i-1]='\0';
		}
		else
		{
			(*str)[i-1]=cTmp;
		}
		i++;

	} while(cTmp!='\n' && cTmp!='\0' && cTmp!=EOF);

	return i-2;
}

int main()
{
    int state=0;
    char data[50];
    char* transition=NULL;
    int iSize=0;
    char* str=NULL;
    int iChoice=0;


    printf("Entrez les données :");
    scanf("%s", data);
    scanf("%*c");

    do
    {
      do
      {
        printf("Rentrez une instruction sous la forme \"ABC\" où \nA: La valeur lue\nB: La valeur écrite\nC: Le déplacement de la tête de lecture (G,D,R)\n");
        iSize=lireChaineCaractere(&str);
        printf("%c", str[2]);

      } while(iSize!=3 && (str[2]!='G' || str[2]!='D' || str[2]!='R'));
      printf("Voulez vous inscrire une autre instruction?");
      scanf("%d", &iChoice);
    } while(iChoice!=1);



  /*  while(transition[state]!=E || transition[state]!=F)
    {

    }*/


}

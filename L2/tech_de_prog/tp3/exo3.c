#include <stdio.h>

//PROFIL
#define NIVEAU_CONSTANT 0
#define EN_MONTEE 1
#define EN_DESCENTE -1

//ETAT
#define NOMINAL 0
#define ALERTE 1
#define DETRESSE 2

#define N 5

typedef struct
{
	int h;
	int m;
	int s;
} Duree;

typedef struct
{
	int code;
	float altitude; //En pieds
	float cap;		//En degrés
	int profile;
	float inclinaison; //En degrés
	Duree autonomie;
	int etat;
} Avion;


int main()
{
	Avion tab[N]={{0}};
	int i=0,j=0,choice=0;

	do
	{
		system("clear");
		printf("Avion selectionné :\n");
		for (j=0; j<N; j++)
			if (j!=i)
				printf("[%d]	", j);
			else
				printf("[%d]<--	", j);	

		printf("\n");
		for (j=0; j<N; j++)
			if (tab[j].code!=0)
				printf("[%d]	", tab[j].code);
			else
				printf("[Vide]	");

		printf("\n\n[0]Code Avion : %d\n[1]Altitude (en pieds) : %f\n[2]Cap (en degrés) : %f\n[3]Profil : %d\n[4]Inclinaison : %f\n[5]Autonomie : %dh%dm%ds\n[6]Etat : %d\n[7]Changer d'avion\n[Autres]Quitter\n\nChoisissez une entrée :\n",tab[i].code,tab[i].altitude,tab[i].cap,tab[i].profile,tab[i].inclinaison,tab[i].autonomie.h,tab[i].autonomie.m,tab[i].autonomie.s,tab[i].etat);
		
		scanf("%d%*c", &choice);

		switch(choice)
		{
			case 0 :
				printf("Entrez le Code Avion :\n");
				scanf("%d%*c", &tab[i].code);
				break;
			case 1 :
				printf("Entrez l'Altitude :\n");
				scanf("%f%*c", &tab[i].altitude);
				break;
			case 2 :
				printf("Entrez le Cap :\n");
				scanf("%f%*c", &tab[i].cap);
				break;
			case 3 :
				printf("Entrez le Profil :\n0 : NIVEAU_CONSTANT\n1 : EN_MONTEE\n2 : EN_DESCENTE\n");
				scanf("%d%*c", &tab[i].profile);
				break;
			case 4 :
				printf("Entrez l'Inclinaison :\n");
				scanf("%f%*c", &tab[i].inclinaison);
				break;
			case 5 :
				printf("Entrez les heures :\n");
				scanf("%d%*c", &tab[i].autonomie.h);
				printf("Entrez les minutes :\n");
				scanf("%d%*c", &tab[i].autonomie.m);
				printf("Entrez les secondes :\n");
				scanf("%d%*c", &tab[i].autonomie.s);
				break;
			case 6 :
				printf("Entrez l'Etat :\n0 : NOMINAL\n1 : ALERTE\n2 : DETRESSE\n");
				scanf("%d%*c", &tab[i].etat);
				break;
			case 7 :
				printf("Saisissez l'indice de l'avion à modifier :\n");
				scanf("%d%*c", &i);
				break;
		}		
	} while (choice>-1 && choice <8);
	
}

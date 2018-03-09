#include<stdio.h>
#include<time.h>

//PROFIL
#define NIVEAU_CONSTANT 0
#define EN_MONTEE 1
#define EN_DESCENTE 2

//ETAT
#define NOMINAL -1
#define ALERTE -2
#define DETRESSE -3

typedef struct
{
	int h;
	int m;
	int s;
} Duree;

typedef struct
{
	int code;
	int altitude; //en pieds
	float cap; //en degré
	int profil;
	float inclinaison; //en degré
	Duree autonomie;
	int etat;
	
} Avion;

int main()
{
	Avion a1;
	int x=0;
	while(x!=6)
	{
	printf("gestion des avions\n1.Aficher/Modifier\n2.Créer\n6.Quitter\n");
	scanf("%d",&x);
		if (x==1)
		{
			printf("[0]Code Avion : %d\n[1]Altitude : %d\n[2]Cap (en degrés) : %f\n[3]Profil : %d\n[4]Inclinaison : %f\n[5]Autonomie : %dh%dm%ds\n[6]Etat : %d\n", a1.code, a1.altitude, a1.cap, a1.profil, a1.inclinaison, a1.autonomie.h, a1.autonomie.m, a1.autonomie.s, a1.etat);
		}
		else if (x==2)
		{
			printf("entrer\ncode avion\naltitude\nle cap\nprofil\ninclinaison\nautonomie(h/m/s)\netat\n");
			scanf("%d%d%f%d%f%d%d%d%d",&a1.code,&a1.altitude,&a1.cap,&a1.profil,&a1.inclinaison,&a1.autonomie.h,&a1.autonomie.m,&a1.autonomie.s,&a1.etat);
		}
	}
}

#include "outils.h"
#include "time.h"
#include "alerte.h"
#include "unite.h"
#include <string.h>

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

void erreurSaisie()
{
	printf("\n!!ERREUR!!\nSAISIE INVALIDE, APPUYEZ SUR ENTREE POUR RECOMMENCER");
	scanf("%*c");
}

void validerSaisie()
{
	printf("APPUYEZ SUR ENTREE POUR CONTINUER");
	scanf("%*c");
}

double creerCodeUnique()
{
	time_t temps;
	temps=time(NULL);
	return (double) temps;
}

void modeDemo(alerte** altTab, int* iAltTabSize, unite** uniTab, int* iUniTabSize)
{
	if (*iAltTabSize==0 && *iUniTabSize==0)
	{
		*altTab=realloc(*altTab,2*sizeof(alerte));
		*iAltTabSize=2;

		(*altTab)[0].dCode=creerCodeUnique();
		(*altTab)[0].strLieu=malloc(sizeof("Pau"));
		strcpy((*altTab)[0].strLieu,"Pau");
		(*altTab)[0].iNiveau=NOMINAL;
		(*altTab)[0].iType=INCENDIE;
		(*altTab)[0].iVictimes=4;
		(*altTab)[0].strDescription=malloc(sizeof("Rue Carnot"));
		strcpy((*altTab)[0].strDescription,"Rue Carnot");
		(*altTab)[0].uniTab=NULL;
		(*altTab)[0].iUniTabSize=malloc(sizeof(int));
		(*(*altTab)[0].iUniTabSize)=0;

		(*altTab)[1].dCode=creerCodeUnique()+1;
		(*altTab)[1].strLieu=malloc(sizeof("Jurançon"));
		strcpy((*altTab)[1].strLieu,"Jurançon");
		(*altTab)[1].iNiveau=URGENCE;
		(*altTab)[1].iType=EXPLOSION;
		(*altTab)[1].iVictimes=25;
		(*altTab)[1].strDescription=malloc(sizeof("Place du Junquet"));
		strcpy((*altTab)[1].strDescription,"Place du Junquet");
		(*altTab)[1].uniTab=NULL;
		(*altTab)[1].iUniTabSize=malloc(sizeof(int));
		(*(*altTab)[1].iUniTabSize)=0;

		*uniTab=realloc(*uniTab,4*sizeof(alerte));
		*iUniTabSize=4;

		(*uniTab)[0].dCode=creerCodeUnique()+3;
		(*uniTab)[0].strBase=malloc(sizeof("Pau"));
		strcpy((*uniTab)[0].strBase,"Pau");
		(*uniTab)[0].iStatut=EN_ALERTE;
		(*uniTab)[0].iTransport=ROUTE;
		(*uniTab)[0].iDisponibilite=ACTIVE;
		(*uniTab)[0].strNom=malloc(sizeof("Alpha"));
		strcpy((*uniTab)[0].strNom,"Alpha");
		(*uniTab)[0].altAssignee=NULL;
		(*uniTab)[0].iCompteurOperation=0;

		(*uniTab)[1].dCode=creerCodeUnique()+4;
		(*uniTab)[1].strBase=malloc(sizeof("Bizanos"));
		strcpy((*uniTab)[1].strBase,"Bizanos");
		(*uniTab)[1].iStatut=EN_ALERTE;
		(*uniTab)[1].iTransport=MER;
		(*uniTab)[1].iDisponibilite=ACTIVE;
		(*uniTab)[1].strNom=malloc(sizeof("Bravo"));
		strcpy((*uniTab)[1].strNom,"Bravo");
		(*uniTab)[1].altAssignee=NULL;
		(*uniTab)[1].iCompteurOperation=0;

		(*uniTab)[2].dCode=creerCodeUnique()+5;
		(*uniTab)[2].strBase=malloc(sizeof("Pau"));
		strcpy((*uniTab)[2].strBase,"Pau");
		(*uniTab)[2].iStatut=EN_ALERTE;
		(*uniTab)[2].iTransport=AIR;
		(*uniTab)[2].iDisponibilite=ACTIVE;
		(*uniTab)[2].strNom=malloc(sizeof("Charlie"));
		strcpy((*uniTab)[2].strNom,"Charlie");
		(*uniTab)[2].altAssignee=NULL;
		(*uniTab)[2].iCompteurOperation=0;

		(*uniTab)[3].dCode=creerCodeUnique()+6;
		(*uniTab)[3].strBase=malloc(sizeof("Jurançon"));
		strcpy((*uniTab)[3].strBase,"Jurançon");
		(*uniTab)[3].iStatut=EN_ALERTE;
		(*uniTab)[3].iTransport=ROUTE;
		(*uniTab)[3].iDisponibilite=ACTIVE;
		(*uniTab)[3].strNom=malloc(sizeof("Epsilon"));
		strcpy((*uniTab)[3].strNom,"Epsilon");
		(*uniTab)[3].altAssignee=NULL;
		(*uniTab)[3].iCompteurOperation=0;

		printf("Valeurs test ajoutées.\n");
	}
	else
	{
		printf("Valeurs test non ajoutées : il y avait déjà des valeurs\n\n");
	}
	validerSaisie();

}

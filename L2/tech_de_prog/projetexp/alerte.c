#include "alerte.h"
#include "unite.h"
#include "outils.h"

void lireType(alerte* alt)
{
	do
	{
		system("clear");
		printf("*****TYPE D'ALERTE*****\n\n[0]Incendie\n[1]Accident de la route\n[2]Accident en mer\n[3]Accident en montagne\n[4]Malaise\n[5]Explosion\n[6]Accident de la vie\nType d'alerte : ");
		scanf("%d%*c", &(alt->iType));
	} while (alt->iType!=INCENDIE && alt->iType!=ACCIDENT_ROUTE && alt->iType!= ACCIDENT_MER && alt->iType!= ACCIDENT_MONTAGNE && alt->iType!=MALAISE && alt->iType!=EXPLOSION && alt->iType!=ACCIDENT_DE_LA_VIE);
}

void lireNiveau(alerte* alt)
{
	do
	{
		system("clear");
		printf("*****NIVEAU*****\n\n[-1]Nominal\n[-2]Urgence\n[-3]URGENCE ABSOLUE\nGravité de l'alerte : ");
		scanf("%d%*c", &(alt->iNiveau));
	} while (alt->iNiveau!=NOMINAL && alt->iNiveau!=URGENCE && alt->iNiveau!=URGENCE_ABSOLUE);
}

void lireLieu(alerte* alt)
{
	system("clear");
	printf("*****LIEU*****\n\nLieu de l'alerte : ");
	lireChaineCaractere(&(alt->strLieu));
}

void lireVictimes(alerte* alt)
{
	do
	{
		system("clear");
		printf("*****VICTIMES*****\n\nNombre de victimes (doit être d'au moins zéro) : ");
		scanf("%d%*c", &(alt->iVictimes));
	} while (alt->iVictimes<0);
}

void lireDescription(alerte* alt)
{
	system("clear");
	printf("*****NOUVELLE ALERTE*****\n\nDescription de l'alerte : ");
	lireChaineCaractere(&(alt->strDescription));
}

void ajouterAlerte(alerte** altTab, int* iSize)
{
	alerte altTmp;

	*altTab=realloc(*altTab, ((*iSize)+1)*sizeof(alerte));

	altTmp.dCode=creerCodeUnique();
	altTmp.uniTab=malloc(sizeof (unite));
	altTmp.iUniTabSize=malloc(sizeof(int));
	*(altTmp.iUniTabSize)=0;

	lireType(&altTmp);
	lireNiveau(&altTmp);
	lireLieu(&altTmp);
	lireVictimes(&altTmp);
	lireDescription(&altTmp);


	*iSize+=1;
	(*altTab)[(*iSize)-1]=altTmp;
}

void modifierAlerte(alerte* alt)
{
	int iUsrChoice=0;
	alerte altTmp=(*alt);
	do
	{
		system("clear");
		printf("*****MODIFIER ALERTE*****\n\n[1]Type d'alerte\n[2]Gravité de l'alerte \n[3]Lieu de l'alerte\n[4]Nombre de victimes\n[5]Description de l'alerte\n[6]Quitter le menu et sauvegarder\n[7]Quitter sans sauvegarder\n");

		scanf("%d%*c",&iUsrChoice);
		switch (iUsrChoice)
		{
			case 1:
				lireType(&altTmp);
				break;
			case 2:
				lireNiveau(&altTmp);
				break;
			case 3:
				lireLieu(&altTmp);
				break;
			case 4:
				lireVictimes(&altTmp);
				break;
			case 5:
				lireDescription(&altTmp);
				break;
			case 6 :
				(*alt)=altTmp;
				printf("L'alerte a bien été modifiée\n");
				validerSaisie();
				break;
			case 7 :
				printf("L'alerte n'a pas été modifiée\n");
				validerSaisie();
				break;
			default :
				erreurSaisie();
				break;
		}
	} while(iUsrChoice!=6 && iUsrChoice!=7);
}

void affichageAlerte(alerte alt)
{
	printf("\n*****AFFICHAGE DE L'ALERTE*****\n\nCode unique : %.2f\nType d'alerte : ", alt.dCode);
	switch(alt.iType)
	{
		case INCENDIE :
			printf("Incendie\nGravité de l'alerte : ");
			break;
		case ACCIDENT_ROUTE :
			printf("Accident de la route\nGravité de l'alerte : ");
			break;
		case ACCIDENT_MER :
			printf("Accident en mer\nGravité de l'alerte : ");
			break;
		case ACCIDENT_MONTAGNE :
			printf("Accident en montagne\nGravité de l'alerte : ");
			break;
		case MALAISE :
			printf("Malaise\nGravité de l'alerte : ");
			break;
		case EXPLOSION :
			printf("Explosion\nGravité de l'alerte : ");
			break;
		case ACCIDENT_DE_LA_VIE :
			printf("Accident de la vie\nGravité de l'alerte : ");
			break;
		default:
			printf("ERREUR: TYPE INCONNU\n");
			exit(-1);
			break;
	}
	switch(alt.iNiveau)
	{
		case NOMINAL :
			printf("Nominal\nLieu : ");
			break;
		case URGENCE :
			printf("Urgence\nLieu : ");
			break;
		case URGENCE_ABSOLUE :
			printf("URGENCE ABSOLUE\nLieu : ");
			break;
		default:
			printf("ERREUR: NIVEAU INCONNU\n");
			exit(-1);
			break;
	}
	printf("%s\nNombre de victimes : %d\nDescription : %s\n", alt.strLieu, alt.iVictimes, alt.strDescription);


}

int affichageTableauAlertes(alerte* altTab, int iSize)
{
	int i=0;
	int iIndex=0;

	if (iSize!=0)
	{
		do
		{
			printf("\n\nALERTES EN COURS\n\n");
			for(i=0; i<iSize; i++)
			{
				printf("[%d][%.2f]", i ,altTab[i].dCode);
				switch (altTab[i].iNiveau)
				{
					case NOMINAL :
						printf("[Nominal]");
						break;
					case URGENCE :
						printf("[Urgence]");
						break;
					case URGENCE_ABSOLUE :
						printf("[URGENCE ABSOLUE]");
						break;
					default :
						printf("ERREUR: NIVEAU INCONNU\n");
						break;
				}
				printf("%s\n",altTab[i].strDescription);
			}
			printf("\nSélectionnez une alerte : ");
			scanf("%d%*c", &iIndex);
		} while(iIndex<0 || iIndex>=iSize);
		return iIndex;
	}
	else
	{
		printf("\n\nAucune alerte en cours\n");

		return -1;
	}
}

void supprimerAlerte(alerte** altTab, int iIndex, int* iSize)
{
	int i=0;
	alerte* altTmp;

	for (i=0; i<(*(*altTab)[iIndex].iUniTabSize); i++)
	{
		/*altTmp=(((*altTab)[iIndex].uniTab)[i]).altAssignee;
		free(altTmp);*/
		printf("mescouilles");

		((((*altTab)[iIndex]).uniTab)[i]).altAssignee=NULL;
	}

	free((*altTab)[iIndex].iUniTabSize);
	free((*altTab)[iIndex].uniTab);
	//free((*altTab)[iIndex].strLieu);
	//free((*altTab)[iIndex].strDescription);

	for (i=iIndex; i<(*iSize)-1; i++)
	{
		(*altTab)[i]=(*altTab)[i+1];
	}
	(*iSize)-=1;

}

void assignerUnite(alerte* alt, unite* uni)
{
	if (uni->altAssignee==NULL)
	{
		uni->iStatut=EN_ROUTE;
		(*uni->altAssignee)=alt;
		uni->iCompteurOperation+=1;

		alt->uniTab=realloc(alt->uniTab,(*(alt->iUniTabSize)+1)*sizeof(unite*));
		alt->uniTab[*(alt->iUniTabSize)]=*uni;
		affichageUnite(alt->uniTab[*(alt->iUniTabSize)]);
		*(alt->iUniTabSize)+=1;
	}
	else
	{
		printf("Cette unité a déjà été déployée\n");
	}
}

void afficherUnitesAssignees(alerte* altTab, int iIndex)
{
	int i=0;

	if (altTab[iIndex].iUniTabSize!=NULL && *(altTab[iIndex].iUniTabSize)!=0)
	{
		printf("\n\nUNITES ASSIGNEES\n\n");

		for(i=0; i<(*(altTab[iIndex].iUniTabSize));i++)
		{
			printf("[%d]%s\n", i, (altTab[iIndex].uniTab[i]).strNom);
		}
	}
	else
	{
		printf("\n\nAucune unitée n'est assignée\n");
	}
}

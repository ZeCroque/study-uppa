#include "unite.h"
#include "alerte.h"
#include "outils.h"

void lireNom(unite* uni)
{
	system("clear");
	printf("*****NOM*****\n\nNom de l'Unité : ");
	lireChaineCaractere(&(uni->strNom));
}

void lireBase(unite* uni)
{
	system("clear");
	printf("*****BASE*****\n\nBase de l'Unité : ");
	lireChaineCaractere(&(uni->strBase));
}

void lireTransport(unite* uni)
{
	do
	{
		system("clear");
		printf("*****TRANSPORT*****\n\n[-4]Routier\n[-5]Aérien\n[-6]Nautique\nMoyen de transport de l'unité : ");
		scanf("%d%*c", &(uni->iTransport));
	} while (uni->iTransport!=ROUTE && uni->iTransport!=AIR && uni->iTransport!= MER);
}

void lireDisponibilite(unite* uni)
{
	do
	{
		system("clear");
		printf("*****DISPONIBILITE*****\n\n[-7]Active\n[-8]Repos\n[-9]Réaprovisionnement\nDisponibilite de l'unité : ");
		scanf("%d%*c", &(uni->iDisponibilite));
	} while (uni->iDisponibilite!=ACTIVE && uni->iDisponibilite!=EN_REPOS && uni->iDisponibilite!= EN_REAPPROVISIONNEMENT);
}

void lireStatut(unite* uni)
{
	do
	{
		system("clear");
		printf("*****STATUT*****\n\n[-10]En Alerte\n[-11]En Route\n[-12]Sur Operation\nStatut de l'unité : ");
		scanf("%d%*c", &(uni->iStatut));
	} while (uni->iStatut!=EN_ALERTE && uni->iStatut!=EN_ROUTE && uni->iStatut!= SUR_OPERATION);
}

void ajouterUnite(unite** uniTab, int* iSize)
{
	unite uniTmp;

	*uniTab=realloc(*uniTab, ((*iSize)+1)*sizeof(unite));

	uniTmp.dCode=creerCodeUnique();
	uniTmp.iCompteurOperation=0;
	uniTmp.altAssignee=NULL;

	lireNom(&uniTmp);
	lireBase(&uniTmp);
	lireTransport(&uniTmp);
	lireDisponibilite(&uniTmp);
	lireStatut(&uniTmp);

	*iSize+=1;
	(*uniTab)[(*iSize)-1]=uniTmp;

}

void modifierUnite(unite* uni)
{
	int iUsrChoice=0;
	unite uniTmp=(*uni);
	do
	{
		system("clear");

		printf("*****MODIFIER UNITE*****\n\n[1]Nom de l'unité\n[2]Base de l'unité\n[3]Moyen de transport de l'unité\n[4]Disponibilité de l'unité\n[5]Statut de l'unité\n[6]Quitter le menu et sauvegarder\n[7]Quitter sans sauvegarder\n");
		scanf("%d%*c",&iUsrChoice);

		switch (iUsrChoice)
		{
			case 1:
				lireNom(&uniTmp);
				break;
			case 2:
				lireBase(&uniTmp);
				break;
			case 3:
				lireTransport(&uniTmp);
				break;
			case 4:
				lireDisponibilite(&uniTmp);
				break;
			case 5:
				lireStatut(&uniTmp);
				break;
				case 6 :
					free(uni);
					(*uni)=uniTmp;
					printf("L'unité a bien été modifiée\n");
					validerSaisie();
					break;
				case 7 :
					printf("L'unité n'a pas été modifiée\n");
					validerSaisie();
					break;
				default :
					erreurSaisie();
					break;
		}
	} while(iUsrChoice!=6 && iUsrChoice!=7);
}

void affichageUnite(unite uni)
{
	printf("*****AFFICHAGE DE L'UNITE*****\n\nCode unique : %.2f\nNom : %s\nType d'unité : ", uni.dCode, uni.strNom);
	switch(uni.iTransport)
	{
		case ROUTE :
			printf("Routier\nDisponibilité de l'unité : ");
			break;
		case MER :
			printf("Nautique\nDisponibilité de l'unité : ");
			break;
		case AIR :
			printf("Aérien\nDisponibilité de l'unité : ");
			break;
		default:
			printf("ERREUR: TYPE INCONNU\n");
			exit(-1);
			break;
	}
	switch(uni.iDisponibilite)
	{
		case ACTIVE :
			printf("Active\nStatut : ");
			break;
		case EN_REPOS :
			printf("En repos\nStatut : ");
			break;
		case EN_REAPPROVISIONNEMENT :
			printf("En réapprovisionnement\nStatut : ");
			break;
		default:
			printf("ERREUR: DISPONIBILITE INCONNUE\n");
			exit(-1);
			break;
	}
	switch(uni.iStatut)
	{
		case EN_ALERTE :
			printf("En alerte\n");
			break;
		case EN_ROUTE :
			printf("En route\n");
			break;
		case SUR_OPERATION :
			printf("Sur opération\n");
			break;
		default:
			printf("ERREUR: STATUT INCONNU\n");
			exit(-1);
			break;
	}
	printf("Base : %s\n", uni.strBase);


}

int affichageTableauUnites(unite* uniTab, int iSize)
{
	int i=0;
	int iIndex=0;

	if (iSize!=0)
	{
		do
		{
			printf("\n\nUNITES EN COURS\n\n");
			for(i=0; i<iSize; i++)
			{
				printf("[%.2f][%d]%s\n",uniTab[i].dCode, i, uniTab[i].strNom);
			}
			printf("\nSélectionnez une unité : ");
			scanf("%d%*c", &iIndex);
		} while(iIndex<0 || iIndex>=iSize);
		return iIndex;
	}
	else
	{
		printf("\n\nAucune unité\n");
		return -1;
	}
}

void supprimerUnite(unite** uniTab, int iIndex, int* iSize)
{
	int i=0;

	for (i=iIndex; i<(*iSize)-1; i++)
	{
		(*uniTab)[i]=(*uniTab)[i+1];
	}
	(*iSize)-=1;
}

void afficherAlerteAssignee(unite uni)
{
	system("clear");
	if (uni.altAssignee!=NULL)
	{
			affichageAlerte(**(uni.altAssignee));
	}
	else
	{
		printf("Aucune unité assignée\n");
	}
}

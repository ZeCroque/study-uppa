#ifndef __unite_h
#define __unite_h

#include <stdio.h>
#include <stdlib.h>
//#include "alerte.h"

#define ROUTE -4
#define AIR -5
#define MER -6

#define ACTIVE -7
#define EN_REPOS -8
#define EN_REAPPROVISIONNEMENT -9

#define EN_ALERTE -10
#define EN_ROUTE -11
#define SUR_OPERATION -12

struct Alerte;

typedef struct Unite
{
	double dCode; //Code unique de l'unité
	char* strNom; //Nom de l'unité
	int iTransport; //Type de moyen de transport
	int iDisponibilite; //Disponibilité de l'unité
	int iCompteurOperation;
	int iStatut; //Statut de l'unité
	char* strBase; //Base de l'unité
	struct Alerte* altAssignee; //Alerte sur laquelle l'unité opère
} unite;

//Ajoute une unité au tableau d'unités passé en paramètre
void ajouterUnite(unite** uniTab, int* iSize);

//Modifie l'unité passée en paramètre
void modifierUnite(unite* uni);

//Affiche l'unité passée en paramètre
void affichageUnite(unite uni);

//Affiche toutes les unités du tableau d'unités passé en paramètre
int affichageTableauUnites(unite* uniTab, int iSize);

//Supprime l'unité se trouvant à l'index indiqué dans le tableau passé en paramètre
void supprimerUnite(unite** uniTab, int iIndex, int* iSize);

//Affiche les unités déployées sur une alerte
void afficherAlerteAssignee(unite uni);

//Gère le statut et la disponibilité d'une alerte
void gestionEtat(unite* uni);

#endif

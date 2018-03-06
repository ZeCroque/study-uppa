#ifndef __alerte_h
#define __alerte_h

#include <stdio.h>
#include <stdlib.h>

#define INCENDIE 0
#define ACCIDENT_ROUTE 1
#define ACCIDENT_MER 2
#define ACCIDENT_MONTAGNE 3
#define MALAISE 4
#define EXPLOSION 5
#define ACCIDENT_DE_LA_VIE 6

#define NOMINAL -1
#define URGENCE -2
#define URGENCE_ABSOLUE -3

typedef struct Unite unite;

typedef struct Alerte
{
	double dCode; //Code unique de l'alerte
	int iType; //Type de l'alert
	int iNiveau; //Niveau de gravité de l'alerte
	char* strLieu; //Lieu de l'alerte
	int iVictimes; //Nombre de victimes
	char* strDescription; //Description de l'alarme
	unite* uniTab; //Tableau contenant les(l') unité(s) opérant sur cette alerte
	int* iUniTabSize;
} alerte;

//Ajoute une alerte au tableau d'alertes passé en paramètre
void ajouterAlerte(alerte** altTab, int* iSize);

//Modifie l'alerte passée en paramètre
void modifierAlerte(alerte* alt);

//Affiche l'alerte passée en paramètre
void affichageAlerte(alerte alt);

//Affiche toutes les alertes du tableau d'alertes passé en paramètre
int affichageTableauAlertes(alerte* altTab, int iSize);

//Supprime l'alerte ayant le code indiqué dans le tableau passé en paramètre
void supprimerAlerte(alerte** altTab, int iIndex, int* iSize);

void assignerUnite(alerte* alt, struct Unite* uni);

void afficherUnitesAssignees(alerte* alt, int iIndex);

#endif

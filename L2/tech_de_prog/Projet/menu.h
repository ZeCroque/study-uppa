#ifndef __menu_h
#define __menu_h

#include "unite.h"
#include "alerte.h"


//Menu principal
void menuPrincipal(alerte** altTab, int* iSize, unite** uniTab, int* iUniSize);

//Affiche le menu de gestion des alertes
void gererAlertes(alerte** altTab, int* iSize);

//Affiche le menu de gestion des unités
void gererUnites(unite** uniTab, int* iSize);

//Affiche le menu permettant le traitement des alertes
void traitementAlertes(alerte** altTab, int* iAltSize, unite* uniTab, int iUniSize);

//Affiche le menu permettant la gestion des unités
void gestionUnite(unite** uniTab, int* iUniSize);

//Affiche le menu permettant la manipulation sans contrainte des structures et l'utilisation du jeu de test
void menuDebug(alerte** altTab, int* iAltSize, unite** uniTab, int* iUniSize);

#endif

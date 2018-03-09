#ifndef __outils_h
#define __outils_h

#include <stdio.h>
#include <stdlib.h>
#include "alerte.h"
#include "unite.h"

//Lis une chaine de caractère, la place dans le pointeur passé en paramètre et renvoie sa taille
int lireChaineCaractere(char** str);

//Affiche une confirmation et demande d'appuyer sur entrée
void validerSaisie();

//Afficher un message d'erreur et demande d'appuyer sur entrée
void erreurSaisie();

//Créer un code unique en se basant sur le temps et le retourne
double creerCodeUnique();

//Ajoute un jeu de test de structures prédéfines à des fin de test/debug
void modeDemo(alerte** altTab, int* iAltTabSize, unite** uniTab, int* iUniTabSize);

#endif

#ifndef __outils_h
#define __outils_h

#include <stdio.h>
#include <stdlib.h>
#include "alerte.h"
#include "unite.h"



int lireChaineCaractere(char** str);
void validerSaisie();
void erreurSaisie();
double creerCodeUnique();
void modeDemo(alerte** altTab, int* iAltTabSize, unite** uniTab, int* iUniTabSize);

#endif

#ifndef DEBUG_MODE
#define DEBUG_MODE 42
#endif

#ifndef outils_h
#define outils_h

#include <string>
#include <sstream>
#include <iostream>
#include "joueur.h"
#include "carte.h"
#include "jeu.h"

//TODO
//COMMENTAIRES CPP
//TRY/CATCH

//Menu de DEBUG
void debugMode();

//Permet de demander à l'utilisateur un entier non signé
//En évitant les erreurs de lecture
unsigned int readUnsignedInt();

//Permet de demander à l'utilisateur un booléen
//En évitant les erreurs de lecture
int readBool();

//Permet de convertir un entier donné en son équivalent en caractères
std::string intToString(int number);

#endif

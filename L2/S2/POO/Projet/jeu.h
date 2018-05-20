#ifndef jeu_h
#define jeu_h

#include "vecteur.h"
#include "carte.h"
#include "joueur.h"
#include "combinaison.h"

//Affiche les résultat d'un tour de jeu
void jouerTour(const Vecteur<Joueur>& joueurs);

//Appelle la fonction draw sur chacun des joueurs avec le deck donné
void drawStep(const Vecteur<Joueur>& joueurs, Deck& deck);

//Affiche les cartes présente sur le board
void afficherTable(const Vecteur<Carte>& table);

//Affiche le nom des joueurs, le contenu de leur main
//et la meilleure combinaison qu'ils ont avec le board passé en paramètre
void afficherJoueurs(const Vecteur<Joueur>& joueurs, const Vecteur<Carte>& table);

#endif

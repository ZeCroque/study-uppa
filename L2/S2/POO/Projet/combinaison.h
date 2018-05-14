#ifndef combinaison_h
#define combinaison_h

#include "carte.h"
#include "vecteur.h"


//****************************
//*        AFFICHAGE         *
//****************************

//Affiche la meilleur combinaison dans les cartes données en paramètre
//Appelles toutes les fonctions de vérification dans leur ordre hiérarchique
//S'arrête lorsque l'une d'elle est trouvée ou affiche la carte haute
void afficherCombinaison(const Vecteur<Carte>& cartes);

//Affiche le kicker parmi les cartes passées en paramètre
//Excepté les cartes dont la hauteur se trouve dans valeurExclues (on exclue du kicker les cartes composant la combinaison)
//Affiche un nombre de kicker égal au paramètre "number"
void afficherKicker(const Vecteur<Carte>& cartes, Vecteur<int> valeurExclues, int number);

//Affiche la carte haute et 4 kickers
void afficherCarteHaute(const Vecteur<Carte>& cartes);


//****************************
//*          OUTILS          *
//****************************

//Renvoie la hauteur d'une combinaison composée de "number" cartes si possible
//Sinon renvoie la carte par défaut
Carte trouverCartesEgales(const Vecteur<Carte>& cartes, int number, int valeurExclue);

//Renvoie la carte de hauteur la plus haute parmi les cartes données
//Excepté les cartes dont la hauteur se trouve dans valeurExclues
Carte trouverCarteHaute(const Vecteur<Carte>& cartes, const Vecteur<int>& valeursExclues=Vecteur<int>());


//******************************
//*VERIFICATION DE COMBINAISONS*
//******************************

//**POUR TOUTES LES FONCTIONS SUIVANTES**
//Vérifie si la combinaison concernée est présente dans les cartes passées en paramètre
//Affiche puis renvoie vrai si la combinaison s'y trouve
//Retourne faux sinon

bool verifierQuinteFlush(const Vecteur<Carte>& cartes);
bool verifierCarre(const Vecteur<Carte>& cartes);
bool verifierFull(const Vecteur<Carte>& cartes);
bool verifierCouleur(const Vecteur<Carte>& cartes);
bool verifierQuinte(const Vecteur<Carte>& cartes);
bool verifierBrelan(const Vecteur<Carte>& cartes);
bool verifierDoublePaire(const Vecteur<Carte>& cartes);
bool verifierPaire(const Vecteur<Carte>& cartes);

#endif

#ifndef jeu_h
#define jeu_h

#include "vecteur.h"
#include "carte.h"
#include "joueur.h"

//TODO Modulariser recherche paire/brelan/etc

void drawStep(const Vecteur<Joueur>& joueurs, Deck& deck);
void afficherTable(const Vecteur<Carte>& table);
void afficherJoueurs(const Vecteur<Joueur>& joueurs, const Vecteur<Carte>& table);
void afficherCouleur(Carte carte);
void afficherValeur(Carte carte);
void afficherKicker(const Vecteur<Carte>& cartes, Vecteur<int> valeurExclues, int number);
Carte verifierEgalite(const Vecteur<Carte>& cartes, int number, int valeurExclue);
Carte trouverCarteHaute(const Vecteur<Carte>& cartes, const Vecteur<int>& valeursExclues=Vecteur<int>());
void verifierCombinaison(const Vecteur<Carte>& cartes);
bool verifierQuinteFlush(const Vecteur<Carte>& cartes);
bool verifierCarre(const Vecteur<Carte>& cartes);
bool verifierFull(const Vecteur<Carte>& cartes);
bool verifierCouleur(const Vecteur<Carte>& cartes);
bool verifierQuinte(const Vecteur<Carte>& cartes);
bool verifierBrelan(const Vecteur<Carte>& cartes);
bool verifierDoublePaire(const Vecteur<Carte>& cartes);
bool verifierPaire(const Vecteur<Carte>& cartes);
void verifierCarteHaute(const Vecteur<Carte>& cartes);

#endif

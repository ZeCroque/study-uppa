#ifndef jeu_h
#define jeu_h

#include "vecteur.h"
#include "carte.h"
#include "joueur.h"

void drawStep(const Vecteur<Joueur>& joueurs, Deck& deck);
void afficherTable(const Vecteur<Carte>& table);
void afficherJoueurs(const Vecteur<Joueur>& joueurs, const Vecteur<Carte>& table);
void verifierCombinaison(const Vecteur<Carte>& cartes);
bool verifierQuinteFlush(const Vecteur<Carte>& cartes);
bool verifierCarre(const Vecteur<Carte>& cartes);
bool verifierFull(const Vecteur<Carte>& cartes);
bool verifierCouleur(const Vecteur<Carte>& cartes);
bool verifierSuite(const Vecteur<Carte>& cartes);
bool verifierQuinte(const Vecteur<Carte>& cartes);
bool verifierBrelan(const Vecteur<Carte>& cartes);
bool verifierDoublePaire(const Vecteur<Carte>& cartes);
bool verifierPaire(const Vecteur<Carte>& cartes);
bool verifierCarteHaute(const Vecteur<Carte>& cartes);

#endif

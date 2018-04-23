#ifndef joueur_h
#define joueur_h

#include "carte.h"
#include "ensemble.h"

class Joueur
{
  private:
    Ensemble<Carte> main;
  public:
    Joueur();
    Joueur(const Joueur& j);
    ~Joueur();
    Joueur& operator = (const Joueur& j);
};

#endif

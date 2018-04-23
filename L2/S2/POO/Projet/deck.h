#ifndef deck_h
#define deck_h

#include "carte.h"
#include "vecteur.h"

class Deck
{
  private:
     Vecteur<Carte> _deck;
  public:
    Deck();
    Deck(const Deck& j);
    ~Deck();
    Deck& operator = (const Deck& j);
    void shuffle();
    Carte draw();
    friend std::ostream& operator << (std::ostream& os, const Deck& c);
};

#endif

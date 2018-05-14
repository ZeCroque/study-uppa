#ifndef deck_h
#define deck_h

#include "carte.h"
#include "vecteur.h"

class Deck
{
  private:
    //Cartes du deck
     Vecteur<Carte> _deck;
  public:
    //Forme canonique de coplien
    Deck();
    Deck(const Deck& j);
    ~Deck();
    Deck& operator = (const Deck& j);

    //Mélange le vecteur de Carte
    void shuffle();

    //Enlève la première carte du deck et la renvoie
    Carte draw();

    //Affichage
    friend std::ostream& operator << (std::ostream& os, const Deck& c);
};

#endif

#ifndef joueur_h
#define joueur_h

#include <string>
#include "carte.h"
#include "vecteur.h"
#include "deck.h"

//TODO COMMENTAIRES CPP & H

class Joueur
{
  private:
    std::string _nom;
    Vecteur<Carte> _main;
  public:
    Joueur();
    Joueur(std::string nom);
    Joueur(const Joueur& j);
    ~Joueur();
    Joueur& operator = (const Joueur& j);
    void draw(Deck& deck);
    Vecteur<Carte> getMain() const;
    friend std::ostream& operator << (std::ostream& os, const Joueur& j);
};



#endif

#ifndef joueur_h
#define joueur_h

#include <string>
#include "carte.h"
#include "vecteur.h"
#include "deck.h"

class Joueur
{
  private:
    //Nom du joueur
    std::string _nom;
    
    //Main du joueur
    Vecteur<Carte> _main;
  public:
    //Forme canonique de coplien
    Joueur();
    Joueur(const Joueur& j);
    ~Joueur();
    Joueur& operator = (const Joueur& j);

    //Constructeur surchargé initialisant avec le nom
    Joueur(std::string nom);

    //Pioche 2 cartes dans le deck passé en paramètre
    //Les ajoute à la main du joueur
    void draw(Deck& deck);

    //Renvoie la main du joueur
    Vecteur<Carte> getMain() const;

    //Affichage
    friend std::ostream& operator << (std::ostream& os, const Joueur& j);
};



#endif

#ifndef carte_h
#define carte_h

#include <iostream>
#include <sstream>
#include <string>

class Carte
{
  private:
    //Famille de la carte (1-13)
    int _famille;

    //Valeur de la carte (1-4)
    int _valeur;
  public:
    //Forme canonique de coplien
    Carte();
    Carte(const Carte& c);
    ~Carte();
    Carte& operator = (const Carte& c);

    //Constructeur surchargé instantiant la carte à la bonne valeur et famille
    Carte(int valeur, int famille);

    //Retourne la valeur de la carte
    int getValeur() const;

    //Retourne la famille de la carte
    int getFamille() const;

    //Renvoie un string correspondant à la famille de la carte
    std::string afficherFamille() const ;

    //Renvoie un string correspondant à la valeur de la carte
    std::string afficherValeur() const;
};

//Affichage
std::ostream& operator << (std::ostream& os, const Carte& c);

#endif

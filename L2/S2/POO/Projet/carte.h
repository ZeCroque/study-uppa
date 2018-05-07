#ifndef carte_h
#define carte_h

#include <iostream>
#include <sstream>
#include <string>

//TODO COMMENTAIRES CPP & H

class Carte
{
  private:
    int _famille;
    int _valeur;
  public:
    Carte();
    Carte(const Carte& c);
    Carte(int valeur, int famille);
    ~Carte();
    int getValeur() const;
    int getFamille() const;
    Carte& operator = (const Carte& c);
    std::string afficherFamille() const ;
    std::string afficherValeur() const;
    friend std::ostream& operator << (std::ostream& os, const Carte& c);
};

#endif

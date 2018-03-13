#ifndef Enseignant__h
#define Enseignant__h

#include "personne.h"

class Enseignant : public Personne
{
  private :
    std::string _metier;
  public :
    Enseignant();
    Enseignant(std::string nom, std::string prenom, std::string metier);
    Enseignant(const Enseignant& e);
    ~Enseignant();
    Enseignant& operator = (const Enseignant& e);
    void setMetier(std::string m);
    std::string getMetier();
    void afficher();
};

#endif

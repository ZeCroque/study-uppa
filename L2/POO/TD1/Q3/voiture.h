#ifndef Voiture__h
#define Voiture__h

#include <string>
#include "personne.h"

class Voiture
{
  private :
    std::string marque;
    std::string modele;
    Personne utilisateurs[5];
    int nbUtilisateurs;
  public :
    Voiture();
    Voiture(std::string marque, std::string modele);
    ~Voiture();
    void ajouterPassager(Personne p);
    void afficherPassager();
};

#endif

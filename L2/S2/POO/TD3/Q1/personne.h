#ifndef Personne__h
#define Personne__h

#include <string>

class Personne
{
  protected :
    std::string nom;
    std::string prenom;
  public :
    Personne();
    Personne(std::string nom, std::string  prenom);
    void afficher();
    void saisir(std::string nom, std::string  prenom);
    void raz();
    std::string getNom();
    std::string getPrenom();
    ~Personne();
    Personne& operator = (const Personne a );
};

#endif

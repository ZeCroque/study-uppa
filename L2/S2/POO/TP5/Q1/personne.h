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
    Personne(const Personne& p);
    virtual ~Personne();
    virtual Personne& operator = (const Personne& a );
    virtual void afficher();
    std::string getNom();
    std::string getPrenom();
    void setNom(std::string s);
    void setPrenom(std::string s);

};

#endif

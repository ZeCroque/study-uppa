#ifndef etudiant__h
#define etudiant__h

#include "personne.h"

class Etudiant : public Personne
{
  private :
    int _code;
  public :
    Etudiant();
    Etudiant(std::string nom, std::string prenom, int code);
    Etudiant(const Etudiant& e);
    ~Etudiant();
    Etudiant& operator = (const Etudiant& e);
    void setCode(int c);
    int getCode();
    void afficher();
};

#endif

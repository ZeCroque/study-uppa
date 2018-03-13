#ifndef etudiant__h
#define etudiant__h

#include "personne.h"

class Etudiant : public Personne
{
  private :
    int _code;
  public :
    virtual void afficher();
};

#endif

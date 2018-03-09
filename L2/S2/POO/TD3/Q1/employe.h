#ifndef employe_h
#define employe_h

#include "personne.h"

class Employe: public Personne
{

  private :
    std::string _metier;
    int _codeId;
  public :
    Employe();
    Employe(std::string nom, std::string  prenom);
    Employe(std::string metier, int codeId);
    Employe(std::string nom, std::string  prenom, std::string metier, int codeId);
    std::string getMetier();
    int getId();
    void travailler();
    bool operator == (const Employe& e);
    bool operator != (const Employe& e);

};

#endif

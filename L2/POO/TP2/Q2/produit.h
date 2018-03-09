#ifndef produit_h
#define produit_h

#include <iostream>
#include <string>

class Produit
{
  private :
    int _code;
    std::string _nom;
  public :
    Produit();
    Produit(const Produit& p);
    ~Produit();
    Produit& operator = (const Produit& p);
    void setCode(int code);
    void setNom(std::string nom);
    int getCode() const;
    std::string getNom() const;
};

std::ostream& operator << (std::ostream& os, const Produit& p);

#endif

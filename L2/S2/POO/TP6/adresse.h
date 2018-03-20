#ifndef adresse_h
#define adresse_h

#include <string>
#include <iostream>

class Adresse
{
  private :
    int _numero;
    std::string _rue;
    std::string _CP;
    std::string _ville;
  public :
    Adresse();
    Adresse(const Adresse& a);
    Adresse(std::string rue, std::string ville, std::string CP, int numero);
    ~Adresse();
    Adresse& operator = (const Adresse& a);
    bool operator == (const Adresse& a);
    std::string getRue() const;
    std::string getVille() const;
    std::string getCP() const;
    int getNumero() const;
};

std::ostream& operator << (std::ostream& os, const Adresse& a);

#endif

#ifndef oeuvres_h
#define oeuvres_h

#include "oeuvre.h"
#include <vector>

class Oeuvres
{
  private :
    std::vector<Oeuvre> _oeuvreTab;
    int _size;
  public :
    Oeuvres();
    Oeuvres(Oeuvres& a);
    ~Oeuvres();
    Oeuvres& operator = (const Oeuvres& a);
    void addOeuvre(Oeuvre& a);
    void removeOeuvre(int index);
    void afficheOeuvre(int index);
};

#endif

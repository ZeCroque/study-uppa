#ifndef adherents_h
#define adherents_h

#include "adherent.h"
#include <vector>

class Adherents
{
  private :
    std::vector<Adherent> _adherentTab;
    int _size;
  public :
    Adherents();
    Adherents(Adherents& a);
    ~Adherents();
    Adherents& operator = (const Adherents& a);
    void addAdherent(Adherent* a);
    void removeAdherent(Adherent* a);
};

#endif

#ifndef tourcontrole_h
#define tourcontrole_h

#include "avion.h"

#define TAILLE 5

class TourDeControle
{

  private :
    Avion tab[TAILLE];
    int indexMax;
  public :
    TourDeControle();
    TourDeControle(const TourDeControle& a);
    ~TourDeControle();
    TourDeControle& operator = (const TourDeControle& a);
    int getIndexMax() const;
    Avion getAvionAt(int index) const;

    void ajouterTabAvionNormal(const Avion& a);
    void ajouterAvionAmie(const Avion& a);
    void ajouterAvion(const Avion &a);


};

#endif

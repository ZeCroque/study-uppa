#include "tourcontrole.h"

using namespace std;

int main()
{
  TourDeControle t;

  Avion a1;
  a1.setFabriquant("Airbus");
  a1.setType(380);
  a1.setCap(45.3);
  a1.setAltitude(1578.6);

  Avion a2;
  a2.setFabriquant("Boeing");
  a2.setType(747);
  a2.setCap(98.6);
  a2.setAltitude(2300.7);

  t.ajouterTabAvionNormal(a1);
  t.ajouterTabAvionNormal(a2);
  t.ajouterTabAvionNormal(a1);
  t.ajouterAvionAmie(a2);
  t.ajouterAvion(a1);
  t.ajouterTabAvionNormal(a2);

  afficheFiche(t.getAvionAt(0));
  afficheFiche(t.getAvionAt(1));
  cout<<t.getAvionAt(2);
  cout<<t.getAvionAt(3);
  cout<<t.getAvionAt(4);
  cout<<t.getAvionAt(5);

  return 0;
}

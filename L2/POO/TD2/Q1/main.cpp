#include "avion.h"

int main()
{
  Avion a;

  a.setFabriquant("Airbus");
  a.setType(380);
  a.setCap(210.74);
  a.setAltitude(2504.56);

  afficheFiche(a);

  return 0;
}

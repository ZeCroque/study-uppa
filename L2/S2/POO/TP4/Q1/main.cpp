#include <iostream>
#include "chaine.h"

int main()
{
  Chaine a;
  a.setText("trololo");
  a.affiche();

  Chaine b(a);
  b.affiche();

  Chaine c;
  c=b;
  c.affiche();

  return 0;
}

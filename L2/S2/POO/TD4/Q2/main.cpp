#include <iostream>
#include "chaine.h"

int main()
{
  Chaine* a=new Chaine();
  a->setText("trololo");
  a->affiche();

  Chaine* b=new Chaine(*a);
  b->affiche();

  Chaine* c=new Chaine();
  *c=*b;
  c->affiche();

  delete b;
  delete c;
  a->affiche();
  c->affiche();


  return 0;
}

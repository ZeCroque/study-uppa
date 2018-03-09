#include <iostream>
#include "personne.h"
#include "voiture.h"

int main()
{
  Personne* p=new Personne("Croquefer", "Gaëtan");
  p->afficher();
  p->raz();
  p->afficher();
  p->saisir("Beau", "Gosse");
  p->afficher();
  delete p;
  std::cout<<"\n";

  Personne a("Lol","mdr");
  Personne b("uu","kk");
  Personne c("kk","jj");

  Voiture v("Peugeot", "405");
  v.ajouterPassager(a);
  v.ajouterPassager(b);
  v.ajouterPassager(c);
  v.ajouterPassager(a);
  v.ajouterPassager(b);
  v.ajouterPassager(c);
  v.afficherPassager();

  return 0;
}

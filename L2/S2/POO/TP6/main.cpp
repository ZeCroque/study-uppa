#include <iostream>
#include "adherents.h"
#include "oeuvre.h"

using namespace std;

int main()
{
  Adherent moi("Croquefer", "Gaëtan", "140996", 21, "Louis Lacaze", "Pau", "64000", 16);

  Adherents ad;
  ad.addAdherent(moi);
  ad.afficheAdherent(0);

  Exemplaire exp1(1);
  Exemplaire exp2(2);
  Exemplaire exp3(3);

  moi.addExemplaire(exp1);
  moi.addExemplaire(exp2);
  moi.addExemplaire(exp3);

  for(int i=0; i<3; i++)
  {
    moi.afficheExemplaire(i);
  }

  Oeuvre o1("Titanic", "Il meurt à la fin");
  cout<<o1;
  OeuvreInterprete o2("Kermesse de Trifouillis-Les-Oies", "Un spectacle assez navrant", "CM2 B option ZEP");
  cout<<o2;
  OeuvreNonInterprete o3("Skyrim", "Le jeu qui te rend asocial");
  cout<<o3;
  CD c("Minutes to Midnight", "Album d'anthologie", "Linkin Park", 45);
  cout<<c;
  Livre l("Harry Potter", "Un chateux cheaté", 1458);
  cout<<l;

  return 0;
}

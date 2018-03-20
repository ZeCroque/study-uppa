#include <iostream>
#include "ensemble.h"
#include "adherent.h"
#include "exemplaire.h"

using namespace std;

int main()
{
  Adherent moi("Croquefer", "Gaëtan", "140996", 21, "Louis Lacaze", "Pau", "64000", 16);

  Ensemble<Adherent> listeAdherents;
  listeAdherents.inserer(moi);
  listeAdherents.affiche(0);

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

  moi.removeExemplaire(exp3);

  moi.addExemplaire(exp3);

  for(int i=0; i<3; i++)
  {
    moi.afficheExemplaire(i);
  }



  return 0;
}

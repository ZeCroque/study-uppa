#include <iostream>
#include "gestionfichier.h"


using namespace std;

int main()
{
  GestionFichier g("donnees.txt");
  string* tab=new string[10];
  tab[0]="lol";
  g.enregistrerFichier(tab, 1);

  string** tab2=new string*;
  g.lireFichier(tab2, 3);
  cout<<*tab2<<endl;

  return 0;
}

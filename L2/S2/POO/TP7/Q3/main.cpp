#include <iostream>
#include "pile.h"
#include <string>

using namespace std;

int main()
{
  Pile<string> p;
  string s;

  p<<"Lefer";
  p<<"Mrissa";
  p<<"Belloir";

  cout<<"Affichage de la pile\n"<<p<<endl;

  cout<<"Affichage du sommet\n"<<p.top()<<endl;

  p>>s;
  cout<<"\nOn dépile\n\nAffichage de l'élément dépilé\n"<<s<<"\n\nAffichage de la pile\n"<<p<<endl;
  return 0;
}

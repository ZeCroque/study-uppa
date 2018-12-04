#include <iostream>
#include "Graphe.h"

using namespace std;

int main()
{
  Graphe g(4);
  g.ajouterLien(1,3);
  g.afficherGraphe();
  cout<<g;
  return 0;
}

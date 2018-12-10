#include <iostream>
#include "Graphe.h"

using namespace std;

int main()
{
  Graphe g(8);
  g.ajouterLien(1,2);
  g.ajouterLien(2,3);
  g.ajouterLien(1,5);
  g.ajouterLien(5,6);
  g.ajouterLien(7,6);
  g.ajouterLien(6,2);
  g.ajouterLien(2,5);
  g.ajouterLien(3,7);
  g.ajouterLien(3,6);
  g.ajouterLien(4,7);
  g.ajouterLien(4,8);
  g.ajouterLien(8,7);

  //g.afficherGraphe();
  //cout<<g<<endl<<endl;
  vector<int> datesFin=g.parcoursHistorique();
  triBulle(datesFin);
  Graphe gt=g.grapheAdjacent();
  //cout<<gt<<endl<<endl;
  //gt.afficherGraphe();


  return 0;
}

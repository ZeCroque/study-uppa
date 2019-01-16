#include "Graphe.h"

using namespace std;

int main()
{

  //Création du graphe
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
  cout<<"Graphe"<<endl;
  cout<<g<<endl;

  //Parcours Historique
  vector<pair<int,int> > datesFin=g.parcoursHistorique();
  triBulle(datesFin);
  cout<<"Dates fin triées :"<<endl;
  for(int i=0; i<(int)datesFin.size(); i++)
  {
    cout<<"sommet :"<<datesFin[i].first<<" poids:"<<datesFin[i].second<<endl;
  }
  cout<<endl;

  //Graphe adjacent
  Graphe gt=g.grapheAdjacent();
  cout<<"Graphe adjacent"<<endl;
  cout<<gt<<endl;

  //Parcours en profondeur
  vector<vector <int> >tmp=g.parcoursProfondeur(gt, datesFin);

  cout<<"Graphe quotient"<<endl;
  for(int i=0; i<(int)tmp.size(); i++)
  {
    for(int j=0; j<(int)tmp[i].size(); j++)
    {
      cout<<tmp[i][j]<<" ";
    }
    cout<<endl;
  }

  //Si vous êtes sur linux et que vous avez le programme dot d'installé, décommentez cette fonction, elle affichera le graphe sous forme d'image
  //gt.afficherGraphe();


  return 0;
}

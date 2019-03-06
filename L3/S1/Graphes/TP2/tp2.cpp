#include "Graphe.h"

using namespace std;

int main()
{
    //===EXO1===

  //Création du graphe des fréquences de réseau mobile
  Graphe g(20);
  g.ajouterLien(1,4);
  g.ajouterLien(1,6);
  g.ajouterLien(1,8);
  g.ajouterLien(1,11);
  g.ajouterLien(1,17);
  g.ajouterLien(2,3);
  g.ajouterLien(2,4);
  g.ajouterLien(2,7);
  g.ajouterLien(2,13);
  g.ajouterLien(2,19);
  g.ajouterLien(3,8);
  g.ajouterLien(3,12);
  g.ajouterLien(3,19);
  g.ajouterLien(3,20);
  g.ajouterLien(4,13);
  g.ajouterLien(4,19);
  g.ajouterLien(5,6);
  g.ajouterLien(5,7);
  g.ajouterLien(5,15);
  g.ajouterLien(6,7);
  g.ajouterLien(6,10);
  g.ajouterLien(6,17);
  g.ajouterLien(6,20);
  g.ajouterLien(7,9);
  g.ajouterLien(8,12);
  g.ajouterLien(8,17);
  g.ajouterLien(8,18);
  g.ajouterLien(9,11);
  g.ajouterLien(9,19);
  g.ajouterLien(10,14);
  g.ajouterLien(10,15);
  g.ajouterLien(11,16);
  g.ajouterLien(11,18);
  g.ajouterLien(12,15);
  g.ajouterLien(14,20);
  g.ajouterLien(16,19);
  g.ajouterLien(16,20);

  cout<<"Graphe des fréquences de réseau mobile"<<endl;
  cout<<g<<endl;

  vector<vector <int> >tmp=g.getStables();

  cout<<"\nStables"<<endl;
  for(int i=0; i<(int)tmp.size(); i++)
  {
    for(int j=0; j<(int)tmp[i].size(); j++)
    {
      cout<<tmp[i][j]+1<<" ";
    }
    cout<<endl;
  }

  //Si vous êtes sur linux et que vous avez le programme dot d'installé, décommentez cette fonction, elle affichera le graphe sous forme d'image
  //g.afficherGraphe();

  //===EXO2===

  //Graphe du cycle d'assemblage d'un smartphone
  Graphe g2(12);
  g2.ajouterLien(1,2);
  g2.ajouterLien(1,3);
  g2.ajouterLien(1,4);
  g2.ajouterLien(1,5);
  g2.ajouterLien(1,6);
  g2.ajouterLien(1,7);
  g2.ajouterLien(1,9);
  g2.ajouterLien(1,10);
  g2.ajouterLien(2,3);
  g2.ajouterLien(2,4);
  g2.ajouterLien(2,5);
  g2.ajouterLien(2,6);
  g2.ajouterLien(2,7);
  g2.ajouterLien(2,8);
  g2.ajouterLien(2,9);
  g2.ajouterLien(2,10);
  g2.ajouterLien(2,12);
  g2.ajouterLien(3,4);
  g2.ajouterLien(3,4);
  g2.ajouterLien(3,5);
  g2.ajouterLien(3,6);
  g2.ajouterLien(3,7);
  g2.ajouterLien(3,9);
  g2.ajouterLien(3,10);
  g2.ajouterLien(3,11);
  g2.ajouterLien(3,12);
  g2.ajouterLien(4,5);
  g2.ajouterLien(4,6);
  g2.ajouterLien(4,7);
  g2.ajouterLien(4,8);
  g2.ajouterLien(4,10);
  g2.ajouterLien(4,11);
  g2.ajouterLien(5,6);
  g2.ajouterLien(5,7);
  g2.ajouterLien(5,8);
  g2.ajouterLien(5,9);
  g2.ajouterLien(5,10);
  g2.ajouterLien(5,11);
  g2.ajouterLien(5,12);
  g2.ajouterLien(6,7);
  g2.ajouterLien(6,9);
  g2.ajouterLien(6,10);
  g2.ajouterLien(6,11);
  g2.ajouterLien(7,8);
  g2.ajouterLien(7,10);
  g2.ajouterLien(7,11);
  g2.ajouterLien(7,12);
  g2.ajouterLien(8,10);
  g2.ajouterLien(8,11);
  g2.ajouterLien(8,12);
  g2.ajouterLien(9,10);
  g2.ajouterLien(10,11);



  cout<<"\n\nGraphe du cycle d'assemblage d'un smartphone"<<endl;
  cout<<g2<<endl;

  vector<vector <int> >tmp2=g2.getStables();

  cout<<"\nStables"<<endl;
  for(int i=0; i<(int)tmp2.size(); i++)
  {
    for(int j=0; j<(int)tmp2[i].size(); j++)
    {
      cout<<tmp2[i][j]+1<<" ";
    }
    cout<<endl;
  }

  //Si vous êtes sur linux et que vous avez le programme dot d'installé, décommentez cette fonction, elle affichera le graphe sous forme d'image
  //g2.afficherGraphe();


  return 0;
}

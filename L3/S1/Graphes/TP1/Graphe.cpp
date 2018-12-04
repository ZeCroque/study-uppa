#include "Graphe.h"

using namespace std;

Graphe::Graphe()
{
  this->_nbSommet=0;
}

Graphe::Graphe(int nbSommet)
{
  this->_nbSommet=nbSommet;

  this->_matrixLiens.reserve(nbSommet);
  this->_matrixLiens.resize(nbSommet);
  for(int i=0; i<nbSommet; i++)
  {
    this->_matrixLiens[i].reserve(nbSommet);
    this->_matrixLiens[i].resize(nbSommet);
  }
}

void Graphe::ajouterLien(int s1, int s2)
{
  if (s1!=s2 && s1<this->_nbSommet && s2<this->_nbSommet && s1>0 && s2>0)
  {
    this->_matrixLiens[s1-1][s2-1]=true;
  }
  else
  {
    cout<<"Valeur incorrecte."<<endl;
  }

}

void Graphe::afficherGraphe()
{
  ofstream fichier("orig.dot", ios::out | ios::trunc);
  if(fichier)
  {
    fichier<<"digraph graphe {"<<endl;
    for(int i=0; i<this->_nbSommet; i++)
    {
      for(int j=0; j<this->_nbSommet; j++)
      {
        if(this->_matrixLiens[j][i]==true)
        {
          fichier<<"\t"<<j+1<<" -> "<<i+1<<";"<<endl;
        }
      }
    }
    fichier<<"}";
    fichier.close();
    system("dot -Tpng ./orig.dot -Gsize=1,1 -Gdpi=300 -o orig.png");
    system("xdg-open ./orig.png");
  }
  else
  {
    cerr<<"Erreur d'entrée/sortie"<<endl;
  }
}

ostream& operator << (ostream& os, const Graphe& g)
{
  for(int i=0; i<g._nbSommet; i++)
  {
    for(int j=0; j<g._nbSommet; j++)
    {
      os<<g._matrixLiens[j][i]<<" ";
    }
    os<<endl;
  }
  return os;
}

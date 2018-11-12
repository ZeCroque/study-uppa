#include "Graphe.h"

using namespace std;

Graphe::Graphe()
{
  this._nbSommet=0;
  this._vectLiens=new vector<Lien>();
}

Graphe::Graphe(int nbSommet, vector<Lien> vectLiens=new vector<Lien>())
{
  this._nbSommet=nbSommet;
  this._vectLiens=vectLiens;
}

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
  if (s1!=s2 && s1-1<this->_nbSommet && s2-1<this->_nbSommet && s1>0 && s2>0)
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

void Graphe::parcoursHistorique()
{
  int i=0;
  int j=0;
  int k=0;
  int sommet=0;
  int datesDeb[this->_nbSommet]={0};
  int datesFin[this->_nbSommet]={0};
  vector<int> chemin;
  bool arret=false;

  do
  {
    if(datesDeb[sommet]==0)
    {
      i++;
      datesDeb[sommet]=i;
      chemin.push_back(sommet);
    }
    for(j=0; j<this->_nbSommet; j++)
    {
      if(this->_matrixLiens[sommet][j]==true && datesDeb[j]==0)
      {
        break;
      }
    }

    if(j!=this->_nbSommet)
    {
      sommet=j;
    }
    else
    {
      i++;
      datesFin[sommet]=i;
      chemin.pop_back();
      if (chemin.size()>0)
      {

        sommet=chemin[chemin.size()-1];
      }
      else
      {
        for(k=0; k<this->_nbSommet; k++)
        {
          if(datesDeb[k]==0)
          {
            break;
          }
        }
        if(k!=this->_nbSommet)
        {
          sommet=k;
        }
        else
        {
          arret=true;
        }
      }
    }

  } while(!arret);
  for(int l=0;l<this->_nbSommet; l++)
  {
    cout<<(char)('a'+l)<<" deb :"<<datesDeb[l]<<" fin:"<<datesFin[l]<<endl;
  }
}

ostream& operator << (ostream& os, const Graphe& g)
{
  for(int i=0; i<g._nbSommet; i++)
  {
    for(int j=0; j<g._nbSommet; j++)
    {
      os<<g._matrixLiens[i][j]<<" ";
    }
    os<<endl;
  }
  return os;
}

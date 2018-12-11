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

vector<int> Graphe::parcoursHistorique()
{
  int i=0;
  int j=0;
  int k=0;
  int sommet=0;
  vector<int> datesDeb;
  vector<int> datesFin;
  vector<int> chemin;
  bool arret=false;

  datesDeb.reserve(this->_nbSommet);
  datesDeb.resize(this->_nbSommet);
  datesFin.reserve(this->_nbSommet);
  datesFin.resize(this->_nbSommet);

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
  return datesFin;
}

Graphe Graphe::grapheAdjacent()
{
  vector<vector<bool> > matrixAdjacente;
  matrixAdjacente.reserve(this->_nbSommet);
  matrixAdjacente.resize(this->_nbSommet);
  for(int i=0; i<this->_nbSommet; i++)
  {
    matrixAdjacente[i].reserve(this->_nbSommet);
    matrixAdjacente[i].resize(this->_nbSommet);
  }

  for(int i=0; i<this->_nbSommet; i++)
  {
    for(int j=0; j<this->_nbSommet; j++)
    {
      matrixAdjacente[i][j]=this->_matrixLiens[j][i];
    }
  }

  Graphe result(this->_nbSommet);
  result._matrixLiens=matrixAdjacente;
  return result;
}

vector<vector <int> > Graphe::parcoursProfondeur(Graphe adj, vector<int> datesFin)
{
  vector<vector <int> > result;
  vector <int> sommetParcourus;
  int tmp=-1;

  for(int i=0; i<this->_nbSommet; i++)
  {
    sommetParcourus.push_back(datesFin[i]);
    for(int j=0; j<this->_nbSommet; j++)
    {
      if(adj._matrixLiens[datesFin[i]][j])
      {
        for(int k=0; k<sommetParcourus.size(); k++)
        {
          if(j==sommetParcourus[k])
          {
            break;
          }
        }
        if(k==sommetParcourus.size())
        {
          tmp=i;
          i=j-1;
          break;
        }
      }
    }
    if(j==this->_nbSommet && sommetParcourus.size()==1)
    {
      if(tmp!=-1)
      {
        i=tmp;
        tmp=-1;
      }

      result.push_back(sommetParcourus);
      sommetParcourus.erase(0, sommetParcourus.size());
    }
    else if(j!=this->_nbSommet && sommetParcourus.size()!=1)
    {
      i=sommetParcourus[sommetParcourus.size()-3];
    }

  }

  return result;
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

void  triBulle(vector<int>& tab)
{
  int tmp, i, j;
  for (i=0; i<(int)tab.size(); i++)
  {
     for(j=i; j<(int)tab.size(); j++)
     {
       if(tab[j]>tab[i])
       {
         tmp = tab[i];
         tab[i] = tab[j];
         tab[j] = tmp;
       }
     }
   }
}

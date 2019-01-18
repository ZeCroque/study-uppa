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
    system("xdg-open ./orig.png &");
  }
  else
  {
    cerr<<"Erreur d'entrée/sortie"<<endl;
  }
}

vector<vector<int> > Graphe::getStables()
{
  vector<vector<int> > result;
  vector<int> sommetsParcourus;
  vector<int> stable;

  while((int)sommetsParcourus.size()!=this->_nbSommet)
  {
    //DEBUG cout<<"\n===NOUVEAU STABLE==="<<endl<<endl;
    for(int i=0; i<this->_nbSommet; i++)
    {
      if(!contains(sommetsParcourus, i))
      {
        sommetsParcourus.push_back(i);
        stable.push_back(i);
        break;
      }
    }

    for(int i=0; i<this->_nbSommet; i++)
    {
      int count=0;
      //DEBUG cout<<"\ni :"<<i+1<<"\t";

      for(int j=0; j<(int)stable.size(); j++)
      {
        //DEBUG cout<<"j :"<<stable[j]+1<<"\t";
        if(!this->_matrixLiens[stable[j]][i] && stable[j]!=i)
        {
          if(!this->_matrixLiens[i][stable[j]])
          {
            count++;
          }
        }
      }
      //DEBUG cout<<endl;
      if(count==(int)stable.size())
      {
        if(!contains(sommetsParcourus, i))
        {
          //DEBUG cout<<i+1<<" est dans le stable"<<endl;
          sommetsParcourus.push_back(i);
          stable.push_back(i);
        }
        /*DEBUG else
        {
          cout<<i+1<<" n'est pas dans le stable"<<endl;
        }*/
      }
      /*DEBUG else
      {
        cout<<i+1<<" n'est pas dans le stable"<<endl;
      }*/

    }
    result.push_back(stable);
    /*DEBUG cout<<"\n\nstable: ";
    for(int i=0; i<stable.size(); i++)
    {
      cout<<stable[i]+1<<" ";
    }
    cout<<endl<<endl;*/
    stable.clear();
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

//Retourne si oui ou non, l'élément e se trouve dans le tableau tab
bool contains(vector<int> tab, int e)
{
  for(int i=0; i<(int)tab.size(); i++)
  {
    if(tab[i]==e)
    {
      return true;
    }
  }
  return false;
}
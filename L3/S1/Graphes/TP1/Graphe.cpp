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

vector<pair<int, int> > Graphe::parcoursHistorique()
{
  int i=0, j=0, k=0, sommet=0;
  vector<int> datesDeb;
  vector<pair<int, int> > datesFin;
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
      datesFin[sommet].second=i;
      datesFin[sommet].first=sommet;
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

vector<vector <int> > Graphe::parcoursProfondeur(Graphe adj, vector<pair<int,int> > datesFin)
{
  vector<vector <int> > result;
  vector <int> sommetParcourus;
  vector <int> sommetResultats;
  bool alreadyBrowsed;
  int i=0,sommetParcourusCount=0;


  //Tant que l'on a pas parcourus tous les sommets
  while(sommetParcourusCount!=(int)datesFin.size())
  {

    //Ajout du sommet au tableau temporaire et au tableau résultat, s'il n'y est pas déjà
    //Incrémentation du compteur de sommet parcourus le cas échéant
    if(!contains(sommetResultats,datesFin[i].first))
    {
      sommetParcourusCount++;
      sommetResultats.push_back(datesFin[i].first);
      sommetParcourus.push_back(datesFin[i].first);
    }

    //Elimination des liens qui vont au sommet
    for(int j=0; j<this->_nbSommet; j++)
    {
      adj._matrixLiens[j][datesFin[i].first]=false;
    }

    //Parcours de tous les sommets du graphes
    alreadyBrowsed=true;
    for(int j=0; j<this->_nbSommet; j++)
    {
      //Si un lien part de ce sommet
      if(adj._matrixLiens[datesFin[i].first][j])
      {
        //On vérifie si la cible du lien a déjà été visitée
        alreadyBrowsed=contains(sommetResultats, j);
        if(!alreadyBrowsed)
        {
          //On assigne i à l'index de la cible dans le tableau datesFin et on quitte la boucle
          i=getElementIndex(datesFin,j);
          break;
        }
      }
    }

    //Si l'on ne trouve pas de cible valide
    if(alreadyBrowsed)
    {
      //Si c'est un graphe unaire on ajoute nos sommets au résultat, on clear nos tableaux et on recommence pour la datesFin suivante
      if(sommetParcourus.size()==1)
      {
        result.push_back(sommetResultats);
        sommetParcourus.clear();
        sommetResultats.clear();
        i++;
      }
      //Sinon on revient en arrière d'un cran pour chercher d'autres liens sur le sommet d'avant
      else
      {
        sommetParcourus.pop_back();
        i=getElementIndex(datesFin,sommetParcourus[sommetParcourus.size()-1]);
      }
    }
  }

  //On ajoute notre dernier résultat et on return
  result.push_back(sommetResultats);
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

void  triBulle(vector<pair<int, int> >& tab)
{
  int i, j;
  pair<int, int> tmp;
  for (i=0; i<(int)tab.size(); i++)
  {
     for(j=i; j<(int)tab.size(); j++)
     {
       if(tab[j].second>tab[i].second)
       {
         tmp=tab[i];
         tab[i] = tab[j];
         tab[j] = tmp;
       }
     }
   }
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

//Retourne l'index de l'élément e dans le tableau tab, en ne cherchant que dans la clé de la paire
//-1 si l'élément n'est pas dans le tableau
int getElementIndex(vector<pair<int, int> > tab, int e)
{
  for(int i=0; i<(int)tab.size(); i++)
  {
    if(tab[i].first==e)
    {
      return i;
    }
  }
  return -1;
}
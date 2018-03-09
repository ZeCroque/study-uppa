#include <iostream>
#include "voiture.h"
#include "personne.h"
#include <string>

using namespace std;

Voiture::Voiture()
{
  this->marque="Vide";
  this->modele="Vide";
  this->nbUtilisateurs=0;
}

Voiture::Voiture(string marque, string modele)
{
  this->marque=marque;
  this->modele=modele;
  this->nbUtilisateurs=0;
}

Voiture::~Voiture()
{

}

void Voiture::ajouterPassager(Personne p)
{
  if(this->nbUtilisateurs<5)
  {
        this->utilisateurs[this->nbUtilisateurs]=p;
        this->nbUtilisateurs++;
  }
  else
  {
    cout<<"Vous ne pouvez ajouter plus d'utilisateurs"<<endl;
  }
}

void Voiture::afficherPassager()
{
  for(int i=0; i<this->nbUtilisateurs; i++)
  {
    utilisateurs[i].afficher();
  }
}

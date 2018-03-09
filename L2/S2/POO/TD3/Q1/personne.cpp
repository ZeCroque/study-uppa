#include <iostream>
#include <string>
#include "personne.h"

using namespace std;

Personne::Personne()
{
  this->nom="Vide";
  this->prenom="Vide";
}

Personne::Personne(string nom, string  prenom)
{
  this->nom=nom;
  this->prenom=prenom;
}

void Personne::afficher()
{
  cout<<"Nom : "<<nom<<endl;
  cout<<"Prénom : "<<prenom<<endl;
}

void Personne::saisir(string nom, string  prenom)
{
  this->nom=nom;
  this->prenom=prenom;
}

void Personne::raz()
{
  this->nom="Vide";
  this->prenom="Vide";
}

string Personne::getNom()
{
  return nom;
}

string Personne::getPrenom()
{
  return prenom;
}

Personne::~Personne()
{

}

Personne& Personne::operator = (const Personne a )
{
  this->nom=a.nom;
  this->prenom=a.prenom;
  return *this;
}

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

Personne::Personne(const Personne& p)
{
  (*this)=p;
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


void Personne::afficher()
{
  cout<<"Nom : "<<nom<<endl;
  cout<<"Prénom : "<<prenom<<endl;
}

string Personne::getNom()
{
  return nom;
}

string Personne::getPrenom()
{
  return prenom;
}

void Personne::setNom(std::string s)
{
  this->nom=s;
}
void Personne::setPrenom(std::string s)
{
  this->prenom=s;
}

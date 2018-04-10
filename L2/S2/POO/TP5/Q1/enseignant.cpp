#include "enseignant.h"
#include <iostream>

Enseignant::Enseignant() : Personne()
{

}

Enseignant::Enseignant(std::string nom, std::string prenom, std::string metier) : Personne(nom, prenom)
{
  this->_metier=metier;
}

Enseignant::Enseignant(const Enseignant& e)
{
 *this=e;
}

Enseignant::~Enseignant()
{

}

Enseignant& Enseignant::operator = (const Enseignant& e)
{
  this->Personne::operator = (e);
  this->_metier=e._metier;
  return (*this);
}

void Enseignant::setMetier(std::string m)
{
  this->_metier=m;
}

std::string Enseignant::getMetier()
{
  return this->_metier;
}

void Enseignant::afficher()
{
  this->Personne::afficher();
  std::cout<<"Enseignant qui a pour métier : "<<this->_metier<<std::endl;
}

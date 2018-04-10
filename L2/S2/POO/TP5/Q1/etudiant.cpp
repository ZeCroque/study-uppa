#include "etudiant.h"
#include <iostream>

Etudiant::Etudiant() : Personne()
{

}

Etudiant::Etudiant(std::string nom, std::string prenom, int code) : Personne(nom, prenom)
{
  this->_code=code;
}

Etudiant::Etudiant(const Etudiant& e)
{
 *this=e;
}

Etudiant::~Etudiant()
{

}

Etudiant& Etudiant::operator = (const Etudiant& e)
{
  this->Personne::operator = (e);
  this->_code=e._code;
  return (*this);
}

void Etudiant::setCode(int c)
{
  this->_code=c;
}

int Etudiant::getCode()
{
  return this->_code;
}

void Etudiant::afficher()
{
  this->Personne::afficher();
  std::cout<<"Etudiant qui a pour code : "<<this->_code<<std::endl;
}

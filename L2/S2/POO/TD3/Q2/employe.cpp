#include "employe.h"
#include <iostream>

using namespace std;

Employe::Employe() : Personne()
{
  this->_codeId=-1;
}

Employe::Employe(std::string nom, std::string  prenom) : Personne(nom, prenom)
{
  this->_codeId=-1;
}

Employe::Employe(std::string metier, int codeId)
{
  this->_metier=metier;
  this->_codeId=codeId;
}

Employe::Employe(std::string nom, std::string  prenom, std::string metier, int codeId) : Personne(nom, prenom)
{
  this->_metier=metier;
  this->_codeId=codeId;
}

int Employe::getId()
{
  return _codeId;
}

string Employe::getMetier()
{
  return _metier;
}

void Employe::travailler()
{
  this->afficher();
  cout<<"Mon identifant est : "<<this->_codeId<<"\nJe suis employé et mon métier est : "<<this->_metier<<endl;
}

bool Employe::operator == (const Employe& e)
{
  return this->_metier==e._metier && this->_codeId==e._codeId && this->nom==e.nom && this->prenom==e.prenom;
}

bool Employe::operator != (const Employe& e)
{
  return !(this->_metier==e._metier && this->_codeId==e._codeId && this->nom==e.nom && this->prenom==e.prenom);
}

#include "produit.h"

Produit::Produit()
{
  this->_code=0;
  this->_nom="Aucun";
  std::cout<<"Constructeur!"<<std::endl;
}

Produit::Produit(const Produit& p)
{
  (*this)=p;
}

Produit::~Produit()
{
    std::cout<<"Destructeur!"<<std::endl;
}

Produit& Produit::operator = (const Produit& p)
{
  this->_code=p._code;
  this->_nom=p._nom;
  return (*this);
}

void Produit::setCode(int code)
{
  this->_code=code;
}

void Produit::setNom(std::string nom)
{
  this->_nom=nom;
}

int Produit::getCode() const
{
  return this->_code;
}

std::string Produit::getNom() const
{
  return this->_nom;
}

std::ostream& operator << (std::ostream& os, const Produit& p)
{
  os<<"Nom : "<<p.getNom()<<"\nCode : "<<p.getCode()<<std::endl;
  return os;
}

//lol

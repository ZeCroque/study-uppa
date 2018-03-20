#include "adresse.h"
#include <string>

using namespace std;

Adresse::Adresse()
{
  this->_rue="Aucun";
  this->_ville="Aucun";
  this->_CP="Aucun";
  this->_numero=0;
}

Adresse::Adresse(string rue, string ville, string CP, int numero)
{
  this->_rue=rue;
  this->_ville=ville;
  this->_CP=CP;
  this->_numero=numero;
}

Adresse::Adresse(const Adresse& a)
{
  *this=a;
}

Adresse::~Adresse()
{

}

Adresse& Adresse::operator = (const Adresse& a)
{
  this->_rue=a._rue;
  this->_ville=a._ville;
  this->_CP=a._CP;
  this->_numero=a._numero;
  return *this;
}

bool Adresse::operator == (const Adresse& a)
{
  if (this->_rue==a._rue && this->_ville==a._ville && this->_CP==a._CP && this->_numero==a._numero)
  {
    return true;
  }
  return false;
}

string Adresse::getRue() const
{
  return this->_rue;
}

string Adresse::getVille() const
{
  return this->_ville;
}

string Adresse::getCP() const
{
  return this->_CP;
}

int Adresse::getNumero() const
{
  return this->_numero;
}

ostream& operator << (ostream& os, const Adresse& a)
{
  return os<<a.getNumero()<<" Rue "<<a.getRue()<<"\n"<<a.getCP()<<" "<<a.getVille()<<endl;
}

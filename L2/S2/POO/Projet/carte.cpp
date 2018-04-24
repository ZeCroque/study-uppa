#include "carte.h"

using namespace std;

Carte::Carte()
{
  this->_famille=0;
  this->_valeur=0;
}

Carte::Carte(const Carte& c)
{
  *this=c;
}

Carte::Carte(int valeur, int famille)
{
  this->_famille=famille;
  this->_valeur=valeur;
}

Carte::~Carte()
{

}

int Carte::getValeur() const
{
  return this->_valeur;
}

int Carte::getFamille() const
{
  return this->_famille;
}

Carte& Carte::operator = (const Carte& c)
{
  this->_famille=c._famille;
  this->_valeur=c._valeur;
  return *this;
}

ostream& operator << (ostream& os, const Carte& c)
{
  switch(c._valeur)
  {
    case 0 :
      break;
    case 1 :
      os<<"As de ";
      break;
    case 11 :
      os<<"Valet de ";
      break;
    case 12 :
      os<<"Dame de ";
      break;
    case 13 :
      os<<"Roi de ";
      break;
    default :
      os<<c._valeur<<" de ";
      break;
  }
  switch (c._famille)
  {
    case 0 :
      break;
    case 1 :
      os<<"Trèfle";
      break;
    case 2 :
      os<<"Pique";
      break;
    case 3 :
      os<<"Carreau";
      break;
    case 4 :
      os<<"Coeur";
      break;
    default :
      os<<"Erreur";
      break;
  }
  return os;
}

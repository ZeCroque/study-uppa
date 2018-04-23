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
    case 1 :
      os<<"As";
      break;
    case 11 :
      os<<"Valet";
      break;
    case 12 :
      os<<"Dame";
      break;
    case 13 :
      os<<"Roi";
      break;
    default :
      os<<c._valeur;
      break;
  }
  os<<" de ";
  switch (c._famille)
  {
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
  return os<<endl;
}

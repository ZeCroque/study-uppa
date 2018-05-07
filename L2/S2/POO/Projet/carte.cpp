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

string Carte::afficherFamille() const
{
  switch (this->_famille)
  {
    case 0 :
      return "Debug";
      break;
    case 1 :
      return "Trèfle";
      break;
    case 2 :
      return "Pique";
      break;
    case 3 :
      return "Carreau";
      break;
    case 4 :
      return "Coeur";
      break;
    default :
      return "Erreur";
      break;
  }
}

string Carte::afficherValeur() const
{
  stringstream ss;
  switch(this->_valeur)
  {
    case 0 :
      ss<<"Joker";
      break;
    case 1 :
      ss<<"As";
      break;
    case 11 :
      ss<<"Valet";
      break;
    case 12 :
      ss<<"Dame";
      break;
    case 13 :
      ss<<"Roi";
      break;
    default :
      ss<<this->_valeur;
      break;
  }
  return ss.str();
}



ostream& operator << (ostream& os, const Carte& c)
{
  os<<c.afficherValeur()<<" de "<<c.afficherFamille();
  return os;
}

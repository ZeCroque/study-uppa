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

void Carte::afficherCouleur()
{
  switch (this->_famille)
  {
    case 0 :
      cout<<"Debug";
      break;
    case 1 :
      cout<<"Trèfle";
      break;
    case 2 :
      cout<<"Pique";
      break;
    case 3 :
      cout<<"Carreau";
      break;
    case 4 :
      cout<<"Coeur";
      break;
    default :
      cout<<"Erreur";
      break;
  }
}

void Carte::afficherValeur()
{
  switch(this->_valeur)
  {
    case 0 :
      cout<<"Joker";
      break;
    case 1 :
      cout<<"As";
      break;
    case 11 :
      cout<<"Valet";
      break;
    case 12 :
      cout<<"Dame";
      break;
    case 13 :
      cout<<"Roi";
      break;
    default :
      cout<<this->_valeur;
      break;
  }
}



ostream& operator << (ostream& os, const Carte& c)
{
  switch(c._valeur)
  {
    case 0 :
      os<<"Joker de ";
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
      os<<"Debug";
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

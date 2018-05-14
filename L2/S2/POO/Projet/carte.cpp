#include "carte.h"

using namespace std;

//Forme canonique de coplien
Carte::Carte()
{
  this->_famille=0;
  this->_valeur=0;
}

Carte::Carte(const Carte& c)
{
  *this=c;
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



//Constructeur surchargé instantiant la carte à la bonne valeur et famille
Carte::Carte(int valeur, int famille)
{
  this->_famille=famille;
  this->_valeur=valeur;
}

//Retourne la valeur de la carte
int Carte::getValeur() const
{
  return this->_valeur;
}

//Retourne la famille de la carte
int Carte::getFamille() const
{
  return this->_famille;
}

//Renvoie un string correspondant à la famille de la carte
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


//Renvoie un string correspondant à la valeur de la carte
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

//Affichage
ostream& operator << (ostream& os, const Carte& c)
{
  os<<c.afficherValeur()<<" de "<<c.afficherFamille();
  return os;
}

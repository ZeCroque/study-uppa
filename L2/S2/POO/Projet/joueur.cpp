#include "joueur.h"

using namespace std;

//Forme canonique de coplien

Joueur::Joueur()
{
  this->_nom="";
  this->_main.resize(2);
}

Joueur::Joueur(const Joueur& j)
{
  *this=j;
}

Joueur::~Joueur()
{

}

Joueur& Joueur::operator = (const Joueur& j)
{
  this->_nom=j._nom;
  this->_main=j._main;
  return *this;
}

//Constructeur surchargé initialisant avec le nom
Joueur::Joueur(string nom)
{
  this->_nom=nom;
  this->_main.resize(2);
}

//Pioche 2 cartes dans le deck passé en paramètre
//Les ajoute à la main du joueur
void Joueur::draw(Deck& deck)
{
  for (int i=0; i<2; i++)
  {
    this->_main[i]=deck.draw();
  }
}

//Renvoie la main du joueur
Vecteur<Carte> Joueur::getMain() const
{
  return this->_main;
}

//Affichage
ostream& operator << (ostream& os, const Joueur& j)
{
  os<<j._nom<<"\nMAIN :"<<endl;
  for(int i=0; i<j._main.size(); i++)
  {
    os<<j._main[i]<<endl;
  }
  return os;
}

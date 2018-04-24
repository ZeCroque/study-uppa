#include "joueur.h"

using namespace std;

Joueur::Joueur()
{
  this->_nom="";
  this->_main.resize(2);
}

Joueur::Joueur(string nom)
{
  this->_nom=nom;
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

void Joueur::draw(Deck& deck)
{
  for (int i=0; i<2; i++)
  {
    this->_main[i]=deck.draw();
  }
}

Vecteur<Carte> Joueur::getMain() const
{
  return this->_main;
}

ostream& operator << (ostream& os, const Joueur& j)
{
  os<<j._nom<<"\nMain :\n";
  for(int i=0; i<j._main.size(); i++)
  {
    os<<j._main[i]<<endl;
  }
  return os;
}

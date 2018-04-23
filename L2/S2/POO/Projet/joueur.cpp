#include "joueur.h"

Joueur::Joueur()
{

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
  this->main=j.main;
  return *this;
}

#include "carte.h"

Carte::Carte()
{
  this->famille=' ';
  this->valeur=0;
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
  this->famille=c.famille;
  this->valeur=c.valeur;
  return *this;
}

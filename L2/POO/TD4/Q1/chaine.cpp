#include "chaine.h"

Chaine::Chaine()
{
  this->_tab=new char[DEFAULT_SIZE];
  this->_size=DEFAULT_SIZE;
  this->_length=0;
}

Chaine::Chaine(const Chaine& c)
{

}

Chaine::~Chaine()
{

}

Chaine& Chaine::operator = (const Chaine& c)
{

}

void Chaine::setText(char* c)
{

}

char* Chaine::getText()
{
  return this->_tab;
}

void Chaine::affiche()
{
  
}

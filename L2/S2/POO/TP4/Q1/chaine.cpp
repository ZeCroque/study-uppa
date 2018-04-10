#include "chaine.h"
#include <iostream>
#include <string.h>

Chaine::Chaine()
{
  this->_tab=new char[DEFAULT_SIZE];
  this->_size=DEFAULT_SIZE;
  this->_length=0;
}

Chaine::Chaine(const Chaine& c)
{
  this->_size=c._size;
  this->_tab=new char[this->_size];
  for(int i=0; i<c._length; i++)
  {
    this->_tab[i]=c._tab[i];
  }
  this->_length=c._length;
}

Chaine::~Chaine()
{

}

Chaine& Chaine::operator = (const Chaine& c)
{
  delete[] this->_tab;
  this->_size=c._size;
  this->_tab=new char[this->_size];
  for(int i=0; i<c._length; i++)
  {
    this->_tab[i]=c._tab[i];
  }
  this->_length=c._length;
  return (*this);
}

void Chaine::setText(char* c)
{
  delete[] this->_tab;
  this->_size=strlen(c);
  this->_length=this->_size;
  this->_tab=new char[this->_size];
  for(int i=0; i<this->_length; i++)
  {
    this->_tab[i]=c[i];
  }

}

char* Chaine::getText()
{
  return this->_tab;
}

void Chaine::affiche()
{
  std::cout<<this->_tab<<std::endl;
}

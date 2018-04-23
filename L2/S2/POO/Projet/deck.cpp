#include "deck.h"
#include <iostream>
#include <stdlib.h>


using namespace std;

Deck::Deck()
{
  //Génère le jeu de 52 de cartes, triées dans l'ordre
  for(int i=1, j=1; j<5; i++)
  {
    this->_deck.push_back(Carte(i,j));
    if (i%13==0)
    {
      i=0;
      j++;
    }
  }

  //Le mélange
  this->shuffle();
}

Deck::Deck(const Deck& j)
{
  *this=j;
}

Deck::~Deck()
{

}

Deck& Deck::operator = (const Deck& j)
{
  this->_deck=j._deck;
  return *this;
}

void Deck::shuffle()
{
  Carte cTmp;
  int iRandom;

  for(unsigned int i=0; i<this->_deck.size(); i++)
  {
    iRandom=rand() % (this->_deck.size()-1);
    cTmp=this->_deck[i];
    this->_deck[i]=this->_deck[iRandom];
    this->_deck[iRandom]=cTmp;
  }
}

Carte Deck::draw()
{
  Carte cTmp=this->_deck[this->_deck.size()-1];
  this->_deck.pop_back();
  return cTmp;
}

std::ostream& operator << (std::ostream& os, const Deck& c)
{
  for(unsigned int i=0; i<c._deck.size(); i++)
  {
    os<<c._deck[i];
  }
  return os;
}

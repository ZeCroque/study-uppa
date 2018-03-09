#include "stock.h"

Stock::Stock()
{
  this->_iMax=0;
}

Stock::Stock(const Stock& s)
{
  (*this)=s;
}

Stock::~Stock()
{

}

Stock& Stock::operator = (const Stock& s)
{
  this->_iMax=s._iMax;

  for(int i=0;i<this->_iMax; i++)
  {
    this->_tab[i]=s._tab[i];
  }

  return *this;
}

void Stock::ajouterProduit(Produit& p)
{
  if (this->_iMax!=TAILLE)
  {
    this->_tab[this->_iMax]=p;
    this->_iMax++;
  }
  else
  {
    std::cout<<"Vous ne pouvez entrer plus de produits"<<std::endl;
  }
}

void Stock::afficherProduits()
{
  for(int i=0;i<this->_iMax; i++)
  {
    std::cout<<this->_tab[i]<<std::endl;
  }
}

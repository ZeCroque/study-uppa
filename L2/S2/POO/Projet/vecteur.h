#ifndef vecteur_h
#define vecteur_h

#include <iostream>
#include <stdlib.h>

using namespace std;

template <class Type> class Vecteur
{
  private:
    Type* _tab;
    int _size;
  public:
    Vecteur();
    Vecteur(const Vecteur<Type>& v);
    ~Vecteur();
    Vecteur<Type>& operator = (const Vecteur<Type>& v);
    Type operator [] (const int index);
    void push_back(Type t);
    void pop_back();
};

template <class Type> Vecteur<Type>::Vecteur()
{
  this->_tab=NULL;
  this->_size=0;
}

template <class Type> Vecteur<Type>::Vecteur(const Vecteur<Type>& v)
{
  *this=v;
}

template <class Type> Vecteur<Type>::~Vecteur()
{
  delete[] this->_tab;
}

template <class Type> Vecteur<Type>& Vecteur<Type>::operator = (const Vecteur<Type>& v)
{
  this->_tab=v._tab;
  this->_size=v._size;
  return *this;
}

template <class Type> Type Vecteur<Type>::operator [] (const int index)
{
  if (index<this->_size)
  {
    return this->_tab[index];
  }
  cout<<"Index hors tableau!"<<endl;
  //TODO Try/catch block
  exit(-1);
}

template <class Type> void Vecteur<Type>::push_back(Type t)
{
  if(this->_tab==NULL)
  {
    this->_tab=new Type();
    *(this->_tab)=t;
  }
  //TODO implementer les deux fonctions
}

template <class Type> void Vecteur<Type>::pop_back()
{

}

#endif

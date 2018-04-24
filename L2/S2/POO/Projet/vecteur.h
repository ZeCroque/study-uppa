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
    Type operator [] (int index) const;
    Type& operator [] (int index);
    void resize(int n);
    void push_back(Type t);
    Type pop_back();
    int size() const;
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

}

template <class Type> Vecteur<Type>& Vecteur<Type>::operator = (const Vecteur<Type>& v)
{
  this->_tab=v._tab;
  this->_size=v._size;
  return *this;
}

template <class Type> Type Vecteur<Type>::operator [] (int index) const
{
  if (index<this->_size)
  {
    return this->_tab[index];
  }
  cout<<"Index hors tableau!"<<endl;
  //TODO Try/catch block
  exit(-1);
}

template <class Type> Type& Vecteur<Type>::operator [] (int index)
{
  if (index<this->_size)
  {
    return this->_tab[index];
  }
  cout<<"Index hors tableau!"<<endl;
  //TODO Try/catch block
  exit(-1);
}

template <class Type> void Vecteur<Type>::resize(int n)
{
  if(this->_tab!=NULL)
  {
    Type* tmp=this->_tab;
    this->_tab=new Type[n];
    if(this->size()<n)
    {
      for(int i=0; i<this->size(); i++)
      {
        this->_tab[i]=tmp[i];
      }
    }
    else
    {
      for(int i=0; i<n; i++)
      {
        this->_tab[i]=tmp[i];
      }
    }
    this->_size=n;
    delete[] tmp;
  }
  else
  {
    this->_tab=new Type[n];
    this->_size=n;
  }

}

template <class Type> void Vecteur<Type>::push_back(Type t)
{
  if(this->_tab==NULL)
  {
    this->_tab=new Type[1];
    *(this->_tab)=t;
  }
  else
  {
    Type* tmp=this->_tab;
    this->_tab=new Type[this->_size+1];
    for(int i=0; i<this->_size; i++)
    {
      this->_tab[i]=tmp[i];
    }
    this->_tab[this->_size]=t;
    delete[] tmp;
  }
  this->_size++;
}

template <class Type> Type Vecteur<Type>::pop_back()
{
  Type t;
  if(this->_tab!=NULL)
  {
    Type* tmp=this->_tab;
    this->_size--;
    this->_tab=new Type[this->_size];
    for(int i=0; i<this->_size; i++)
    {
      this->_tab[i]=tmp[i];
    }
    t=tmp[this->_size];
    delete[] tmp;

  }
  return t;
}

template <class Type> int Vecteur<Type>::size() const
{
  return this->_size;
}

#endif

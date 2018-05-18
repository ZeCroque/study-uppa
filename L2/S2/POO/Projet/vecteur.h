#ifndef vecteur_h
#define vecteur_h

#ifndef OOR_ERROR
#define OOR_ERROR -1
#endif

#include <iostream>

using namespace std;

//Implémentation maison de la classe vecteur
template <class Type> class Vecteur
{
  private:
    //Tableau contenant les éléments
    Type* _tab;

    //Taille du tableau
    int _size;
  public:
    //Forme canonique de coplien
    Vecteur();
    Vecteur(const Vecteur<Type>& v);
    ~Vecteur();
    Vecteur<Type>& operator = (const Vecteur<Type>& v);

    //Accès à l'élément à l'index donné
    //Lecture seule
    Type operator [] (int index) const;

    //Accès à l'élément à l'index donné
    //Ecriture
    Type& operator [] (int index);

    //Redimensionne le tableau à la taille donnée
    void resize(int n);

    //Agrandit le tableau et ajoute l'élément à la fin
    void push_back(Type t);

    //Rétrécit le tableau en enlevant le dernier élément et en le retournant
    Type pop_back();

    //Retourne la taille du tableau
    int size() const;
};

//Forme canonique de coplien
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


//Accès à l'élément à l'index donné
//Lecture seule
template <class Type> Type Vecteur<Type>::operator [] (int index) const
{
  try
  {
    if (index>=this->_size)
    {
      throw OOR_ERROR;
    }
  }
  catch(int errorcode)
  {
    cout<<"Index hors tableau!"<<endl;
  }
  return this->_tab[index];

}

//Accès à l'élément à l'index donné
//Ecriture
template <class Type> Type& Vecteur<Type>::operator [] (int index)
{
  try
  {
    if (index>=this->_size)
    {
      throw OOR_ERROR;
    }
  }
  catch(int errorcode)
  {
    cout<<"Index hors tableau!"<<endl;
  }
  return this->_tab[index];
}

//Redimensionne le tableau à la taille donnée
template <class Type> void Vecteur<Type>::resize(int n)
{
  //Si le vecteur a déjà été initialisé
  if(this->_tab!=NULL)
  {
    //On affecte le tableau pointé sur un pointeur tampon
    Type* tmp=this->_tab;
    //On déclare un nouveau tableau à la taille souhaitée
    this->_tab=new Type[n];
    //Si la taille du premier tableau et inférieur à la taille demandée
    if(this->size()<n)
    {
      //On remplit le nouveau tableau avec les valeurs de l'ancier
      for(int i=0; i<this->size(); i++)
      {
        this->_tab[i]=tmp[i];
      }
    }
    //Sinon
    else
    {
      //On remplit le nouveau tableau en excluant les derniers éléments
      for(int i=0; i<n; i++)
      {
        this->_tab[i]=tmp[i];
      }
    }
    //On change la taille
    this->_size=n;
    //On supprime l'ancien tableau
    delete[] tmp;
  }
  //Si le vecteur n'est pas iniatialisé
  else
  {
    //On l'initialise à la taille donné
    this->_tab=new Type[n];
    this->_size=n;
  }

}

//Agrandit le tableau et ajoute l'élément à la fin
template <class Type> void Vecteur<Type>::push_back(Type t)
{
  //Si le vecteur n'est pas initialisé
  if(this->_tab==NULL)
  {
    //On l'initialise avec une taille de 1
    this->_tab=new Type[1];
    //On ajoute l'élément
    *(this->_tab)=t;
  }
  //Sinon
  else
  {
    //On affecte le tableau pointé sur un pointeur tampon
    Type* tmp=this->_tab;
    //On déclare un nouveau tableau à la taille+1
    this->_tab=new Type[this->_size+1];
    //On recopie les valeurs de l'ancien tableau
    for(int i=0; i<this->_size; i++)
    {
      this->_tab[i]=tmp[i];
    }
    //On ajoute l'élément en fin de tableau
    this->_tab[this->_size]=t;
    //On supprime l'ancien tableau
    delete[] tmp;
  }
  //On incrément la taille
  this->_size++;
}

//Rétrécit le tableau en enlevant le dernier élément et en le retournant
template <class Type> Type Vecteur<Type>::pop_back()
{
  //Tampon contenant la dernière valeur du tableu
  Type t;
  //Si le tableau a été initialisé
  if(this->_tab!=NULL)
  {
    //On affecte le tableau pointé sur un pointeur tampon
    Type* tmp=this->_tab;
    //On décrémente la taille
    this->_size--;
    //On déclare un nouveau tableau à la taille-1
    this->_tab=new Type[this->_size];
    //On remplit le nouveau tableau en excluant les derniers éléments
    for(int i=0; i<this->_size; i++)
    {
      this->_tab[i]=tmp[i];
    }
    //On affecte au tampon la dernière valeur de l'ancien tableau
    t=tmp[this->_size];
    //On supprime l'ancien tampon
    delete[] tmp;
  }
  //On renvoie l'élément supprimé
  //Ou un élément par défaut si le vecteur était vide
  return t;
}

//Retourne la taille du tableau
template <class Type> int Vecteur<Type>::size() const
{
  return this->_size;
}

#endif

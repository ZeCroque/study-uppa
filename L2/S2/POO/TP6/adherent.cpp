#include "adherent.h"

using namespace std;

Adherent::Adherent()
{
  this->_nom="Aucun";
  this->_prenom="Aucun";
  this->_id="Aucun";
  this->_age=0;
  this->_adresse=Adresse();
  this->_nbExemplairesEmprunte=0;
  for(int i=0; i<3; i++)
  {
    this->_exemplaireTab[i]=NULL;
  }
}

Adherent::Adherent(string nom, string prenom, string id, int age, string rue, string ville, string CP, int numero)
{
  this->_nom=nom;
  this->_prenom=prenom;
  this->_id=id;
  this->_age=age;
  this->_adresse=Adresse(rue, ville, CP, numero);
  this->_exemplaireTab=new Exemplaire*[3];
  this->_nbExemplairesEmprunte=0;
  for(int i=0; i<3; i++)
  {
    this->_exemplaireTab[i]=NULL;
  }
}

Adherent::Adherent(const Adherent& a)
{
  *this=a;
}

Adherent::~Adherent()
{

}

Adherent& Adherent::operator = (const Adherent& a)
{
  this->_nom=a._nom;
  this->_prenom=a._prenom;
  this->_id=a._id;
  this->_age=a._age;
  this->_adresse=a._adresse;
  this->_exemplaireTab=a._exemplaireTab;
  this->_nbExemplairesEmprunte=a._nbExemplairesEmprunte;
  return *this;
}

bool Adherent::operator == (const Adherent& a)
{
  if (this->_nom==a._nom && this->_prenom==a._prenom && this->_id==a._id && this->_age==a._age && this->_adresse==a._adresse &&   this->_exemplaireTab==a._exemplaireTab && this->_nbExemplairesEmprunte==a._nbExemplairesEmprunte)
  {
    return true;
  }
  return false;
}

void Adherent::addExemplaire(const Exemplaire e)
{
  if (this->_nbExemplairesEmprunte<3)
  {
    this->_exemplaireTab[this->_nbExemplairesEmprunte]=new Exemplaire();
    (*this->_exemplaireTab[this->_nbExemplairesEmprunte])=e;
    this->_nbExemplairesEmprunte++;
  }
  else
  {
    cout<<"Vous ne pouvez emprunter plus de trois exemplaires."<<endl;
  }
}

void Adherent::removeExemplaire(const Exemplaire e)
{
  for (int i=0; i<this->_nbExemplairesEmprunte; i++)
  {
    if (*(this->_exemplaireTab[i])==e)
    {
      this->_exemplaireTab[i]=NULL;
      if(i!=this->_nbExemplairesEmprunte-1)
      {
        for(int j=i+1; j<this->_nbExemplairesEmprunte; j++)
        {
          this->_exemplaireTab[j-1]=this->_exemplaireTab[j];
        }
      }
      this->_nbExemplairesEmprunte--;
    }
  }
}

void Adherent::afficheExemplaire(int i)
{
  if (i<this->_nbExemplairesEmprunte)
  {
    cout<<this->_exemplaireTab[i]->getRef()<<endl;
  }
  else
  {
    cout<<"Vous essayez d'accéder à un champ vide."<<endl;
  }
}

string Adherent::getNom() const
{
  return this->_nom;
}
string Adherent::getPrenom() const
{
    return this->_prenom;
}

string Adherent::getId() const
{
  return this->_id;
}

int Adherent::getAge() const
{
  return this->_age;
}

Adresse Adherent::getAdresse() const
{
  return this->_adresse;
}

ostream& operator << (ostream& os, const Adherent& a)
{
  return os<<a.getNom()<<"\n"<<a.getPrenom()<<"\n"<<a.getId()<<"\n"<<a.getAge()<<" ans\n"<<a.getAdresse()<<endl;
}

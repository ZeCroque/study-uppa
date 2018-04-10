#include "gestionfichier.h"

using namespace std;

GestionFichier::GestionFichier()
{
  this->_nom="";
}

GestionFichier::GestionFichier(std::string nom)
{
  this->_nom=nom;
}

GestionFichier::GestionFichier(GestionFichier& g)
{
  *this=g;
}

GestionFichier::~GestionFichier()
{

}

GestionFichier& GestionFichier::operator = (const GestionFichier& g)
{
  this->_nom=g._nom;
  return *this;
}

void GestionFichier::lireFichier(std::string** tab, int nbElt)
{
  ifstream fichier(this->_nom.c_str());
  char c;

  delete[] *tab;
  *tab = new string(nbElt, ' ');


  for(int i=0; i<nbElt && fichier.get(c); i++)
  {
    *tab[i]=c;
  }
  fichier.close();
}

void GestionFichier::enregistrerFichier(const std::string* tab, const int nbElt)
{
  ofstream fichier(this->_nom.c_str());
  for (int i=0; i<nbElt; i++)
  {
    fichier<<tab[i];
  }
  fichier.close();
}

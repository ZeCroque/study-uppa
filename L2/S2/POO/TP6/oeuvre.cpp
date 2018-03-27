#include "oeuvre.h"

using namespace std;

Oeuvre::Oeuvre()
{
  this->_titre="Aucun";
  this->_resume="Aucun";
}

Oeuvre::Oeuvre(string titre, string resume)
{
  this->_titre=titre;
  this->_resume=resume;
}

Oeuvre::Oeuvre(const Oeuvre& o)
{
  *this=o;
}

Oeuvre::~Oeuvre()
{

}

Oeuvre& Oeuvre::operator = (const Oeuvre& o)
{
  this->_titre=o._titre;
  this->_resume=o._resume;
  return *this;
}

string Oeuvre::getTitre() const
{
  return this->_titre;
}

string Oeuvre::getResume() const
{
  return this->_resume;
}

ostream& operator << (ostream& os, const Oeuvre& o)
{
  return os<<o.getTitre()<<"\n"<<o.getResume()<<endl;
}

OeuvreInterprete::OeuvreInterprete()
{
  Oeuvre();
  this->_interprete="Aucun";
}

OeuvreInterprete::OeuvreInterprete(string titre, string resume, string interprete) : Oeuvre(titre, resume)
{
  Oeuvre(titre, resume);
  this->_interprete=interprete;
}

OeuvreInterprete::OeuvreInterprete(const OeuvreInterprete& o)
{
  *this=o;
}

OeuvreInterprete::~OeuvreInterprete()
{

}

OeuvreInterprete& OeuvreInterprete::operator = (const OeuvreInterprete& o)
{
  (Oeuvre)(*this)=(Oeuvre) o;
  this->_interprete=o._interprete;
  return *this;
}

string OeuvreInterprete::getInterprete() const
{
  return this->_interprete;
}

ostream& operator << (ostream& os, const OeuvreInterprete& o)
{
  return os<<(Oeuvre) o<<"\n"<<o.getInterprete()<<endl;
}

CD::CD()
{
  OeuvreInterprete();
  this->_duree=0;
}

CD::CD(string titre, string resume, string interprete, int duree) : OeuvreInterprete(titre, resume, interprete)
{
  this->_duree=duree;
}

CD::CD(const CD& c)
{
  *this=c;
}

CD::~CD()
{

}

CD& CD::operator = (const CD& c)
{
  (OeuvreInterprete)(*this)=(OeuvreInterprete) c;
  this->_duree=c._duree;
  return *this;
}

int CD::getDuree() const
{
  return this->_duree;
}

ostream& operator << (ostream& os, const CD& c)
{
  return os<<(OeuvreInterprete) c<<"\n"<<c.getDuree()<<endl;
}

OeuvreNonInterprete::OeuvreNonInterprete()
{
  Oeuvre();
}

OeuvreNonInterprete::OeuvreNonInterprete(string titre, string resume) :  Oeuvre(titre, resume)
{

}

OeuvreNonInterprete::OeuvreNonInterprete(const OeuvreNonInterprete& o)
{
  *this=o;
}

OeuvreNonInterprete::~OeuvreNonInterprete()
{

}

OeuvreNonInterprete& OeuvreNonInterprete::operator = (const OeuvreNonInterprete& o)
{
  (Oeuvre)(*this)=(Oeuvre) o;
  return *this;
}

ostream& operator << (ostream& os, const OeuvreNonInterprete& o)
{
  return os<<(Oeuvre) o;
}

Livre::Livre()
{
  OeuvreNonInterprete();
  this->_isbn=0;
}

Livre::Livre(std::string titre, std::string resume, int isbn)
{
  OeuvreNonInterprete(titre, resume);
  this->_isbn=isbn;
}

Livre::Livre(const Livre& l)
{
  *this=l;
}

Livre::~Livre()
{

}

Livre& Livre::operator = (const Livre& l)
{
  (OeuvreNonInterprete)(*this)=(OeuvreNonInterprete) l;
  this->_isbn=l._isbn;
  return *this;
}

int Livre::getIsbn() const
{
  return this->_isbn;
}

ostream& operator << (ostream& os, const Livre& l)
{
    return os<<(OeuvreNonInterprete) l<<"\n"<<l.getIsbn()<<endl;
}

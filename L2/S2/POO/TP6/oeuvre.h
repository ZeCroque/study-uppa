#ifndef oeuvre_h
#define oeuvre_h

#include <iostream>
#include <string>
#include "exemplaire.h"

class Oeuvre
{
  private :
    std::string _titre;
    std::string _resume;
  public :
    Oeuvre();
    Oeuvre(std::string titre, std::string resume);
    Oeuvre(const Oeuvre& o);
    ~Oeuvre();
    Oeuvre& operator = (const Oeuvre& o);
    std::string getTitre() const;
    std::string getResume() const;

};

class OeuvreInterprete : public Oeuvre
{
  private :
    std::string _interprete;
  public :
    OeuvreInterprete();
    OeuvreInterprete(std::string titre, std::string resume, std::string interprete);
    OeuvreInterprete(const OeuvreInterprete& o);
    ~OeuvreInterprete();
    OeuvreInterprete& operator = (const OeuvreInterprete& o);
    std::string getInterprete() const;

};

class CD : public OeuvreInterprete
{
  private :
    int _duree;
  public :
    CD();
    CD(std::string titre, std::string resume, std::string interprete, int duree);
    CD(const CD& c);
    ~CD();
    CD& operator = (const CD& c);
    int getDuree() const;
};

class OeuvreNonInterprete : public Oeuvre
{
  public :
    OeuvreNonInterprete();
    OeuvreNonInterprete(std::string titre, std::string resume);
    OeuvreNonInterprete(const OeuvreNonInterprete& o);
    ~OeuvreNonInterprete();
    OeuvreNonInterprete& operator = (const OeuvreNonInterprete& o);
};

class Livre : public OeuvreNonInterprete
{
  private :
    int _isbn;
  public :
    Livre();
    Livre(std::string titre, std::string resume, int isbn);
    Livre(const Livre& l);
    ~Livre();
    Livre& operator = (const Livre& l);
    int getIsbn() const;
};

std::ostream& operator << (std::ostream& os, const Oeuvre& o);
std::ostream& operator << (std::ostream& os, const OeuvreInterprete& o);
std::ostream& operator << (std::ostream& os, const CD& c);
std::ostream& operator << (std::ostream& os, const OeuvreNonInterprete& o);
std::ostream& operator << (std::ostream& os, const Livre& l);

#endif

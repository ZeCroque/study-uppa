#ifndef adherent_h
#define adherent_h

#include "exemplaire.h"
#include "adresse.h"
#include <string>
#include <iostream>

class Adherent
{
  private :
    std::string _nom;
    std::string _prenom;
    std::string _id;
    int _age;
    int _nbExemplairesEmprunte;
    Adresse _adresse;
    Exemplaire** _exemplaireTab;
  public :
    Adherent();
    Adherent(const Adherent& a);
    Adherent(std::string nom, std::string prenom, std::string id, int age, std::string rue, std::string ville, std::string CP, int numero);
    ~Adherent();
    Adherent& operator = (const Adherent& a);
    bool operator == (const Adherent& a);
    std::string getNom() const;
    std::string getPrenom() const;
    std::string getId() const;
    int getAge() const;
    Adresse getAdresse() const;
    void addExemplaire(const Exemplaire e);
    void removeExemplaire(const Exemplaire e);
    void afficheExemplaire(int i);
};

std::ostream& operator << (std::ostream& os, const Adherent& a);

#endif

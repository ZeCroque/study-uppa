#ifndef gestionfichier__h
#define gestionfichier__h

#include <iostream>
#include <fstream>
#include <string>

class GestionFichier
{
  private:
    std::string _nom;

  public:
    GestionFichier();
    GestionFichier(std::string nom);
    GestionFichier(GestionFichier& g);
    ~GestionFichier();
    GestionFichier& operator = (const GestionFichier& g);
    void lireFichier(std::string** tab, int nbElt);
    void enregistrerFichier(const std::string* tab, const int nbElt);
};

#endif

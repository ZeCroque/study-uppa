#include <iostream>
#include <string>

#include "Devise.h"

const double Devise::Taux_de_conversion[3][2] = { // Taux valides le 11 octobre 2017
    {0.845534, 0.151725}, // Dollar -> Euro, Dollar -> Yuan
    {1.18268, 0.128320}, // Euro -> Dollar, Euro -> Yuan
    {6.59169, 7.79636} // Yuan -> Dollar, Yuan -> Euro
};

Devise::Devise(Type_de_devise type_de_devise, const std::string& symbole) : _type_de_devise(type_de_devise), _symbole(symbole) {
}

std::string Devise::conversion(double montant, const Devise& devise) const {
    double resultat = montant * Taux_de_conversion[(int) this->_type_de_devise][(int) devise._type_de_devise];
    return std::to_string(resultat) + _symbole;
}

std::string Devise::conversion(double montant, Type_de_devise type_de_devise) const {
    double resultat = montant * Taux_de_conversion[(int) this->_type_de_devise][(int) type_de_devise];
    return std::to_string(resultat) + _symbole;
}

int main(int argc, char** argv) {
    Devise dollar(Devise::Type_de_devise::Dollar, "$");
    Devise euro(Devise::Type_de_devise::Euro, "€");
    std::cout << euro.conversion(1.0, dollar) << '\n'; // '1.182680€' est affiché...
    std::cout << euro.conversion(1.0, Devise::Type_de_devise::Dollar) << '\n'; // '1.182680€' est affiché...
    return 0;
}

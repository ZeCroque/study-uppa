#ifndef  _Devise
#define  _Devise

#include <string>

class Devise final {
public:

    enum class Type_de_devise : int { // Dollar->0, Euro->1 et Yuan->2
        Dollar, Euro, Yuan
    };
    static const double Taux_de_conversion[3][2];
private:
    const Type_de_devise _type_de_devise;
    const std::string _symbole;
public:
    Devise(Type_de_devise, const std::string&);
    virtual std::string conversion(double, const Devise&) const;
    virtual std::string conversion(double, Type_de_devise) const;
};

#endif

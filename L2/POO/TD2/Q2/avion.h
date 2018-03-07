#ifndef avion__h
#define avion__h

#include <iostream>
#include <string.h>

class Avion
{
  private :
   std::string _fabriquant;
   int _type;
   float _altitude;
   float _cap;
  public :
    Avion();
    Avion(const Avion& a);
    ~Avion();
    Avion& operator = (const Avion& a);
    void setFabriquant(std::string fabriquant);
    void setType(int type);
    void setAltitude(float alt);
    void setCap(float cap);
    std::string getFabriquant() const ;
    int getType()const  ;
    float getCap() const ;
    float getAltitude() const ;
    friend void afficheFiche(const Avion& a);
    friend class TourDeControle;
};

std::ostream & operator << (std::ostream& os, const Avion& a);



#endif

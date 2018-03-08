#ifndef __Dichotomie_h
#define __Dichotomie_h


#include "racinebase.h"

class Dichotomie:public RacineBase
{
  public :
    Dichotomie();
    Dichotomie(double a, double b, double (*f)(double), double eps, int itermax);
    std::string getName() const;
    double solve() const;
};

#endif

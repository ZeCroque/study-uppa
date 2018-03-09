#ifndef __Newton_h
#define __Newton_h

#include "racinebase.h"

class Newton:public RacineBase
{
  private :
    double (*_df)(double);

  public :
    Newton();
    Newton(double a, double b, double (*f)(double), double eps, int itermax, double (*df)(double));
    void setDF(double (*df)(double));
    std::string getName() const;
    double solve() const;
};



#endif

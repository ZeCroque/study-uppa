#ifndef __RacineBase_h
#define __RacineBase_h

#include <iostream>
#include <stdio.h>
#include <stdlib.h>


class RacineBase
{
  private :
    double _a;
    double _b;
    double (*_f)(double);
    int _itermax;
    double _eps;

  public :
    RacineBase();
    RacineBase(double a, double b, double (*f)(double), double eps, int itermax);
    double getA() const;
    double getB() const;
    int getItermax() const;
    double getEps() const;
    void setA(double a);
    void setB(double b);
    void setItermax(int itermax);
    void setEps(double eps);
    void setF(double (*f)(double));
    virtual std::string getName() const;
    virtual double solve() const=0;
};


#endif

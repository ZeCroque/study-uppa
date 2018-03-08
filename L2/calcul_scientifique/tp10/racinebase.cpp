
#include  "racinebase.h"

RacineBase::RacineBase()
{
  _a=0.0;
  _b=0.0;
  _f=NULL;
  _itermax=0;
  _eps=0.0;
}

RacineBase::RacineBase(double a, double b, double (*f)(double), double eps, int itermax)
{
  _a=a;
  _b=b;
  _f=f;
  _itermax=itermax;
  _eps=eps;
}

double RacineBase::getA() const
{
  return _a;
}

double RacineBase::getB() const
{
  return _b;
}

int RacineBase::getItermax() const
{
  return _itermax;
}

double RacineBase::getEps() const
{
 return _eps;
}

void RacineBase::setA(double a)
{
  _a=a;
}

void RacineBase::setB(double b)
{
  _b=b;
}

void RacineBase::setItermax(int itermax)
{
  _itermax=itermax;
}

void RacineBase::setEps(double eps)
{
  _eps=eps;
}

void RacineBase::setF(double (*f)(double))
{
  _f=f;
}

std::string RacineBase::getName() const
{
  return "RacineBase";
}

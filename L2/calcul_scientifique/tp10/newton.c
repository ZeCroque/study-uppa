#include "newton.h"

Newton::Newton()
{
  RacineBase();
  _df=NULL;
}

Newton::Newton(double a, double b, double (*f)(double), double eps, int itermax, double (*df)(double))
{
  RacineBase(a, b, f, eps, itermax);
  _df=df;
}

void Newton::setDF(double (*df)(double))
{
  _df=df;
}

std::string Newton::getName() const
{
  return "Newton";
}

double Newton::solve() const
{

}

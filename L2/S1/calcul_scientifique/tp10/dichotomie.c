#include "dichotomie.h"

Dichotomie::Dichotomie()
{
  RacineBase();
}

Dichotomie::Dichotomie(double a, double b, double (*f)(double), double eps, int itermax)
{
  RacineBase(a, b, f, eps, itermax);
}

virtual std::string Dichotomie::getName() const
{
 return "Dichotomie";
}

virtual double Dichotomie::solve() const
{

}

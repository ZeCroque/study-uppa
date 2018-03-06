#ifndef __Polynom_h
#define __Polynom_h

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

namespace L2Info
{

	class Polynom
	{
		private :
			int _deg;
			double* _coeff;

		public :
			Polynom();
			Polynom(int deg);
			Polynom(int deg, double* coeff);
			~Polynom();
			int getDegree() const;
			void setCoeffAndDegree(int deg, double* coeff);
			double & operator [] (int i);
			double operator [] (int i) const;
			Polynom& operator=(const Polynom& p);
			void operator +=(const Polynom& p);
			void operator *=(const Polynom& p);
			void operator *=(double a);
			double operator()(double x);
	};

}
	ostream& operator << (ostream& os, const L2Info::Polynom& p);


#endif

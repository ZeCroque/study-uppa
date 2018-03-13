#include "Polynom.h"

using namespace L2Info;

Polynom::Polynom()
{
	_deg=0;
	_coeff=NULL;
}

Polynom::Polynom(int deg)
{
	_deg=deg;
	_coeff=NULL;
}

Polynom::Polynom(int deg, double* coeff)
{
	_deg=deg;
	_coeff=new double[deg+1];
	_coeff=coeff;
}

Polynom::~Polynom()
{
	delete[] _coeff;
}

int Polynom::getDegree() const
{
	return _deg;
}

void Polynom::setCoeffAndDegree(int deg, double* coeff)
{
	_deg=deg;
	if(_coeff!=NULL)
	{
		delete[] _coeff;
	}
	_coeff=new double[deg+1];
	_coeff=coeff;

}

double & Polynom::operator [] (int i)
{
	return _coeff[i];
}

double Polynom::operator [] (int i) const
{
	return _coeff[i];
}

Polynom& Polynom::operator=(const Polynom& p)
{
	_deg=p._deg;
	if(_coeff!=NULL)
	{
		delete[] _coeff;
	}
	_coeff=new double[p._deg+1];
	_coeff=p._coeff;
}

void Polynom::operator +=(const Polynom& p)
{
	int i;
	double* tmp;

	if (_deg<p._deg)
	{
		tmp=new double[p._deg+1];
		for(i=_deg+1; i<=p._deg; i++)
		{
			tmp[i]=p._coeff[i];
		}
		for (i=0; i<=_deg; i++)
		{
			tmp[i]=p._coeff[i]+_coeff[i];
		}
		_deg=p._deg;
		if(_coeff!=NULL)
		{
			delete[] _coeff;
		}
		_coeff=new double[p._deg+1];
		_coeff=tmp;
	}
	else
	{
		tmp=new double[_deg+1];
		for(i=p._deg+1; i<=_deg; i++)
		{
			tmp[i]=_coeff[i];
		}
		for (i=0; i<=p._deg; i++)
		{
			tmp[i]=p._coeff[i]+_coeff[i];
		}
		if(_coeff!=NULL)
		{
			delete[] _coeff;
		}
		_coeff=new double[_deg+1];
		_coeff=tmp;
	}
	
}

void Polynom::operator *=(const Polynom& p)
{
	
	int i,j,degMax,degMin;
	double* tmp;
	
	degMax=(_deg<p._deg)?p._deg:_deg;
	degMin=(_deg<p._deg)?_deg:p._deg;
	
	tmp=new double[degMax+2];

	for(i=0; i<degMax+2; i++)
	{
		tmp[i]=0;
	}

	for (i=0; i<degMax+1; i++)
	{
		for (j=0; j<degMin+1; j++)
		{	
			if (degMax==_deg)
			{
				tmp[i+j]+=_coeff[i]*p._coeff[j];
			}
			else
			{
				tmp[i+j]+=p._coeff[i]*_coeff[j];
			}
		}
	}
	delete[] _coeff;
	_coeff=new double[degMax+2];
	_coeff=tmp;
	_deg=degMax+1;
}

void Polynom::operator *=(double a)
{
	int i;

	for (i=0; i<=_deg; i++)
	{
		_coeff[i]*=a;
	}
}

double Polynom::operator()(double x)
{
	int i;
	double tmp=0;

	for(i=0; i<=_deg; i++)
	{
		
			tmp+=_coeff[_deg-i];
			if (_deg-i!=0)
			{
				tmp*=x;
			}
	}
}

ostream& operator << (ostream& os, const L2Info::Polynom& p)
{
	int i;
	int size=p.getDegree()+1;

	for (i=0; i<size; i++)
	{
		if (i==0)
		{
			os<<p[i];
		}
		else if (i==1)
		{
			os<<" + "<<p[i]<<"x";
		}
		else
		{
			os<<" + "<<p[i]<<"x^"<<i;
		}
	}
	os<<endl;
}

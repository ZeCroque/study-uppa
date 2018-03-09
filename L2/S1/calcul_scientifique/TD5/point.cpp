#include <iostream>
#include <cmath>
#include "point.h"
#include "triangle.h"
using namespace std;

	Point::Point()
	{
		(*this)._x=0;
		(*this)._y=0;
		(*this)._z=0;
	}
	Point::Point(double _x, double _y, double _z)
	{
		(*this)._x=_x;
		(*this)._y=_y;
		(*this)._z=_z;
	}
	Point::Point(double _x, double _y)
	{
		(*this)._x=_x;
		(*this)._y=_y;
		(*this)._z=0;
	}
	double Point::getX() const
	{
		return (*this)._x;
	}
	double Point::getY() const
	{
		return (*this)._y;
	}
	double Point::getZ() const
	{
		return (*this)._z;	
	}
	double& Point::getX()
	{
		return (*this)._x;
	}
	double& Point::getY()
	{
		return (*this)._y;
	}
	double& Point::getZ()
	{
		return (*this)._z;
	}
	double Point::distance(const Point& P)
	{
		return sqrt(pow(((*this).getX()-P.getX()),2)+pow(((*this).getY()-P.getY()),2)+pow(((*this).getZ()-P.getZ()),2));
	}
	void Point::translate(const Point& P)
	{
		(*this).getX()+=P.getX();
		(*this).getY()+=P.getY();
		(*this).getZ()+=P.getZ();
	}

	ostream & operator << (ostream& os, const Point& P)
	{
		os<<P.getX()<<'\n'<<P.getY()<<'\n'<<P.getZ()<<'\n';
		return os;
	}

	istream & operator >> (istream& is, Point& P)
	{
		is>>P.getX()>>P.getY()>>P.getZ();
	}

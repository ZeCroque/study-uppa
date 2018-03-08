#ifndef __Point_h
#define __Point_h

#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Point
{
	private:
		double _x;
		double _y;
		double _z;
	public:
		Point();
		Point(double _x, double _y, double _z);
		Point(double _x, double _y);
		double getX() const;
		double getY() const;
		double getZ() const;
		double& getX();
		double& getY();
		double& getZ();
		double distance(const Point& P);
		void translate(const Point& P);

};
ostream & operator << (ostream& os, const Point& P);
istream & operator >> (istream& is, Point& P);

#endif

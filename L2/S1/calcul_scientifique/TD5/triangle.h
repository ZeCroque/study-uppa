#ifndef __Triangle_h
#define __Triangle_h

#include <iostream>
#include <cstdlib>
#include <vector>
#include "point.h"
using namespace std;

class Triangle
{
	private:
		vector<Point> _nodes;
		double _area;
		double _perimeter;
		void _computeArea();
		void _computePerimeter();
	public:
		Triangle();
		Triangle(const Point& P1, const Point& P2, const Point& P3);
		Triangle(const vector<Point>& vpts);
		void initGeometry();
		const Point& getNode(int i) const;
		Point& getNode(int i);		
		double getArea() const;
		double getPerimeter() const;
		

};
ostream & operator << (ostream& os, const Triangle& P);
istream & operator >> (istream& is, const Triangle& P);

#endif

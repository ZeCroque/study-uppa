#include <iostream>
#include "point.h"
#include "triangle.h"
using namespace std;

	void Triangle::_computeArea()
	{

	}
	
	void Triangle::_computePerimeter()
	{
		
	}
	
	Triangle::Triangle();
	{
		_nodes.reserve(3);
		_nodes.resize(3);
		_nodes[0]=0;
		_nodes[1]=0;
		_nodes[2]=0;
	}
	Triangle::Triangle(const Point& P1, const Point& P2, const Point& P3);
	{

	}
	Triangle::Triangle(const vector<Point>& vpts);
	{

	}
	void Triangle::initGeometry();
	{

	}
	const Triangle::Point& getNode(int i) const;
	{

	}
	Point& Triangle::getNode(int i);
	{

	}	
	double Triangle::getArea() const;
	{

	}
	double Triangle::getPerimeter() const
	{
		
	}

#include <iostream>
#include "point.h"
#include "triangle.h"
using namespace std;

int main()
{
	Point P1(1,1);
	Point P2(3,1);
	cout<<P1;
	cout<<P1.distance(P2)<<endl;
	P1.translate(P2);
	cout<<P1<<endl<<endl<<endl;
	cin>>P2;
	cout<<P2;

	return 0;
}

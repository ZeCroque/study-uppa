#include <iostream>
using namespace std;

long fibonacci(int n);
long fibonacciRecursif(int n, long a, long b);

int main()
{
	int n=0;

	cout<<"Entrez n"<<endl;
	cin>>n;
	
	cout<<fibonacci(45)<<endl;
	cout<<fibonacciRecursif(45,0,1)<<endl;

	return 0;
}

long fibonacci(int n) 
{
    long i = 0;
    long j = 1;
    long temp;

    for (int k = 0; k < n; k++) 
    {
        temp = i + j;
        i = j;
        j = temp;
    }
    return temp;
}

long fibonacciRecursif(int n, long a, long b) 
{
	return (n > 0) ? fibonacciRecursif(n - 1, b, a + b) : a;       
}

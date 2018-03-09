#ifndef __vecteur_h
#define __vecteur_h

#include <iostream>
#include <cstdlib>

using namespace std;

class VecteurChar
{
	private :
		int _nelem;
		char *_v;
		string _key;
		bool _encoded;
	public :
		VecteurChar();
		VecteurChar(int n);
		VecteurChar(const string& s);
		~VecteurChar();
		void reDim(int n);
		int getSize() const;
		void setKey(const string &s);
		void encode();
		void decode();
		char & operator [] (int i);
		char operator [] (int i) const;
		VecteurChar& operator = (const VecteurChar& V);
		VecteurChar& operator = (const string& s);
};

ostream& operator << (ostream os, const VecteurChar& v);

#endif
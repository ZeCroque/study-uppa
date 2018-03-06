#include "vecteur.h"
#include <cstdlib>

using namespace std;

VecteurChar::VecteurChar(){}
VecteurChar::VecteurChar(int n){}
VecteurChar::VecteurChar(const string& s){}
VecteurChar::~VecteurChar(){}
void VecteurChar::reDim(int n){}
int VecteurChar::getSize() const{}
void VecteurChar::setKey(const string &s){}
void VecteurChar::encode(){}
void VecteurChar::decode(){}
char & VecteurChar::operator [] (int i){}
char VecteurChar::operator [] (int i) const{}
VecteurChar& VecteurChar::operator = (const VecteurChar& V){}
VecteurChar& VecteurChar::operator = (const string& s){}
ostream& operator << (ostream os, const VecteurChar& v){}
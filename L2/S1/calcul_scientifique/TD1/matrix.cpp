#include  "matrix.h"
#include <iostream>
using namespace std;

// Constructeur sans argument de l'objet "Matrix"
Matrix::Matrix():_nlines(0),_mcolumns(0){}

// Redimensionne la matrice à la taille définie par n & m
void Matrix::reDim(int n, int m)
{
  _nlines = n;
  _mcolumns = m;
  _data.reserve(n*m);
  _data.resize(n*m);
}

// Retourne le nombre de lignes
int Matrix::getN() const
{
  return _nlines;
}
// Retourne le nombre de colonne
int Matrix::getM() const
{
  return _mcolumns;
}
// Definit un opérateur permettant d'accèder en lecture à un couple (i,j) dans le vecteur unidimensionnel "_data"
double Matrix::operator()(int i, int j) const
{
  return _data[j+_mcolumns*i];
}

// Definit un opérateur permettant d'accèder en écriture à un couple (i,j) dans le vecteur unidimensionnel "_data"
double&  Matrix::operator()(int i, int j)
{
  return _data[j+_mcolumns*i];
}

void Matrix::zero()
{
	for (int i=0; i<_nlines*_mcolumns; i++)
		_data[i]=0;
}

void Matrix::identity(int n)
{
	if (_mcolumns==_nlines && _nlines>=n)
		for (int i=0; i<n; i++)
			_data[i+n*i]=1;
	else
		cout<<"La matrice n'est pas carrée et/où trop petite";
}

bool Matrix::symmetrical() const
{
	if (_mcolumns!=_nlines)
		return false;
	else
		for(int i=0; i<_nlines; i++)
			for(int j=0; j<_mcolumns; j++)
				if (_data[i+_nlines*j]!=_data[j+_nlines*i])
					return false;
	return true;
}


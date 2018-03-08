#include  "matrix.h"


// constructeur sans paramètre
Matrix::Matrix():_nlines(0),_mcolumns(0){}

// constructeur avec le nombre de lignes et d ecolonnes passés en paramètre
Matrix::Matrix(int n, int m)
{
  reDim(n,m);
}

// fonction permettant de dimensionner la matrice
void Matrix::reDim(int n, int m)
{
  _nlines = n;
  _mcolumns = m;
  _data.reserve(n*m);
  _data.resize(n*m);
}

// fonction renvoyant le nombre de lignes
int Matrix::getN() const
{
  return _nlines;
}
// fonction renvoyant le nombre de lignes
int Matrix::getM() const
{
  return _mcolumns;
}
// opérateur permettant d'accéder à un élément de la matrice à l'aide de parenthèses
// il s'agit ici de la version en lecture seulement
double Matrix::operator()(int i, int j) const
{
  return _data[j+_mcolumns*i];
}

// // opérateur permettant d'accéder à un élément de la matrice à l'aide de parenthèses
// il s'agit ici de la version en écriture
double&  Matrix::operator()(int i, int j)
{
  return _data[j+_mcolumns*i];
}

// fonction initialisant tous les coefficients de la matrice à zéro.
void Matrix::zero()
{
  for (int i=0; i<_nlines*_mcolumns; i++) _data[i]=0.0;
}

// fonction renvoyant vrai si la matrice est symétrique et faux sinon
bool Matrix::symmetrical() const
{
  if (_nlines!=_mcolumns) return false;
  for (int i=1; i<_nlines; i++)
  {
    for (int j=0; j<i; j++)
    {
      if ((*this)(i,j)!=(*this)(j,i)) return false;
    }
  }
  return true;
}

// fonction initialisant la matrice à la matrice identité de taille n
void Matrix::identity(int n)
{
  reDim(n,n);
  zero();
  for (int i=0; i<_nlines; i++) (*this)(i,i)=1.0;
}

// fonction initialisant la matrice par la combinaison linéaire alpha × A + beta × B.
void Matrix::linearCombi(double alpha, const Matrix& A, double beta, const Matrix & B)
{
  int nA=A.getN();
  int nB=B.getN();
  int mA=A.getM();
  int mB=B.getM();
  if ((nA!=nB)||(mA!=mB))
  {
    std::cerr<<"****Error in Matrix::linearCombi: incompatible matrix dimensions\n";
    std::exit(1);
  }
  reDim(nA,mA);
  for (int i=0; i<nA; i++)
  {
    for (int j=0; j<mA; j++)
    {
      (*this)(i,j)=alpha*A(i,j)+beta*B(i,j);
    }
  }
}
// fonction initialisant la matrice au produit A × B.
void Matrix::productMatrix1(const Matrix&A, const Matrix& B)
{
  int nA=A.getN();
  int nB=B.getN();
  int mA=A.getM();
  int mB=B.getM();
  if (nB!=mA)
  {
    std::cerr<<"****Error in Matrix::productMatrix1: incompatible matrix dimensions\n";
    std::exit(1);
  }
  reDim(nA,mB);
  zero();
  for (int i=0; i<nA;i++)
  {
    for (int j=0; j<mB;j++)
    {
      for (int k=0; k<mA; k++)
      {
        (*this)(i,j)+=A(i,k)*B(k,j);
      }
    }
  }
}

// fonction initialisant la matrice C au produit this × B.
void Matrix::productMatrix2(const Matrix&B, Matrix& C) const
{
  int n=getN();
  int nB=B.getN();
  int m=getM();
  int mB=B.getM();
  if (nB!=m)
  {
    std::cerr<<"****Error in Matrix::productMatrix2: incompatible matrix dimensions\n";
    std::exit(1);
  }
  C.reDim(n,mB);
  C.zero();
  for (int i=0; i<n;i++)
  {
    for (int j=0; j<mB;j++)
    {
      for (int k=0; k<m; k++)
      {
        C(i,j)+=(*this)(i,k)*B(k,j);
      }
    }
  }
}

// fonction permettant de résoudre le système linéaire Ax = b en supposant que A est triangulaire inférieure.
void Matrix::solveTriL(const std::vector<double> & b, std::vector<double> &x) const
{
  int n=b.size();
  x.reserve(n);x.resize(n);
  double s;
  for (int i=0; i<n;i++)
  {
    s=0.0;
    for (int j=0; j<i-1;j++)
    {
      s=s+(*this)(i,j)*x[j];
    }
    x[i]=(x[i]-s)/(*this)(i,i);
  }
}


// fonction permettant de résoudre le système linéaire Ax = b en supposant que A est triangulaire supérieure.
void Matrix::solveTriU(const std::vector<double> & b, std::vector<double> &x) const
{
  int n=b.size();
  x.reserve(n);x.resize(n);
  double s;
  for (int i=n-1; i>=0;i--)
  {
    s=0.0;
    for (int j=i+1; j<n;j++)
    {
      s=s+(*this)(i,j)*x[j];
    }
    x[i]=(x[i]-s)/(*this)(i,i);
  }
}

// opérateur de sortie
std::ostream & operator << (std::ostream& os, const Matrix& A)
{
  int n=A.getN();
  int m=A.getM();
  for (int i=0; i<n; i++)
  {
    for (int j=0; j<m; j++)
    {
      os<<A(i,j)<<" ";
    }
    os<<'\n';
  }
  return os;
}


void Matrix::productVector(const std::vector<double> &x, std::vector<double> &b) const
{
	int n=(*this).getN();
	int m=(*this).getM();
	b.resize(n);

	if (x.size()==m)
		for (int i=0; i<n;i++)
	 	 {
	   		 for (int j=0; j<m;j++)
	    		{
	       			b[i]+=(*this)(i,j)*x[j];
					
	    		}
	  	}
}

void Matrix::_jacobiMatrix(Matrix &J) const
{


	int i,j,n,m;
	Matrix D,M;

	n=(*this).getN();
	m=(*this).getM();

	D.reDim(n,m);
	M.reDim(n,m);
	J.reDim(n,m);

	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		{
			if(i==j)
				D(i,j)=1/(*this)(i,j);
			else
				M(i,j)=(*this)(i,j);
		}
	}
	J.productMatrix1(D, M);	
}

void Matrix::solveJacobi(const std::vector<double> &b, std::vector<double> &x, double eps, int nitermax) const
{
	int i,j,n,m;
	Matrix J,D;
	std::vector<double> tmp, tmp1;
	tmp.reserve(J.getM());
	tmp.resize(b.size());
	tmp1.reserve(J.getM());
	tmp1.resize(b.size());

	(*this)._jacobiMatrix(J);
	D.reDim(J.getN(),J.getM());

	for(i=0; i<J.getN(); i++)
		for (j=0; j<J.getM(); j++)
		{
			J(i,j)=-J(i,j);
			if(i==j)
				D(i,j)=1/(*this)(i,j);
		}
	
	x.reserve(J.getM());
	x.resize(J.getM());

	for(i=0; i<nitermax; i++)
	{
		J.productVector(x, tmp);
		D.productVector(b, tmp1);
		for(j=0; j<x.size(); j++)
			x[j]=tmp[j]+tmp1[j];
	}

		
}



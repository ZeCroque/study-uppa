#ifndef __Matrix_h
#define __Matrix_h

#include  <cstdlib>
#include  <vector>
#include <iostream>

/*-----------------------------------------------------------------*/
//Xavier Dufillon & Gaëtan Croquefer
class Matrix
{
private:

  int _nlines, _mcolumns;
  std::vector<double> _data;

public:

  Matrix();
  Matrix(int n, int m);
  void reDim(int n,int m);
  int getN() const;
  int getM() const;
  double operator()(int i, int j) const;
  double& operator()(int i, int j);
  void zero();
  bool symmetrical() const;
  void identity(int n);
  void linearCombi(double alpha, const Matrix& A, double beta, const Matrix & B);
  void productMatrix1(const Matrix&A, const Matrix& B);
  void productMatrix2(const Matrix&B, Matrix& C) const;
  void productVector(const std::vector<double> &x , std::vector<double> & b) const;
  void solveTriL(const std::vector<double> & b, std::vector<double> &x) const;
  void solveTriU(const std::vector<double> & b, std::vector<double> &x) const;
  void _jacobiMatrix(Matrix &J) const;
  void solveJacobi(const std::vector<double> &b, std::vector<double> &x, double eps, int nitermax) const;
  void factoCholesky(Matrix &B) const;
  void solveCholesky(const std::vector<double> &b, std::vector<double> &x) const;

};
std::ostream & operator << (std::ostream& os, const Matrix& A);
#endif


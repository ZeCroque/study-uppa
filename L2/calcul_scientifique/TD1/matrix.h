#ifndef __Matrix_h
#define __Matrix_h

#include  <cstdlib>
#include  <vector>

/*-----------------------------------------------------------------*/
class Matrix
{
private:

  int _nlines, _mcolumns;
  std::vector<double> _data;

public:

  Matrix();
  void reDim(int n,int m);
  int getN() const;
  int getM() const;
  double operator()(int i, int j) const;
  double&       operator()(int i, int j);
	void zero();
	void identity(int n);
	bool symmetrical() const;
	void linearCombi(double alpha, const Matrix& A, double beta, const Matrix& B);
	void productMatrix(const Matrix& A, const Matrix& B);
	void productMatrix (const Matrix &B, Matrix& C);

};
#endif


#ifndef GUARD_MATRIX_H
#define GUARD_MATRIX_H

#include <vector>
#include <initializer_list>

class Matrix
{
 public:
  // Konstruiere eine Matrix mit numRows Zeilen und
  // numCols Spalten, jedes Element erhaelt den Wert value
  Matrix(size_t numRows, size_t numCols, double value);

  // Konstruiere eine Matrix aus geschachtelten std::initializer_lists
  Matrix(std::initializer_list<std::vector<double>> values);

  // Copy-Konstruktor
  Matrix(const Matrix& b);

  // Zugriffsfunktion: Anzahl der Zeilen 
  size_t rows() const;
  // Zugriffsfunktion: Anzahl der Spalten 
  size_t cols() const;

  // Schreibzugriff auf Element in Zeile i und Spalte j
  double& operator()(size_t i, size_t j);
  // Lesezugriff auf Element in Zeile i und Spalte j
  double operator()(size_t i, size_t j) const;

  // Schreibzugriff auf Zeile i
  std::vector<double>& operator [](size_t i);
  // Lesezugriff auf Zeile i
  const std::vector<double>& operator [](size_t i) const;


  // Multipliziere jedes Element mit einer Zahl x 
  Matrix& operator *=(double x);
  // Addiere eine Matrix b 
  Matrix& operator +=(const Matrix& b);

  // Ausgabe der Matrix 
  void print() const;

  // Loesen eines Gleichungssystems 
  std::vector<double> solve(std::vector<double> b) const;
 private:
  std::vector<std::vector<double> > a_;
  size_t numRows_;
  size_t numCols_;
};

// Matrix-Vektor-Multiplikation 
std::vector<double> operator *(const Matrix& a,
			       const std::vector<double>& x);
// Multiplikation jedes Elements mit x
Matrix operator *(double x, const Matrix& a);
// Addition zweier Matrizen a und b
Matrix operator +(const Matrix& a, const Matrix& b);

#endif

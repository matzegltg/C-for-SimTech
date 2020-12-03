#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <initializer_list>

#include "matrix.hpp"

size_t Matrix::rows() const
{
    return numRows_;
}

size_t Matrix::cols() const
{
    return numCols_;
}

Matrix::Matrix(size_t numRows, size_t numCols, double value)
: a_(numRows), numRows_(numRows), numCols_(numCols)
{
    for(size_t i = 0; i < numRows_; ++i)
    {
        a_[i].resize(numCols_);
        for(size_t j = 0; j < a_[i].size(); ++j)
            a_[i][j]= value;
    }
}

Matrix::Matrix(std::initializer_list<std::vector<double>> values)
: a_(values), numRows_(a_.size())
{
    if (numRows_ > 0)
        numCols_ = a_[0].size();
    else
        numCols_ = 0;
}

Matrix::Matrix(const Matrix& b)
{
    a_= b.a_;
    numRows_ = b.numRows_;
    numCols_ = b.numCols_;
}

double& Matrix::operator()(size_t i, size_t j)
{
    if(i >= numRows_)
    {
        std::cerr << " Illegal row index " << i;
        std::cerr << " valid range is(0: " << numRows_ << ")";
        std::cerr << std::endl;
        exit(EXIT_FAILURE);
    }
    if(j >= numCols_)
    {
        std::cerr << " Illegal column index " << i;
        std::cerr << " valid range is(0: " << numCols_ << ")";
        std::cerr << std::endl;
        exit(EXIT_FAILURE);
    }
    return a_[i][j];
}

double Matrix::operator()(size_t i, size_t j) const
{
    if(i >= numRows_)
    {
        std::cerr << " Illegal row index " << i;
        std::cerr << " valid range is(0: " << numRows_ << ")";
        std::cerr << std::endl;
        exit(EXIT_FAILURE);
    }
    if(j >= numCols_)
    {
        std::cerr << " Illegal column index " << i;
        std::cerr << " valid range is(0: " << numCols_ << ")";
        std::cerr << std::endl;
        exit(EXIT_FAILURE);
    }
    return a_[i][j];
}

std::vector<double>& Matrix::operator [](size_t i)
{
    if(i >= numRows_)
    {
        std::cerr << " Illegal row index " << i;
        std::cerr << " valid range is(0: " << numRows_ << ")";
        std::cerr << std::endl;
        exit(EXIT_FAILURE);
    }
    return a_[i];
}

const std::vector<double>& Matrix::operator [](size_t i) const
{
    if(i >= numRows_)
    {
        std::cerr << " Illegal row index " << i;
        std::cerr << " valid range is(0: " << numRows_ << ")";
        std::cerr << std::endl;
        exit(EXIT_FAILURE);
    }
    return a_[i];
}

Matrix& Matrix::operator *=(double x)
{
    for(size_t i=0;i< numRows_;++ i)
        for(size_t j=0;j< numCols_;++ j)
            a_[i][j ]*=x;
    return * this;
}

Matrix& Matrix::operator +=(const Matrix& x)
{
    if((x.numRows_ != numRows_) ||(x.numCols_ != numCols_))
    {
        std::cerr << " Dimensions of matrix a(" << numRows_
        << "x" << numCols_ << ") and matrix x("
        << numRows_ << "x" << numCols_ << ") do not match !";
        exit(EXIT_FAILURE);
    }
    for(size_t i=0;i< numRows_;++ i)
        for(size_t j=0;j<x.numCols_;++ j)
            a_[i][j]+=x[i][j];
    return * this;
}

void Matrix::print() const
{
    std::cout << "(" << numRows_ << "x";
    std::cout << numCols_ << ") matrix :" << std::endl;
    for(size_t i=0;i< numRows_;++ i)
    {
        std::cout << std::setprecision(3);
        for(size_t j=0;j< numCols_;++ j)
            std::cout << std::setw(5) << a_[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

std::vector<double> Matrix::solve(std::vector<double> b) const
{
    std::vector<std::vector<double> > a(a_);
    for(size_t m = 0; m < numRows_ - 1; ++m)
        for(size_t i = m + 1; i < numRows_; ++i)
        {
            double q = a[i][m]/a[m][m];
            a[i][m] = 0.0;
            for(size_t j = m + 1; j < numRows_; ++j)
                a[i][j] = a[i][j] - q*a[m][j];
            b[i] -= q*b[m];
        }
    std::vector<double> x(b);
    x.back() /= a[numRows_ - 1][numRows_ - 1];
    for(int i = numRows_ - 2; i >= 0; --i)
    {
        for(size_t j = i + 1; j < numRows_; ++j)
            x[i] -= a[i][j]*x[j];
        x[i] /= a[i][i];
    }
    return(x);
}

Matrix operator *(double x, const Matrix& a)
{
    Matrix temp(a);
    temp *= x;
    return temp;
}

std::vector<double> operator *(const Matrix& a,
                               const std::vector<double>& x)
{
    if(x.size() !=a.cols())
    {
        std::cerr << " Dimensions of vector " << x.size();
        std::cerr << " and matrix " << a.cols() << " do not match !";
        std::cerr << std::endl;
        exit(EXIT_FAILURE);
    }
    std::vector<double> y(a.rows());
    for(size_t i=0;i<a.rows();++ i)
    {
        y[i ]=0.0;
        for(size_t j=0;j<a.cols();++ j)
            y[i]+=a[i][j]*x[j];
    }
    return y;
}

Matrix operator +(const Matrix& a, const Matrix& b)
{
    Matrix temp(a);
    temp += b;
    return temp;
}

#include <iostream>
#include <vector>
#include <cmath>

#include "newtonmethod.hpp"
#include "matrix.hpp"


double f(double x)
{
    return exp(x) - 2;
}

double df(double x)
{
    return exp(x);
}

std::vector<double> fVec(const std::vector<double>& x)
{
    return {x[0]*x[0]*x[0] + x[1] - 1, x[1]*x[1]*x[1] - x[0] + 1};
}

Matrix dfVec(const std::vector<double>& x)
{
    return { {3*x[0]*x[0], 1},
             {-1, 3*x[1]*x[1]} };
}

int main()
{
    double eps = 1e-14;
    size_t maxIt = 15;

    std::cout << std::endl << "Scalar function:" << std::endl;
    double x0 = 0;
    using NP = NewtonParams<double, double, double>;
    NP params = {x0, eps, maxIt, f, df};
    NewtonMethod<NP> newton(params);
    auto x = newton.solve();
    for (auto val : x)
        std::cout << val << std::endl;

    std::cout << std::endl << "Vector-valued function:" << std::endl;
    using Vector = std::vector<double>;
    Vector x0Vec = {0.5, 0.5};
    using NPVec = NewtonParams<Vector, Vector, Matrix>;
    NPVec paramsVec = {x0Vec, eps, maxIt, fVec, dfVec};
    NewtonMethod<NPVec> newtonVec(paramsVec);
    auto xVec = newtonVec.solve();
    for (auto val : xVec)
        std::cout << val << std::endl;

    return 0;
}

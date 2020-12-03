#include <vector>
#include <iostream>

#include "newtonmethod.hpp"

using namespace std;

//vector<double> NewtonMethod::solve() const
//{
//    double x = params_.x0;
//    vector<double> xVec = {x};
//
//    double fval = params_.f(x);
//    size_t k = 0;
//    while (abs(fval) > params_.epsilon
//           && k < params_.maxIt)
//    {
//        double dfval = params_.df(x);
//        x -= fval/dfval;
//        xVec.push_back(x);
//        fval = params_.f(x);
//        k++;
//    }
//
//    if (abs(fval) > params_.epsilon)
//        cout << "Newton didn't converge in ";
//    else
//        cout << "Newton converged after ";
//    cout << k << " iterations with a residual of " << abs(fval) << "." << endl;
//
//    return xVec;
//}

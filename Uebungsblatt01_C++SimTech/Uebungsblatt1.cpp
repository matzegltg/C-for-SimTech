//============================================================================
// Name        : Abgabe C++ f�r SimTech
// Author      : Jonathan Schnitzler, Jona van Moll, Matthias G�ltig
// Version     : finished
// Description : Newtonverfahren f�r zwei gegebene Funktionen
//============================================================================

#include <iostream>
#include <cmath>
#include <vector>
#include <functional>
#include "NewtonMethodNewtonParmas.hpp"
using namespace std;

double f(double x) {
	return exp(x) - 2;
}
double df(double x) {
	return exp(x);
}

double g(double x) {
	return pow(x, 3.0);
}

double dg(double x) {
	return pow(x, 2.0) * 3;
}

int main() {

	NewtonParams newtonParams1_(1, 1e-14, f, df, 15);
	NewtonParams newtonParams2_(1, 1e-14, g, dg, 15);
	NewtonMethod newtonMethod1_(newtonParams1_);
	NewtonMethod newtonMethod2_(newtonParams2_);

	cout << "Iteration f�r Funktion f:" << endl;
    vector<double> x = newtonMethod1_.solvef();
	for (const auto& val : x)
	        cout << val << endl;
	cout << endl;
	cout << "Iteration f�r Funktion g:" << endl;
	vector<double> y = newtonMethod2_.solveg();
	for (const auto& val : y)
	        cout << val << endl;

	return 0;
}

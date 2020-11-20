/*
 * NewtonMethodNewtonParmas.cpp
 *
 *  Created on: 19.11.2020
 *      Author: Matthias Gültig
 */

#include"NewtonMethodNewtonParmas.hpp"
#include <iostream>
#include <cmath>
#include <vector>
#include <functional>


double f(double x);
double df(double x);
double g(double x);
double dg(double x);

NewtonMethod::NewtonMethod(const NewtonParams &v) :
		newtonParams_(v) {}

void NewtonMethod::setX0(double d) {
	newtonParams_.x0_ = d;
}

void NewtonMethod::setEpsilon(double d) // in Aufgabe nur Datentyp
		{
	newtonParams_.epsilon_ = d;
}

void NewtonMethod::setMaxIt(double d) {
	newtonParams_.maxIt_ = d;
}

double NewtonMethod::x0() const {
	return newtonParams_.x0_;
}

double NewtonMethod::epsilon() const
	{ return newtonParams_.epsilon_; }

double NewtonMethod::maxIt() const {
	return newtonParams_.maxIt_;
}


vector<double> NewtonMethod::solvef() {
	double x = x0();
	vector<double> xVec = { x };

	double fval = f(x);
	size_t counter = 0;
	while (abs(fval) > epsilon() && counter < maxIt()) {
		double dfval = df(x);
		x -= fval / dfval;
		xVec.push_back(x);
		fval = f(x);
		counter++;
		if (counter == maxIt())
			cout << "Leider maximale Iterationsschrittzahl überschritten!" << endl;
	}

	return xVec;
}

vector<double> NewtonMethod::solveg() {
	double x = x0();
	vector<double> xVec = { x };

	double fval = g(x);
	size_t counter = 0;
	while (abs(fval) > epsilon() && counter < maxIt()) {
		double dfval = dg(x);
		x -= fval / dfval;
		xVec.push_back(x);
		fval = g(x);
		counter++;
		if (counter == maxIt())
			cout << "Leider maximale Iterationsschrittzahl überschritten!" << endl;
	}

	return xVec;
}


//============================================================================
// Name        : Uebungsblatt1.cpp
// Author      : Matthias Gültig
// Version     : alpha
// Copyright   : Your copyright notice oink
// Description : alpha-Version des Übungsblatts
//============================================================================

#include <iostream>
#include <cmath>
#include <vector>
#include <functional>
using namespace std;

struct NewtonParams {
	double x0_;
	double epsilon_;
	function<double(double)> f_;
	function<double(double)> df_;
	size_t maxIt_;
};


class NewtonMethod {

public:
	NewtonMethod(const NewtonParams v)

	{ newtonParams_ = v; }

	double f(double x) {
		return exp(x) - 2;
	}

	double df(double x) {
		return exp(x);
	}

//	double g(double x) {
//		return pow(x, 3.0);
//	}
//
//	double dg(double x) {
//		return pow(x, 2.0)*3;
//	}
	void setX0(double d) {
		newtonParams_.x0_ = d;
	}

	void setEpsilon(double d) // in Aufgabe nur Datentyp
			{
		newtonParams_.epsilon_ = d;
	}

	void setMaxIt(double d) {
		newtonParams_.maxIt_ = d;
	}

	double x0() const {
		return newtonParams_.x0_;
	}

	double epsilon() const {
		return newtonParams_.epsilon_;
	}

	double maxIt() const {
		return newtonParams_.maxIt_;
	}

	vector<double> solve() {
		double x = newtonParams_.x0_;
		vector<double> xVec = { x };

		double fval = f(x);
		cout << "das ist f(x)" << fval << endl;
		size_t counter = 0;
		while (abs(fval) > newtonParams_.epsilon_
				|| counter == newtonParams_.maxIt_) {
			double dfval = df(x);
			x -= fval / dfval;
			xVec.push_back(x);
			fval = f(x);
			counter++;
			if (counter == newtonParams_.maxIt_)
				cout << "Leider nicht geügend Iterationen!" << endl;
		}

		return xVec;
	}

private:
	NewtonParams newtonParams_; //parameter hier eingeben
};

int main() {
	double x0 = 0;
	double eps = 1e-14;
	size_t maxIt = 15;

	NewtonParams newtonParams_;
	NewtonMethod newtonMethod_(newtonParams_);
	newtonMethod_.setX0(x0);
	newtonMethod_.setEpsilon(eps);
	newtonMethod_.setMaxIt(maxIt);
	vector<double> x = newtonMethod_.solve();

	for (const auto& val : x)
	        cout << val << endl;
	return 0;
}

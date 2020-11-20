/*
 * NewtonMethodNewtonParmas.hpp
 *
 *  Created on: 19.11.2020
 *      Author: Matthias Gültig
 */

#ifndef HEADER_HPP_
#define HEADER_HPP_
#include <iostream>
#include <cmath>
#include <vector>
#include <functional>
using namespace std;

struct NewtonParams {

	NewtonParams(double x0, double epsilon, function<double(double)> f,
			function<double(double)> df, size_t maxIt) :
			x0_(x0), epsilon_(epsilon), f_(f), df_(df), maxIt_(maxIt) {
	}
public:
	double x0_;
	double epsilon_;
	function<double(double)> f_;
	function<double(double)> df_;
	size_t maxIt_;
};

class NewtonMethod {

public:
	explicit NewtonMethod(const NewtonParams &v);

	vector<double> solvef();
	vector<double> solveg();

	void setX0(double);
	void setEpsilon(double);
	void setMaxIt(double);
	double x0() const;
	double epsilon() const;
	double maxIt() const;


private:
	NewtonParams newtonParams_; //parameter hier eingeben
};

#endif /* HEADER_HPP_ */

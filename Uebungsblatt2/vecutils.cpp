/*
 * vecutils.cpp
 *
 *  Created on: 03.12.2020
 *      Author: Matthias Gültig
 */

#include <vector>
#include <functional>
#include <cmath>

#include "vecutils.hpp"

double Vecutils::norm(const std::vector<double> &v) {
	double x = 0;
	for (auto vElem : v)
		x += vElem * vElem;
	return sqrt(x);
}

double Vecutils::norm(double d) {
	return d > 0 ? d : -d;
}

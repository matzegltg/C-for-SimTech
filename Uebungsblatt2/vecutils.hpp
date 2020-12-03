/*
 * vecutils.hpp
 *
 *  Created on: 03.12.2020
 *      Author: Matthias Gültig
 */

#ifndef VECUTILS_HPP_
#define VECUTILS_HPP_

#include <vector>
#include <functional>

class Vecutils {
public:
	Vecutils() {}

	double norm(double d);
	double norm(const std::vector<double> &v);
};
#endif /* VECUTILS_HPP_ */

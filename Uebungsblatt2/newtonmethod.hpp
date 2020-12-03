#ifndef NEWTONMETHOD_H
#define NEWTONMETHOD_H

#include <vector>
#include <functional>
#include <cmath>
#include "vecutils.hpp"
#include "matrix.hpp"

std::vector<double> operator/(const std::vector<double> &b, const Matrix &a) {
	return a.solve(b);
}

std::ostream& operator<<(std::ostream &out,
		const std::vector<double> &vec) {
	for (auto elem : vec) {
		std::cout << elem << std::endl;
	}
	return out;
}

std::vector<double> operator-=(std::vector<double> &lhs,
		const std::vector<double> &rhs) {
	std::vector<double> output;
	for (std::size_t i = 0; i != lhs.size(); ++i) {
		output.push_back(lhs[i] - rhs[i]);
	}
	return output;
}

template<class FunctionPT, class FunctionRT, class DerivativeRT>
struct NewtonParams {
	using FunctionParameterType = FunctionPT;
	using FunctionReturnType = FunctionRT;
	using DerivativeReturnType = DerivativeRT;

	FunctionParameterType x0;
	double epsilon;
	size_t maxIt;
	std::function<FunctionReturnType(FunctionParameterType)> f;
	std::function<DerivativeReturnType(FunctionParameterType)> df;
};




template<class NewtonParams>
class NewtonMethod {
	using FunctionParameterType = typename NewtonParams::FunctionParameterType;
	using FunctionReturnType = typename NewtonParams::FunctionReturnType;
	using DerivativeReturnType = typename NewtonParams::DerivativeReturnType;

public:
	NewtonMethod(const NewtonParams &params) :
			params_(params) {
	}

	void setX0(FunctionParameterType x0) {
		params_.x0 = x0;
	}

	void setEpsilon(double eps) {
		params_.epsilon = eps;
	}

	void setMaxIt(size_t maxIt) {
		params_.maxIt = maxIt;
	}

	FunctionParameterType x0() const {
		return params_.x0;
	}

	double epsilon() const {
		return params_.epsilon;
	}

	size_t maxIt() const {
		return params_.maxIt;
	}

	std::vector<FunctionParameterType> solve() {
		FunctionParameterType x = params_.x0;
		std::vector<FunctionParameterType> xVec = { x };
		Vecutils v1;
		auto fval = params_.f(x);
		size_t k = 0;
		while (v1.norm((fval)) > params_.epsilon && k < params_.maxIt) {
			auto dfval = params_.df(x);
			x -= fval / dfval;
			xVec.push_back(x);
			fval = params_.f(x);
			k++;
		}

		if (v1.norm(fval) > params_.epsilon)
			std::cout << "Newton didn't converge in ";
		else
			std::cout << "Newton converged after ";
		std::cout << k << " iterations with a residual of " << v1.norm(fval)
				<< "." << std::endl;

		return xVec;
	}
private:
	NewtonParams params_;
};






#endif

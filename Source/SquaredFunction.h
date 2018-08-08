/*
 * SphereFunction.h
 *
 *  Created on: 5 Jul 2018
 *      Author: dom
 */

#ifndef SOURCE_SQUAREDFUNCTION_H_
#define SOURCE_SQUAREDFUNCTION_H_

#include <cmath>

#include "AbstractCost.h"

namespace Cost {

	class SquaredFunction : public AbstractCost {

	public:
		SquaredFunction() = default;
		~SquaredFunction() = default;

	public:
		virtual double get(const double x) const override {
			return pow(x,2);
		}
	};

}



#endif /* SOURCE_SQUAREDFUNCTION_H_ */

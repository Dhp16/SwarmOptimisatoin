/*
 * SphereFunction.h
 *
 *  Created on: 5 Jul 2018
 *      Author: dom
 */

#ifndef SOURCE_SQUAREDFUNCTION_H_
#define SOURCE_SQUAREDFUNCTION_H_

#include <cmath>
#include <memory>

#include "AbstractCost.h"
#include "2DLocation.h"
#include "1DLocation.h"

namespace Cost {

	class SquaredFunction : public AbstractCost {

	public:
		SquaredFunction() = default;
		~SquaredFunction() = default;

	public:
		static double get(const std::shared_ptr<OneDLocation>& property) {
			return pow(property->getX(), 2);
		}
		static double get(const std::shared_ptr<TwoDLocation>& property) {
			return pow(property->getX(), 2);
		}
	};

}



#endif /* SOURCE_SQUAREDFUNCTION_H_ */

/*
 * CostCalculator.h
 *
 *  Created on: 9 Aug 2018
 *      Author: dom
 */

#ifndef SOURCE_COSTCALCULATOR_H_
#define SOURCE_COSTCALCULATOR_H_

#include <memory>

#include "AbstractCost.h"

namespace Cost {
	class Calculator {
	public:
		Calculator(){};
		~Calculator(){};

		static double calculate(const std::shared_ptr<AbstractProperties>& property,
				Type costType);
	};
}







#endif /* SOURCE_COSTCALCULATOR_H_ */

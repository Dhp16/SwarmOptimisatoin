/*
 * CostCalculator.cpp
 *
 *  Created on: 9 Aug 2018
 *      Author: dom
 */

#include "CostCalculator.h"

#include "1DLocation.h"
#include "2DLocation.h"
#include "SquaredFunction.h"

double Cost::Calculator::calculate(
		const std::shared_ptr<AbstractProperties>& property,
		Cost::Type costType) {

	std::shared_ptr<OneDLocation> derived = nullptr;

	switch(costType){
	case Cost::Type::SquaredFunction:
		derived = std::dynamic_pointer_cast<OneDLocation>(property);
		return SquaredFunction::get(derived);
	default:
		throw "Cost Type UNDEFINED";
	}
	return 0;
}



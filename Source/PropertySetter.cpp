/*
 * PropertySetter.cpp
 *
 *  Created on: 7 Aug 2018
 *      Author: dom
 */

#include "PropertySetter.h"

#include <iostream>

#include "1DLocation.h"
#include "2DLocation.h"
#include "Particle.h"

std::shared_ptr<AbstractProperties> PropertySetter::set(const PropertyType propertyType) {
	std::shared_ptr<AbstractProperties> property;
	switch(propertyType) {
	case PropertyType::ONED:
		property.reset(new OneDLocation());
		return property;
	case PropertyType::TWOD:
		property.reset(new TwoDLocation());
		return property;
	default:
		std::cout << "Property type UNDEFINED" << std::endl;
		break;
	}
	throw;
	return nullptr;
}

void PropertySetter::copyTo(const std::shared_ptr<AbstractProperties>& original,
		const std::shared_ptr<AbstractProperties>& copy) {
	copy->set(original->get());
}







/*
 * Particle.cpp
 *
 *  Created on: 5 Jul 2018
 *      Author: dom
 */

#include "Particle.h"

#include "tools.h"

#include "PropertySetter.h"

PropertyType Particle::_propertyType = PropertyType::UNDEFINED;

// public:
Particle::Particle(){
	_property = generateProperty();
	_velocity = 0.0;
	_cost = Tools::fRand(5.0, 10000.0);

	_personalBestValue = _cost;
	_personalBestProperty = _property;
}


std::weak_ptr<AbstractProperties> Particle::getProperty() const {
	return _property;
}

double
Particle::getCost() const {
	return _cost;
}

std::shared_ptr<AbstractProperties> Particle::generateProperty() {
	return PropertySetter::set(_propertyType);
}

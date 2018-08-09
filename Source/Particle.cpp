/*
 * Particle.cpp
 *
 *  Created on: 5 Jul 2018
 *      Author: dom
 */

#include "Particle.h"

#include <iostream>

#include "tools.h"

#include "PropertySetter.h"
#include "CostCalculator.h"

PropertyType Particle::_propertyType = PropertyType::UNDEFINED;
Cost::Type Particle::_costType = Cost::Type::SquaredFunction;

// public:
Particle::Particle(){
	_property = generateProperty();
	_velocity = 0.0;
	_cost = Cost::Calculator::calculate(_property, _costType);

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

double
Particle::getVelocity() const {
	return _velocity;
}

std::shared_ptr<AbstractProperties> Particle::generateProperty() {
	return PropertySetter::set(_propertyType);
}

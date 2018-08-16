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
	_personalBestProperty = generateProperty();
	PropertySetter::copyTo(_property, _personalBestProperty);
}


std::weak_ptr<AbstractProperties> Particle::getProperty() const {
	return _property;
}

std::shared_ptr<AbstractProperties> Particle::getHistorialBestProperty() const {
	return _personalBestProperty;
}


double
Particle::getCost() const {
	return _cost;
}

double
Particle::getVelocity() const {
	return _velocity;
}

void
Particle::getVelocity(Velocity& velocity) const {
	velocity = _vel;
}

void
Particle::updateLocation(const double velocity) {
	_velocity = velocity;
	_property->update(_velocity);
	updatePersonalData();
}

void
Particle::updateLocation(const Velocity& velocity) {
	_vel = velocity;
	_property->update(velocity);
	updatePersonalData();
}

std::shared_ptr<AbstractProperties> Particle::generateProperty() {
	return PropertySetter::set(_propertyType);
}

// private:

void
Particle::updatePersonalData() {
	_cost = Cost::Calculator::calculate(_property, _costType);
	updatePersonalBest();
}

void
Particle::updatePersonalBest() {
	if(_cost < _personalBestValue) {
		_personalBestValue = _cost;
		PropertySetter::copyTo(_property, _personalBestProperty);
	}
}






#include "Population.h"
#include <array>
#include <limits>
#include <iostream>

#include "PropertySetter.h"

Population::Population(const int nMembers, const int propertyType): _nMembers(nMembers),
		_globalBestCost(std::numeric_limits<double>::max()) {
	Particle::_propertyType = PropertyType::ONED;
	Particle::_costType = Cost::Type::SquaredFunction;
	_particles = new Particle[nMembers];
	updateGlobalBest();
}

Population::~Population() {
	delete[] _particles;
}

void Population::update() {
	OptimisationParameters optimisationParameters;
	for(int i = 0; i < _nMembers; ++i) {
		double velocity = calculateVelocity(i, optimisationParameters);
		_particles[i].updateLocation(velocity);
		optimisationParameters.reset();
	}
	updateGlobalBest();
	std::cout << _globalBestCost << std::endl;

	print();
}

void Population::updateGlobalBest() const {
	for(unsigned int i = 0; i < _nMembers; ++i) {
		const double& particleCost = _particles[i].getCost();
		if(_globalBestCost > particleCost) {
			_globalBestCost = particleCost;
			_globalBestProperty = _particles[i].getProperty();
		}
	}
}

double Population::getGlobalBest() const {
	return _globalBestProperty.lock()->get();
}

void Population::print() const {
	for(unsigned int i = 0; i < _nMembers; ++i) {
		_particles[i].getProperty().lock()->print();
	}
}

double Population::calculateVelocity(const int i,
		const OptimisationParameters ops) {

	std::weak_ptr<AbstractProperties> property = _particles[i].getProperty();
	std::weak_ptr<AbstractProperties> historialBest = _particles[i].getHistorialBestProperty();
	double currentPosition = property.lock()->get();
	double bestPosition = historialBest.lock()->get();

	double vectorToPersonalBest = bestPosition - currentPosition;
	double vectorToGlobalBest = getGlobalBest() - currentPosition;
	double inertia = ops._w*_particles[i].getVelocity();
	double cognitiveComponent = ops._c1*ops._r1*vectorToPersonalBest;
	double socialComponent = ops._c2*ops._r2*vectorToGlobalBest;
	return inertia + cognitiveComponent + socialComponent;

}










































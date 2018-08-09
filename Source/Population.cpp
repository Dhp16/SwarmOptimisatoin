#include "Population.h"
#include <array>
#include <limits>

#include "PropertySetter.h"

Population::Population(const int nMembers, const int propertyType): _nMembers(nMembers),
		_globalBestCost(std::numeric_limits<double>::max()) {
	Particle::_propertyType = PropertyType::ONED;
	Particle::_costType = Cost::Type::SquaredFunction;
	_particles = new Particle[nMembers];
}

Population::~Population() {
	delete[] _particles;
}

void Population::update() {
	OptimisationParameters optimisationParameters;
	for(int i = 0; i < _nMembers; ++i) {
		double velocity = calculateVeclocity(i, optimisationParameters);
		_particles[i].updateLocation(velocity)
		optimisationParameters.reset();
	}
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
	double vectorToPersonalBest = _particles[i] - _particles[i].getPosition();
	double vectorToGlobalBest = _globalBest - _particles[i].getPosition();
	double inertia = ops._w*_particles[i].getVelocity();
	double cognitiveComponent = ops._c1*ops._r1*vectorToPersonalBest;
	double socialComponent = ops._c2*ops._r2*vectorToGlobalBest;
	return inertia + cognitiveComponent + socialComponent;

}










































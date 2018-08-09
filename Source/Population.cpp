#include "Population.h"
#include <array>

#include "PropertySetter.h"

Population::Population(const int nMembers, const int propertyType,
		std::shared_ptr<Cost::AbstractCost> cost): _nMembers(nMembers),
		_globalBestCost(0.0) {
	Particle::_propertyType = PropertyType::TWOD;
	Particle::_costType = Cost::Type::SquaredFunction;
	_particles = new Particle[nMembers];
}

Population::~Population() {
	delete[] _particles;
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

void Population::setCost(const std::shared_ptr<Cost::AbstractCost> cost) {
	_cost = cost;
}

void Population::print() const {
	for(unsigned int i = 0; i < _nMembers; ++i) {
		_particles[i].getProperty().lock()->print();
	}
}










































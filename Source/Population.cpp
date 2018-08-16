#include "Population.h"
#include <array>
#include <limits>
#include <iostream>

#include "PropertySetter.h"
#include "Velocity.h"


std::vector<double> operator - (const std::vector<double>& vec1, const std::vector<double>& vec2) {
	std::vector<double> vector(vec1.size());
	for(unsigned int i = 0; i < vec1.size(); ++i) {
		vector[i] = vec1[i] - vec2[i];
	}
	return vector;
}

std::vector<double> operator * (const double scalar, const std::vector<double>& vec1) {
	std::vector<double> vector(vec1.size());
	for(unsigned int i = 0; i < vec1.size(); ++i) {
		vector[i] = vec1[i]*scalar;
	}
	return vector;
}

std::vector<double> operator + (const std::vector<double>& vec1, const std::vector<double>& vec2) {
	std::vector<double> vector(vec1.size());
	for(unsigned int i = 0; i < vec1.size(); ++i) {
		vector[i] = vec1[i] + vec2[i];
	}
	return vector;
}


Population::Population(const int nMembers, const int propertyType):
_nMembers(nMembers),
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
	for(unsigned int i = 0; i < _nMembers; ++i) {
		double velocity = calculateVelocity(i, optimisationParameters);
		_particles[i].updateLocation(velocity);
		optimisationParameters.reset();
	}
	updateGlobalBest();
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


void
Population::getGlobalBest(std::vector<double>& globalBest) const {
	_globalBestProperty.lock()->get(globalBest);
}


void Population::print() const {
	for(unsigned int i = 0; i < _nMembers; ++i) {
		_particles[i].getProperty().lock()->print();
	}
}

void
Population::printToFile(std::ofstream& file) const {
	for(unsigned int i = 0; i < _nMembers; ++i) {
		file << _particles[i].getCost() << " ";
	}
	file << std::endl;
}


// private:

double Population::calculateVelocity(const int i,
		const OptimisationParameters& ops) {

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

Velocity Population::calculateVelocity(const int i,
		const OptimisationParameters& ops, int k) {

	std::weak_ptr<AbstractProperties> property = _particles[i].getProperty();
	std::weak_ptr<AbstractProperties> historialBest = _particles[i].getHistorialBestProperty();
	std::vector<double> currentPosition, bestPosition, globalBest;
	property.lock()->get(currentPosition);
	historialBest.lock()->get(bestPosition);
	getGlobalBest(globalBest);

	std::vector<double> vectorToPersonalBest = bestPosition - currentPosition;
	std::vector<double> vectorToGlobalBest = globalBest - currentPosition;
	Velocity velocity;
	_particles[i].getVelocity(velocity);
	std::vector<double> inertia = ops._w*velocity.get();
	std::vector<double> cognitiveComponent = ops._c1*ops._r1*vectorToPersonalBest;
	std::vector<double> socialComponent = ops._c2*ops._r2*vectorToGlobalBest;
	return inertia + cognitiveComponent + socialComponent;
}









































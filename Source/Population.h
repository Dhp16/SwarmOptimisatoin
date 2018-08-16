/*
 * Population.h
 *
 *  Created on: 5 Jul 2018
 *      Author: dom
 */

#ifndef SOURCE_POPULATION_H_
#define SOURCE_POPULATION_H_

#include <numeric>
#include <memory>
#include <fstream>

#include "Particle.h"

#include "AbstractCost.h"
#include "AbstractProperties.h"
#include "OptimisationParameters.h"
#include "Velocity.h"

class Population {

public:

	Particle& operator [] (int index) {
		return _particles[index];
	}

	Population(const int nMembers, const int propertyType);
	~Population();
	unsigned int size() const {
		return _nMembers;
	}
	void print() const;
	double getGlobalBest() const;
	void getGlobalBest(std::vector<double>& globalBest) const;
	void update();

	void printToFile(std::ofstream& file) const;

private:
	void generateParticleProperties(const int propertyType);
	void updateGlobalBest() const;
	double calculateVelocity(const int index,
			const OptimisationParameters& ops);
	Velocity calculateVelocity(const int i,
			const OptimisationParameters& ops, int k);

private:
	Particle* _particles = nullptr;
	std::shared_ptr<Cost::AbstractCost> _cost = nullptr;
	unsigned int _nMembers = 0;
	mutable double _globalBestCost;
	double _globalBest;
	mutable std::weak_ptr<AbstractProperties> _globalBestProperty = std::weak_ptr<AbstractProperties>();
};



#endif /* SOURCE_POPULATION_H_ */



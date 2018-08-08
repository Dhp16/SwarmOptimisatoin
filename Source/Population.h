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

#include "Particle.h"

#include "AbstractCost.h"
#include "AbstractProperties.h"

class Population {

public:

	Particle& operator [] (int index) {
		return _particles[index];
	}

	Population(const int nMembers, const int propertyType,
			std::shared_ptr<Cost::AbstractCost> cost);
	~Population();
	void updateGlobalBest() const;
	void setCost(const std::shared_ptr<Cost::AbstractCost> cost);
	unsigned int size() const {
		return _nMembers;
	}
	void print() const;

private:
	void generateParticleProperties(const int propertyType);

private:
	Particle* _particles = nullptr;
	std::shared_ptr<Cost::AbstractCost> _cost = nullptr;
	unsigned int _nMembers = 0;
	mutable double _globalBestCost;
	mutable std::weak_ptr<AbstractProperties> _globalBestProperty = std::weak_ptr<AbstractProperties>();
};



#endif /* SOURCE_POPULATION_H_ */



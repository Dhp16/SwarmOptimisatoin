/*
 * Particle.h
 *
 *  Created on: 5 Jul 2018
 *      Author: dom
 */

#ifndef SOURCE_PARTICLE_H_
#define SOURCE_PARTICLE_H_

#include <vector>
#include <memory>

#include "AbstractProperties.h"

class Particle {

public:
	static PropertyType _propertyType;

	Particle();
	~Particle() = default;

	std::weak_ptr<AbstractProperties> getProperty() const;
	double getCost() const;
	void set(std::shared_ptr<AbstractProperties> property);

private:
	std::shared_ptr<AbstractProperties> generateProperty();

private:
	int _nVar = 0;
	std::shared_ptr<AbstractProperties> _property = nullptr;
	double _velocity = 0.0;
	double _cost = 0.0;

	double _personalBestValue = 0.0;
	std::weak_ptr<AbstractProperties> _personalBestProperty = std::weak_ptr<AbstractProperties>();
};



#endif /* SOURCE_PARTICLE_H_ */

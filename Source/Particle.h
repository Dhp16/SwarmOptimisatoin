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
#include "AbstractCost.h"
#include "Velocity.h"

class Particle {

public:
	static PropertyType _propertyType;
	static Cost::Type _costType;

	Particle();
	~Particle() = default;

	std::weak_ptr<AbstractProperties> getProperty() const;
	std::shared_ptr<AbstractProperties> getHistorialBestProperty() const;
	double getCost() const;
	void updateLocation(const double velocity);
	void updateLocation(const Velocity& velocity);
	double getVelocity() const;
	void getVelocity(Velocity& velocity) const;
	void set(std::shared_ptr<AbstractProperties> property);

private:
	std::shared_ptr<AbstractProperties> generateProperty();
	void updatePersonalData();
	void updatePersonalBest();

private:
	int _nVar = 0;
	double _velocity = 0.0;
	Velocity _vel = Velocity();

	std::shared_ptr<AbstractProperties> _property = nullptr;
	double _personalBestValue = 0.0;
	double _cost = 0.0;
	std::shared_ptr<AbstractProperties> _personalBestProperty = nullptr;
};



#endif /* SOURCE_PARTICLE_H_ */



















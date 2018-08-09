/*
 * Optimiser.h
 *
 *  Created on: 9 Aug 2018
 *      Author: dom
 */

#ifndef SOURCE_OPTIMISER_H_
#define SOURCE_OPTIMISER_H_

#include "Population.h"
#include "HyperParameters.h"
#include "OptimisationParameters.h"

class Optimiser {

public:
	Optimiser(Population& initialPop, const HyperParameters& hyperParameters);
	~Optimiser(){};

private:
	void setParameters();
	double velocity(double previousVelocity, double personalBest,
			double currentPosition);

	OptimisationParameters _parameters;
};




#endif /* SOURCE_OPTIMISER_H_ */

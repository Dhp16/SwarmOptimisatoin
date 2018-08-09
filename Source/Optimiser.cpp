#include "Optimiser.h"


#include "tools.h"

// will need to do a deep copy to keep the population

Optimiser::Optimiser(Population& population, const HyperParameters& hyperParameters) {

	for(int i = 0; i < hyperParameters._nMaxIterations; ++i) {
		population.updateProperties();
	}
}

double Optimiser::velocity(double previousVelocity, double personalBest, double currentPosition) {
	double vectorToPersonalBest = personalBest - currentPosition;
	double vectorToGlobalBest = _globalBest - currentPosition;
	double inertia = _w*previousVelocity;
	double cognitiveComponent = _c1*_r1*vectorToPersonalBest;
	double socialComponent = _c2*_r2*vectorToGlobalBest;
	return inertia + cognitiveComponent + socialComponent;
}



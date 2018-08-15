#include "Optimiser.h"

#include <iostream>


#include "tools.h"

// will need to do a deep copy to keep the population

Optimiser::Optimiser(Population& population, const HyperParameters& hyperParameters) {

	for(int i = 0; i < hyperParameters._nMaxIterations; ++i) {
		std::cout << "\nIteration: " << i << std::endl;
		population.update();
	}
}

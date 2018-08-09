#include <iostream>
#include <string>

#include <utility>
#include <vector>
#include <memory>

#include "AbstractCost.h"
#include "AbstractProperties.h"
#include "SquaredFunction.h"
#include "2DLocation.h"
#include "1DLocation.h"

#include "HyperParameters.h"
#include "Population.h"
#include "Optimiser.h"

int main() {

	std::cout << "Starting program\n\n" << std::endl;

	// pass these as iterators rather than cost/property types
	const int propertyType = 0;

	// PSO parameters
	HyperParameters hyperParameters;
	hyperParameters._nMaxIterations = 30;

	// Initialisation
	int swarmSize = 20;
	Population population(swarmSize, propertyType);
	population.print();


	Optimiser optimiser(population, hyperParameters);

	std::cout << "\n\nEnd of program" << std::endl;

	return 0;
}





































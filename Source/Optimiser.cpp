#include "Optimiser.h"

#include <iostream>
#include <fstream>

#include "tools.h"

// will need to do a deep copy to keep the population

Optimiser::Optimiser(Population& population, const HyperParameters& hyperParameters) {

	std::ofstream file;
	file.open("OutputFiles/positions.txt");

	for(int i = 0; i < hyperParameters._nMaxIterations; ++i) {
		std::cout << "\nIteration: " << i << std::endl;
		population.update();
		population.printToFile(file);
	}

	file.close();
}

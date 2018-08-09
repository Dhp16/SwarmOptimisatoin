#include <iostream>
#include <string>

#include <utility>
#include <vector>
#include <memory>

#include "AbstractCost.h"
#include "AbstractProperties.h"
#include "SquaredFunction.h"
#include "2DLocation.h"

#include "Population.h"

int main() {

	std::cout << "Starting program\n\n" << std::endl;

	// Problem definition
	std::shared_ptr<Cost::AbstractCost> cost;
	cost.reset(new Cost::SquaredFunction());

	std::shared_ptr<AbstractProperties> property;
	property.reset(new TwoDLocation());

	// pass these as iterators rather than cost/property types
	const int propertyType = 0;

	int nVar = 5; // number of dimensions
	int* decisionVariablesMatrix = new int[nVar];
	int varMin = -10; 	// lower bound
	int varMax = 10;	// upper bound

	std::vector<std::pair<double,double>> variablesBounds(nVar);
	for(auto bounds: variablesBounds) {
		bounds.first = -10;
		bounds.second = 10;
	}

	// PSO parameters
	int nMaxIterations = 500;
	int swarmSize = 400;

	double inertia = 1.;
	double cognitiveAcc = 2.0;
	double socialAcc = 2.0;

	// Initialisation

	Population population(swarmSize, propertyType, cost);

	population.print();

	std::cout << "\n\nEnd of program" << std::endl;

	return 0;
}





































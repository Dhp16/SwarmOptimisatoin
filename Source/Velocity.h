/*
 * Velocity.h
 *
 *  Created on: 15 Aug 2018
 *      Author: dom
 */

#ifndef SOURCE_VELOCITY_H_
#define SOURCE_VELOCITY_H_

#include <vector>

class Velocity {

public:
	Velocity() = default;

	Velocity(const unsigned int dimension): _dimension(dimension) {
		_values = std::vector<double>(_dimension);
	}

	Velocity(const std::vector<double>& velocity): _values(velocity),
			_dimension(velocity.size()) {

	}

	std::vector<double> get() const {
		return _values;
	}

	double operator[] (int index) const {
		return _values[index];
	}

private:
	unsigned int _dimension = 0;
	std::vector<double> _values = std::vector<double>();

};



#endif /* SOURCE_VELOCITY_H_ */

/*
 * AbstractProperties.h
 *
 *  Created on: 5 Aug 2018
 *      Author: dom
 */

#ifndef SOURCE_ABSTRACTPROPERTIES_H_
#define SOURCE_ABSTRACTPROPERTIES_H_

#include <memory>

#include "Velocity.h"

enum class PropertyType {UNDEFINED, ONED, TWOD};

class AbstractProperties {

public:
		~AbstractProperties();
		virtual void print() const = 0;
		virtual double get() const = 0;
		virtual void get(std::vector<double>& values) const = 0;
		virtual void update(const double velocity) = 0;
		virtual void update(const Velocity& velocity) = 0;
		virtual void set(const double position) = 0;
private:

};



#endif /* SOURCE_ABSTRACTPROPERTIES_H_ */

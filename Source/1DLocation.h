/*
 * 1DLocation.h
 *
 *  Created on: 9 Aug 2018
 *      Author: dom
 */

#ifndef SOURCE_1DLOCATION_H_
#define SOURCE_1DLOCATION_H_

#include <iostream>

#include "AbstractProperties.h"

#include "tools.h"

class OneDLocation : public AbstractProperties {
public:
	OneDLocation(){
		_x = Tools::fRand(-50.0, 50.0);
	};
	~OneDLocation(){

	};
	double getX() {
		return _x;
	}
	virtual double get() const override {
		return _x;
	}

	virtual void print() const override {
		std::cout << "_x: " << _x << std::endl;
	}

private:
	double _x = 0.0;
};





#endif /* SOURCE_1DLOCATION_H_ */

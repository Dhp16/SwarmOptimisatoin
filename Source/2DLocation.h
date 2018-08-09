/*
 * 2DLocation.h
 *
 *  Created on: 5 Aug 2018
 *      Author: dom
 */

#ifndef SOURCE_2DLOCATION_H_
#define SOURCE_2DLOCATION_H_

#include <iostream>

#include "AbstractProperties.h"

#include "tools.h"

class TwoDLocation : public AbstractProperties {
public:
	TwoDLocation(){
		_x = Tools::fRand(-50.0, 50.0);
		_y = Tools::fRand(-50.0, 50.0);
	};
	~TwoDLocation(){

	};
	double getX() {
		return _x;
	}

	virtual void print() const override {
		std::cout << "_x: " << _x << "  _y: " << _y << std::endl;
	}

private:
	double _x = 0.0;
	double _y = 0.0;
};



#endif /* SOURCE_2DLOCATION_H_ */

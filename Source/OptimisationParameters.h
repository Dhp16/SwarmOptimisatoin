/*
 * OptimisationParameters.h
 *
 *  Created on: 9 Aug 2018
 *      Author: dom
 */

#ifndef SOURCE_OPTIMISATIONPARAMETERS_H_
#define SOURCE_OPTIMISATIONPARAMETERS_H_

#include "tools.h"

struct OptimisationParameters {
	double _w;
	double _c1;
	double _c2;
	double _r1;
	double _r2;

	OptimisationParameters() {
		_w  = Tools::fRand(0.0, 1.2);
		_c1 = Tools::fRand(0.0, 2.0);
		_c2 = Tools::fRand(0.0, 2.0);
		_r1 = Tools::fRand(0.0, 1.0);
		_r2 = Tools::fRand(0.0, 1.0);
	};

	void reset() {
		_w  = Tools::fRand(0.0, 1.2);
		_c1 = Tools::fRand(0.0, 2.0);
		_c2 = Tools::fRand(0.0, 2.0);
		_r1 = Tools::fRand(0.0, 1.0);
		_r2 = Tools::fRand(0.0, 1.0);
	}
};



#endif /* SOURCE_OPTIMISATIONPARAMETERS_H_ */

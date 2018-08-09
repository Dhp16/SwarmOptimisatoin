/*
 * HyperParameters.h
 *
 *  Created on: 9 Aug 2018
 *      Author: dom
 */

#ifndef SOURCE_HYPERPARAMETERS_H_
#define SOURCE_HYPERPARAMETERS_H_

struct HyperParameters {
	double _intertia = 1.0;
	double _cognitiveAcceleration = 2.0;
	double _socialAcceleration = 2.0;
	double _nMaxIterations = 100;
};


#endif /* SOURCE_HYPERPARAMETERS_H_ */

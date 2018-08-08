/*
 * tools.cpp
 *
 *  Created on: 8 Aug 2018
 *      Author: dom
 */

#include "tools.h"

double Tools::fRand(const double fMin, const double fMax)
{
	double f = (double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
}

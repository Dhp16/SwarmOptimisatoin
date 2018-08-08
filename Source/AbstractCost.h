/*
 * AbstractCost.h
 *
 *  Created on: 5 Jul 2018
 *      Author: dom
 */

#ifndef SOURCE_ABSTRACTCOST_H_
#define SOURCE_ABSTRACTCOST_H_


namespace Cost {

	class AbstractCost {

	public:
		AbstractCost() = default;
		virtual ~AbstractCost() = default;
		virtual double get(const double x) const = 0;

	private:

	};

}



#endif /* SOURCE_ABSTRACTCOST_H_ */

/*
 * PropertySetter.h
 *
 *  Created on: 7 Aug 2018
 *      Author: dom
 */

#ifndef SOURCE_PROPERTYSETTER_H_
#define SOURCE_PROPERTYSETTER_H_

#include <memory>
#include "AbstractProperties.h"

class PropertySetter {
	public:
	PropertySetter() = default;
	~PropertySetter() = default;

	static std::shared_ptr<AbstractProperties> set(const PropertyType propertyType);

};



#endif /* SOURCE_PROPERTYSETTER_H_ */

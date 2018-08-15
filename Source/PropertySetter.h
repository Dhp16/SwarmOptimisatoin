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
	static void copyTo(const std::shared_ptr<AbstractProperties>& original,
			const std::shared_ptr<AbstractProperties>& copy);
};



#endif /* SOURCE_PROPERTYSETTER_H_ */

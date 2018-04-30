/*
 * ParameterMap.h
 *
 *  Created on: Apr 28, 2018
 *      Author: anderson
 */

#ifndef _ParameterMap_
#define _ParameterMap_

#include <map>
#include "SCC_DataType.h"

namespace SCC
{

class ParameterMap : public  std::map<string, SCC::DataType>
{
	public:

	ParameterMap(){};

	bool isParameter(const std::string& key) const
	{
	if(find(key) != end()) {return true;}
	return false;
	}

	SCC::DataType getParameterOrDefault(const std::string& key,const SCC::DataType& defaultValue)
	{
	if(isParameter(key)) return operator[](key);
	return defaultValue;
	}
};

}


#endif /* _ParameterMap_ */

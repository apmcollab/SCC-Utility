/*
 * ParameterMap.h
 *
 *  Created on: Apr 28, 2018
 *      Author: anderson
 */

#ifndef _ParameterMap_
#define _ParameterMap_

#include <map>
#include <iostream>
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


	friend ostream& operator<<(ostream& outStream, const SCC::ParameterMap& P)
	{
	for(auto it = P.cbegin(); it != P.cend(); ++it)
	{
	   outStream <<  it->first <<  "  "  << it->second << endl;
	}
	return outStream;
	}


};

}


#endif /* _ParameterMap_ */

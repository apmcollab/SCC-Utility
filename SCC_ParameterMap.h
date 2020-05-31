/*
 * ParameterMap.h
 *
 *  Created on: Apr 28, 2018
 *      Author: anderson
 */
/*
 This class creates an associative array that maps strings to
 standard C++ data types; different data types can be contained within
 the same instance.

 An instance of this class is a std::map object that is
 predefined to be a std::map<std::string, SCC_DataType> instance.

 The SCC_DataType is a container class for different C++ data types
 with conversions so that the contained data is converted to appropriate
 data types upon assignment.

 */
 /*
#############################################################################
#
# Copyright  2015 Chris Anderson
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the Lesser GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# For a copy of the GNU General Public License see
# <http://www.gnu.org/licenses/>.
#
#############################################################################
*/

#include "SCC_DataType.h"
#include <map>
#include <iostream>
#include <string>

#ifndef SCC_ParameterMap_H_
#define SCC_ParameterMap_H_

namespace SCC
{

class ParameterMap : public  std::map<std::string, SCC::DataType>
{
	public:

	ParameterMap(){};

	bool isParameter(const std::string& key) const
	{
	if(find(key) != end()) {return true;}
	return false;
	}

	SCC::DataType  getParameterOrDefault(const std::string& key, const SCC::DataType& defaultValue)
	{
	if(isParameter(key)) return operator[](key);
	return defaultValue;
	}


    void setParameters(const ParameterMap& P)
    {
	for(auto it =  P.cbegin(); it !=  P.cend(); ++it)
	{
		this->operator[](it->first) = it->second;
	}
    }

	friend std::ostream& operator<<(std::ostream& outStream, const SCC::ParameterMap& P)
	{
	for(auto it = P.cbegin(); it != P.cend(); ++it)
	{
	   outStream <<  it->first <<  "  "  << it->second << std::endl;
	}
	return outStream;
	}


};

}


#endif /* _ParameterMap_ */

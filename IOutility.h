/*
 * IOutility.h
 *
 *  Created on: Jul 6, 2017
 *      Author: anderson
 */

/*
#############################################################################
#
# Copyright 2016 Chris Anderson
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


#include <sys/stat.h>
#include <string>

#ifndef SCC_UTILITY_IOUTILITY_H_
#define SCC_UTILITY_IOUTILITY_H_

class IOutility
{

public:

inline bool isFile(const std::string& name)
{
  struct stat buffer;
  return (stat (name.c_str(), &buffer) == 0);
}

};



#endif /* SCC_UTILITY_IOUTILITY_H_ */

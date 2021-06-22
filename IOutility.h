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

#ifndef _MSC_VER
#include <sys/stat.h>
#endif

#include <fstream>
#include <string>

#ifndef IOutility_H_
#define IOutility_H_

class IOutility
{
public:

#ifndef _MSC_VER
inline bool isFile(const std::string& name)
{
  struct stat buffer;
  return (stat (name.c_str(), &buffer) == 0);
}
#else
inline bool isFile(const std::string& name)
{
    std::ifstream f(name.c_str());
    return f.good();
}
#endif

#ifndef _MSC_VER
inline bool isFile(const std::string& directory, const std::string& name)
{
   std::string fileName = directory + "/" + name;
  struct stat buffer;
  return (stat (fileName.c_str(), &buffer) == 0);
}
#else
inline bool isFile(const std::string& directory, const std::string& name)
{
	std::string fileName = directory + "\\" + name;
    std::ifstream f(fileName.c_str());
    return f.good();
}
#endif


};

#endif

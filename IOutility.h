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


#include <fstream>
#include <string>


#if __cplusplus > 301402L
#include <filesystem>
#define CPP_FILESYSTEM
#else
#include <sys/stat.h>
#undef CPP_FILESYSTEM
#endif

#ifndef IOutility_H_
#define IOutility_H_

class IOutility
{
public:

#ifdef CPP_FILESYSTEM
static inline bool isFile(const std::string& name)
{
return std::filesystem::exists(name);
}
#elif _MSC_VER
static inline bool isFile(const std::string& name)
{
  struct stat buffer;
  return (stat (name.c_str(), &buffer) == 0);
}
#else
static inline bool isFile(const std::string& name)
{
    std::ifstream f(name.c_str());
    return f.good();
}
#endif

#ifdef CPP_FILESYSTEM
static inline bool createDirectory(const std::string& name)
{
	std::filesystem::path newDir(name);
    if(not std::filesystem::create_directory(newDir))
    {
    	return false;
    }
    //
    // set the permissions to 0755
    //
    std::filesystem::permissions(name, std::filesystem::perms::others_write | std::filesystem::perms::group_write,
    	                               std::filesystem::perm_options::remove);
    return true;
}
#else
static inline bool createDirectory(const std::string& name, mode_t mode = 0755)
{
	return mkdir(name.c_str(),mode);
}
#endif




#ifndef _MSC_VER
static inline bool isFile(const std::string& dirName, const std::string& name)
{
  std::string fileName = dirName + "/" + name;
  struct stat buffer;
  return (stat (fileName.c_str(), &buffer) == 0);
}
#else
static inline bool isFile(const std::string& dirName, const std::string& name)
{
	std::string fileName = dirName + "\\" + name;
    std::ifstream f(fileName.c_str());
    return f.good();
}
#endif

// Returns true if an error is found in opening the file and appends
// to the error message


static bool checkFileSpecifiedError(const std::string& name, const std::string& routineName, std::string& errMsg)
{
	if(isFile(name)){return false;}
	errMsg.append("\nXXXXX ");
	errMsg.append(routineName  + " specified file not found \n");
    errMsg.append("File name : ");
	errMsg.append(name);
	errMsg.append("\n");
	return true;
}

// Returns true if an error is found in opening the file and appends
// to the error message
#ifndef _MSC_VER
static bool checkFileSpecifiedError(const std::string& dirName, const std::string& name, const std::string& routineName, std::string& errMsg)
{
	std::string fileName = dirName + "/" + name;
	if(isFile(fileName)){return false;}
    errMsg.append("\nXXXXX ");
	errMsg.append(routineName  + " specified file not found \n");
    errMsg.append("Directory name : ");
	errMsg.append(dirName);
	errMsg.append("\n");
	errMsg.append("File name      : ");
	errMsg.append(name);
	errMsg.append("\n");
	return true;
}
#else
static bool checkFileSpecifiedError(const std::string& dirName, const std::string& name, const std::string& routineName, std::string& errMsg)
{
	std::string fileName = dirName + "\\" + name;
	if(isFile(fileName)){return false;}
    errMsg.append("\nXXXXX ");
	errMsg.append(routineName  + " specified file not found \n");
    errMsg.append("Directory name : ");
	errMsg.append(dirName);
	errMsg.append("\n");
	errMsg.append("File name : ");
	errMsg.append(name);
	errMsg.append("\n");
	return true;
}
#endif
};
#endif

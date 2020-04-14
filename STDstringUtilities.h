#ifndef STDstringUtilities_
#define STDstringUtilities_

#include <sys/stat.h>

#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

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


#define SPACES " \t\r\n"

#define _LOCAL_PATH_MAX 4096

class STDstringUtilities
{

public:

inline std::string trim_right (const std::string & s, const std::string & t = SPACES)
  { 
  std::string d (s);
  std::string::size_type i (d.find_last_not_of (t));
  if (i == std::string::npos)
    return "";
  else
   return d.erase (d.find_last_not_of (t) + 1) ; 
  }  // end of trim_right

inline std::string trim_left (const std::string & s, const std::string & t = SPACES)
  { 
  std::string d (s);
  return d.erase (0, s.find_first_not_of (t)) ; 
  }  // end of trim_left

inline std::string trim (const std::string & s, const std::string & t = SPACES)
  { 
  std::string d (s);
  return trim_left (trim_right (d, t), t) ; 
  }  // end of trim
  



void replaceFirstSubstring(std::string& str,const std::string& str1,const std::string& str2)
{
    std::string::size_type pos  = str.find(str1, 0);
    if(pos != std::string::npos )
    {
        str.replace(pos, str1.size(), str2);
    }
}

void replaceAllSubstring(std::string& str,const std::string& str1,const std::string& str2)
{
    std::string::size_type pos = 0;
    while ( (pos = str.find(str1, pos)) != std::string::npos ) {
        str.replace( pos, str1.size(), str2 );
        pos++;
    }
}

void toUpper(std::string& str)
{
	std::transform(str.begin(), str.end(), str.begin(),[](unsigned char c)
	{return std::toupper(c); });
}

void toLower(std::string& str)
{
	std::transform(str.begin(), str.end(), str.begin(),[](unsigned char c)
	{return std::tolower(c); });
}


std::string getBaseFilename(const std::string& filename)
{
    size_t pos = filename.rfind(".");
    if(pos == std::string::npos)  //No extension.
        return filename;

    if(pos == 0)    //. is at the front. Not an extension.
        return filename;
    return filename.substr(0, pos);
}

void Tokenize(const std::string& str,std::vector<std::string>& tokens, const std::string& delimiters = " ")
{
    // Skip delimiters at beginning.
    std::string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    // Find first "non-delimiter".
    std::string::size_type pos     = str.find_first_of(delimiters, lastPos);

    while (std::string::npos != pos || std::string::npos != lastPos)
    {
        // Found a token, add it to the vector.
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        // Skip delimiters.  Note the "not_of"
        lastPos = str.find_first_not_of(delimiters, pos);
        // Find next "non-delimiter"
        pos = str.find_first_of(delimiters, lastPos);
    }
}

//#####################################################
//  Utilities for string containing file names 
//
//  Since code w.r.t. file and path names os OS specific,
//  separate versions are required for
//  Linux/Unix systems (the default) and Microsoft OS's. 
//#####################################################
std::string getBasePath(const std::string& fileName)
{
	const char *symlinkpath = fileName.c_str();
	char *actualpath;
    char pathBuffer[_LOCAL_PATH_MAX];
	string actualPath;
	string   basePath;
	#ifndef _MSC_VER
    actualpath =   realpath(symlinkpath, pathBuffer);
    #else
    actualpath =  _fullpath(pathBuffer,symlinkpath,_LOCAL_PATH_MAX);
    #endif

    if (actualpath != NULL)
    {
        actualPath.assign(actualpath);
    	basePath   = actualPath.substr(0,actualPath.find_last_of("/\\"));
    	return basePath;
   }
   return basePath;
}

std::string getCWD()
{
	char *actualpath;
	std::string actualPath;
	char   pathBuffer[_LOCAL_PATH_MAX];

#ifndef _MSC_VER
	actualpath = realpath("./", pathBuffer);
#else
	actualpath = _fullpath(pathBuffer, "./", _LOCAL_PATH_MAX);
#endif

    if (actualpath != NULL)
    {
    	actualPath.assign(actualpath);
   }
   return actualPath;
}

std::string getBaseName(std::string& fileName)
{
	const char *symlinkpath = fileName.c_str();
	char *actualpath;

	std::string actualPath;
	std::string   baseName;
	char   pathBuffer[_LOCAL_PATH_MAX];

#ifndef _MSC_VER
	actualpath = realpath(symlinkpath, pathBuffer);
#else
	actualpath = _fullpath(pathBuffer, symlinkpath, _LOCAL_PATH_MAX);
#endif
    if (actualpath != NULL)
    {
    	actualPath.assign(actualpath);
    	baseName = actualPath.substr(actualPath.find_last_of("/\\")+1);
    	return baseName;
   }
   else // Just strip away all directory modifiers
   {
	baseName = fileName.substr(fileName.find_last_of("/\\")+1);
   }
   return baseName;
}

bool fileExists(const std::string fileName)
{
	struct stat buffer;
	return (stat(fileName.c_str(), &buffer) == 0);
}



};

#undef _LOCAL_PATH_MAX
#undef SPACES
#endif

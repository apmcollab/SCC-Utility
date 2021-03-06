#ifndef CmdOptionUtility_H
#define CmdOptionUtility_H

#include <stdexcept>
#include <algorithm>
#include <string>
//
// CmdOptionUtility is a "minimal" self-contained
// class to assist in parsing command line options
//
// *) All options must be specified with an option string
// *) An option string must begin with a "-"
// *) An option argument cannot begin with a "-" unless it is a negative number
//
// All option arguments are read in as strings.
//
// Data conversion and "usage" messages (typically triggered by -h ) must
// be externally coded.
//
// If cmdOptionUtility is a class instance then
// typical usage
//
// int main(int argc, char* argv[])
// {
//
// /* For options with no arguments */
//
// if(cmdOptionUtility.isNoArgCmdOption(argc,argv,"option"))
// {
// ... process  option
// }
//
// /* For options with arguments */
//
// string inputOption = cmdOptionUtility.getCmdOption(argc,argv,"option");
// {
// ... if inputOption.size() > 0 process option
// }
//
// A std::invalid_argument exception is thrown if an option with no argument is supplied with one,
// or if an option that requires an argument isn't supplied with one.
//
// Chris Anderson Sept. 17, 2012
// Updated 4/13/2020
//
/*
#############################################################################
#
# Copyright 2017 Chris Anderson
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
class CmdOptionUtility
{
    public:

	std::string getCmdOption(int argc, char* argv[], const std::string & option)
	{
	std::string optionValue;
	char**   end = argc + argv;
    char ** itr  = std::find(argv, end, option);
    bool errorFlag = false;
    if ((itr != end) && (++itr != end))
    {
        optionValue.assign(*itr);
        if(optionValue[0] == '-')      // Possible missing argument
        {
        	if(optionValue.size() > 1)  // Check to see if argument is a negative number
        	{
        	if((int)optionValue[1] > 58) { errorFlag = true;}
            }
            else
            {errorFlag = true;}
        }
    }


    std::string errorString;
    if(errorFlag)
    {
    errorString   =  (std::string)"\nXXXXXXXXXXXXXX   Error  XXXXXXXXXXXXXXXXXXX\n" +
                     (std::string)"Command line option " + option +
                     (std::string)" requires an argument\n" +
                     (std::string)"XXXXXXX     Program Terminated    XXXXXXXX\n";
    throw std::invalid_argument(errorString);
    }
    return optionValue;
    }

    bool isCmdOption(int argc, char* argv[], const std::string& option)
    {
    char** end  = argc + argv;
    if(std::find(argv, end, option) != end) return true;
    return false;
    }

    bool isNoArgCmdOption(int argc, char* argv[], const std::string& option)
    {
    std::string errorString;
    char**  end = argc + argv;
    char ** itr = std::find(argv, end, option);
    if(itr != end)
    {
    if(++itr != end)
    {
     if(*(itr)[0] != '-')
     {
        errorString   =   (std::string)"\nXXXXXXXXXXXXXX   Error  XXXXXXXXXXXXXXXXXXX\n" +
                          (std::string)"Command line option " + option +
                          (std::string)" requires NO argument\n" +
                          (std::string)"XXXXXXX     Program Terminated    XXXXXXXX\n";
        throw std::invalid_argument(errorString);
     }
     else
     {
     return true;
     }
    }
    else
    {return true;}
    }
    return false;
    }
};




#endif

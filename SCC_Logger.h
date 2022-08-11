/*
 * Logger.h
 *
 *  Created on: August 11, 2022
 *      Author: anderson
 */

//
// A not particularly sophisticated class whose instances using stdio (C) output (for formatting reasons)
// functionality to output to a log file using a specified file pointer.
//
// After each output invocation the buffer is flushed so that file contents are
// updated immediately.
//
// The opening and closing of the file accessed using the FILE pointer must be done externally.
//
// The destruction of a class instance does not close the file accessed by the FILE pointer.
//

/*
#############################################################################
#
# Copyright  2022 Chris Anderson
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

#include <string>
#include <ctime>
#include <vector>
#include <cstdio>

#include "Utility/STDstringUtilities.h"

#ifndef LOGGER_
#define LOGGER_

namespace SCC
{
class Logger
{

	public:

	Logger()
	{initialize();}

    Logger(const Logger& M)
    {initialize(M);}

    Logger(FILE *LogFout)
	{initialize(LogFout);}

	void initialize()
    {LogFout = 0;}

    void initialize(FILE *LogFout)
    {this->LogFout = LogFout;}

    void initialize(const Logger& M)
    {LogFout = M.LogFout;}

    bool isLogging()
    {
    if(LogFout != 0) return true;
    return false;
    }

    void timeStamp(std::string message = "")
    {
    struct tm when;
    time_t now; time(&now);
    when = *localtime( &now );

    //Www Mmm dd hh:mm:ss yyyy
    std::string dateString(asctime( &when ));

    std::vector<std::string> dateTokens;
    sUtilities.Tokenize(dateString,dateTokens," \n\r\0");

    fprintf(LogFout,":  %s  : %s \n",dateTokens[3].c_str(), message.c_str()); fflush(LogFout);
    fflush(LogFout);
    }

    void timeAndDateStamp(std::string message = "")
    {
    struct tm when;
    time_t now; time(&now);
    when = *localtime( &now );

    //Www Mmm dd hh:mm:ss yyyy
    std::string dateString(asctime( &when ));

    std::vector<std::string> dateTokens;
    sUtilities.Tokenize(dateString,dateTokens," \n\r\0");

    fprintf(LogFout,":  %s  : %s %s %s %s :  %s \n",dateTokens[3].c_str(),
    		                                    dateTokens[0].c_str(),
    		                                    dateTokens[1].c_str(),
												dateTokens[2].c_str(),
												dateTokens[4].c_str(),
												message.c_str()); fflush(LogFout);
    fflush(LogFout);
    }


    void programHaltMessage()
    {
    	timeStamp("Program halted");
    }

    void operator()(const std::string& message)
    {
    fprintf(LogFout,"XXXXXXXXXXX    %s\n",message.c_str()); fflush(LogFout);
    }

    void operator()(const std::string& messageWithFormat, long val1)
    {
    std::string output("XXXXXXXXXXX    ");
    output.append(messageWithFormat);
    fprintf(LogFout,output.c_str(),val1); fflush(LogFout);
    }

    void operator()(const std::string& messageWithFormat, double val1)
    {
    std::string output("XXXXXXXXXXX    ");
    output.append(messageWithFormat);
    fprintf(LogFout,output.c_str(),val1); fflush(LogFout);
    }

    void operator()(const std::string& messageWithFormat, double val1, double val2 )
    {
    std::string output("XXXXXXXXXXX    ");
    output.append(messageWithFormat);
    fprintf(LogFout,output.c_str(),val1,val2); fflush(LogFout);
    }

    void operator()(const std::string& messageWithFormat, long val1, double val2 )
    {
    std::string output("XXXXXXXXXXX    ");
    output.append(messageWithFormat);
    fprintf(LogFout,output.c_str(),val1,val2); fflush(LogFout);
    }

    void operator()(const std::string& messageWithFormat, long val1, double val2, double val3 )
    {
    std::string output("XXXXXXXXXXX    ");
    output.append(messageWithFormat);
    fprintf(LogFout,output.c_str(),val1,val2,val3); fflush(LogFout);
    }

    FILE *LogFout;
    STDstringUtilities sUtilities;
};

}// namespace SCC
#endif /* _Logger_*/

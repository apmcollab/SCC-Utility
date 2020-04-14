/*
 * DateTimeUtility.h
 *
 *  Created on: Jun 15, 2017
 *      Author: anderson
 */

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

#ifndef DateTimeUtility_
#define DateTimeUtility_

#include <string>
#include <ctime>
#include <cstdint>

#include "STDstringUtilities.h"

class DateTimeUtility
{
public:

std::string getAsciiTime()
{
    STDstringUtilities stringUtil;
    struct tm when; time_t now; time(&now); when = *localtime( &now );
	std::string timeString = asctime(&when);
	timeString = stringUtil.trim(timeString);
	return timeString;
}

// To facilitate reading and writing binary representations
// of the hash, this routine returns a hash of the time string
// as an std::uint64_t, a fixed width size integer.

std::uint64_t getTimeHash()
{
    time_t rawtime;
    time (&rawtime);
    std::size_t timeHash = str_hash(ctime(&rawtime));
    return (std::uint64_t)timeHash;
}
std::hash<std::string> str_hash;


};




#endif /* +DateTimeUtility_ */

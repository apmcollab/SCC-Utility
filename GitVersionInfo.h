 /*
 * GitVersionInfo.h
 *
 *  Created on: Aug 1, 2021
 *      Author: anderson
 */
/*
#############################################################################
#
# Copyright 2021 Chris Anderson
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

#ifndef GIT_VERSION_INFO_

#ifndef GIT_REV_COUNT_
#define GIT_REV_COUNT_ 0
#endif
#ifndef GIT_HASH_
#define GIT_HASH_ "NONE   "
#endif
#ifndef GIT_DATE_
#define GIT_DATE_ " NONE"
#endif

#ifndef BLAS_TYPE_
#define BLAS_TYPE_ "NONE"
#endif

#ifndef FFTW_TYPE_
#define FFTW_TYPE_ "NONE"
#endif

#ifndef THREADED_
#define THREADED_ false
#else
#define THREADED_ true
#endif

class GitVersionInfo
{
public:

	GitVersionInfo()
	{
		//buildVersion = (long)GIT_REV_COUNT_;
		buildDate    = std::string(GIT_DATE_).substr(1,20);
		buildID      = std::string(GIT_HASH_).substr(0,7);
		blasType     = BLAS_TYPE_;
		fftwType     = FFTW_TYPE_;
	}

	GitVersionInfo(const GitVersionInfo& G)
	{
		//buildVersion = G.buildVersion;
		buildDate    = G.buildDate;
		buildID      = G.buildID;
		blasType     = G.blasType;
		fftwType     = G.fftwType;
	}

	std::string getVersionMsg()
	{
		//std::string versionMsg = "############# Build       : ";
		//versionMsg  = versionMsg + std::to_string(buildVersion) + "\n";
	    std::string versionMsg   =  "############# Build_Date  : " + buildDate + "\n";
        versionMsg  = versionMsg +  "############# Build_ID    : " + buildID + "\n";
        if(blasType.compare("NONE"))
        {
        if(THREADED_)
        {
        versionMsg  = versionMsg +  "############# BLAS_type   : OPENBLAS_THREADED \n";
        }
        else
        {
        versionMsg  = versionMsg +  "############# BLAS_type   : " + blasType + "\n";
        }}

        if(fftwType.compare("NONE"))
        {
        versionMsg  = versionMsg +  "############# FFTW_type   : " + fftwType + "\n";
        }

        return versionMsg;
	}

	//long getBuildVersion() const
	//{
	//	return buildVersion;
	//}

	std::string getBuildDate() const
	{
		return buildDate;
	}

	std::string getBuildID() const
	{
		return buildID;
	}
	//long     buildVersion;
    std::string buildDate;
	std::string   buildID;

	std::string   blasType;
	std::string   fftwType;
};

#undef GIT_REV_COUNT_
#undef GIT_HASH_
#undef GIT_DATE_
#undef BLAS_TYPE_
#undef FFTW_TYPE_
#undef THREADED_

// The CMakelists.txt entries that pack the defines used by the GitVersionInfo
// class are
/*
find_package (Git)
if (GIT_FOUND)
    execute_process(
    COMMAND $${GIT_EXECUTABLE} rev-list --all --count
    RESULT_VARIABLE RESULT
    OUTPUT_VARIABLE GIT_BUILD_VERSION
    OUTPUT_STRIP_TRAILING_WHITESPACE)
    message(STATUS "Build Version $${GIT_BUILD_VERSION}")
    add_compile_definitions(GIT_REV_COUNT_=$${GIT_BUILD_VERSION})
    execute_process(
    COMMAND $${GIT_EXECUTABLE} rev-list --max-count=1 HEAD
    RESULT_VARIABLE RESULT
    OUTPUT_VARIABLE GIT_HASH
    OUTPUT_STRIP_TRAILING_WHITESPACE)
    message(STATUS "Build hash $${GIT_HASH}")
    add_compile_definitions(GIT_HASH_="$${GIT_HASH}")
    execute_process(
    COMMAND $${GIT_EXECUTABLE} show --no-patch --no-notes --pretty='%ci' $${GIT_HASH}
    RESULT_VARIABLE RESULT
    OUTPUT_VARIABLE GIT_DATE
    OUTPUT_STRIP_TRAILING_WHITESPACE)
    message(STATUS "Build date $${GIT_DATE}")
    add_compile_definitions(GIT_DATE_="$${GIT_DATE}")
endif (GIT_FOUND)

*/

#endif // GIT_VERSION_INFO_/*


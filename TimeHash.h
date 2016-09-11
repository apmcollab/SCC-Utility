/*
 * TimeHash.h
 *
 *  Created on: May 17, 2016
 *      Author: anderson
 */

#ifndef _TimeHash_
#define _TimeHash_

#include <functional>
#include <string>
#include <ctime>
#include <cstdint>
using namespace std;

class TimeHash
{
public:

	TimeHash(){};
	virtual ~TimeHash(){};

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
#endif


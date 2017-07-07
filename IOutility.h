/*
 * IOutility.h
 *
 *  Created on: Jul 6, 2017
 *      Author: anderson
 */

#include <sys/stat.h>
#include <string>
using namespace std;

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

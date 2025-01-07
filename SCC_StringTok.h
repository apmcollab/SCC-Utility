/*
 * SCC_stringTok.h
 *
 *  Created on: Jan 6, 2025
 *      Author: anderson
 */
#include <vector>
#include <string>

#ifndef STRING_TOK_
#define STRING_TOK_

namespace SCC
{
// Class StringTok decomposes a std::string into individual string tokens, based
// upon delimiter(s) specified.
//
// This class was created to replace the use of the cstring function strtok().
// Usage of the class is similar to that for strtok() but not an identical drop
// in replacement.
//
// The class is thread safe: if separate instances are associated with
// distinct threads, invocations of nextToken() or nextTokenPtr() by
// separate instances will not interfere with one another.
//
// The std::string instance being tokenized is unaltered.
//

class StringTok
{
public:

    // Tokenizes the input std::string using delimiter(s) specified as characters
	// in the delimiters string, and sets the tokenIndex to 0.
	//
	// If the delimiters argument is not specified, the default delimiter of a space
	// is used.
	//
	// The input std::string is unaltered;
	//

	StringTok(const std::string& str,const std::string& delimiters = " ")
	{
		initialize(str,delimiters);
	}

    StringTok()
	{
		 initialize();
	}


    virtual ~StringTok(){};

    // nextTokenPtr() returns a char* pointer to next token if available and updates
    // the token index, otherwise returns a null pointer

	char* nextTokenPtr()
	{
		char* returnPtr = nullptr;
		if(tokenIndex < tokenCount)
		{
	    returnPtr = tokens[tokenIndex].data();
		tokenIndex += 1;
		return returnPtr;
		}
		return returnPtr;
	}

	// nextToken() returns a copy of the next token if available
	// and updates the token index, otherwise returns a null string.

	std::string nextToken()
	{
		std::string returnStr = std::string();
		if(tokenIndex < tokenCount)
		{
	    returnStr = tokens[tokenIndex];
		tokenIndex += 1;
		return returnStr;
		}
		return returnStr;
	}

	//
	// Returns the vector of std::string tokens created
	// with instantiation or initialization of the class.
	//
	std::vector<std::string> getTokens() const
	{
		return tokens;
	}

	void initialize()
	{
		tokens.clear();
		tokenCount  = 0;
		tokenIndex  = 0;
	}

	// Tokenizes the input std::string using delimiter(s) specified as characters
	// in the delimiters string, and sets the tokenIndex to 0.
	//
	// If the delimiters argument is not specified, the default delimiter of a space
	// is used.
	//
	//
	// The input std::string is unaltered;
	//
	void initialize(const std::string& str,const std::string& delimiters = " ")
	{
	initialize();
	tokenize(str,tokens,delimiters);
	tokenCount = tokens.size();
	tokenIndex = 0;
	}

	size_t getTokenCount()
	{
		return tokenCount;
	}

	size_t tokenCount;
	size_t tokenIndex;

	std::vector<std::string> tokens;

protected:

	void tokenize(const std::string& str,std::vector<std::string>& tokens, const std::string& delimiters = " ")
	{
    std::string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    std::string::size_type pos     = str.find_first_of(delimiters, lastPos);

    while (std::string::npos != pos || std::string::npos != lastPos)
    {
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        lastPos = str.find_first_not_of(delimiters, pos);
        pos = str.find_first_of(delimiters, lastPos);
    }
	}
};


}
#endif /* STRING_TOK_ */

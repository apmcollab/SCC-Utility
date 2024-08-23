/*
 * Base64.h
 *
 *  Created on: May 3, 2017
 *  Author    : anderson
 */

#ifndef Base64_H_
#define Base64_H_

//
// Class Base64: A class for conversion to and from Base64 character encoding.
//
// From http://stackoverflow.com/questions/180947/base64-decode-snippet-in-c
// with minor modifications.
//
// Modifications:
//
// Placed all code in the header and removed static declarations (the latter to
// facilitate usage in a multi-threaded environment).
//
// Added encodeXXX(...) and decodeXXX(...) to work with vector<XXX> where XXX
// are double, float, long and int. These were added to facilitate
// the primary use case of creating an XML representation of arrays of
// standard data types.
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


#include <vector>
#include <string>
#include <cstring>
typedef unsigned char BYTE;

class Base64
{
public:

const BYTE from_base64[128]     = { 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
                                    255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
                                    255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,  62, 255,  62, 255,  63,
                                     52,  53,  54,  55,  56,  57,  58,  59,  60,  61, 255, 255, 255, 255, 255, 255,
                                    255,   0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12,  13,  14,
                                     15,  16,  17,  18,  19,  20,  21,  22,  23,  24,  25, 255, 255, 255, 255,  63,
                                    255,  26,  27,  28,  29,  30,  31,  32,  33,  34,  35,  36,  37,  38,  39,  40,
                                     41,  42,  43,  44,  45,  46,  47,  48,  49,  50,  51, 255, 255, 255, 255, 255};

const char to_base64[65] =
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz"
            "0123456789+/";


std::string encodeInt(const std::vector<int>& intData)
{
	if (intData.empty()) return "";
    return encode((const BYTE*)&intData[0], (size_t)(intData.size()*sizeof(int)));
}

std::vector<int> decodeInt(const std::string& encodedData)
{
	std::vector<BYTE>   dataDecoded = decode(encodedData);
	std::vector<int> data(dataDecoded.size()/sizeof(int));
	std::memcpy(&data[0],&dataDecoded[0],dataDecoded.size());
	return data;
}


std::string encodeLong(const std::vector<long>& longData)
{
	if (longData.empty()) return "";
    return encode((const BYTE*)&longData[0], (size_t)(longData.size()*sizeof(long)));
}

std::vector<long> decodeLong(const std::string& encodedData)
{
	std::vector<BYTE>   dataDecoded = decode(encodedData);
	std::vector<long> data(dataDecoded.size()/sizeof(long));
	std::memcpy(&data[0],&dataDecoded[0],dataDecoded.size());
	return data;
}

std::string encodeSingleLong(const long& longData)
{
    return encode((const BYTE*)&longData, (size_t)(sizeof(long)));
}

long decodeSingleLong(const std::string& encodedData)
{
	std::vector<BYTE>   dataDecoded = decode(encodedData);
	long                data;
	std::memcpy(&data,&dataDecoded[0],dataDecoded.size());
	return data;
}


std::string encodeSingleFloat(const float& floatData)
{
    return encode((const BYTE*)&floatData, (size_t)(sizeof(float)));
}

float decodeSingleFloat(const std::string& encodedData)
{
	std::vector<BYTE>   dataDecoded = decode(encodedData);
	float               data;
	std::memcpy(&data,&dataDecoded[0],dataDecoded.size());
	return data;
}

std::string encodeSingleDouble(const double& doubleData)
{
    return encode((const BYTE*)&doubleData, (size_t)(sizeof(double)));
}

double decodeSingleDouble(const std::string& encodedData)
{
	std::vector<BYTE>   dataDecoded = decode(encodedData);
	double              data;
	std::memcpy(&data,&dataDecoded[0],dataDecoded.size());
	return data;
}


std::string encodeFloat(const std::vector<float>& floatData)
{
	if (floatData.empty()) return "";
    return encode((const BYTE*)&floatData[0], (size_t)(floatData.size()*sizeof(float)));
}

std::string encodeFloat(size_t dataSize, const float* floatData)
{
	if (dataSize == 0) return "";
    return encode((const BYTE*)&floatData[0],(size_t)(dataSize*sizeof(float)));
}

std::vector<float> decodeFloat(const std::string& encodedData)
{
	std::vector<BYTE>   dataDecoded = decode(encodedData);
	std::vector<float> data(dataDecoded.size()/sizeof(float));
	std::memcpy(&data[0],&dataDecoded[0],dataDecoded.size());
	return data;
}

std::string encodeDouble(const std::vector<double>& doubleData)
{
	if (doubleData.empty()) return "";
    return encode((const BYTE*)&doubleData[0], (size_t)(doubleData.size()*sizeof(double)));
}

std::string encodeDouble(size_t dataSize, const double* doubleData)
{
	if (dataSize == 0) return "";
    return encode((const BYTE*)&doubleData[0],(size_t)(dataSize*sizeof(double)));
}

std::vector<double> decodeDouble(const std::string& encodedData)
{
	std::vector<BYTE>   dataDecoded = decode(encodedData);
	std::vector<double> data(dataDecoded.size()/sizeof(double));
	std::memcpy(&data[0],&dataDecoded[0],dataDecoded.size());
	return data;
}

void decodeDouble(const std::string& encodedData, size_t dataSize, double* doubleData)
{
	std::vector<BYTE>   dataDecoded = decode(encodedData);
	std::vector<double> data(dataDecoded.size()/sizeof(double));
	std::memcpy(&doubleData[0],&dataDecoded[0],(size_t)(dataSize*sizeof(double)));
}

std::string encode(const std::vector<BYTE>& buf)
{
    if (buf.empty())
        return ""; // Avoid dereferencing buf if it's empty
    return encode(&buf[0], (size_t)buf.size());
}

std::string encode(const BYTE* buf, size_t bufLen)
{
    // Calculate how many bytes that needs to be added to get a multiple of 3
    size_t missing = 0;
    size_t ret_size = bufLen;
    while ((ret_size % 3) != 0)
    {
        ++ret_size;
        ++missing;
    }

    // Expand the return string size to a multiple of 4
    ret_size = 4*ret_size/3;

    std::string ret;
    ret.reserve(ret_size);

    for (size_t i=0; i<ret_size/4; ++i)
    {
        // Read a group of three bytes (avoid buffer overrun by replacing with 0)
        size_t index = i*3;
        BYTE b3[3];
        b3[0] = (index+0 < bufLen) ? buf[index+0] : 0;
        b3[1] = (index+1 < bufLen) ? buf[index+1] : 0;
        b3[2] = (index+2 < bufLen) ? buf[index+2] : 0;

        // Transform into four base 64 characters
        BYTE b4[4];
        b4[0] =                         ((b3[0] & 0xfc) >> 2);
        b4[1] = ((b3[0] & 0x03) << 4) + ((b3[1] & 0xf0) >> 4);
        b4[2] = ((b3[1] & 0x0f) << 2) + ((b3[2] & 0xc0) >> 6);
        b4[3] = ((b3[2] & 0x3f) << 0);

        // Add the base 64 characters to the return value
        ret.push_back(to_base64[b4[0]]);
        ret.push_back(to_base64[b4[1]]);
        ret.push_back(to_base64[b4[2]]);
        ret.push_back(to_base64[b4[3]]);
    }

    // Replace data that is invalid (always as many as there are missing bytes)
    for (size_t i=0; i<missing; ++i)
        ret[ret_size - i - 1] = '=';

    return ret;
}

std::vector<BYTE> decode(std::string encoded_string)
{
    // Make sure string length is a multiple of 4
    while ((encoded_string.size() % 4) != 0)
        encoded_string.push_back('=');

    size_t encoded_size = encoded_string.size();
    std::vector<BYTE> ret;
    ret.reserve(3*encoded_size/4);

    for (size_t i=0; i<encoded_size; i += 4)
    {
        // Get values for each group of four base 64 characters
        BYTE b4[4];
        b4[0] = (encoded_string[i+0] <= 'z') ? from_base64[(int)encoded_string[i+0]] : 0xff;
        b4[1] = (encoded_string[i+1] <= 'z') ? from_base64[(int)encoded_string[i+1]] : 0xff;
        b4[2] = (encoded_string[i+2] <= 'z') ? from_base64[(int)encoded_string[i+2]] : 0xff;
        b4[3] = (encoded_string[i+3] <= 'z') ? from_base64[(int)encoded_string[i+3]] : 0xff;

        // Transform into a group of three bytes
        BYTE b3[3];
        b3[0] = ((b4[0] & 0x3f) << 2) + ((b4[1] & 0x30) >> 4);
        b3[1] = ((b4[1] & 0x0f) << 4) + ((b4[2] & 0x3c) >> 2);
        b3[2] = ((b4[2] & 0x03) << 6) + ((b4[3] & 0x3f) >> 0);

        // Add the byte to the return value if it isn't part of an '=' character (indicated by 0xff)
        if (b4[1] != 0xff) ret.push_back(b3[0]);
        if (b4[2] != 0xff) ret.push_back(b3[1]);
        if (b4[3] != 0xff) ret.push_back(b3[2]);
    }

    return ret;
}

};
#endif


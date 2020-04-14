//
// DataType.h
//
// Author: Chris Anderson  
// (C) UCLA 2018
//
/*
DataType is a class which provides a minimal wrapping for a subset
of the basic data types available in C++. The data types supported are
bool, int, long, float, double and strings. The class is a
container class which holds the value of the data and it's type.
The constructors and conversions associated with this class have been
implemented so that functions which return a DataType object can
"communicate" with variables of the standard data types. This class is
purely a mechanism for implementing functions with identical signature
but different return types. Algebraic operations (other than assignment)
are not implemented for the objects of this class.
*/
/*
#############################################################################
#
# Copyright  2015 Chris Anderson
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

#ifndef  DataType_
#define  DataType_
#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <stdexcept>

namespace SCC
{
class  DataType
{

public :

    bool    b;
    int     i;
    long    l;
    float   f;
    double  d;
    std::string  s;
    int  type_name;

public :

//
//  Type Enumerations
//

enum {TYPE_NULL, TYPE_BOOL, TYPE_INT ,TYPE_LONG ,TYPE_FLOAT ,TYPE_DOUBLE ,TYPE_STRING};
//
//  Constructors
//

DataType(): s()
{
	b = false;
	i = 0;
	l = 0;
	f = 0.0;
	d = 0.0;
	type_name = TYPE_NULL;
}

DataType( const DataType& A)
{
	b = A.b;
	i = A.i;
	l = A.l;
	f = A.f;
	d = A.d;
	s = A.s;
	type_name = A.type_name;

}

DataType(bool A ): s()
{
	b = A;
    i = 0;
    l = 0;
    f = 0.0;
    d = 0.0;
    type_name = TYPE_BOOL;
}



DataType(int A ): s()
{
	b = false;
    i = A;
    l = 0;
    f = 0.0;
    d = 0.0;
    type_name = TYPE_INT;
}

DataType(long A ): s()
{
	b = false;
    i = 0;
    l = A;
    f = 0.0;
    d = 0.0;
    type_name = TYPE_LONG;
}

DataType(float A ): s()
{
	b = false;
    i = 0;
    l = 0;
    f = A;
    d = 0.0;
    type_name = TYPE_FLOAT;
}

DataType(double A ): s()
{
	b = false;
    i = 0;
    l = 0;
    f = 0.0;
    d = A;
    type_name = TYPE_DOUBLE;
}

DataType(const std::string& A ): s(A)
{
	b = false;
    i = 0;
    l = 0;
    f = 0.0;
    d = 0.0;
    type_name = TYPE_STRING;
}


DataType(const char* A): s(A)
{
	b = false;
    i = 0;
    l = 0;
    f = 0.0;
    d = 0.0;
    type_name = TYPE_STRING;
}



//
//********************************************************************************
//                    DESTRUCTOR
//********************************************************************************
//
~DataType()
{
}

//
//********************************************************************************
//                    Initialize
//********************************************************************************
//
void initialize()
{
	b = false;
	i = 0;
	l = 0;
	f = 0.0;
	d = 0.0;
	s.clear();
	type_name = TYPE_NULL;
}

//
//********************************************************************************
//                    ASSIGNMENT
//********************************************************************************
//
DataType&  operator =( const DataType& A)
{
//
//  Memberwise Assignment
//
	b = A.b;
    i = A.i;
    l = A.l;
    f = A.f;
    d = A.d;
    s = A.s;
	type_name = A.type_name;

    return *this;
}

//
//********************************************************************************
//                    OUTPUT
//********************************************************************************
//
friend std::ostream&  operator <<(std::ostream& out_stream, const DataType& A)
{
//
//  Default Output  : Memberwise Output
//
     switch(A.type_name)
     {
     case TYPE_NULL         : out_stream << "Null Type"; break;
     case TYPE_BOOL         : out_stream << A.b; break;
     case TYPE_INT          : out_stream << A.i; break;
     case TYPE_LONG         : out_stream << A.l; break;
     case TYPE_FLOAT        : out_stream << A.f; break;
     case TYPE_DOUBLE       : out_stream << A.d; break;
     case TYPE_STRING       : out_stream << A.s; break;
     }
     return out_stream;
}

friend std::istream&  operator >>(std::istream& in_stream, DataType& A)
{
//
//   Input
//
     switch(A.type_name)
     {
	 case TYPE_NULL     : nullOperand(); break;
	 case TYPE_BOOL     : in_stream >> A.b; break;
     case TYPE_INT      : in_stream >> A.i; break;
     case TYPE_LONG     : in_stream >> A.l; break;
     case TYPE_FLOAT    : in_stream >> A.f; break;
     case TYPE_DOUBLE   : in_stream >> A.d; break;
     case TYPE_STRING   : in_stream >> A.s; break;
     }
     return in_stream;
}
//
//********************************************************************************
//                    MEMBER_FUNCTIONS
//********************************************************************************
//

operator bool()
{
     bool b_return = 0;

     switch(type_name)
     {
     case TYPE_BOOL     : b_return =     b; break;
     case TYPE_INT      : if(i == 0){b_return = false;} else {b_return = true;} break;
     case TYPE_LONG     : if(l == 0){b_return = false;} else {b_return = true;} break;
     case TYPE_FLOAT    : illegalConversion(TYPE_FLOAT,   TYPE_BOOL); break;
     case TYPE_DOUBLE   : illegalConversion(TYPE_DOUBLE,  TYPE_BOOL); break;
     case TYPE_STRING   : illegalConversion(TYPE_STRING,  TYPE_BOOL); break;
     case TYPE_NULL     : nullOperand(); break;
     }
     return b_return;
}

operator int()
{
     int i_return = 0;

     switch(type_name)
     {
     case TYPE_BOOL     : i_return = int(i); break;
     case TYPE_INT      : i_return =     i; break;
     case TYPE_LONG     : i_return = int(l); break;
     case TYPE_FLOAT    : i_return = int(f); break;
     case TYPE_DOUBLE   : i_return = int(d); break;
     case TYPE_STRING   : illegalConversion(TYPE_STRING, TYPE_INT); break;
     case TYPE_NULL     : nullOperand(); break;
     }
     return i_return;
}

operator long()
{
     long l_return = 0;

     switch(type_name)
     {
     case TYPE_BOOL     : l_return = long(i); break;
     case TYPE_INT      : l_return = long(i); break;
     case TYPE_LONG     : l_return =       l; break;
     case TYPE_FLOAT    : l_return = long(f); break;
     case TYPE_DOUBLE   : l_return = long(d); break;
     case TYPE_STRING   : illegalConversion(TYPE_STRING,TYPE_LONG); break;
     case TYPE_NULL     : nullOperand(); break;
     }
     return l_return;
}

operator float()
{
     float f_return =0.0;

     switch(type_name)
     {
     case TYPE_BOOL     : illegalConversion(TYPE_BOOL,TYPE_FLOAT); break;
     case TYPE_INT      : f_return = float(i); break;
     case TYPE_LONG     : f_return = float(l); break;
     case TYPE_FLOAT    : f_return =        f; break;
     case TYPE_DOUBLE   : f_return = float(d); break;
     case TYPE_STRING   : illegalConversion(TYPE_STRING,TYPE_FLOAT); break;
     case TYPE_NULL     : nullOperand(); break;
     }
     return f_return;
}

operator double()
{
     double d_return = 0.0;

     switch(type_name)
     {
     case TYPE_BOOL     : illegalConversion(TYPE_BOOL,TYPE_DOUBLE); break;
     case TYPE_INT      : d_return = double(i); break;
     case TYPE_LONG     : d_return = double(l); break;
     case TYPE_FLOAT    : d_return = double(f); break;
     case TYPE_DOUBLE   : d_return =        d ; break;
     case TYPE_STRING   : illegalConversion(TYPE_STRING,TYPE_DOUBLE); break;
     case TYPE_NULL     : nullOperand(); break;
     }
     return d_return;
}

operator std::string()
{

     std::string string_return;

     switch(type_name)
     {
     case TYPE_BOOL     : illegalConversion(TYPE_BOOL,   TYPE_STRING); break;
     case TYPE_INT      : illegalConversion(TYPE_INT,    TYPE_STRING); break;
     case TYPE_LONG     : illegalConversion(TYPE_LONG,   TYPE_STRING); break;
     case TYPE_FLOAT    : illegalConversion(TYPE_FLOAT,  TYPE_STRING); break;
	 case TYPE_DOUBLE   : illegalConversion(TYPE_DOUBLE, TYPE_STRING); break;
	 case TYPE_STRING   : string_return = s; break;
	 case TYPE_NULL     : nullOperand(); break;
     }
     return string_return;
}


//
//******************************************************************************
//                    MEMBER_FUNCTIONS
//******************************************************************************
//


void  operator =(bool A)
{
     if(type_name == TYPE_NULL) type_name = TYPE_BOOL;

     switch(type_name)
     {
     case TYPE_BOOL     : b = A; break;
     case TYPE_INT      : i = int(A); break;
     case TYPE_LONG     : l = long(A); break;
     case TYPE_FLOAT    : illegalConversion(TYPE_BOOL,TYPE_FLOAT); break;
     case TYPE_DOUBLE   : illegalConversion(TYPE_BOOL,TYPE_DOUBLE); break;
     case TYPE_STRING   : illegalAssignment(TYPE_BOOL,TYPE_STRING); break;
     }
}


void  operator =(int A)
{
     if(type_name == TYPE_NULL) type_name = TYPE_INT;

     switch(type_name)
     {
     case TYPE_BOOL     : if(A == 0){b = false;} else {b = true;} break;
     case TYPE_INT      : i = A; break;
     case TYPE_LONG     : l = A; break;
     case TYPE_FLOAT    : f = (float)A; break;
     case TYPE_DOUBLE   : d = A; break;
     case TYPE_STRING   : illegalAssignment(TYPE_STRING,TYPE_INT); break;

     }
}

void  operator =(long A)
{
     if(type_name == TYPE_NULL) type_name = TYPE_LONG;

     switch(type_name)
     {
     case TYPE_BOOL     : if(A == 0){b = false;} else {b = true;} break;
     case TYPE_INT      : i = int(A); break;
     case TYPE_LONG     : l = A; break;
     case TYPE_FLOAT    : f = float(A); break;
     case TYPE_DOUBLE   : d = A; break;
     case TYPE_STRING   : illegalAssignment(TYPE_STRING,TYPE_LONG); break;
     }
}

void  operator =(float A)
{
     if(type_name == TYPE_NULL) type_name = TYPE_FLOAT;

     switch(type_name)
     {
     case TYPE_BOOL     : illegalAssignment(TYPE_FLOAT,TYPE_BOOL); break;
     case TYPE_INT      : i = int(A); break;
     case TYPE_LONG     : l = long(A); break;
     case TYPE_FLOAT    : f = A; break;
     case TYPE_DOUBLE   : d = A; break;
     case TYPE_STRING   : illegalAssignment(TYPE_FLOAT,TYPE_STRING); break;
     }
}

void  operator =(double A)
{
     if(type_name == TYPE_NULL) type_name = TYPE_DOUBLE;

     switch(type_name)
     {
     case TYPE_BOOL     : illegalAssignment(TYPE_DOUBLE,TYPE_BOOL); break;
     case TYPE_INT      : i = int(A); break;
     case TYPE_LONG     : l = long(A); break;
     case TYPE_FLOAT    : f = float(A); break;
     case TYPE_DOUBLE   : d = A; break;
     case TYPE_STRING   : illegalAssignment(TYPE_DOUBLE,TYPE_STRING); break;
     }
}

void  operator =(const std::string& A)
{
     if(type_name == TYPE_NULL) type_name = TYPE_STRING;

     switch(type_name)
     {
     case TYPE_BOOL     : illegalAssignment(TYPE_BOOL,TYPE_STRING); break;
     case TYPE_INT      : illegalAssignment(TYPE_INT,TYPE_STRING); break;
     case TYPE_LONG     : illegalAssignment(TYPE_LONG,TYPE_STRING); break;
     case TYPE_FLOAT    : illegalAssignment(TYPE_FLOAT,TYPE_STRING); break;
     case TYPE_DOUBLE   : illegalAssignment(TYPE_DOUBLE,TYPE_STRING ); break;
     case TYPE_STRING   : s = A; break;
     }
}


void  operator =(const char* A)
{
     if(type_name == TYPE_NULL) type_name = TYPE_STRING;

     switch(type_name)
	 {
     case TYPE_BOOL     : illegalAssignment(TYPE_BOOL,TYPE_STRING); break;
     case TYPE_INT      : illegalAssignment(TYPE_INT,TYPE_STRING); break;
     case TYPE_LONG     : illegalAssignment(TYPE_LONG,TYPE_STRING); break;
     case TYPE_FLOAT    : illegalAssignment(TYPE_FLOAT,TYPE_STRING); break;
     case TYPE_DOUBLE   : illegalAssignment(TYPE_DOUBLE,TYPE_STRING ); break;
	 case TYPE_STRING   : s = A; break;
     }
}


//
//******************************************************************************
//                    MEMBER_FUNCTIONS
//******************************************************************************
//

std::string toString()
{


	 std::ostringstream oss(std::ostringstream::out);
	 std::string string_return;
     switch(type_name)
     {
     case TYPE_BOOL     : if(b == true) {string_return = "true"; } else {string_return = "false";}  break;
     case TYPE_INT      : oss << i; string_return = oss.str(); break;
     case TYPE_LONG     : oss << l; string_return = oss.str(); break;
     case TYPE_FLOAT    : oss.setf(std::ios::scientific); oss.precision(8);   oss << f; string_return = oss.str(); break;
     case TYPE_DOUBLE   : oss.setf(std::ios::scientific); oss.precision(15);  oss << d; string_return = oss.str(); break;
     case TYPE_STRING   : string_return = s; break;
     }

     return string_return;


     /*
     Code using to_string which works but doesn't allow for increasing the number of digits output
     for a double.

	 std::string string_return;
     switch(type_name)
     {
     case TYPE_BOOL     : if(b == true) {string_return = "true"; } else {string_return = "false";}  break;
     case TYPE_INT      : return std::to_string(i); break;
     case TYPE_LONG     : return std::to_string(l); break;
     case TYPE_FLOAT    : return std::to_string(f); break;
     case TYPE_DOUBLE   : return std::to_string(d); break;
     case TYPE_STRING   : string_return = s; break;
     }

     return string_return;
     */

}
void  setType(int type)
{
    type_name = type;
}

int  getType()
{
    return type_name;
}

bool isString()
{
	if(type_name == TYPE_STRING) return true;
	return false;
}

std::string getTypeAsString() const
{
     std::string sReturn;

     switch(this->type_name)
     {
     case TYPE_BOOL     : sReturn =  "bool";        break;
     case TYPE_INT      : sReturn =  "int";         break;
     case TYPE_LONG     : sReturn =  "long";        break;
     case TYPE_FLOAT    : sReturn =  "float";       break;
     case TYPE_DOUBLE   : sReturn =  "double";      break;
     case TYPE_STRING   : sReturn =  "string"; break;
     }
     return sReturn;
}
//
//******************************************************************************
//              	ERROR HANDLING
//******************************************************************************
//
static void illegalConversion()
{
    std::string errorMsg   =  (std::string)"\nSCC::DataType Class Error :\nIllegal Data Type Conversion" +
                               (std::string)"XXXXXXX     Program Terminated    XXXXXXXX\n";
    throw std::invalid_argument(errorMsg);
}
static void illegalConversion(int typeA, int typeB)
{
	std::string typeAstring;
	std::string typeBstring;
	switch(typeA)
	{
     case TYPE_BOOL     : typeAstring.assign("bool")  ; break;
     case TYPE_INT      : typeAstring.assign("int")   ; break;
     case TYPE_LONG     : typeAstring.assign("long")  ; break;
     case TYPE_FLOAT    : typeAstring.assign("float") ; break;
     case TYPE_DOUBLE   : typeAstring.assign("double"); break;
     case TYPE_STRING   : typeAstring.assign("string"); break;
     case TYPE_NULL     : typeAstring.assign("null" ) ; break;
    }
    switch(typeB)
	{
     case TYPE_BOOL     : typeBstring.assign("bool")   ; break;
     case TYPE_INT      : typeBstring.assign("int")    ; break;
     case TYPE_LONG     : typeBstring.assign("long")   ; break;
     case TYPE_FLOAT    : typeBstring.assign( "float") ; break;
     case TYPE_DOUBLE   : typeBstring.assign("double") ; break;
     case TYPE_STRING   : typeBstring.assign("string") ; break;
     case TYPE_NULL     : typeBstring.assign( "null")  ; break;
    }

    std::string errorMsg   =  (std::string)"\nSCC::DataType Class Error :\nIllegal Data Type Conversion\n" +
                              (std::string)"Attempting to convert a " + typeAstring +
                              (std::string)" to a " + typeBstring +
                              (std::string)"\nXXXXXXX     Program Terminated    XXXXXXXX\n";
    throw std::invalid_argument(errorMsg);
}

static void nullOperand()
{
    std::string errorMsg   =  (std::string)"\nSCC::DataType Class Error :\nNull Operand "  +
                              (std::string)"\nXXXXXXX     Program Terminated    XXXXXXXX\n";
    throw std::invalid_argument(errorMsg);
}

static void illegalAssignment()
{
    std::string errorMsg   =  (std::string)"\nSCC::DataType Class Error :\nIllegal Assignment"  +
                              (std::string)"\nXXXXXXX     Program Terminated    XXXXXXXX\n";
    throw std::invalid_argument(errorMsg);
}


static void illegalAssignment(int typeA, int typeB)
{
	std::string typeAstring;
	std::string typeBstring;
	switch(typeA)
	{
     case TYPE_BOOL     : typeAstring.assign("bool")  ; break;
     case TYPE_INT      : typeAstring.assign("int")   ; break;
     case TYPE_LONG     : typeAstring.assign("long")  ; break;
     case TYPE_FLOAT    : typeAstring.assign("float") ; break;
     case TYPE_DOUBLE   : typeAstring.assign("double"); break;
     case TYPE_STRING   : typeAstring.assign("string"); break;
     case TYPE_NULL     : typeAstring.assign("null" ) ; break;
    }
    switch(typeB)
	{
     case TYPE_BOOL     : typeBstring.assign("bool")   ; break;
     case TYPE_INT      : typeBstring.assign("int")    ; break;
     case TYPE_LONG     : typeBstring.assign("long")   ; break;
     case TYPE_FLOAT    : typeBstring.assign( "float") ; break;
     case TYPE_DOUBLE   : typeBstring.assign("double") ; break;
     case TYPE_STRING   : typeBstring.assign("string") ; break;
     case TYPE_NULL     : typeBstring.assign( "null")  ; break;
    }

    std::string errorMsg   =  (std::string)"\nSCC::DataType Class Error :\nIllegal Assignment\n"  +
                              (std::string)"Attempting to assign a  " + typeAstring + (std::string)" to a " + typeBstring +
                              (std::string)"\nXXXXXXX     Program Terminated    XXXXXXXX\n";
    throw std::invalid_argument(errorMsg);
}


};

} // SCC namespace

#endif


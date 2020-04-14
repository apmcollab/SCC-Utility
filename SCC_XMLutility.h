/*
 * SCC_XMLutility.h
 *
 *  Created on: Apr 15, 2016
 *      Author: anderson
 */


//
// Utility functions for SCC class operators
// involving XML_ParameterListArray
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
#include "XML_ParameterList/XML_ParameterListArray.h"

#include "GridFunctionNd/SCC_GridFunction1d.h"
#include "GridFunctionNd/SCC_GridFunction2d.h"
#include "GridFunctionNd/SCC_GridFunction3d.h"

#include <string>

#ifndef _SCC_XMLutilty_
#define _SCC_XMLutilty_



namespace SCC
{

class XMLutility
{

public:

XMLutility(){};


void XMLinitialize(XML_ParameterListArray& paramList, GridFunction1d& G)
{

		    if(paramList.isParameterList("ComputationalDomain") == 0)
		    {
		    std::string mesg = "\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
		    mesg       += "Error initializing GridFunction1d class \n";
		    mesg       += "ComputationalDomain parameter list was not found \n";
		    mesg       += "in input XML_ParameterListArray \n";
		    mesg       += "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
		    throw runtime_error(mesg);
		    }

		    if(paramList.isParameterList("GridParameters") == 0)
		    {
		    std::string mesg = "\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
		    mesg       += "Error initializing GridFunction1d class \n";
		    mesg       += "GridParameters parameter list was not found \n";
		    mesg       += "in input XML_ParameterListArray \n";
		    mesg       += "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
		    throw runtime_error(mesg);
		    }

		    long xPanelsInput  = paramList.getParameterValue("xPanels","GridParameters");

		    double xMinInput  = paramList.getParameterValue("xMin","ComputationalDomain");
			double xMaxInput  = paramList.getParameterValue("xMax","ComputationalDomain");

		    G.initialize(xPanelsInput, xMinInput, xMaxInput);
}

void XMLinitialize(XML_ParameterListArray& paramList, GridFunction2d& G)
{

	    if(paramList.isParameterList("ComputationalDomain") == 0)
	    {
	    std::string mesg = "\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
	    mesg       += "Error initializing GridFunction2d class \n";
	    mesg       += "ComputationalDomain parameter list was not found \n";
	    mesg       += "in input XML_ParameterListArray \n";
	    mesg       += "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
	    throw runtime_error(mesg);
	    }

	    if(paramList.isParameterList("GridParameters") == 0)
	    {
	    std::string mesg = "\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
	    mesg       += "Error initializing GridFunction2d class \n";
	    mesg       += "GridParameters parameter list was not found \n";
	    mesg       += "in input XML_ParameterListArray \n";
	    mesg       += "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
	    throw runtime_error(mesg);
	    }

	    long xPanelsInput  = paramList.getParameterValue("xPanels","GridParameters");
	    long yPanelsInput  = paramList.getParameterValue("yPanels","GridParameters");

	    double xMinInput  = paramList.getParameterValue("xMin","ComputationalDomain");
		double yMinInput  = paramList.getParameterValue("yMin","ComputationalDomain");
		double xMaxInput  = paramList.getParameterValue("xMax","ComputationalDomain");
		double yMaxInput  = paramList.getParameterValue("yMax","ComputationalDomain");

	    G.initialize(xPanelsInput, xMinInput, xMaxInput, yPanelsInput, yMinInput, yMaxInput);
}


void XMLinitialize(XML_ParameterListArray& paramList, GridFunction3d& G)
{

    if(paramList.isParameterList("ComputationalDomain") == 0)
    {
    std::string mesg = "\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
    mesg       += "Error initializing GridFunction3d class \n";
    mesg       += "ComputationalDomain parameter list was not found \n";
    mesg       += "in input XML_ParameterListArray \n";
    mesg       += "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
    throw runtime_error(mesg);
    }

    if(paramList.isParameterList("GridParameters") == 0)
    {
    std::string mesg = "\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
    mesg       += "Error initializing GridFunction3d class \n";
    mesg       += "GridParameters parameter list was not found \n";
    mesg       += "in input XML_ParameterListArray \n";
    mesg       += "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
    throw runtime_error(mesg);
    }

    long xPanelsInput  = paramList.getParameterValue("xPanels","GridParameters");
    long yPanelsInput  = paramList.getParameterValue("yPanels","GridParameters");
    long zPanelsInput  = paramList.getParameterValue("zPanels","GridParameters");

    double xMinInput  = paramList.getParameterValue("xMin","ComputationalDomain");
	double yMinInput  = paramList.getParameterValue("yMin","ComputationalDomain");
	double zMinInput  = paramList.getParameterValue("zMin","ComputationalDomain");
	double xMaxInput  = paramList.getParameterValue("xMax","ComputationalDomain");
	double yMaxInput  = paramList.getParameterValue("yMax","ComputationalDomain");
	double zMaxInput  = paramList.getParameterValue("zMax","ComputationalDomain");

    G.initialize(xPanelsInput, xMinInput, xMaxInput, yPanelsInput, yMinInput, yMaxInput, zPanelsInput, zMinInput, zMaxInput);
}

};

} // SCC namespace


#endif /* _SCC_XMLutilty_ */

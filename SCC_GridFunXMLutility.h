/*
 * SCC_GridFunXMLutility.h
 *
 *  Created on: July 2, 2011
 *      Author: anderson
 */


//
// Utility functions for initializing grid function instances
// from XML parameter specifications.


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
#include "XML_ParameterList/XML_ParameterListArray.h"
#include "XML_ParameterList/XML_ParameterCheck.h"

#include "GridFunctionNd/SCC_GridFunction1d.h"
#include "GridFunctionNd/SCC_GridFunction2d.h"
#include "GridFunctionNd/SCC_GridFunction3d.h"

#include <string>

#ifndef SCC_GRID_FUN_XML_UTILITY_
#define SCC_GRID_FUN_XML_UTILITY_

namespace SCC
{

class GridFunXMLutility
{

public:

GridFunXMLutility(){};

void XMLinitialize(XML_ParameterListArray& paramList, GridFunction1d& G)
{
    if(paramList.isParameterList("ComputationalDomain") == 0)
    {
    std::string mesg = "\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
    mesg       += "Error initializing GridFunction1d class \n";
    mesg       += "ComputationalDomain parameter list was not found \n";
    mesg       += "in input XML_ParameterListArray \n";
    mesg       += "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
    throw std::runtime_error(mesg);
    }

    if(paramList.isParameterList("GridParameters") == 0)
    {
    std::string mesg = "\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
    mesg       += "Error initializing GridFunction1d class \n";
    mesg       += "GridParameters parameter list was not found \n";
    mesg       += "in input XML_ParameterListArray \n";
    mesg       += "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
    throw std::runtime_error(mesg);
    }

    double xMin  = paramList.getParameterValue("xMin","ComputationalDomain");
    double xMax  = paramList.getParameterValue("xMax","ComputationalDomain");

    long xPanels; double xPanelDensity;

    if(paramList.isParameter("xPanelDensity",  "GridParameters"))
    {
    	xPanelDensity = paramList.getParameterValue("xPanelDensity",  "GridParameters");
    	xPanels       = (long)((xMax-xMin)*xPanelDensity);
    	if(xPanels < 1) {xPanels = 1;}
    }
    else
    {
    	xPanels  = paramList.getParameterValue("xPanels","GridParameters");
    }


    G.initialize(xPanels, xMin, xMax);
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
    throw std::runtime_error(mesg);
    }

    if(paramList.isParameterList("GridParameters") == 0)
    {
    std::string mesg = "\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
    mesg       += "Error initializing GridFunction2d class \n";
    mesg       += "GridParameters parameter list was not found \n";
    mesg       += "in input XML_ParameterListArray \n";
    mesg       += "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
    throw std::runtime_error(mesg);
    }

    double xMin  = paramList.getParameterValue("xMin","ComputationalDomain");
    double xMax  = paramList.getParameterValue("xMax","ComputationalDomain");

    double yMin  = paramList.getParameterValue("yMin","ComputationalDomain");
    double yMax  = paramList.getParameterValue("yMax","ComputationalDomain");

    long xPanels; double xPanelDensity;
    long yPanels; double yPanelDensity;

    if(paramList.isParameter("xPanelDensity",  "GridParameters"))
    {
    	xPanelDensity = paramList.getParameterValue("xPanelDensity",  "GridParameters");
    	xPanels       = (long)((xMax-xMin)*xPanelDensity);
    	if(xPanels < 1) {xPanels = 1;}
    }
    else
    {
    	xPanels  = paramList.getParameterValue("xPanels","GridParameters");
    }

    if(paramList.isParameter("yPanelDensity",  "GridParameters"))
    {
    	yPanelDensity = paramList.getParameterValue("yPanelDensity",  "GridParameters");
    	yPanels       = (long)((yMax-yMin)*yPanelDensity);
    	if(yPanels < 1) {yPanels = 1;}
    }
    else
    {
    	yPanels  = paramList.getParameterValue("yPanels","GridParameters");
    }



    G.initialize(xPanels, xMin, xMax, yPanels, yMin, yMax);
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
    throw std::runtime_error(mesg);
    }

    if(paramList.isParameterList("GridParameters") == 0)
    {
    std::string mesg = "\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
    mesg       += "Error initializing GridFunction3d class \n";
    mesg       += "GridParameters parameter list was not found \n";
    mesg       += "in input XML_ParameterListArray \n";
    mesg       += "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
    throw std::runtime_error(mesg);
    }

    double xMin  = paramList.getParameterValue("xMin","ComputationalDomain");
    double xMax  = paramList.getParameterValue("xMax","ComputationalDomain");

    double yMin  = paramList.getParameterValue("yMin","ComputationalDomain");
    double yMax  = paramList.getParameterValue("yMax","ComputationalDomain");

    double zMin  = paramList.getParameterValue("zMin","ComputationalDomain");
    double zMax  = paramList.getParameterValue("zMax","ComputationalDomain");

    long xPanels; double xPanelDensity;
    long yPanels; double yPanelDensity;
    long zPanels; double zPanelDensity;

    if(paramList.isParameter("xPanelDensity",  "GridParameters"))
    {
    	xPanelDensity = paramList.getParameterValue("xPanelDensity",  "GridParameters");
    	xPanels       = (long)((xMax-xMin)*xPanelDensity);
    	if(xPanels < 1) {xPanels = 1;}
    }
    else
    {
    	xPanels  = paramList.getParameterValue("xPanels","GridParameters");
    }

    if(paramList.isParameter("yPanelDensity",  "GridParameters"))
    {
    	yPanelDensity = paramList.getParameterValue("yPanelDensity",  "GridParameters");
    	yPanels       = (long)((yMax-yMin)*yPanelDensity);
    	if(yPanels < 1) {yPanels = 1;}
    }
    else
    {
    	yPanels  = paramList.getParameterValue("yPanels","GridParameters");
    }


    if(paramList.isParameter("zPanelDensity",  "GridParameters"))
    {
    	zPanelDensity = paramList.getParameterValue("zPanelDensity",  "GridParameters");
    	zPanels       = (long)((zMax-zMin)*zPanelDensity);
    	if(zPanels < 1) {zPanels = 1;}
    }
    else
    {
    	zPanels  = paramList.getParameterValue("zPanels","GridParameters");
    }


    G.initialize(xPanels, xMin, xMax, yPanels, yMin, yMax, zPanels, zMin, zMax);
}

   bool checkParametersError(const XML_ParameterListArray& paramList, int dimension, std::string& errMsg)
   {
	XML_ParameterCheck xmlCheck;
	bool errorFlag      = false;

	std::string routineName = "SCC::GridFunXMLutility";

	errorFlag = xmlCheck.checkParameterError(routineName, paramList, "ComputationalDomain",errMsg)  || errorFlag;
	errorFlag = xmlCheck.checkParameterError(routineName, paramList, "GridParameters",errMsg)       || errorFlag;

    errorFlag = xmlCheck.checkParameterError(routineName, paramList, "xMin","ComputationalDomain", errMsg) || errorFlag;
    errorFlag = xmlCheck.checkParameterError(routineName, paramList, "xMax","ComputationalDomain", errMsg) || errorFlag;
    if((not paramList.isParameter("xPanelDensity",  "GridParameters")) &&
       (not paramList.isParameter("xPanels",  "GridParameters")))
    {
        errMsg.append("\nXXXXX ");
	    errMsg.append(routineName  + " Parameter Error \n");
		errMsg.append("Parameter missing : ");
		errMsg.append("xPanelDensity or xPanels");
	    errMsg.append("\n");
		errMsg.append("Parameter list    : ");
		errMsg.append("GridParameters");
		errMsg.append("\n");
		errorFlag = true;
    }


    if(dimension >= 2)
    {
    errorFlag = xmlCheck.checkParameterError(routineName, paramList, "yMin","ComputationalDomain", errMsg) || errorFlag;
    errorFlag = xmlCheck.checkParameterError(routineName, paramList, "yMax","ComputationalDomain", errMsg) || errorFlag;
    if((not paramList.isParameter("yPanelDensity",  "GridParameters")) &&
       (not paramList.isParameter("yPanels",  "GridParameters")))
    {
        errMsg.append("\nXXXXX ");
	    errMsg.append(routineName  + " Parameter Error \n");
		errMsg.append("Parameter missing : ");
		errMsg.append("yPanelDensity or yPanels");
	    errMsg.append("\n");
		errMsg.append("Parameter list    : ");
		errMsg.append("GridParameters");
		errMsg.append("\n");
		errorFlag = true;
    }

    }

    if(dimension >= 3)
    {
    errorFlag = xmlCheck.checkParameterError(routineName, paramList, "zMin","ComputationalDomain", errMsg) || errorFlag;
    errorFlag = xmlCheck.checkParameterError(routineName, paramList, "zMax","ComputationalDomain", errMsg) || errorFlag;
    if((not paramList.isParameter("zPanelDensity",  "GridParameters")) &&
       (not paramList.isParameter("zPanels",  "GridParameters")))
    {
        errMsg.append("\nXXXXX ");
	    errMsg.append(routineName  + " Parameter Error \n");
		errMsg.append("Parameter missing : ");
		errMsg.append("zPanelDensity or zPanels");
	    errMsg.append("\n");
		errMsg.append("Parameter list    : ");
		errMsg.append("GridParameters");
		errMsg.append("\n");
		errorFlag = true;
    }
    }

    return errorFlag;

   }

};

} // SCC namespace


#endif /* SCC_GRID_FUN_XML_UTILITY_  */

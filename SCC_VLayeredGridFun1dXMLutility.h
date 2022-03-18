/*
 * VLayeredGridFun1dXMLutility.h
 *
 *  Created on: Nov. 13, 2018
 *  Modified  : Mar. 18, 2022
 *      Author: anderson
 *
 *  A utility class for extracting from an input XML files the
 *  data required to instantiate a VLayeredGridFun1d
 *
 *
 */
#include <vector>
#include <cmath>

#include "XML_ParameterList/XML_ParameterListArray.h"
#include "XML_ParameterList/XML_ParameterCheck.h"

#include "VLayeredGridFunNd/SCC_VLayeredGridFun1d.h"


#ifndef VLAYERED_GRID_FUN_1D_XML_UTILITY_
#define VLAYERED_GRID_FUN_1D_XML_UTILITY_

namespace SCC
{
class  VLayeredGridFun1dXMLutility
{
public:

VLayeredGridFun1dXMLutility(){};
virtual ~VLayeredGridFun1dXMLutility(){};


void initializeVLayeredGridFun1d(const XML_ParameterListArray& paramList,
SCC::VLayeredGridFun1d& G) const
{
    long layerCount     = paramList.getParameterInstanceCount("Layer","LayeredStructure");
    double baseLocation = paramList.getParameterValue("baseLocation", "LayeredStructure");

    std::vector<long>    panels(layerCount,0);
    std::vector<double> bdry(layerCount+1,0.0);

    double height; double panelDensity;

    bdry[0] = baseLocation;

    for(long k = 0; k < layerCount; k++)
    {
    	height    =  paramList.getParameterInstanceChildValue(k,"height","Layer","LayeredStructure");
    	bdry[k+1] = bdry[k] + height;
    	if(paramList.isParameterInstanceChildValue(k,"panels","Layer","LayeredStructure"))
	    {
	    	panels[k] =  paramList.getParameterInstanceChildValue(k,"panels","Layer","LayeredStructure");
	    }
	    else if(paramList.isParameterInstanceChildValue(k,"panelCount","Layer","LayeredStructure"))
	    {
	    	panels[k] =  paramList.getParameterInstanceChildValue(k,"panelCount","Layer","LayeredStructure");
	    }
	    else if(paramList.isParameterInstanceChildValue(k,"panelDensity","Layer","LayeredStructure"))
	    {
		    panelDensity =  paramList.getParameterInstanceChildValue(k,"panelDensity","Layer","LayeredStructure");
		    panels[k]    =  (long)(std::floor(panelDensity*height) + 1);
	    }
    }

    G.initialize(layerCount,panels,bdry);
}


    bool checkParameters(const XML_ParameterListArray& paramList, std::string& errMsg)
    {
	XML_ParameterCheck xmlCheck;
	bool errorFlag      = false;

	std::string routineName = "VLayeredGridFun1dXMLutility";
    errorFlag = xmlCheck.checkParameterError(routineName, paramList, "LayeredStructure",errMsg)         || errorFlag;
    xmlCheck.ifErrorAbort(errorFlag, errMsg, routineName);

    errorFlag = xmlCheck.checkParameterError(routineName, paramList, "Layer","LayeredStructure",errMsg) || errorFlag;
    xmlCheck.ifErrorAbort(errorFlag, errMsg, routineName);

    long layerCount  = paramList.getParameterInstanceCount("Layer","LayeredStructure");

    for(long k = 0; k < layerCount; k++)
    {
        errorFlag = xmlCheck.checkParameterError(routineName, paramList, k,"height","Layer","LayeredStructure",errMsg)    || errorFlag;
    	if ((not paramList.isParameterInstanceChildValue(k,"panels","Layer","LayeredStructure"))
    	&&  (not paramList.isParameterInstanceChildValue(k,"panelCount","Layer","LayeredStructure"))
    	&&  (not paramList.isParameterInstanceChildValue(k,"panelDensity","Layer","LayeredStructure")))
    	{
    		errorFlag = xmlCheck.checkParameterError(routineName, paramList, k,"panelDensity","Layer","LayeredStructure",errMsg)    || errorFlag;
    	}
    }
    return errorFlag;
    }

};

} // Namespace SCC


#endif /*  */

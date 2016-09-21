/**                                                                     
*  /file wb_switch_subsumption_traffic_lights.h 
*                                                                         
*  Created by Vlad Estivill-Castro in 2015.
*  Copyright (c) 2015 Vlad Estivill-Castro
*  All rights reserved
*/   
#ifndef wb_switch_subsumption_traffic_lights_h
#define wb_switch_subsumption_traffic_lights_h

#include <gu_util.h>

/**
 *  Configurations of traffic lights 
*/
#define TL_SUBSUMPTION_LEVELS	9 // number of subsumption levels
				 // this is the number of layers in the subsumbtion array

enum TrafficLightConfigurationValues
{	LIGHT_NO_COMMAND, // no command do not subsumme
	LIGHT_NS_GREEN,  // switch the ligh NS light to GREEN other NS OFF; EW others same
	LIGHT_EW_GREEN,  // switch the ligh EW light to GREEN other EW OFF; all NS others same
	LIGHT_NS_AMBER,  // switch the ligh NS light to AMBER other NS OFF; all EW others same
	LIGHT_EW_AMBER,  // switch the ligh EW light to AMBER other EW OFF; all NS others same
	LIGHT_NS_RED,  // switch the ligh NS light to RED other NS OFF; all EW others same
	LIGHT_EW_RED,  // switch the ligh EW light to RED other EW OFF; all NS others same
	LIGHT_ALL_OFF,  // switch all lights off
	LIGHT_NS_OFF,  // switch all the lights of  NS OFF; all EW others same
	LIGHT_EW_OFF,  // switch the lights of EW OFF; all NS others same
	LIGHT_BOTH_AMBER  // switch NS and EW to AMBER, leave the others same
};

struct wb_traffic_light_configuration
{
        PROPERTY(enum TrafficLightConfigurationValues, lightConfiguration)
};


struct wb_switch_subsumption_traffic_lights
{
     ARRAY_PROPERTY(enum TrafficLightConfigurationValues, theConfigurations, TL_SUBSUMPTION_LEVELS)

#ifdef __cplusplus
        /** struct constructor */
	wb_switch_subsumption_traffic_lights()
	{ memset(this, 0, sizeof(*this));
	}
	      	
#endif

};
#endif //wb_switch_subsumption_traffic_lights_h

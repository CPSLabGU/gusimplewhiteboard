/**
 *  /file wb_iot_control.h
 *
 *  Created by Carl Lusty in 2016.
 *  Copyright (c) 2016 Carl Lusty
 *  All rights reserved.
 */
 
#ifndef wb_iot_control_h
#define wb_iot_control_h

#include <gu_util.h>

#ifndef GU_SIMPLE_WHITEBOARD_BUFSIZE 
#define GU_SIMPLE_WHITEBOARD_BUFSIZE 128
#endif

/** IoT node list */
typedef enum node_list
{
    OutdoorPoolLightAndGardenWater  = 0,	///< Outdoor node for the pool light and garden watering system 
    OutdoorAreaLighting             = 1,    ///< 12V lights for the outside area
    AirCon                          = 2,    ///< Air conditioner control message for the master bedroom (IR controlled)
    SonarInput                      = 3,    ///< Test input message for a sonar sensor
    OutdoorAreaLightingRemote       = 4,    ///< Remote controller for the outdoor 12v lights (OutdoorAreaLighting)
    ControlPanel                    = 5,    ///< IoT control panel node
	NUMBER_OF_NODES	                        ///< NUMBER_OF_NODES
} IoT_NodeList;

const int IoT_ids[] = 
{
        761675,     //Real
        16631463,   //Real
        1134,       //Bogus 
        1,          //Bogus 
        10702516,   //Real
        13588140    //Real
};

/** List of nodes that actually need to SET data into the wb instead of just sending queries */
#define NUMBER_OF_INPUT_NODES 3
const int IoT_inputNodes[NUMBER_OF_INPUT_NODES] = 
{
    SonarInput,
    OutdoorAreaLightingRemote,
    ControlPanel
};

static inline IoT_NodeList findNodeFromID(int id);
static inline IoT_NodeList findNodeFromID(int id)
{
    for(int i = 0; i < NUMBER_OF_NODES; i++)
        if (id == IoT_ids[i])
        {
#ifdef __cplusplus
            return static_cast<IoT_NodeList>(i);
#else
            return (IoT_NodeList)i;
#endif
        }
    return NUMBER_OF_NODES;
}

static inline bool isInputNode(IoT_NodeList n);
static inline bool isInputNode(IoT_NodeList n)
{
    for(int i = 0; i < NUMBER_OF_INPUT_NODES; i++)
        if (n == IoT_inputNodes[i])
            return true;
    return false;
}

/** Different potential states for an air conditioner */
typedef enum air_con_states
{
    Off = 0,	                ///< Off
    Hot,	                    ///< Hot
    Cold,	                    ///< Cold
    Hot_Quiet,	                ///< Hot_Quiet
    Cold_Quiet,	                ///< Cold_Quiet
	NUMBER_OF_AIR_CON_STATES	///< NUMBER_OF_PACKET_TYPES	
} AirConStates;

/** OutdoorAreaLightingState enum */
typedef enum OutdoorAreaLightingState
{
    Lights_Off = 0,	        ///< Lights_Off 
    Main_On,	            ///< Main lights on
    Side_On,	            ///< Side lights on
    Both_On,                ///< Both lights on
    Lights_Timer,           ///< Timer control
	NUMBER_OF_OUTDOOR_LIGHTING_STATES	///< NUMBER_OF_OUTDOOR_LIGHTING_STATES	
} OutdoorAreaLightingState;
 
/** PoolAreaLightingState enum */
typedef enum PoolAreaLightingState
{
    PoolLights_Off = 0,	    ///< PoolLights_Off 
    DimLights_On,           ///< Pool light on
    BrightLights_On,	    ///< NYI
    AllPoolLights_On,	    ///< NYI
    PoolLights_Timer,       ///< Timer control
	NUMBER_OF_POOL_LIGHTING_STATES	///< NUMBER_OF_POOL_LIGHTING_STATES	
} PoolAreaLightingState;
 
/** Toggle with timer enum */
typedef enum ToggleTimerState
{
    Toggle_Off = 0,	        ///< Toggle_Off 
    Toggle_On,	            ///< Toggle_On
    Toggle_Timer,           ///< Timer control
	NUMBER_OF_TOGGLE_STATES	///< NUMBER_OF_TOGGLE_STATES	
} ToggleTimerState;
 
//! @cond Doxygen_Suppress
    //Doxy is warning about undocumented functions as a result of our macros and the fact that they're used in this union. This will disable doxy from parsing this section, which means no warnings but also no generated documentation for this section. The other option is to redefine the macros locally to fix the naming problem. - Carl.

#define IOT_MSG_SIZE (sizeof(int)*4)

/**
 * Param for each mode
 */
union NodeMCUMessages
{
    /**
    * NodeMCUGenericToggle
    */
    struct NodeMCUGenericToggle {
        /** D0 */
        BIT_PROPERTY(D0) 
        /** D1 */
        BIT_PROPERTY(D1) 
        /** D2 */
        BIT_PROPERTY(D2) 
        /** D3 */
        BIT_PROPERTY(D3) 
        /** D4 */
        BIT_PROPERTY(D4) 
        /** D5 */
        BIT_PROPERTY(D5) 
        /** D6 */
        BIT_PROPERTY(D6) 
        /** D7 */
        BIT_PROPERTY(D7) 
    } NodeMCUGenericToggle; ///< desired pin toggle states

    /**
    * OutdoorPoolLightAndGardenWater
    */
    struct OutdoorPoolLightAndGardenWater {
        //This is just a convenience for me to store what's plugged into where.
        /** D0 */
        BIT_PROPERTY(Pool_Filter) 
        /** D1 */
        BIT_PROPERTY(Pool_Light) 
        /** D2 */
        BIT_PROPERTY(Garden_Water) 
        /** D3 */
        BIT_PROPERTY(Garden_Light) 
        /** D4 */
        BIT_PROPERTY(Garden_Lights_Left) // when looking at the pool from the house 
        /** D5 */
        BIT_PROPERTY(Garden_Lights_Right) // when looking at the pool from the house 
        /** D6 */
        BIT_PROPERTY(D6) 
        /** D7 */
        BIT_PROPERTY(D7) 
    } OutdoorPoolLightAndGardenWater; ///< desired pin toggle states

    /**
    * OutdoorAreaLighting
    */
    struct OutdoorAreaLighting {
        //This is just a convenience for me to store what's plugged into where.
        /** D0 */
        BIT_PROPERTY(D0) 
        /** D1 */
        BIT_PROPERTY(Side_Lights) 
        /** D2 */
        BIT_PROPERTY(D2) 
        /** D3 */
        BIT_PROPERTY(D3) 
        /** D4 */
        BIT_PROPERTY(D4) 
        /** D5 */
        BIT_PROPERTY(Main_Lights) 
        /** D6 */
        BIT_PROPERTY(D6) 
        /** D7 */
        BIT_PROPERTY(D7) 
    } OutdoorAreaLighting; ///< desired pin toggle states

    /**
    * OutdoorAreaLightingRemote
    */
    struct OutdoorAreaLightingRemote {
        /** OutdoorAreaLightingState states */
        PROPERTY(OutdoorAreaLightingState, outdoorAreaLightingState)
    } OutdoorAreaLightingRemote; ///< desired pin toggle states

    /**
    * Control Panel
    */
    struct ControlPanel {
        /** OutdoorAreaLightingState states */
        PROPERTY(OutdoorAreaLightingState, outdoorAreaLightingState)
        /** PoolAreaLightingState states */
        PROPERTY(PoolAreaLightingState, poolAreaLightingState)
        /** Garden watering states */
        PROPERTY(ToggleTimerState, gardenWateringState)
        /** Pool filter states */
        PROPERTY(ToggleTimerState, poolFilterState)
    } ControlPanel; 

    /**
    * AirCon
    */
    struct AirCon {
        /** Desired state */
        PROPERTY(AirConStates, airConState)
    } AirCon; ///< desired pin toggle states

    int SingleSonarInput;

    int padding[IOT_MSG_SIZE/sizeof(int)];		///< int padding array
};
//! @endcond

/**
 * Personal IoT layout
 */
struct wb_iot_control
{
    union NodeMCUMessages msgs[GU_SIMPLE_WHITEBOARD_BUFSIZE/IOT_MSG_SIZE];		///< int padding array

#ifdef __cplusplus
    /**
    * stuct constructor 
    */       
    wb_iot_control()
    {
        memset(this, 0, sizeof(*this));
    }
#endif
};

/**
 * Packet sent by and to nodes
 */
struct iot_control_packet
{
    uint32_t node_id;            ///< Determines what is done with the packet. Packets from some nodes are treated as queries, packets from some are treated as setters for their msg data.
    union NodeMCUMessages msg;    ///< Data
};

#endif //wb_iot_control_h

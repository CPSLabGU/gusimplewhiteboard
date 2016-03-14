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
	NUMBER_OF_NODES	                        ///< NUMBER_OF_NODES
} IoT_NodeList;

const int IoT_ids[] = 
{
        761675, //Real
        16631463,   //Real
        1134    //Bogus 
};

IoT_NodeList findNodeFromID(int id);
IoT_NodeList findNodeFromID(int id)
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
 
//! @cond Doxygen_Suppress
    //Doxy is warning about undocumented functions as a result of our macros and the fact that they're used in this union. This will disable doxy from parsing this section, which means no warnings but also no generated documentation for this section. The other option is to redefine the macros locally to fix the naming problem. - Carl.

#define IOT_MSG_SIZE 4

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
        //XXX This is just a convenience for me to store what's plugged into where. I'll populate it with different names at some point
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
    * AirCon
    */
    struct AirCon {
        /** Desired state */
        PROPERTY(AirConStates, airConState)
    } AirCon; ///< desired pin toggle states

    int padding[IOT_MSG_SIZE/sizeof(int)];		///< int padding array
};
//! @endcond

/**
 * Personal IoT layout
 */
struct wb_iot_control
{
    NodeMCUMessages msgs[GU_SIMPLE_WHITEBOARD_BUFSIZE/IOT_MSG_SIZE];		///< int padding array

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
    NodeMCUMessages msg;    ///< Data
};

#endif //wb_iot_control_h

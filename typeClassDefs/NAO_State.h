/**                                                                     
 *  /file NAO_State.h
 *                                                                      
 *  Created by Carl Lusty in 2013.                                      
 *  Copyright (c) 2013 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     
                                                                        
#ifndef NAO_State_DEFINED
#define NAO_State_DEFINED

#include <sys/types.h>
#include <sstream>
#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
#include <ctype.h>
#endif

#include "wb_nao_state.h"

namespace guWhiteboard                                                  
{
#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
	/** strings for pretty printing and parsing the various known positions of the robot. This is updated by the position machines and should be removed once the varified stance part of the motion module is working. */
        static const char *Robot_Stance_stringValues[NUM_OF_STANCES] =
        {
                "Standing",
                "FallenForward",
                "FallenBack",
                "FallenLeft",
                "FallenRight",
                "Sitting",      //NYI
                "Kneeling",     //NYI
                "Knitting",     //NYI to be implemented by Rene
                "PickedUp"
        };

	/** String values for printing which type of walk engine is currently running */
        static const char *Robot_Walk_stringValues[NUM_OF_WALKS] =
        {
                "Modded_UNSW_Walk",
                "ALMotion_Walk"
        };
#endif

        /**
 	* @brief This class is for the robot to report its current state. It is updated by various machines 
	*
	* NOTE: Read, Change, Write operations in state machines will not result in a race condition here. clfsm evaluates and runs states synchronously 
	*
	* Examples
	* --------
	*
	* Get the 'sticky' state of the Chest Button (worked out and updated by the SMButtonChest fsm)
	*
	*     NAO_State s = NAO_State_t.get(); //get from the whiteboard
	*     bool button_state = s.chest_pressed_long(); //pull the variable out of the class
	*
 	*/
        class NAO_State : public wb_nao_state
        {
        public:
		/** Constructor, calls the data structs default constructor, which sets some default values. */
                NAO_State(): wb_nao_state() {}

		/** Convenience method for checking the Fallen values */
                bool fallen() const { return stance() == FallenForward || stance() == FallenBack || stance() == FallenLeft || stance() == FallenRight; }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
                /** string constructor (see from_string() below)
		 *  @param[in] command a serialised string containing properties to set in this class
		 */
                NAO_State(const std::string &command): wb_nao_state() { from_string(command); }

                /** pretty print method for showing the current property values 
		 *  @return pretty printed string
		 */
                std::string description()
                {
                        std::stringstream ss;

                        ss << Robot_Stance_stringValues[int(stance())] << ", " << Robot_Walk_stringValues[int(walk())] << ", " << (chest_pressed_long() ? "L" : "") << int(chest_pressed()) << " @chest, " << (left_foot_pressed_long() ? "L" : "") << int(left_foot_pressed()) << " @lfoot, " << (right_foot_pressed_long() ? "L" : "") << int(right_foot_pressed()) << " @rfoot";

                        return ss.str();
                }

                /** parse class properties from a string
		 *  @param[in] str a serialised string containing properties to set in this class
		 */
                void from_string(const std::string &str)
                {
                        std::istringstream iss(str);
                        std::string token;
                        getline(iss, token, ',');
                        gu_trim(token);

                        if (token.length() && (token[0] == 'l' || token[0] == 'L' || isdigit(*token.c_str()))) goto chest_button;

                        for (int i = Standing; i < NUM_OF_STANCES; i++)
                        {
                                if (token == Robot_Stance_stringValues[i])
                                {
                                        set_stance(Robot_Stance(i));
                                        break;
                                }
                        }

                        if (!getline(iss, token, ',')) return;
                        gu_trim(token);
			
			for (int i = Modded_UNSW_Walk; i < NUM_OF_WALKS; i++)
                        {
                                if (token == Robot_Walk_stringValues[i])
                                {
                                        set_walk(Robot_Walk(i));
                                        break;
                                }
                        }

                        if (!getline(iss, token, ',')) return;
                        gu_trim(token);

                chest_button:
                        if (token.length())
                        {
                                const char *value = token.c_str();
                                if (*value == 'l' || *value == 'L')
                                {
                                        set_chest_pressed_long(true);
                                        value++;
                                }
                                set_chest_pressed(bool(value));
                        }

                        if (!getline(iss, token, ',')) return;
                        gu_trim(token);
                        if (token.length())
                        {
                                const char *value = token.c_str();
                                if (*value == 'l' || *value == 'L')
                                {
                                        set_left_foot_pressed_long(true);
                                        value++;
                                }
                                set_left_foot_pressed(bool(value));
                        }

                        if (!getline(iss, token, ',')) return;
                        gu_trim(token);
                        if (token.length())
                        {
                                const char *value = token.c_str();
                                if (*value == 'l' || *value == 'L')
                                {
                                        set_right_foot_pressed_long(true);
                                        value++;
                                }
                                set_right_foot_pressed(bool(value));
                        }
                }
#endif // WHITEBOARD_POSTER_STRING_CONVERSION
        };
}


#endif //NAO_State_DEFINED

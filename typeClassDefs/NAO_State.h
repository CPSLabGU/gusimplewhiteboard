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
#include <gu_util.h>
#include <sstream>
#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
#include <ctype.h>
#endif

namespace guWhiteboard                                                  
{
        enum Robot_Stance {
                Standing = 0,
                FallenForward,
                FallenBack,
                FallenLeft,
                FallenRight,
                Sitting,        //NYI
                Kneeling,       //NYI
                Knitting,       //NYI to be implemented by Rene
                NUM_OF_STANCES
        };

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
        static const char *Robot_Stance_stringValues[NUM_OF_STANCES] =
        {
                "Standing",
                "FallenForward",
                "FallenBack",
                "FallenLeft",
                "FallenRight",
                "Sitting",      //NYI
                "Kneeling",     //NYI
                "Knitting"      //NYI to be implemented by Rene
        };
#endif // WHITEBOARD_POSTER_STRING_CONVERSION

        class NAO_State //NOTE: Read, Change, Write operations in state machines will not result in a race condition here. clfsm evaluates and runs states synchronously
        {
                PROPERTY(Robot_Stance, stance)          ///< Currently SMRobotPosition detects if the robot has fallen over. If not fallen over SMRobotPosition posts Standing.
                PROPERTY(bool, chest_pressed_long)      ///< chest pressed for more than half a second
                PROPERTY(bool, left_foot_pressed_long)  ///< left foot pressed for more than half a second
                PROPERTY(bool, right_foot_pressed_long)  ///< right foot pressed for more than half a second
                PROPERTY(int8_t, chest_pressed) ///< This is the fudged version of this information, it counts presses within half a second instead of the actual duration of the push event (which is provided by sensors) - Updated by SMChestButton

                PROPERTY(int8_t, left_foot_pressed) ///< This is the fudged version of this information, it counts presses within half a second instead of the actual duration of the push event (which is provided by sensors) - Updated by SMLeftFootButton
                
                PROPERTY(int8_t, right_foot_pressed) ///< This is the fudged version of this information, it counts presses within half a second instead of the actual duration of the push event (which is provided by sensors) - Updated by SMRightFootButton
                int16_t pad;
        public:
                NAO_State(): _stance(Standing), _chest_pressed_long(false), _left_foot_pressed_long(false), _right_foot_pressed_long(false), _chest_pressed(0), _left_foot_pressed(0), _right_foot_pressed(0) {}

                bool fallen() const { return stance() == FallenForward || stance() == FallenBack || stance() == FallenLeft || stance() == FallenRight; }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
                /** string constructor */
                NAO_State(const std::string &command): _stance(Standing), _chest_pressed_long(false), _left_foot_pressed_long(false), _right_foot_pressed_long(false), _chest_pressed(0), _left_foot_pressed(0), _right_foot_pressed(0) { from_string(command); }

                /** convert to a string */
                std::string description()
                {
                        std::stringstream ss;

                        ss << Robot_Stance_stringValues[int(stance())] << ", " << (chest_pressed_long() ? "L" : "") << int(chest_pressed()) << " @chest, " << (left_foot_pressed_long() ? "L" : "") << int(left_foot_pressed()) << " @lfoot, " << (right_foot_pressed_long() ? "L" : "") << int(right_foot_pressed()) << " @rfoot";

                        return ss.str();
                }

                /** convert from a string */
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

                chest_button:
                        if (token.length())
                        {
                                const char *value = token.c_str();
                                if (*value == 'l' || *value == 'L')
                                {
                                        set_chest_pressed_long(true);
                                        value++;
                                }
                                set_chest_pressed(static_cast<int8_t>(atoi(value)));
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
                                set_left_foot_pressed(static_cast<int8_t>(atoi(value)));
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
                                set_right_foot_pressed(static_cast<int8_t>(atoi(value)));
                        }
                }
#endif // WHITEBOARD_POSTER_STRING_CONVERSION
        };
}

#endif //NAO_State_DEFINED

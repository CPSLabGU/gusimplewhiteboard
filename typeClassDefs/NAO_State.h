/**                                                                     
 *  /file NAO_State.h
 *                                                                      
 *  Created by Carl Lusty in 2013.                                      
 *  Copyright (c) 2013 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     

                                                                        
#ifndef NAO_State_DEFINED
#define NAO_State_DEFINED

#include <gu_util.h>
#include <sstream>

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
        
        const std::string Robot_Stance_stringValues[NUM_OF_STANCES] =
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
        
        
        class NAO_State //NOTE: Read, Change, Write operations in state machines will not result in a race condition here. clfsm evaluates and runs states synchronously
        {
                PROPERTY(Robot_Stance, Stance) //Currently SMRobotPosition detects if the robot has fallen over. If not fallen over SMRobotPosition posts Standing.
                
                PROPERTY(bool, Chest_Pressed) //This is the fudged version of this information, it lasts for half a second instead of the actual duration of the push event (which is provided by sensors) - Updated by SMChestButton
                
                PROPERTY(bool, Left_Foot_Pressed) //This is the fudged version of this information, it lasts for half a second instead of the actual duration of the push event (which is provided by sensors) - Updated by SMLeftFootButton
                
                PROPERTY(bool, Right_Foot_Pressed) //This is the fudged version of this information, it lasts for half a second instead of the actual duration of the push event (which is provided by sensors) - Updated by SMRightFootButton
                
        public:
                NAO_State()
                {
                        _Stance = Standing;
                        _Chest_Pressed = false;
                        _Left_Foot_Pressed = false;
                        _Right_Foot_Pressed = false;
                }
                
                /** convert to a string */
                std::string description()
                {
                        std::stringstream ss;

                        ss << "Stance: " << Robot_Stance_stringValues[(int)Stance()] << ", Chest_Pressed: " << Chest_Pressed() << ", Left_Foot_Pressed: " << Left_Foot_Pressed() << ", Right_Foot_Pressed: " << Right_Foot_Pressed() << ";";
                        
                        return ss.str();
                }
        };
}

#endif //NAO_State_DEFINED

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

namespace guWhiteboard                                                  
{
        enum Robot_Stance {
                Standing = 0,
                FallenForward,
                FallenBack,
                FallenLeft,
                FallenRight,
                Sitting, //NYI
                Kneeling //NYI
        };
        
        class NAO_State
        {
                PROPERTY(Robot_Stance, Stance); //Currently SMRobotPosition detects if the robot has fallen over. If not fallen over SMRobotPosition posts Standing.
                
                PROPERTY(bool, Chest_Pressed); //This is the fudged version of this information, it last for half a second instead of the actual duration of the push event (which is provided by sensors) - Updated by SMChestButton
                
        public:
                NAO_State()
                {
                        _Stance = Standing;
                        _Chest_Pressed = false;
                }
        };
}

#endif //NAO_State_DEFINED
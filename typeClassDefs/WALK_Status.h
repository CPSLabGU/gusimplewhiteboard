/**                                                                     
 *  /file WALK_Status.h
 *                                                                      
 *  Created by Carl Lusty in 2013.                                      
 *  Copyright (c) 2013 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     

                                                                        
#ifndef WALK_Status_DEFINED
#define WALK_Status_DEFINED

#include <gu_util.h>

namespace guWhiteboard                                                  
{
        class WALK_Status
        {
                PROPERTY(float, HeadYaw)

                /*
                 float currentForward;
                 float currentLeft;
                 float currentTurn;
                 float currentPower;
                 bool readyRequested;
                 bool walkReadyState;
                 bool connected;
                 */
                
        public:
                WALK_Status()
                {

                }
        };
}

#endif //WALK_Status_DEFINED
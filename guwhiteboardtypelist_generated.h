/*                                                                      
 *  guwhiteboardtypelist_generated.h                                    
 *                                                                      
 *  Created by Carl Lusty in 2013.                                      
 *  Copyright (c) 2013 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     
                                                                        
                                                                        
#ifndef _GUGENERICWHITEBOARDOBJECT_H_                                   
#define _GUGENERICWHITEBOARDOBJECT_H_                                   
                                                                        
#include "guwhiteboardtypegenerator/create_map.h" //std::map template creation shorthand        
                                                                        
//Generated on: Tue Feb  5 11:59:32 2013
                              
namespace guWhiteboard                                                  
{                                                                       
        typedef enum wb_types      
        {                                                               
                kNaoIsReadyToRun = 4,
                kNaogtrfedRun = 5,
                kSuperTest = 6,
                wb_reserved_SubscribeToAllTypes = 3
        } WBTypes;

        static std::map<int, int> type_map = create_map<int, int>(3,0)(4,1)(5,2)(6,3);

        const std::string WBTypes_stringValues[] = {    
                "wb_reserved_SubscribeToAllTypes",
                "NaoIsReadyToRun",
                "1234567",
                "Woot!"
        };      
}

#endif // _GUGENERICWHITEBOARDOBJECT_H_                                 

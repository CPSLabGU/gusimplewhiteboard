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
#include "gugenericwhiteboardobject.h"
                                                                        
//Generated on: Tue Feb  5 11:59:32 2013
                              
namespace guWhiteboard                                                  
{                                                                       
        typedef enum wb_types     //remove the reserved types in the simplewb
        {                                                               
                kNaoIsReadyToRun = 4,
                kNaogtrfedRun = 5,
                kSuperTest = 6,
                wb_reserved_SubscribeToAllTypes = 3
        } WBTypes;

        //remove and reorder string array to match the enum values
        static std::map<int, int> type_map = create_map<int, int>(3,0)(4,1)(5,2)(6,3);

        const char *WBTypes_stringValues[] = {
                "wb_reserved_SubscribeToAllTypes",
                "NaoIsReadyToRun",
                "1234567",
                "Woot!"
        };
        
        class Foo : public generic_whiteboard_object<int>
        {
        };
        
        class Foo2 : public generic_whiteboard_object<class name>;
}

#endif // _GUGENERICWHITEBOARDOBJECT_H_                                 

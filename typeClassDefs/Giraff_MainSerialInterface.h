/**                                                                     
 *  /file Giraff_MainSerialInterface.h
 *                                                                      
 *  Created by Carl Lusty in 2014.                                      
 *  Copyright (c) 2014 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     
                                                                        
#ifndef Giraff_MainSerialInterface_DEFINED
#define Giraff_MainSerialInterface_DEFINED

#include "wb_giraff_main_serial.h" 

namespace guWhiteboard                                                  
{
        /**
 	* @brief Serial interface for the main giraff board.
 	* This includes the buttons, battery data and motor control.
	*
	* Examples
	* --------
	*
	* Set the giraff motor acceleration
	*
	*     Giraff_MainSerialInterface i; 
	*     float acc = 0.3f;
	*     i.set_a(acc); //Sets the acceleration variable
	*     Giraff_MainSerialInterface_t.set(i); //Sends the set command via the wb to the giraff
	*
	* Gets the current number of button presses on one of the giraffs front buttons
	*
	*     Giraff_MainSerialInterface i = Giraff_MainSerialInterface_t.get(); //get from the whiteboard
	*     fprintf(stderr, "Number of button presses: %d", i.but0());
	*
 	*/
        class Giraff_MainSerialInterface: public wb_giraff_main_serial
        {
        public:
#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
                /** string constructor (see from_string() below) - NYI
		 *  @param[in] str a serialised string containing properties to set in this class
		 */
		Giraff_MainSerialInterface(const std::string &str) { from_string(str); }

                /** parse class properties from a string - NYI
		 *  @param[in] str a serialised string containing properties to set in this class
		 */
                void from_string(const std::string &str) 
		{
			fprintf(stderr, "NYI - Have it back: %s\n", const_cast<char *>(str.c_str()));
		}

                /** pretty print method for showing the current property values 
		 *  @return pretty printed string
		 */
                std::string description() const
                {
                        std::stringstream ss;
			ss << "NYI";
                        return ss.str();
                }
#endif // WHITEBOARD_POSTER_STRING_CONVERSION
        };
}

#endif //Giraff_MainSerialInterface_DEFINED

/**                                                                     
 *  /file Oculus_PrimeSerialInterface.h
 *                                                                      
 *  Created by Carl Lusty in 2015.                                      
 *  Copyright (c) 2015 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     
                                                                        
#ifndef Oculus_PrimeSerialInterface_DEFINED
#define Oculus_PrimeSerialInterface_DEFINED

#include "wb_oculus_prime_serial.h" 

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
#include <arpa/inet.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreserved-id-macro"
#include <sstream>
#pragma clang diagnostic pop
#endif

namespace guWhiteboard                                                  
{
        /**
 	* @brief Serial interface for the main oculus prime board.
	*
	* Examples
	* --------
	*
	* Set the oculus prime motor acceleration
	*
	*     Oculus_PrimeSerialInterface i; 
    *     wb_byte_pair p; p.set_first(15); p.set_second(15);
	*     i.set_forward(p); 
	*     Oculus_PrimeSerialInterface_t.set(i); //Sends the set command via the wb to the oculus prime
 	*/
        class Oculus_PrimeSerialInterface: public wb_oculus_prime_serial
        {
        public:

        /** default constructor 
		 */
		Oculus_PrimeSerialInterface() { }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
                /** string constructor (see from_string() below)
		 *  @param[in] str a serialised string containing properties to set in this class
		 */
		Oculus_PrimeSerialInterface(const std::string &str) { from_string(str); }

#define DELIMITER ','
#define SEP ':'
#define ARRAY_DEL '-'
#define SV std::vector<std::string>
#define PARSER(s, c, p) if (k.compare(s) == 0) { set_##c ( p ); continue; }
#define ARRAY_PARSER(s, c, p) if (k.compare(s) == 0)                        \
            {                                                               \
                SV kk = components_of_string_separated(v, ARRAY_DEL, true); \
			    for(size_t n = 0; n < kk.size(); n++)                       \
                    { v = kk.at(n); _##c[n] = p; }                                        \
                continue;                                                   \
            }
#define COMP(v, s) v.compare(0, 2, s) == 0
#define IS_HEX(v) COMP(v, "F*") || COMP(v, "I*")

#define PARSE_FLOAT static_cast<float>(atof(v.c_str()))
#define PARSE_INT16 static_cast<int16_t>(atoi(v.c_str()))
#define PARSE_INT32 static_cast<int32_t>(atoi(v.c_str()))
#define PARSE_UINT8 static_cast<uint8_t>(atoi(v.c_str())) 

                /** parse class properties from a string
		 *  @param[in] str a serialised string containing properties to set in this class
		 */
                void from_string(const std::string &str) 
		{
			SV sn = components_of_string_separated(str, DELIMITER, true);
			for(size_t i = 0; i < sn.size(); i++)
			{
				SV kv = components_of_string_separated(sn.at(i), SEP, true);
				if(kv.size() != 2)
				{
					fprintf(stderr, "parse error\n");
					return;
				}
				std::string k = kv.at(0);
				std::string v = kv.at(1);

                //serial parser - removed indenting so I can read it, Carl.
ARRAY_PARSER("f",     forward,                    PARSE_UINT8 )
PARSER("s",     stop,                       1)

                //pretty parser - removed indenting so I can read it, Carl.
ARRAY_PARSER("forward",       forward,               PARSE_UINT8)
PARSER("stop",          stop,                       1)
			}
		}

                /** pretty print method for showing the current property values 
		 *  @return pretty printed string
		 */
                std::string description() const
                {
                        std::stringstream ss;
                        //ss  
       //                 << forward().first() << " " << forward().second() << " forward : , ";
                        return ss.str();
                }
#endif // WHITEBOARD_POSTER_STRING_CONVERSION
        };
}

#endif //Oculus_PrimeSerialInterface_DEFINED

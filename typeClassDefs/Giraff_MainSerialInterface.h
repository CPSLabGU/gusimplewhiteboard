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

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
#include <arpa/inet.h>
#include <sstream>
#endif

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

        /** default constructor 
		 */
		Giraff_MainSerialInterface() { }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
                /** string constructor (see from_string() below)
		 *  @param[in] str a serialised string containing properties to set in this class
		 */
		Giraff_MainSerialInterface(const std::string &str) { from_string(str); }

                /** parse class properties from a string
		 *  @param[in] str a serialised string containing properties to set in this class
		 */
#define DELIMITER ','
#define SEP ':'
#define PARSER(s, c, p) if (k.compare(s) == 0) { set_##c ( p ); }
#define SV std::vector<std::string>
#define COMP(v, s) v.compare(0, 2, s) == 0
#define IS_HEX(v) COMP(v, "F*") || COMP(v, "I*")
#define READ_HEX(v) ^(void){ \
        uint32_t num;                           \
        char *ch = (char *)v.substr(2).c_str(); \
        sscanf(ch, "%x", &num);                 \
        int temp =  htonl(*(unsigned int*)&num);\
        return temp; }()

#define PARSE_HEX_FLOAT(v) ^(void) { int tmp = READ_HEX(v); \
                                     return *((float*)&tmp); }()
#define PARSE_HEX_INT16(v) ^(void) { return static_cast<int16_t>(READ_HEX(v)); }()
#define PARSE_HEX_INT32(v) ^(void) { return static_cast<int32_t>(READ_HEX(v)); }()
#define PARSE_HEX_BITSET(v) ^(void) { return static_cast<int8_t>(0); }()

#define PARSE_FLOAT IS_HEX(v) ? PARSE_HEX_FLOAT(v) : static_cast<float>(atof(v.c_str()))
#define PARSE_INT16 IS_HEX(v) ? PARSE_HEX_INT16(v) : static_cast<int16_t>(atoi(v.c_str()))
#define PARSE_INT32 IS_HEX(v) ? PARSE_HEX_INT32(v) : static_cast<int32_t>(atoi(v.c_str()))
#define PARSE_BITSET IS_HEX(v) ? PARSE_HEX_BITSET(v) : static_cast<uint8_t>(0) //NYI
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

				PARSER("v", v, PARSE_FLOAT)
				PARSER("r", r, PARSE_FLOAT)
				PARSER("a", a, PARSE_FLOAT)
				PARSER("p", p, PARSE_FLOAT)
				PARSER("mode", mode, PARSE_BITSET)
				//PARSER("undock", undock, PARSE_FLOAT)
				//PARSER("home", home, PARSE_FLOAT)
				PARSER("tilt_homing_state", tilt_homing_state, PARSE_BITSET)
				PARSER("tilt_angle_from_home", tilt_angle_from_home, PARSE_FLOAT)
				PARSER("head_angle", tilt_angle_from_home, PARSE_FLOAT)
				PARSER("vg", vg, PARSE_FLOAT)
				PARSER("vgr", vgr, PARSE_FLOAT)
				PARSER("cdp", cdp, PARSE_FLOAT)
				PARSER("cvg", cvg, PARSE_FLOAT)
				PARSER("but0", but0, PARSE_INT16)
				PARSER("but1", but1, PARSE_INT16)
				PARSER("dial", dial, PARSE_INT16)
				PARSER("enc0", enc0, PARSE_INT32)
				PARSER("enc1", enc1, PARSE_INT32)
				PARSER("enc2", enc2, PARSE_INT32)
				//PARSER("button_data", button_data, PARSE_FLOAT)
				//PARSER("bulk_data", bulk_data, PARSE_FLOAT)
				//PARSER("charger_data", charger_data, PARSE_FLOAT)
			}
		}

                /** pretty print method for showing the current property values 
		 *  @return pretty printed string
		 */
                std::string description() const
                {
                        std::stringstream ss;
                        ss << v() << " : v, " << r() << " : r, " << a() << " : a, " << p() << " : p, " << /*mode() <<*/ " : mode, " << /*tilt_homing_state() <<*/ " : tilt_homing_state, " << tilt_angle_from_home() << " : tilt_angle_from_home, " << vg() << " : vg, " << vgr() << " : vgr, " << cdp() << " : cdp, " << cvg() << " : cvg, " << but0() << " : but0, " << but1() << " : but1, " << dial() << " : dial, " << enc0() << " : enc0, " << enc1() << " : enc1, " << enc2() << " : enc2";
                        return ss.str();
                }
#endif // WHITEBOARD_POSTER_STRING_CONVERSION
        };
}

#endif //Giraff_MainSerialInterface_DEFINED

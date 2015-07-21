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

#define DELIMITER ','
#define SEP ':'
#define PARSER(s, c, p) if (k.compare(s) == 0) { set_##c ( p ); continue; }
#define SV std::vector<std::string>
#define COMP(v, s) v.compare(0, 2, s) == 0
#define IS_HEX(v) COMP(v, "F*") || COMP(v, "I*")

#define READ_HEX(v) htonl(strtol(v.c_str()+2, NULL, 16))
#define PARSE_HEX_FLOAT(v) static_cast<float>(READ_HEX(v))
#define PARSE_HEX_INT32(v) static_cast<int32_t>(READ_HEX(v))
#define PARSE_HEX_INT16(v) static_cast<int16_t>(READ_HEX(v))
#define PARSE_HEX_INT8(v) static_cast<int8_t>(READ_HEX(v))

#define PARSE_FLOAT IS_HEX(v) ? PARSE_HEX_FLOAT(v) : static_cast<float>(atof(v.c_str()))
#define PARSE_INT16 IS_HEX(v) ? PARSE_HEX_INT16(v) : static_cast<int16_t>(atoi(v.c_str()))
#define PARSE_INT32 IS_HEX(v) ? PARSE_HEX_INT32(v) : static_cast<int32_t>(atoi(v.c_str()))
#define PARSE_INT8 IS_HEX(v) ? PARSE_HEX_INT8(v) : static_cast<uint8_t>(atoi(v.c_str())) 
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
PARSER("v",     velocity,                   PARSE_FLOAT)
PARSER("r",     movement_type,              static_cast<Giraff_MovementType>(PARSE_FLOAT))
PARSER("a",     acceleration,               PARSE_FLOAT)
PARSER("p",     position,                   PARSE_FLOAT)
PARSER("mode",  coord_type,                 static_cast<Giraff_CoordType>(PARSE_INT8))
PARSER("tilt_angle_from_home", head_angle,  PARSE_FLOAT)
PARSER("vg",    max_gear_ratio,             PARSE_FLOAT)
PARSER("vgr",   gear_ratio_increments,      PARSE_FLOAT)
PARSER("cdp",   gear_ratio_slowdown_dist,   PARSE_FLOAT)
PARSER("cvg",   current_gear_ratio,         PARSE_FLOAT)
PARSER("but0",  red_button_presses,         PARSE_INT16)
PARSER("but1",  blue_button_presses,        PARSE_INT16)
PARSER("dial",  dial_increments,            PARSE_INT16)
PARSER("enc0",  left_motor_encoder_ticks,   PARSE_INT32)
PARSER("enc1",  right_motor_encoder_ticks,  PARSE_INT32)
PARSER("enc2",  head_motor_encoder_ticks,   PARSE_INT32)

                //pretty parser - removed indenting so I can read it, Carl.
PARSER("velocity",                  velocity,               PARSE_FLOAT)
PARSER("movement_type",             movement_type,          static_cast<Giraff_MovementType>(PARSE_FLOAT))
PARSER("acceleration",              acceleration,           PARSE_FLOAT)
PARSER("position",                  position,               PARSE_FLOAT)
PARSER("coord_type",                coord_type,             static_cast<Giraff_CoordType>(PARSE_INT8))
PARSER("head_angle",                head_angle,             PARSE_FLOAT)
PARSER("max_gear_ratio",            max_gear_ratio,         PARSE_FLOAT)
PARSER("gear_ratio_increments",     gear_ratio_increments,  PARSE_FLOAT)
PARSER("gear_ratio_slowdown_dist",  gear_ratio_slowdown_dist, PARSE_FLOAT)
PARSER("current_gear_ratio",        current_gear_ratio,     PARSE_FLOAT)
PARSER("red_button_presses",        red_button_presses,     PARSE_INT16)
PARSER("blue_button_presses",       blue_button_presses,    PARSE_INT16)
PARSER("dial_increments",           dial_increments,        PARSE_INT16)
PARSER("left_motor_encoder_ticks",  left_motor_encoder_ticks, PARSE_INT32)
PARSER("right_motor_encoder_ticks", right_motor_encoder_ticks, PARSE_INT32)
PARSER("head_motor_encoder_ticks",  head_motor_encoder_ticks, PARSE_INT32)
			}
		}

                /** pretty print method for showing the current property values 
		 *  @return pretty printed string
		 */
                std::string description() const
                {
                        std::stringstream ss;
                        ss  
                        << velocity() << "velocity : , " 
                        << movement_type() << "movement_type : , " 
                        << acceleration() << "acceleration : , " 
                        << position() << "position : , " 
                        << coord_type() << "coord_type : , " 
                        << head_angle() << "head_angle : , " 
                        << max_gear_ratio() << "max_gear_ratio : , " 
                        << gear_ratio_increments() << "gear_ratio_increments : , " 
                        << gear_ratio_slowdown_dist() << "gear_ratio_slowdown_dist : , " 
                        << current_gear_ratio() << "current_gear_ratio : , " 
                        << red_button_presses() << "red_button_presses : , " 
                        << blue_button_presses() << "blue_button_presses : , " 
                        << dial_increments() << "dial_increments : , " 
                        << left_motor_encoder_ticks() << "left_motor_encoder_ticks : , " 
                        << right_motor_encoder_ticks() << "right_motor_encoder_ticks : , " 
                        << head_motor_encoder_ticks() << "head_motor_encoder_ticks : ";
                        return ss.str();
                }
#endif // WHITEBOARD_POSTER_STRING_CONVERSION
        };
}

#endif //Giraff_MainSerialInterface_DEFINED

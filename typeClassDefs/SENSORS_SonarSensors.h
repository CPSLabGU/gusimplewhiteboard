/**                                                                     
 *  /file SENSORS_SonarSensors.h
 *                                                                      
 *  Created by Carl Lusty in 2013.                                      
 *  Copyright (c) 2013 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     

                                                                        
#ifndef SENSORS_SonarSensors_DEFINED
#define SENSORS_SonarSensors_DEFINED

#include "wb_sensors_sonar.h" 

namespace guWhiteboard                                                  
{
        namespace Sonar
        {
                typedef enum ReadingCodesEnum {
                        Left0,
                        Left1,
                        Left2,
                        Left3,
                        Left4,
                        Left5,
                        Left6,
                        Left7,
                        Left8,
                        Left9,
                        Center0,
                        Center1,
                        Center2,
                        Center3,
                        Center4,
                        Center5,
                        Center6,
                        Center7,
                        Center8,
                        Center9,
                        Right0,
                        Right1,
                        Right2,
                        Right3,
                        Right4,
                        Right5,
                        Right6,
                        Right7,
                        Right8,
                        Right9,
                        NUMBER_OF_READINGS
                } ReadingCode;

            /**
             * Indexes for the Giraff sonar sensors
             */
            enum Giraff
            {
                LeftFrontCM          = ReadingCode::Left0,
                LeftBackCM           = ReadingCode::Left1,
                LeftFrontMM          = ReadingCode::Left2,
                LeftBackMM           = ReadingCode::Left3,
                LeftFrontAverageCM   = ReadingCode::Left4,
                LeftBackAverageCM    = ReadingCode::Left5,
                LeftFrontAverageMM   = ReadingCode::Left6,
                LeftBackAverageMM    = ReadingCode::Left7,
                LeftFrontHighByte    = ReadingCode::Left8,
                LeftBackHighByte     = ReadingCode::Left9,

                CentreFrontCM        = ReadingCode::Center0,
                CentreFrontMM        = ReadingCode::Center1,
                CentreFrontAverageCM = ReadingCode::Center2,
                CentreFrontAverageMM = ReadingCode::Center3,
                
                RightFrontCM          = ReadingCode::Right0,
                RightBackCM           = ReadingCode::Right1,
                RightFrontMM          = ReadingCode::Right2,
                RightBackMM           = ReadingCode::Right3,
                RightFrontAverageCM   = ReadingCode::Right4,
                RightBackAverageCM    = ReadingCode::Right5,
                RightFrontAverageMM   = ReadingCode::Right6,
                RightBackAverageMM    = ReadingCode::Right7,
                RightFrontHighByte    = ReadingCode::Right8,
                RightBackHighByte     = ReadingCode::Right9
            };
        }
 
        /**
 	* @brief Contains the latest Sonar readings.
	*
	* Measured in CM, Range is 0-255, Updated at 10Hz (currently, max of 100Hz). Object nearer than 20cm to a Nao will report a distance of 20cm.
	*
	* Examples
	* --------
	*
	* Get the distance in cm to the nearest object on the left
	*
	*     SENSORS_SonarSensors s = SENSORS_SonarSensors_t.get(); //get from the whiteboard
	*     int dist = s.sonar(Sonar::Left0); //pull the variable out of the class
	*
 	*/       
        class SENSORS_SonarSensors : public wb_sensors_sonar
        {
                
        public:
                SENSORS_SonarSensors()
                {

                }
                
#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
                /** string constructor (see from_string() below) 
		 *  @param str a serialised string containing properties to set in this class
		 */
                SENSORS_SonarSensors(const std::string &str) { from_string(str); }
                
                /** parse class properties from a string 
		 *  @param str a serialised string containing properties to set in this class
		 */
                void from_string(const std::string &str)
                {
	                std::istringstream iss(str);
	                std::string token;
			for (int i=0; i< Sonar::NUMBER_OF_READINGS && getline(iss, token, ','); i++  )  
			{ u_int8_t value = static_cast<u_int8_t>(atoi(token.c_str())); 
					set_sonar(value,i); 
			}
                }
                
#pragma clang diagnostic ignored "-Wcovered-switch-default"
#pragma clang diagnostic ignored "-Wunreachable-code"
                
                /** pretty print method for showing the current property values 
		 *  @return pretty printed string
		 */
                std::string description() const
                {
                        std::stringstream ss;

                        for (int i = 0; i < (Sonar::NUMBER_OF_READINGS-1); i++)
                                ss << static_cast<int>(sonar(i)) << ",";
                        ss << static_cast<int>(sonar(Sonar::NUMBER_OF_READINGS-1)); //Don't want a ', ' for the last element.
                        
                        return ss.str();
                }
#endif // WHITEBOARD_POSTER_STRING_CONVERSION
                
        };
}

#endif //SENSORS_SonarSensors_DEFINED

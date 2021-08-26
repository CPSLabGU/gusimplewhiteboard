/**                                                                     
 *  /file SENSORSSonarSensors.h
 *                                                                      
 *  Created by Carl Lusty in 2013.                                      
 *  Copyright (c) 2013 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     

                                                                        
#ifndef SENSORSSonarSensors_DEFINED
#define SENSORSSonarSensors_DEFINED

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
                LeftFrontCM          = Left0,
                LeftBackCM           = Left1,
                LeftFrontMM          = Left2,
                LeftBackMM           = Left3,
                LeftFrontAverageCM   = Left4,
                LeftBackAverageCM    = Left5,
                LeftFrontAverageMM   = Left6,
                LeftBackAverageMM    = Left7,
                LeftFrontHighByte    = Left8,
                LeftBackHighByte     = Left9,

                CentreFrontCM        = Center0,
                CentreFrontMM        = Center1,
                CentreFrontAverageCM = Center2,
                CentreFrontAverageMM = Center3,
                
                RightFrontCM          = Right0,
                RightBackCM           = Right1,
                RightFrontMM          = Right2,
                RightBackMM           = Right3,
                RightFrontAverageCM   = Right4,
                RightBackAverageCM    = Right5,
                RightFrontAverageMM   = Right6,
                RightBackAverageMM    = Right7,
                RightFrontHighByte    = Right8,
                RightBackHighByte     = Right9
            };

	    enum Toto
	    {
		    sZero = Left0,
		    sEleven = Left1,
		    sTen = Left2,
		    sNine = Left3,

		    sOne = Center0,
		    sTwo = Center1,
		    sThree = Center2,
		    sFour = Center3,

		    sFive = Right0,
		    sSix = Right1,
		    sSeven = Right2,
		    sEight = Right3
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
	*     SENSORSSonarSensors s = SENSORSSonarSensors_t.get(); //get from the whiteboard
	*     int dist = s.sonar(Sonar::Left0); //pull the variable out of the class
	*
 	*/       
        class SENSORSSonarSensors : public wb_sensors_sonar
        {
                
        public:
                SENSORSSonarSensors()
                {

                }

                 /** comparison operator */
		        inline bool operator == (const SENSORSSonarSensors &s) 
	        	{
                   for(int i = Sonar::Left0; i < Sonar::NUMBER_OF_READINGS; i++)
                   {
                        if(this->sonar(i) != s.sonar(i))
                            return false;
                        else
                            continue;
                   }
    		    	return true;
        		}

            /// compare two sonar sensor value records and return false if they are the same
		        inline bool operator != (const SENSORSSonarSensors &s) 
                {
                    return !(*this == s);
                }

#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
                /** string constructor (see from_string() below) 
		 *  @param str a serialised string containing properties to set in this class
		 */
                SENSORSSonarSensors(const std::string &str) { from_string(str); }
                
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

#endif //SENSORSSonarSensors_DEFINED

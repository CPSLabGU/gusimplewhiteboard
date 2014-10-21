/**                                                                     
 *  /file SENSORS_LedsSensors.h
 *                                                                      
 *  Created by Carl Lusty in 2013.                                      
 *  Copyright (c) 2013 Carl Lusty                                       
 *  All rights reserved.                                                
 */                                                                     

                                                                        
#ifndef SENSORS_LedsSensors_DEFINED
#define SENSORS_LedsSensors_DEFINED


#include <gu_util.h>
#include <assert.h>
#include "wb_sensors_leds.h" 

namespace guWhiteboard                                                  
{
	/// Predefined colour values, feel free to add more, just implement them in changeLedColour 
        enum LEDColour
        {
                Off = -1, 	///< turn off leds
                Red = 0,	///< turn leds red
                Green,		///< turn leds green
                Blue,		///< turn leds blue
                Yellow,		///< turn leds yellow
                NUMBER_OF_LEDS_COLOURS	///< number of LEDColours
        };
        
	/*! Predefined groups of leds that can be changed together, when adding more make sure to implement them in LEDsGroupChange */
        enum LEDGroups
        {
                AllLEDs = 0,  	///< Only off is supported regardless of what is passed in
                Ears,         	///< Number of leds to turn on is the value
                LEar,      	///< Number of leds to turn on is the value 
                REar,		///< Number of leds to turn on is the value	
                Eyes,		///< All others have the desired colour as the passed value to LEDsGroupChange
                LEye,
                REye,
                Chest,
                Feet,
                LFoot,
                RFoot,
                NUMBER_OF_LEDS_GROUPS
        };
        
        namespace LEDs
        {
		/*! LED selection enum */
                enum LEDCode
                {
                        LeftEar1 = 0,
                        LeftEar2,
                        LeftEar3,
                        LeftEar4,
                        LeftEar5,
                        LeftEar6,
                        LeftEar7,
                        LeftEar8,
                        LeftEar9,
                        LeftEar10,
                        RightEar1,
                        RightEar2,
                        RightEar3,
                        RightEar4,
                        RightEar5,
                        RightEar6,
                        RightEar7,
                        RightEar8,
                        RightEar9,
                        RightEar10,
                        LeftEyeRed1,
                        LeftEyeRed2,
                        LeftEyeRed3,
                        LeftEyeRed4,
                        LeftEyeRed5,
                        LeftEyeRed6,
                        LeftEyeRed7,
                        LeftEyeRed8,
                        LeftEyeGreen1,
                        LeftEyeGreen2,
                        LeftEyeGreen3,
                        LeftEyeGreen4,
                        LeftEyeGreen5,
                        LeftEyeGreen6,
                        LeftEyeGreen7,
                        LeftEyeGreen8,
                        LeftEyeBlue1,
                        LeftEyeBlue2,
                        LeftEyeBlue3,
                        LeftEyeBlue4,
                        LeftEyeBlue5,
                        LeftEyeBlue6,
                        LeftEyeBlue7,
                        LeftEyeBlue8,
                        RightEyeRed1,
                        RightEyeRed2,
                        RightEyeRed3,
                        RightEyeRed4,
                        RightEyeRed5,
                        RightEyeRed6,
                        RightEyeRed7,
                        RightEyeRed8,
                        RightEyeGreen1,
                        RightEyeGreen2,
                        RightEyeGreen3,
                        RightEyeGreen4,
                        RightEyeGreen5,
                        RightEyeGreen6,
                        RightEyeGreen7,
                        RightEyeGreen8,
                        RightEyeBlue1,
                        RightEyeBlue2,
                        RightEyeBlue3,
                        RightEyeBlue4,
                        RightEyeBlue5,
                        RightEyeBlue6,
                        RightEyeBlue7,
                        RightEyeBlue8,
                        ChestRed,
                        ChestGreen,
                        ChestBlue,
                        LeftFootRed,
                        LeftFootGreen,
                        LeftFootBlue,
                        RightFootRed,
                        RightFootGreen,
                        RightFootBlue,
                        NUMBER_OF_LEDS
                };
                
#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
		/*! pretty print and parse string values for each LED in the LED enum */
                static const char *ledNames[NUMBER_OF_LEDS] =
                {
                        "LeftEar1",
                        "LeftEar2",
                        "LeftEar3",
                        "LeftEar4",
                        "LeftEar5",
                        "LeftEar6",
                        "LeftEar7",
                        "LeftEar8",
                        "LeftEar9",
                        "LeftEar10",
                        "RightEar1",
                        "RightEar2",
                        "RightEar3",
                        "RightEar4",
                        "RightEar5",
                        "RightEar6",
                        "RightEar7",
                        "RightEar8",
                        "RightEar9",
                        "RightEar10",
                        "LeftEyeRed1",
                        "LeftEyeRed2",
                        "LeftEyeRed3",
                        "LeftEyeRed4",
                        "LeftEyeRed5",
                        "LeftEyeRed6",
                        "LeftEyeRed7",
                        "LeftEyeRed8",
                        "LeftEyeGreen1",
                        "LeftEyeGreen2",
                        "LeftEyeGreen3",
                        "LeftEyeGreen4",
                        "LeftEyeGreen5",
                        "LeftEyeGreen6",
                        "LeftEyeGreen7",
                        "LeftEyeGreen8",
                        "LeftEyeBlue1",
                        "LeftEyeBlue2",
                        "LeftEyeBlue3",
                        "LeftEyeBlue4",
                        "LeftEyeBlue5",
                        "LeftEyeBlue6",
                        "LeftEyeBlue7",
                        "LeftEyeBlue8",
                        "RightEyeRed1",
                        "RightEyeRed2",
                        "RightEyeRed3",
                        "RightEyeRed4",
                        "RightEyeRed5",
                        "RightEyeRed6",
                        "RightEyeRed7",
                        "RightEyeRed8",
                        "RightEyeGreen1",
                        "RightEyeGreen2",
                        "RightEyeGreen3",
                        "RightEyeGreen4",
                        "RightEyeGreen5",
                        "RightEyeGreen6",
                        "RightEyeGreen7",
                        "RightEyeGreen8",
                        "RightEyeBlue1",
                        "RightEyeBlue2",
                        "RightEyeBlue3",
                        "RightEyeBlue4",
                        "RightEyeBlue5",
                        "RightEyeBlue6",
                        "RightEyeBlue7",
                        "RightEyeBlue8",
                        "ChestRed",
                        "ChestGreen",
                        "ChestBlue",
                        "LeftFootRed",
                        "LeftFootGreen",
                        "LeftFootBlue",
                        "RightFootRed",
                        "RightFootGreen",
                        "RightFootBlue",
                };
#endif
        }

        /**
 	* @brief Class for changing the LEDs on a robot, designed for Nao but is fairly generic
	*
	* Examples
	* --------
	*
	* Change a group of LEDs
	*
	*     LEDsGroupChange(AllLEDs, Off);    //turn all LEDs off
	*     LEDsGroupChange(Eyes, Red);       //make the eyes completely red
	*     LEDsGroupChange(Ears, 5);         //turn half of the ear LEDs on
	*     
	* Change a single LED, stateful: on / off
	*     
	*     changeLed(LEDs::ChestRed, false);
	*     
	* Change a single LED, intensity: 0 == Off, 100 == Max
	*     
	*     changeLed(LEDs::ChestRed, 0);
	*     changeLed(LEDs::ChestGreen, 0);
	*     changeLed(LEDs::ChestBlue, 100); 	//0 red, 0 green, 100 percent blue == Chest button turns blue
	*
 	*/ 
        class SENSORS_LedsSensors : public wb_sensors_leds
        {
                
        public:
		/** Constructor, sets all LED values to off */
                SENSORS_LedsSensors()
                {
                        LEDsGroupChange(AllLEDs, Off);
                }
                
		/** @brief Allows changes to be made to a group of LEDs
		 *  @param target_group The LED group to be changed
		 *  @param target_colour_or_numOfEars The colour to change to, this is also a counter in the case of the Ears which can only be blue anyway. ie Ears 5 == turn on five ear LEDs, Eyes Red == change the eye colours to red
		 */
                void LEDsGroupChange(LEDGroups target_group, LEDColour target_colour_or_numOfEars)
                {
                        switch (target_group)
                        {
                                case AllLEDs: //Only supporting off command
                                {
                                        for(int i = LEDs::LeftEar1; i < LEDs::NUMBER_OF_LEDS; i++)
                                                changeLed(static_cast<LEDs::LEDCode>(i), false);
                                        break;
                                }
                                case Ears:
                                {
                                        for(int i = LEDs::LeftEar1; i <= LEDs::LeftEar10; i++)
                                                i-LEDs::LeftEar1 < target_colour_or_numOfEars ? changeLed(static_cast<LEDs::LEDCode>(i), true) : changeLed(static_cast<LEDs::LEDCode>(i), false);
                                        for(int i = LEDs::RightEar1; i <= LEDs::RightEar10; i++)
                                                i-LEDs::RightEar1 < target_colour_or_numOfEars ? changeLed(static_cast<LEDs::LEDCode>(i), true) : changeLed(static_cast<LEDs::LEDCode>(i), false);
                                        break;
                                }
                                case LEar:
                                {
                                        for(int i = LEDs::LeftEar1; i <= LEDs::LeftEar10; i++)
                                                i-LEDs::LeftEar1 < target_colour_or_numOfEars ? changeLed(static_cast<LEDs::LEDCode>(i), true) : changeLed(static_cast<LEDs::LEDCode>(i), false);
                                        break;
                                }
                                case REar:
                                {
                                        for(int i = LEDs::RightEar1; i <= LEDs::RightEar10; i++)
                                                i-LEDs::RightEar1 < target_colour_or_numOfEars ? changeLed(static_cast<LEDs::LEDCode>(i), true) : changeLed(static_cast<LEDs::LEDCode>(i), false);
                                        break;
                                }
                                case Eyes:
                                {
                                        for(int i = LEDs::LeftEyeRed1; i <= LEDs::LeftEyeRed8; i++)
                                        {
                                                LEDs::LEDCode led[3] = {LEDs::LEDCode(i), LEDs::LEDCode(i+(LEDs::LeftEyeGreen1-LEDs::LeftEyeRed1)), LEDs::LEDCode(i+(LEDs::LeftEyeBlue1-LEDs::LeftEyeRed1))};
                                                changeLedColour(led, target_colour_or_numOfEars);
                                        }
                                        for(int i = LEDs::RightEyeRed1; i <= LEDs::RightEyeRed8; i++)
                                        {
                                                LEDs::LEDCode led[3] = {LEDs::LEDCode(i), LEDs::LEDCode(i+(LEDs::RightEyeGreen1-LEDs::RightEyeRed1)), LEDs::LEDCode(i+(LEDs::RightEyeBlue1-LEDs::RightEyeRed1))};
                                                changeLedColour(led, target_colour_or_numOfEars);
                                        }
                                        break;
                                }
                                case LEye:
                                {
                                        for(int i = LEDs::LeftEyeRed1; i <= LEDs::LeftEyeRed8; i++)
                                        {
                                                LEDs::LEDCode led[3] = {LEDs::LEDCode(i), LEDs::LEDCode(i+(LEDs::LeftEyeGreen1-LEDs::LeftEyeRed1)), LEDs::LEDCode(i+(LEDs::LeftEyeBlue1-LEDs::LeftEyeRed1))};
                                                changeLedColour(led, target_colour_or_numOfEars);
                                        }
                                        break;
                                }
                                case REye:
                                {
                                        for(int i = LEDs::RightEyeRed1; i <= LEDs::RightEyeRed8; i++)
                                        {
                                                LEDs::LEDCode led[3] = {LEDs::LEDCode(i), LEDs::LEDCode(i+(LEDs::RightEyeGreen1-LEDs::RightEyeRed1)), LEDs::LEDCode(i+(LEDs::RightEyeBlue1-LEDs::RightEyeRed1))};
                                                changeLedColour(led, target_colour_or_numOfEars);
                                        }
                                        break;
                                }
                                case Chest:
                                {
                                        LEDs::LEDCode led[3] = {LEDs::ChestRed, LEDs::ChestGreen, LEDs::ChestBlue};
                                        changeLedColour(led, target_colour_or_numOfEars);
                                        break;
                                }
                                case Feet:
                                {
                                        LEDs::LEDCode led[3] = {LEDs::LeftFootRed, LEDs::LeftFootGreen, LEDs::LeftFootBlue};
                                        changeLedColour(led, target_colour_or_numOfEars);
                                        LEDs::LEDCode led2[3] = {LEDs::RightFootRed, LEDs::RightFootGreen, LEDs::RightFootBlue};
                                        changeLedColour(led2, target_colour_or_numOfEars);
                                        break;
                                }
                                case LFoot:
                                {
                                        LEDs::LEDCode led[3] = {LEDs::LeftFootRed, LEDs::LeftFootGreen, LEDs::LeftFootBlue};
                                        changeLedColour(led, target_colour_or_numOfEars);
                                        break;
                                }
                                case RFoot:
                                {
                                        LEDs::LEDCode led[3] = {LEDs::RightFootRed, LEDs::RightFootGreen, LEDs::RightFootBlue};
                                        changeLedColour(led, target_colour_or_numOfEars);
                                        break;
                                }
                                case NUMBER_OF_LEDS_GROUPS:
                                        break;
                        }
                }
 
		/** @brief Colour mixer for RGB LEDs
		 *  @param led 0 == Red, 1 == Green, 2 == Blue LEDs
		 *  @param colour the target colour
		 */
                void changeLedColour(LEDs::LEDCode led[3], LEDColour colour)
                {
                        //led[0] R, led[1] G, led[2] B
                        switch (colour)
                        {
                                case Off:
                                        changeLed(led[0], false);
                                        changeLed(led[1], false);
                                        changeLed(led[2], false);
                                        break;
                                case Red:
                                        changeLed(led[0], true);
                                        changeLed(led[1], false);
                                        changeLed(led[2], false);
                                        break;
                                case Green:
                                        changeLed(led[0], false);
                                        changeLed(led[1], true);
                                        changeLed(led[2], false);
                                        break;
                                case Blue:
                                        changeLed(led[0], false);
                                        changeLed(led[1], false);
                                        changeLed(led[2], true);
                                        break;
                                case Yellow:
                                        changeLed(led[0], static_cast<u_int8_t>(100));
                                        changeLed(led[1], static_cast<u_int8_t>(25));
                                        changeLed(led[2], static_cast<u_int8_t>(0));
                                        break;
                                case NUMBER_OF_LEDS_COLOURS:
                                        break;
                        }
                }
  
		/** @brief Turn on or off an individual LED
		 *  @param led The LED to change
		 *  @param state on or off
		 */               
                void changeLed(LEDs::LEDCode led, bool state)
                {
                 	changeLed(led, state ? static_cast<u_int8_t>(100) : static_cast<u_int8_t>(0));
                }
   
		/** @brief Set the intensity value for an individual LED
		 *  @param led The LED to change
		 *  @param level the new intensity value. Range: 0 - 100
		 */               
                void changeLed(LEDs::LEDCode led, u_int8_t level) //level == percentage, 100 == MAX
                {
                        _leds[led] = level;
                }
        };
}

#endif //SENSORS_LedsSensors_DEFINED

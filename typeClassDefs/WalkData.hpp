/* 
 * File:   WalkDaata.h
 * Author: eugene
 *
 * Created on 5 December 2013, 11:19 AM
 */
#include <string>

#ifndef WalkData_DEFINED
#define	WalkData_DEFINED

namespace guWhiteboard {
/**@brief Class contain information about the Nao's Walk for debug purposes
 * Contains sensors readings while the nao walks to debug it's walk
 */
class WalkData {
public:
	/**The sensor data. First dimension of the array is for different sensors, accelometer etc
	 * Second dimension contains last 7 readings
	 */
	float data[4][7];
	/**Number of data points in the message*/
	int numPoints;
	/**Constructor*/
	WalkData() {}
	/**
	 * @brief String Constructor NYI
     */
	WalkData(std::string s) {
        from_string(s);
    }

    void from_string(const std::string)  {
		for(int i = 0; i<3; ++i) {
			for(int j = 0; j<4; ++j) {
				data[j][i] = static_cast<float>(i*j);
			}
		}
	}
	
	/**
	 * @brief convert message to a serialized string. NYI
     * @return The serailised string
     */
	std::string description() {
		return std::string("NYI");
	}
};
}

#endif	/* WalkData_DEFINED */


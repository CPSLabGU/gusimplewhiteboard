#ifndef DifferentialRobotControlStatus_DEFINED
#define	DifferentialRobotControlStatus_DEFINED

#include <cstdlib>
#include <stdlib.h>
#include <cstring>
#include <gu_util.h>
#include "gusimplewhiteboard.h" 
#include "wb_differential_robot.h"

namespace guWhiteboard {
	class DifferentialRobotControlStatus: public wb_differential_robot {
		public:
			DifferentialRobotControlStatus(): wb_differential_robot() {}
			
#ifdef WHITEBOARD_POSTER_STRING_CONVERSION
			DifferentialRobotControlStatus(const std::string &name) { 
			    from_string(name);
            }
			
			std::string description() {
                using namespace std;
                ostringstream ss;
                const wb_motor &l = left_motor();
                const wb_motor &r = right_motor();
                ss << static_cast<int>(l.speed()) << "," << static_cast<int>(r.speed()) \
                << ", " << l.dist() << "," << r.dist() << ", " << static_cast<unsigned>(l.accel()) \
                << "," << static_cast<unsigned>(r.accel());
                return ss.str();
			}

			void from_string (std::string str) {
                using namespace std;
                vector<string> elements = components_of_string_separated(str, ',', true);
                wb_motor &l = left_motor();
                wb_motor &r = right_motor();
                if (elements.size() == 0) return;
                l.set_speed(static_cast<int8_t>(atoi(elements[0].c_str())));
                if (elements.size() < 2) return;
                r.set_speed(static_cast<int8_t>(atoi(elements[1].c_str())));
                if (elements.size() < 3) return;
                l.set_dist(static_cast<uint16_t>(atoi(elements[2].c_str())));
                if (elements.size() < 4) return;
                r.set_dist(static_cast<uint16_t>(atoi(elements[3].c_str())));
                if (elements.size() < 5) return;
                l.set_accel(static_cast<uint8_t>(atoi(elements[4].c_str())));
                if (elements.size() < 6) return;
                r.set_accel(static_cast<uint8_t>(atoi(elements[5].c_str())));
			}
#endif
            void move_forward (int8_t speed) {
                wb_motor &l = left_motor();
                wb_motor &r = right_motor();
                
                if (speed > 100) speed = 100;
                if (speed < 0) speed = 0;

                int a = (speed * 127) / 100;
                
                l.set_speed (static_cast<int8_t> (a));
                r.set_speed (static_cast<int8_t> (a));
                l.set_accel (static_cast<uint8_t> (a));
                r.set_accel (static_cast<uint8_t> (a));
                l.set_dist (static_cast<uint16_t> (10000));
                r.set_dist (static_cast<uint16_t> (10000));
            }

            void move_backward (int8_t speed) {
                wb_motor &l = left_motor();
                wb_motor &r = right_motor();

                if (speed > 100) speed = 100;
                if (speed < 0) speed = 0;

                int a = (speed * 127) / 100;
                
                l.set_speed (static_cast<int8_t> (-a));
                r.set_speed (static_cast<int8_t> (-a));
                l.set_accel (static_cast<uint8_t> (a));
                r.set_accel (static_cast<uint8_t> (a));
                l.set_dist (static_cast<uint16_t> (10000));
                r.set_dist (static_cast<uint16_t> (10000));
            }           
            
            void turn_left (int8_t speed) {
                wb_motor &l = left_motor();
                wb_motor &r = right_motor();

                if (speed > 100) speed = 100;
                if (speed < 0) speed = 0;

                int a = (speed * 127) / 100;
                
                l.set_speed (static_cast<int8_t> (-a));
                r.set_speed (static_cast<int8_t> (a));
                l.set_accel (static_cast<uint8_t> (a));
                r.set_accel (static_cast<uint8_t> (a));
                l.set_dist (static_cast<uint16_t> (1000000));
                r.set_dist (static_cast<uint16_t> (1000000));
            }           
            
            void turn_right (int8_t speed) {
                wb_motor &l = left_motor();
                wb_motor &r = right_motor();

                if (speed > 100) speed = 100;
                if (speed < 0) speed = 0;

                int a = (speed * 127) / 100;
                
                l.set_speed (static_cast<int8_t> (a));
                r.set_speed (static_cast<int8_t> (-a));
                l.set_accel (static_cast<uint8_t> (a));
                r.set_accel (static_cast<uint8_t> (a));
                l.set_dist (static_cast<uint16_t> (1000000));
                r.set_dist (static_cast<uint16_t> (1000000));
            }           
    
            void stop () {
                wb_motor &l = left_motor();
                wb_motor &r = right_motor();

                l.set_speed (static_cast<int8_t> (0));
                r.set_speed (static_cast<int8_t> (0));
                l.set_accel (static_cast<uint8_t> (0));
                r.set_accel (static_cast<uint8_t> (0));
                l.set_dist (static_cast<uint16_t> (0));
                r.set_dist (static_cast<uint16_t> (0));
            }           
	};
}
#endif //DifferentialRobotControlStatus_DEFINED

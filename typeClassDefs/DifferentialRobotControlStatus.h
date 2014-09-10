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
			DifferentialRobotControl(const std::string &name) { 
			    from_string(name);
            }
			
			std::string description() {
                using namespace std;
                ostringstream ss;
                const wb_motor &l = left_motor();
                const wb_motor &r = right_motor();
                ss << l.speed() << "," << r.speed() << ", " << l.odo() << "," << r.odo() << ", " << l.accel() << "," << r.accel();
                return ss.str();
			}

			void from_string (std::string str) {
                using namespace std;
                vector<string> elements = components_of_string_separated(str, ',', true);
                wb_motor &l = left_motor();
                wb_motor &r = right_motor();
                if (elements.size() == 0) return;
                l.set_speed(atoi(elements[0].c_str()));
                if (elements.size() < 2) return;
                r.set_speed(atoi(elements[1].c_str()));
                if (elements.size() < 3) return;
                l.set_odo(atoi(elements[2].c_str()));
                if (elements.size() < 4) return;
                r.set_odo(atoi(elements[3].c_str()));
                if (elements.size() < 5) return;
                l.set_accel(atoi(elements[4].c_str()));
                if (elements.size() < 6) return;
                r.set_accel(atoi(elements[5].c_str()));
			}
#endif            
	};
}

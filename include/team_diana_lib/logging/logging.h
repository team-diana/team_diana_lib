#ifndef TEAM_DIANA_LIB_LOGGING_LOGGING
#define TEAM_DIANA_LIB_LOGGING_LOGGING

#include <string>

namespace Td
{

using namespace std;

// Log function instead of ROS macros
void ros_info(const string& msg);
void ros_warn(const string& msg);
void ros_error(const string& msg);
void ros_fatal(const string& msg);

}

#endif

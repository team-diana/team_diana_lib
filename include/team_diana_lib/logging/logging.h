#ifndef TEAM_DIANA_LIB_LOGGING_LOGGING
#define TEAM_DIANA_LIB_LOGGING_LOGGING

#include <string>

namespace Td
{

void ros_info(const std::string& msg);

void ros_warn(const std::string& msg);

void ros_error(const std::string& msg);

void ros_fatal(const std::string& msg);

}

#endif

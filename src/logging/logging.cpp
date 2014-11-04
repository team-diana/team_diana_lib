#include <team_diana_lib/logging/logging.h>

#include <ros/ros.h>

void Td::ros_info(const std::string& msg) {
	ROS_INFO("%s", msg.c_str());
}

void Td::ros_warn(const std::string& msg) {
  ROS_WARN("%s", msg.c_str());
}

void Td::ros_error(const std::string& msg) {
  ROS_ERROR("%s", msg.c_str());
}

void Td::ros_fatal(const std::string& msg) {
	ROS_FATAL("%s", msg.c_str());
}

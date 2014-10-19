#include <team_diana_lib/logging/logging.h>

#include <ros/ros.h>

void Td::ros_info(const std::string& msg) {
  ROS_INFO(msg.c_str());
}

void Td::ros_warn(const std::string& msg) {
  ROS_WARN(msg.c_str());
}

void Td::ros_error(const std::string& msg) {
  ROS_ERROR(msg.c_str());
}

void Td::ros_fatal(const std::string& msg) {
  ROS_FATAL(msg.c_str());
}

#include "ros/ros.h"
#include "ros_demo/demo_msg.h"
#include <iostream>
#include <sstream>


void number_callback(const ros_demo::demo_msg::ConstPtr& msg)
{
  ROS_INFO("Recieved  greeting [%s]",msg->greeting.c_str());
  ROS_INFO("Recieved  [%d]",msg->number);
}

int main(int argc, char **argv)

{
  ros::init(argc, argv,"demo_msg_subscriber");
  //Created a nodehandle object
  ros::NodeHandle node_obj;
  //Create a publisher object
  ros::Subscriber number_subscriber = node_obj.subscribe("/demo_msg_topic",10,number_callback);
  ros::spin();
  return 0;
}


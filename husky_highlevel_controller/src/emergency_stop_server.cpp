#include <ros/ros.h>
#include "husky_highlevel_controller/HuskyHighlevelController.hpp"
#include <std_srvs/SetBool.h>

ros::Publisher start_stop_publ; 

bool stop_(std_srvs::SetBool::Request &request, std_srvs::SetBool::Response &response){
	if(request.data == false){
		std_msgs::Bool data;
		data.data = false;		
		start_stop_publ.publish(data);
		response.success = false; 	
		response.message = "False";
		// ROS_DEBUG_STREAM("SokaSoka");	
	}
	if(request.data == true){
		std_msgs::Bool data;
		data.data = true;
		start_stop_publ.publish(data);
		response.success = true; 	
		response.message = "True"; 
		// ROS_DEBUG_STREAM("NaniNani");	
	}
	return true; 
}

int main(int argc, char **argv){
	ros::init(argc, argv, "emergency_stop_server");
	ros::NodeHandle nh;
	start_stop_publ = nh.advertise<std_msgs::Bool>("/start_stop", 1);
	ros::ServiceServer service = nh.advertiseService("emergency_stop", stop_);
	ros::spin();
	return 0;
}



#include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.026607, 0.005);
void chatterCallback8(const std_msgs::String::ConstPtr& msg){
  	usleep(d(gen)*1000000);
  	ROS_INFO("I'm node14 and heard from node8: [%s]", msg->data.c_str());
  }
void chatterCallback11(const std_msgs::String::ConstPtr& msg){
  	usleep(d(gen)*1000000);
  	ROS_INFO("I'm node14 and heard from node11: [%s]", msg->data.c_str());
  }
void chatterCallback13(const std_msgs::String::ConstPtr& msg){
  	usleep(d(gen)*1000000);
  	ROS_INFO("I'm node14 and heard from node13: [%s]", msg->data.c_str());
  }
int main(int argc, char **argv){
  	ros::init(argc, argv, "node14");
  	ros::NodeHandle n;
	ros::Subscriber sub_8_14 = n.subscribe("topic_8_14", 1, chatterCallback8);
	ros::Subscriber sub_11_14 = n.subscribe("topic_11_14", 1, chatterCallback11);
	ros::Subscriber sub_13_14 = n.subscribe("topic_13_14", 1, chatterCallback13);

  	ros::spin();
  	return 0;
  }

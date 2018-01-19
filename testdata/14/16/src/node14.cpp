#include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.020687, 0.005);
void chatterCallback1(const std_msgs::String::ConstPtr& msg){
  	usleep(d(gen)*1000000);
  	ROS_INFO("I'm node14 and heard from node1: [%s]", msg->data.c_str());
  }
void chatterCallback10(const std_msgs::String::ConstPtr& msg){
  	usleep(d(gen)*1000000);
  	ROS_INFO("I'm node14 and heard from node10: [%s]", msg->data.c_str());
  }
void chatterCallback13(const std_msgs::String::ConstPtr& msg){
  	usleep(d(gen)*1000000);
  	ROS_INFO("I'm node14 and heard from node13: [%s]", msg->data.c_str());
  }
int main(int argc, char **argv){
  	ros::init(argc, argv, "node14");
  	ros::NodeHandle n;
	ros::Subscriber sub_1_14 = n.subscribe("topic_1_14", 1, chatterCallback1);
	ros::Subscriber sub_10_14 = n.subscribe("topic_10_14", 1, chatterCallback10);
	ros::Subscriber sub_13_14 = n.subscribe("topic_13_14", 1, chatterCallback13);

  	ros::spin();
  	return 0;
  }

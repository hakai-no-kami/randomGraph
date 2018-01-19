#include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.027556, 0.005);
void chatterCallback13(const std_msgs::String::ConstPtr& msg){
  	usleep(d(gen)*1000000);
  	ROS_INFO("I'm node16 and heard from node13: [%s]", msg->data.c_str());
  }
void chatterCallback15(const std_msgs::String::ConstPtr& msg){
  	usleep(d(gen)*1000000);
  	ROS_INFO("I'm node16 and heard from node15: [%s]", msg->data.c_str());
  }
int main(int argc, char **argv){
  	ros::init(argc, argv, "node16");
  	ros::NodeHandle n;
	ros::Subscriber sub_13_16 = n.subscribe("topic_13_16", 1, chatterCallback13);
	ros::Subscriber sub_15_16 = n.subscribe("topic_15_16", 1, chatterCallback15);

  	ros::spin();
  	return 0;
  }

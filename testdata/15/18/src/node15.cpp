#include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.028360, 0.005);
void chatterCallback11(const std_msgs::String::ConstPtr& msg){
  	usleep(d(gen)*1000000);
  	ROS_INFO("I'm node15 and heard from node11: [%s]", msg->data.c_str());
  }
void chatterCallback14(const std_msgs::String::ConstPtr& msg){
  	usleep(d(gen)*1000000);
  	ROS_INFO("I'm node15 and heard from node14: [%s]", msg->data.c_str());
  }
int main(int argc, char **argv){
  	ros::init(argc, argv, "node15");
  	ros::NodeHandle n;
	ros::Subscriber sub_11_15 = n.subscribe("topic_11_15", 1, chatterCallback11);
	ros::Subscriber sub_14_15 = n.subscribe("topic_14_15", 1, chatterCallback14);

  	ros::spin();
  	return 0;
  }

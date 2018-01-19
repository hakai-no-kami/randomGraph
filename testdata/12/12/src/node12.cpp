#include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.020747, 0.005);
void chatterCallback8(const std_msgs::String::ConstPtr& msg){
  	usleep(d(gen)*1000000);
  	ROS_INFO("I'm node12 and heard from node8: [%s]", msg->data.c_str());
  }
void chatterCallback10(const std_msgs::String::ConstPtr& msg){
  	usleep(d(gen)*1000000);
  	ROS_INFO("I'm node12 and heard from node10: [%s]", msg->data.c_str());
  }
void chatterCallback11(const std_msgs::String::ConstPtr& msg){
  	usleep(d(gen)*1000000);
  	ROS_INFO("I'm node12 and heard from node11: [%s]", msg->data.c_str());
  }
int main(int argc, char **argv){
  	ros::init(argc, argv, "node12");
  	ros::NodeHandle n;
	ros::Subscriber sub_8_12 = n.subscribe("topic_8_12", 1, chatterCallback8);
	ros::Subscriber sub_10_12 = n.subscribe("topic_10_12", 1, chatterCallback10);
	ros::Subscriber sub_11_12 = n.subscribe("topic_11_12", 1, chatterCallback11);

  	ros::spin();
  	return 0;
  }

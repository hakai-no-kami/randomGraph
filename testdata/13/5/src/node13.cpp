#include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.011585, 0.005);
void chatterCallback12(const std_msgs::String::ConstPtr& msg){
  	usleep(d(gen)*1000000);
  	ROS_INFO("I'm node13 and heard from node12: [%s]", msg->data.c_str());
  }
int main(int argc, char **argv){
  	ros::init(argc, argv, "node13");
  	ros::NodeHandle n;
	ros::Subscriber sub_12_13 = n.subscribe("topic_12_13", 1, chatterCallback12);

  	ros::spin();
  	return 0;
  }

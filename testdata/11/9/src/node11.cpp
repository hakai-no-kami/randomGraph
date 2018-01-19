#include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.021730, 0.005);
void chatterCallback10(const std_msgs::String::ConstPtr& msg){
  	usleep(d(gen)*1000000);
  	ROS_INFO("I'm node11 and heard from node10: [%s]", msg->data.c_str());
  }
int main(int argc, char **argv){
  	ros::init(argc, argv, "node11");
  	ros::NodeHandle n;
	ros::Subscriber sub_10_11 = n.subscribe("topic_10_11", 1, chatterCallback10);

  	ros::spin();
  	return 0;
  }

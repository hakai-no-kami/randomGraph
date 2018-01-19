#include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.022396, 0.005);
void chatterCallback14(const std_msgs::String::ConstPtr& msg){
  	usleep(d(gen)*1000000);
  	ROS_INFO("I'm node18 and heard from node14: [%s]", msg->data.c_str());
  }
void chatterCallback17(const std_msgs::String::ConstPtr& msg){
  	usleep(d(gen)*1000000);
  	ROS_INFO("I'm node18 and heard from node17: [%s]", msg->data.c_str());
  }
int main(int argc, char **argv){
  	ros::init(argc, argv, "node18");
  	ros::NodeHandle n;
	ros::Subscriber sub_14_18 = n.subscribe("topic_14_18", 1, chatterCallback14);
	ros::Subscriber sub_17_18 = n.subscribe("topic_17_18", 1, chatterCallback17);

  	ros::spin();
  	return 0;
  }

#include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.024011, 0.005);
void chatterCallback12(const std_msgs::String::ConstPtr& msg){
  	usleep(d(gen)*1000000);
  	ROS_INFO("I'm node20 and heard from node12: [%s]", msg->data.c_str());
  }
void chatterCallback18(const std_msgs::String::ConstPtr& msg){
  	usleep(d(gen)*1000000);
  	ROS_INFO("I'm node20 and heard from node18: [%s]", msg->data.c_str());
  }
void chatterCallback19(const std_msgs::String::ConstPtr& msg){
  	usleep(d(gen)*1000000);
  	ROS_INFO("I'm node20 and heard from node19: [%s]", msg->data.c_str());
  }
int main(int argc, char **argv){
  	ros::init(argc, argv, "node20");
  	ros::NodeHandle n;
	ros::Subscriber sub_12_20 = n.subscribe("topic_12_20", 1, chatterCallback12);
	ros::Subscriber sub_18_20 = n.subscribe("topic_18_20", 1, chatterCallback18);
	ros::Subscriber sub_19_20 = n.subscribe("topic_19_20", 1, chatterCallback19);

  	ros::spin();
  	return 0;
  }

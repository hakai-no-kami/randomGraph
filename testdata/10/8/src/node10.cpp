#include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.025092, 0.005);
void chatterCallback7(const std_msgs::String::ConstPtr& msg){
  	usleep(d(gen)*1000000);
  	ROS_INFO("I'm node10 and heard from node7: [%s]", msg->data.c_str());
  }
void chatterCallback9(const std_msgs::String::ConstPtr& msg){
  	usleep(d(gen)*1000000);
  	ROS_INFO("I'm node10 and heard from node9: [%s]", msg->data.c_str());
  }
int main(int argc, char **argv){
  	ros::init(argc, argv, "node10");
  	ros::NodeHandle n;
	ros::Subscriber sub_7_10 = n.subscribe("topic_7_10", 1, chatterCallback7);
	ros::Subscriber sub_9_10 = n.subscribe("topic_9_10", 1, chatterCallback9);

  	ros::spin();
  	return 0;
  }

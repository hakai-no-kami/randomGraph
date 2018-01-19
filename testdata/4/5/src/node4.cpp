#include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.012167, 0.005);
void chatterCallback2(const std_msgs::String::ConstPtr& msg){
  	usleep(d(gen)*1000000);
  	ROS_INFO("I'm node4 and heard from node2: [%s]", msg->data.c_str());
  }
void chatterCallback3(const std_msgs::String::ConstPtr& msg){
  	usleep(d(gen)*1000000);
  	ROS_INFO("I'm node4 and heard from node3: [%s]", msg->data.c_str());
  }
int main(int argc, char **argv){
  	ros::init(argc, argv, "node4");
  	ros::NodeHandle n;
	ros::Subscriber sub_2_4 = n.subscribe("topic_2_4", 1, chatterCallback2);
	ros::Subscriber sub_3_4 = n.subscribe("topic_3_4", 1, chatterCallback3);

  	ros::spin();
  	return 0;
  }

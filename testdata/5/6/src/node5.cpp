#include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.015142, 0.005);
void chatterCallback3(const std_msgs::String::ConstPtr& msg){
  	usleep(d(gen)*1000000);
  	ROS_INFO("I'm node5 and heard from node3: [%s]", msg->data.c_str());
  }
void chatterCallback4(const std_msgs::String::ConstPtr& msg){
  	usleep(d(gen)*1000000);
  	ROS_INFO("I'm node5 and heard from node4: [%s]", msg->data.c_str());
  }
int main(int argc, char **argv){
  	ros::init(argc, argv, "node5");
  	ros::NodeHandle n;
	ros::Subscriber sub_3_5 = n.subscribe("topic_3_5", 1, chatterCallback3);
	ros::Subscriber sub_4_5 = n.subscribe("topic_4_5", 1, chatterCallback4);

  	ros::spin();
  	return 0;
  }

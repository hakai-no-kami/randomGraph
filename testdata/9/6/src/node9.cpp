#include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.021087, 0.005);
void chatterCallback4(const std_msgs::String::ConstPtr& msg){
  	usleep(d(gen)*1000000);
  	ROS_INFO("I'm node9 and heard from node4: [%s]", msg->data.c_str());
  }
void chatterCallback8(const std_msgs::String::ConstPtr& msg){
  	usleep(d(gen)*1000000);
  	ROS_INFO("I'm node9 and heard from node8: [%s]", msg->data.c_str());
  }
int main(int argc, char **argv){
  	ros::init(argc, argv, "node9");
  	ros::NodeHandle n;
	ros::Subscriber sub_4_9 = n.subscribe("topic_4_9", 1, chatterCallback4);
	ros::Subscriber sub_8_9 = n.subscribe("topic_8_9", 1, chatterCallback8);

  	ros::spin();
  	return 0;
  }

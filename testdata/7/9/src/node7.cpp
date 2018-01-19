#include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.019256, 0.005);
void chatterCallback6(const std_msgs::String::ConstPtr& msg){
  	usleep(d(gen)*1000000);
  	ROS_INFO("I'm node7 and heard from node6: [%s]", msg->data.c_str());
  }
int main(int argc, char **argv){
  	ros::init(argc, argv, "node7");
  	ros::NodeHandle n;
	ros::Subscriber sub_6_7 = n.subscribe("topic_6_7", 1, chatterCallback6);

  	ros::spin();
  	return 0;
  }

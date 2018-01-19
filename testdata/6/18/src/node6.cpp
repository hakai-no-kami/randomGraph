#include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.014139, 0.005);
void chatterCallback5(const std_msgs::String::ConstPtr& msg){
  	usleep(d(gen)*1000000);
  	ROS_INFO("I'm node6 and heard from node5: [%s]", msg->data.c_str());
  }
int main(int argc, char **argv){
  	ros::init(argc, argv, "node6");
  	ros::NodeHandle n;
	ros::Subscriber sub_5_6 = n.subscribe("topic_5_6", 1, chatterCallback5);

  	ros::spin();
  	return 0;
  }

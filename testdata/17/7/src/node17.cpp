#include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.018042, 0.005);
void chatterCallback16(const std_msgs::String::ConstPtr& msg){
  	usleep(d(gen)*1000000);
  	ROS_INFO("I'm node17 and heard from node16: [%s]", msg->data.c_str());
  }
int main(int argc, char **argv){
  	ros::init(argc, argv, "node17");
  	ros::NodeHandle n;
	ros::Subscriber sub_16_17 = n.subscribe("topic_16_17", 1, chatterCallback16);

  	ros::spin();
  	return 0;
  }

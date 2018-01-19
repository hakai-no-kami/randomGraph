#include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.018469, 0.005);
void chatterCallback18(const std_msgs::String::ConstPtr& msg){
  	usleep(d(gen)*1000000);
  	ROS_INFO("I'm node19 and heard from node18: [%s]", msg->data.c_str());
  }
int main(int argc, char **argv){
  	ros::init(argc, argv, "node19");
  	ros::NodeHandle n;
	ros::Subscriber sub_18_19 = n.subscribe("topic_18_19", 1, chatterCallback18);

  	ros::spin();
  	return 0;
  }

#include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.025943, 0.005);
void chatterCallback5(const std_msgs::String::ConstPtr& msg){
  	usleep(d(gen)*1000000);
  	ROS_INFO("I'm node8 and heard from node5: [%s]", msg->data.c_str());
  }
void chatterCallback7(const std_msgs::String::ConstPtr& msg){
  	usleep(d(gen)*1000000);
  	ROS_INFO("I'm node8 and heard from node7: [%s]", msg->data.c_str());
  }
int main(int argc, char **argv){
  	ros::init(argc, argv, "node8");
  	ros::NodeHandle n;
	ros::Subscriber sub_5_8 = n.subscribe("topic_5_8", 1, chatterCallback5);
	ros::Subscriber sub_7_8 = n.subscribe("topic_7_8", 1, chatterCallback7);

  	ros::spin();
  	return 0;
  }

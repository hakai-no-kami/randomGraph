
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.010779, 0.005);
  class Node15{
  	public:
  		Node15(){
			sub_0_15_flag = 0;
  			sub_0_15 = n.subscribe("topic_0_15", 1, &Node15::middlemanCallback0,this);
			pub_15_17 = n.advertise<std_msgs::String>("topic_15_17", 1);
			pub_15_16 = n.advertise<std_msgs::String>("topic_15_16", 1);
		}
		void middlemanCallback0(const std_msgs::String::ConstPtr& msg){
  			if( true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node15 last from node0, intercepted: [%s]", msg->data.c_str());
				pub_15_17.publish(msg);
				pub_15_16.publish(msg);
			}
  			else{
  				ROS_INFO("I'm node15, from node0 intercepted: [%s]", msg->data.c_str());
  				sub_0_15_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_15_17;
		ros::Publisher pub_15_16;
		int sub_0_15_flag;
  		ros::Subscriber sub_0_15;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node15");
  	Node15 node15;
  	ros::spin();
  	return 0;
  }

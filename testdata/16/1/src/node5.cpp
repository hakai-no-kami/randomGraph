
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.028830, 0.005);
  class Node5{
  	public:
  		Node5(){
			sub_0_5_flag = 0;
  			sub_0_5 = n.subscribe("topic_0_5", 1, &Node5::middlemanCallback0,this);
			pub_5_7 = n.advertise<std_msgs::String>("topic_5_7", 1);
			pub_5_6 = n.advertise<std_msgs::String>("topic_5_6", 1);
		}
		void middlemanCallback0(const std_msgs::String::ConstPtr& msg){
  			if( true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node5 last from node0, intercepted: [%s]", msg->data.c_str());
				pub_5_7.publish(msg);
				pub_5_6.publish(msg);
			}
  			else{
  				ROS_INFO("I'm node5, from node0 intercepted: [%s]", msg->data.c_str());
  				sub_0_5_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_5_7;
		ros::Publisher pub_5_6;
		int sub_0_5_flag;
  		ros::Subscriber sub_0_5;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node5");
  	Node5 node5;
  	ros::spin();
  	return 0;
  }

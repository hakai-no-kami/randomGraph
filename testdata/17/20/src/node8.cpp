
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.020015, 0.005);
  class Node8{
  	public:
  		Node8(){
			sub_0_8_flag = 0;
  			sub_0_8 = n.subscribe("topic_0_8", 1, &Node8::middlemanCallback0,this);
			pub_8_13 = n.advertise<std_msgs::String>("topic_8_13", 1);
			pub_8_11 = n.advertise<std_msgs::String>("topic_8_11", 1);
			pub_8_10 = n.advertise<std_msgs::String>("topic_8_10", 1);
		}
		void middlemanCallback0(const std_msgs::String::ConstPtr& msg){
  			if( true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node8 last from node0, intercepted: [%s]", msg->data.c_str());
				pub_8_13.publish(msg);
				pub_8_11.publish(msg);
				pub_8_10.publish(msg);
			}
  			else{
  				ROS_INFO("I'm node8, from node0 intercepted: [%s]", msg->data.c_str());
  				sub_0_8_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_8_13;
		ros::Publisher pub_8_11;
		ros::Publisher pub_8_10;
		int sub_0_8_flag;
  		ros::Subscriber sub_0_8;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node8");
  	Node8 node8;
  	ros::spin();
  	return 0;
  }

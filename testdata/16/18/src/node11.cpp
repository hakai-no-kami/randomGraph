
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.012825, 0.005);
  class Node11{
  	public:
  		Node11(){
			sub_0_11_flag = 0;
  			sub_0_11 = n.subscribe("topic_0_11", 1, &Node11::middlemanCallback0,this);
			pub_11_14 = n.advertise<std_msgs::String>("topic_11_14", 1);
			pub_11_13 = n.advertise<std_msgs::String>("topic_11_13", 1);
			pub_11_12 = n.advertise<std_msgs::String>("topic_11_12", 1);
		}
		void middlemanCallback0(const std_msgs::String::ConstPtr& msg){
  			if( true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node11 last from node0, intercepted: [%s]", msg->data.c_str());
				pub_11_14.publish(msg);
				pub_11_13.publish(msg);
				pub_11_12.publish(msg);
			}
  			else{
  				ROS_INFO("I'm node11, from node0 intercepted: [%s]", msg->data.c_str());
  				sub_0_11_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_11_14;
		ros::Publisher pub_11_13;
		ros::Publisher pub_11_12;
		int sub_0_11_flag;
  		ros::Subscriber sub_0_11;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node11");
  	Node11 node11;
  	ros::spin();
  	return 0;
  }

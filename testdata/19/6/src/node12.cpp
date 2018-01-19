
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.025036, 0.005);
  class Node12{
  	public:
  		Node12(){
			sub_0_12_flag = 0;
  			sub_0_12 = n.subscribe("topic_0_12", 1, &Node12::middlemanCallback0,this);
			pub_12_16 = n.advertise<std_msgs::String>("topic_12_16", 1);
			pub_12_13 = n.advertise<std_msgs::String>("topic_12_13", 1);
		}
		void middlemanCallback0(const std_msgs::String::ConstPtr& msg){
  			if( true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node12 last from node0, intercepted: [%s]", msg->data.c_str());
				pub_12_16.publish(msg);
				pub_12_13.publish(msg);
			}
  			else{
  				ROS_INFO("I'm node12, from node0 intercepted: [%s]", msg->data.c_str());
  				sub_0_12_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_12_16;
		ros::Publisher pub_12_13;
		int sub_0_12_flag;
  		ros::Subscriber sub_0_12;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node12");
  	Node12 node12;
  	ros::spin();
  	return 0;
  }

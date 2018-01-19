
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.020598, 0.005);
  class Node14{
  	public:
  		Node14(){
			sub_0_14_flag = 0;
  			sub_0_14 = n.subscribe("topic_0_14", 1, &Node14::middlemanCallback0,this);
			pub_14_16 = n.advertise<std_msgs::String>("topic_14_16", 1);
			pub_14_15 = n.advertise<std_msgs::String>("topic_14_15", 1);
		}
		void middlemanCallback0(const std_msgs::String::ConstPtr& msg){
  			if( true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node14 last from node0, intercepted: [%s]", msg->data.c_str());
				pub_14_16.publish(msg);
				pub_14_15.publish(msg);
			}
  			else{
  				ROS_INFO("I'm node14, from node0 intercepted: [%s]", msg->data.c_str());
  				sub_0_14_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_14_16;
		ros::Publisher pub_14_15;
		int sub_0_14_flag;
  		ros::Subscriber sub_0_14;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node14");
  	Node14 node14;
  	ros::spin();
  	return 0;
  }

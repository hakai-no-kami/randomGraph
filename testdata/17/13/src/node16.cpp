
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.015630, 0.005);
  class Node16{
  	public:
  		Node16(){
			sub_12_16_flag = 0;
  			sub_12_16 = n.subscribe("topic_12_16", 1, &Node16::middlemanCallback12,this);
			pub_16_17 = n.advertise<std_msgs::String>("topic_16_17", 1);
		}
		void middlemanCallback12(const std_msgs::String::ConstPtr& msg){
  			if( true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node16 last from node12, intercepted: [%s]", msg->data.c_str());
				pub_16_17.publish(msg);
			}
  			else{
  				ROS_INFO("I'm node16, from node12 intercepted: [%s]", msg->data.c_str());
  				sub_12_16_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_16_17;
		int sub_12_16_flag;
  		ros::Subscriber sub_12_16;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node16");
  	Node16 node16;
  	ros::spin();
  	return 0;
  }

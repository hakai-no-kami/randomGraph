
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.010590, 0.005);
  class Node14{
  	public:
  		Node14(){
			sub_8_14_flag = 0;
  			sub_8_14 = n.subscribe("topic_8_14", 1, &Node14::middlemanCallback8,this);
			pub_14_16 = n.advertise<std_msgs::String>("topic_14_16", 1);
		}
		void middlemanCallback8(const std_msgs::String::ConstPtr& msg){
  			if( true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node14 last from node8, intercepted: [%s]", msg->data.c_str());
				pub_14_16.publish(msg);
			}
  			else{
  				ROS_INFO("I'm node14, from node8 intercepted: [%s]", msg->data.c_str());
  				sub_8_14_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_14_16;
		int sub_8_14_flag;
  		ros::Subscriber sub_8_14;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node14");
  	Node14 node14;
  	ros::spin();
  	return 0;
  }

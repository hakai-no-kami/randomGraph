
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.012878, 0.005);
  class Node16{
  	public:
  		Node16(){
			sub_6_16_flag = 0;
  			sub_6_16 = n.subscribe("topic_6_16", 1, &Node16::middlemanCallback6,this);
			pub_16_18 = n.advertise<std_msgs::String>("topic_16_18", 1);
		}
		void middlemanCallback6(const std_msgs::String::ConstPtr& msg){
  			if( true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node16 last from node6, intercepted: [%s]", msg->data.c_str());
				pub_16_18.publish(msg);
			}
  			else{
  				ROS_INFO("I'm node16, from node6 intercepted: [%s]", msg->data.c_str());
  				sub_6_16_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_16_18;
		int sub_6_16_flag;
  		ros::Subscriber sub_6_16;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node16");
  	Node16 node16;
  	ros::spin();
  	return 0;
  }

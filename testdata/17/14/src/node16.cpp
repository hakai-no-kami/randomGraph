
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.021393, 0.005);
  class Node16{
  	public:
  		Node16(){
			sub_4_16_flag = 0;
  			sub_4_16 = n.subscribe("topic_4_16", 1, &Node16::middlemanCallback4,this);
			pub_16_17 = n.advertise<std_msgs::String>("topic_16_17", 1);
		}
		void middlemanCallback4(const std_msgs::String::ConstPtr& msg){
  			if( true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node16 last from node4, intercepted: [%s]", msg->data.c_str());
				pub_16_17.publish(msg);
			}
  			else{
  				ROS_INFO("I'm node16, from node4 intercepted: [%s]", msg->data.c_str());
  				sub_4_16_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_16_17;
		int sub_4_16_flag;
  		ros::Subscriber sub_4_16;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node16");
  	Node16 node16;
  	ros::spin();
  	return 0;
  }

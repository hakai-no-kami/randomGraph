
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.027197, 0.005);
  class Node10{
  	public:
  		Node10(){
			sub_2_10_flag = 0;
  			sub_2_10 = n.subscribe("topic_2_10", 1, &Node10::middlemanCallback2,this);
			pub_10_15 = n.advertise<std_msgs::String>("topic_10_15", 1);
			pub_10_13 = n.advertise<std_msgs::String>("topic_10_13", 1);
			pub_10_12 = n.advertise<std_msgs::String>("topic_10_12", 1);
		}
		void middlemanCallback2(const std_msgs::String::ConstPtr& msg){
  			if( true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node10 last from node2, intercepted: [%s]", msg->data.c_str());
				pub_10_15.publish(msg);
				pub_10_13.publish(msg);
				pub_10_12.publish(msg);
			}
  			else{
  				ROS_INFO("I'm node10, from node2 intercepted: [%s]", msg->data.c_str());
  				sub_2_10_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_10_15;
		ros::Publisher pub_10_13;
		ros::Publisher pub_10_12;
		int sub_2_10_flag;
  		ros::Subscriber sub_2_10;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node10");
  	Node10 node10;
  	ros::spin();
  	return 0;
  }

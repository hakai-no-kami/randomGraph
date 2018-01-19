
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.025058, 0.005);
  class Node11{
  	public:
  		Node11(){
			sub_9_11_flag = 0;
  			sub_9_11 = n.subscribe("topic_9_11", 1, &Node11::middlemanCallback9,this);
			pub_11_15 = n.advertise<std_msgs::String>("topic_11_15", 1);
			pub_11_14 = n.advertise<std_msgs::String>("topic_11_14", 1);
			pub_11_13 = n.advertise<std_msgs::String>("topic_11_13", 1);
		}
		void middlemanCallback9(const std_msgs::String::ConstPtr& msg){
  			if( true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node11 last from node9, intercepted: [%s]", msg->data.c_str());
				pub_11_15.publish(msg);
				pub_11_14.publish(msg);
				pub_11_13.publish(msg);
			}
  			else{
  				ROS_INFO("I'm node11, from node9 intercepted: [%s]", msg->data.c_str());
  				sub_9_11_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_11_15;
		ros::Publisher pub_11_14;
		ros::Publisher pub_11_13;
		int sub_9_11_flag;
  		ros::Subscriber sub_9_11;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node11");
  	Node11 node11;
  	ros::spin();
  	return 0;
  }

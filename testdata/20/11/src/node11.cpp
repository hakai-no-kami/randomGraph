
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.024090, 0.005);
  class Node11{
  	public:
  		Node11(){
			sub_6_11_flag = 0;
  			sub_6_11 = n.subscribe("topic_6_11", 1, &Node11::middlemanCallback6,this);
			sub_10_11_flag = 0;
  			sub_10_11 = n.subscribe("topic_10_11", 1, &Node11::middlemanCallback10,this);
			pub_11_16 = n.advertise<std_msgs::String>("topic_11_16", 1);
			pub_11_15 = n.advertise<std_msgs::String>("topic_11_15", 1);
		}
		void middlemanCallback6(const std_msgs::String::ConstPtr& msg){
  			if(sub_10_11_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node11 last from node6, intercepted: [%s]", msg->data.c_str());
				pub_11_16.publish(msg);
				pub_11_15.publish(msg);
				sub_10_11_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node11, from node6 intercepted: [%s]", msg->data.c_str());
  				sub_6_11_flag = 1;
  			}
  		}
		void middlemanCallback10(const std_msgs::String::ConstPtr& msg){
  			if(sub_6_11_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node11 last from node10, intercepted: [%s]", msg->data.c_str());
				pub_11_16.publish(msg);
				pub_11_15.publish(msg);
				sub_6_11_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node11, from node10 intercepted: [%s]", msg->data.c_str());
  				sub_10_11_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_11_16;
		ros::Publisher pub_11_15;
		int sub_6_11_flag;
  		ros::Subscriber sub_6_11;
		int sub_10_11_flag;
  		ros::Subscriber sub_10_11;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node11");
  	Node11 node11;
  	ros::spin();
  	return 0;
  }

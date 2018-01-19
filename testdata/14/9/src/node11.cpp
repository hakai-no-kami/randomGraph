
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.011809, 0.005);
  class Node11{
  	public:
  		Node11(){
			sub_8_11_flag = 0;
  			sub_8_11 = n.subscribe("topic_8_11", 1, &Node11::middlemanCallback8,this);
			sub_9_11_flag = 0;
  			sub_9_11 = n.subscribe("topic_9_11", 1, &Node11::middlemanCallback9,this);
			sub_10_11_flag = 0;
  			sub_10_11 = n.subscribe("topic_10_11", 1, &Node11::middlemanCallback10,this);
			pub_11_13 = n.advertise<std_msgs::String>("topic_11_13", 1);
		}
		void middlemanCallback8(const std_msgs::String::ConstPtr& msg){
  			if(sub_9_11_flag == 1 && sub_10_11_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node11 last from node8, intercepted: [%s]", msg->data.c_str());
				pub_11_13.publish(msg);
				sub_9_11_flag = 0;
				sub_10_11_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node11, from node8 intercepted: [%s]", msg->data.c_str());
  				sub_8_11_flag = 1;
  			}
  		}
		void middlemanCallback9(const std_msgs::String::ConstPtr& msg){
  			if(sub_8_11_flag == 1 && sub_10_11_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node11 last from node9, intercepted: [%s]", msg->data.c_str());
				pub_11_13.publish(msg);
				sub_8_11_flag = 0;
				sub_10_11_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node11, from node9 intercepted: [%s]", msg->data.c_str());
  				sub_9_11_flag = 1;
  			}
  		}
		void middlemanCallback10(const std_msgs::String::ConstPtr& msg){
  			if(sub_8_11_flag == 1 && sub_9_11_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node11 last from node10, intercepted: [%s]", msg->data.c_str());
				pub_11_13.publish(msg);
				sub_8_11_flag = 0;
				sub_9_11_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node11, from node10 intercepted: [%s]", msg->data.c_str());
  				sub_10_11_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_11_13;
		int sub_8_11_flag;
  		ros::Subscriber sub_8_11;
		int sub_9_11_flag;
  		ros::Subscriber sub_9_11;
		int sub_10_11_flag;
  		ros::Subscriber sub_10_11;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node11");
  	Node11 node11;
  	ros::spin();
  	return 0;
  }


  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.011862, 0.005);
  class Node10{
  	public:
  		Node10(){
			sub_4_10_flag = 0;
  			sub_4_10 = n.subscribe("topic_4_10", 1, &Node10::middlemanCallback4,this);
			sub_6_10_flag = 0;
  			sub_6_10 = n.subscribe("topic_6_10", 1, &Node10::middlemanCallback6,this);
			sub_8_10_flag = 0;
  			sub_8_10 = n.subscribe("topic_8_10", 1, &Node10::middlemanCallback8,this);
			pub_10_13 = n.advertise<std_msgs::String>("topic_10_13", 1);
			pub_10_11 = n.advertise<std_msgs::String>("topic_10_11", 1);
		}
		void middlemanCallback4(const std_msgs::String::ConstPtr& msg){
  			if(sub_6_10_flag == 1 && sub_8_10_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node10 last from node4, intercepted: [%s]", msg->data.c_str());
				pub_10_13.publish(msg);
				pub_10_11.publish(msg);
				sub_6_10_flag = 0;
				sub_8_10_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node10, from node4 intercepted: [%s]", msg->data.c_str());
  				sub_4_10_flag = 1;
  			}
  		}
		void middlemanCallback6(const std_msgs::String::ConstPtr& msg){
  			if(sub_4_10_flag == 1 && sub_8_10_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node10 last from node6, intercepted: [%s]", msg->data.c_str());
				pub_10_13.publish(msg);
				pub_10_11.publish(msg);
				sub_4_10_flag = 0;
				sub_8_10_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node10, from node6 intercepted: [%s]", msg->data.c_str());
  				sub_6_10_flag = 1;
  			}
  		}
		void middlemanCallback8(const std_msgs::String::ConstPtr& msg){
  			if(sub_4_10_flag == 1 && sub_6_10_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node10 last from node8, intercepted: [%s]", msg->data.c_str());
				pub_10_13.publish(msg);
				pub_10_11.publish(msg);
				sub_4_10_flag = 0;
				sub_6_10_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node10, from node8 intercepted: [%s]", msg->data.c_str());
  				sub_8_10_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_10_13;
		ros::Publisher pub_10_11;
		int sub_4_10_flag;
  		ros::Subscriber sub_4_10;
		int sub_6_10_flag;
  		ros::Subscriber sub_6_10;
		int sub_8_10_flag;
  		ros::Subscriber sub_8_10;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node10");
  	Node10 node10;
  	ros::spin();
  	return 0;
  }


  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.015557, 0.005);
  class Node8{
  	public:
  		Node8(){
			sub_3_8_flag = 0;
  			sub_3_8 = n.subscribe("topic_3_8", 1, &Node8::middlemanCallback3,this);
			sub_5_8_flag = 0;
  			sub_5_8 = n.subscribe("topic_5_8", 1, &Node8::middlemanCallback5,this);
			pub_8_15 = n.advertise<std_msgs::String>("topic_8_15", 1);
			pub_8_10 = n.advertise<std_msgs::String>("topic_8_10", 1);
		}
		void middlemanCallback3(const std_msgs::String::ConstPtr& msg){
  			if(sub_5_8_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node8 last from node3, intercepted: [%s]", msg->data.c_str());
				pub_8_15.publish(msg);
				pub_8_10.publish(msg);
				sub_5_8_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node8, from node3 intercepted: [%s]", msg->data.c_str());
  				sub_3_8_flag = 1;
  			}
  		}
		void middlemanCallback5(const std_msgs::String::ConstPtr& msg){
  			if(sub_3_8_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node8 last from node5, intercepted: [%s]", msg->data.c_str());
				pub_8_15.publish(msg);
				pub_8_10.publish(msg);
				sub_3_8_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node8, from node5 intercepted: [%s]", msg->data.c_str());
  				sub_5_8_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_8_15;
		ros::Publisher pub_8_10;
		int sub_3_8_flag;
  		ros::Subscriber sub_3_8;
		int sub_5_8_flag;
  		ros::Subscriber sub_5_8;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node8");
  	Node8 node8;
  	ros::spin();
  	return 0;
  }

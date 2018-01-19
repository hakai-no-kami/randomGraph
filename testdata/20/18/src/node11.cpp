
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.023976, 0.005);
  class Node11{
  	public:
  		Node11(){
			sub_5_11_flag = 0;
  			sub_5_11 = n.subscribe("topic_5_11", 1, &Node11::middlemanCallback5,this);
			sub_6_11_flag = 0;
  			sub_6_11 = n.subscribe("topic_6_11", 1, &Node11::middlemanCallback6,this);
			sub_8_11_flag = 0;
  			sub_8_11 = n.subscribe("topic_8_11", 1, &Node11::middlemanCallback8,this);
			pub_11_16 = n.advertise<std_msgs::String>("topic_11_16", 1);
			pub_11_15 = n.advertise<std_msgs::String>("topic_11_15", 1);
			pub_11_12 = n.advertise<std_msgs::String>("topic_11_12", 1);
		}
		void middlemanCallback5(const std_msgs::String::ConstPtr& msg){
  			if(sub_6_11_flag == 1 && sub_8_11_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node11 last from node5, intercepted: [%s]", msg->data.c_str());
				pub_11_16.publish(msg);
				pub_11_15.publish(msg);
				pub_11_12.publish(msg);
				sub_6_11_flag = 0;
				sub_8_11_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node11, from node5 intercepted: [%s]", msg->data.c_str());
  				sub_5_11_flag = 1;
  			}
  		}
		void middlemanCallback6(const std_msgs::String::ConstPtr& msg){
  			if(sub_5_11_flag == 1 && sub_8_11_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node11 last from node6, intercepted: [%s]", msg->data.c_str());
				pub_11_16.publish(msg);
				pub_11_15.publish(msg);
				pub_11_12.publish(msg);
				sub_5_11_flag = 0;
				sub_8_11_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node11, from node6 intercepted: [%s]", msg->data.c_str());
  				sub_6_11_flag = 1;
  			}
  		}
		void middlemanCallback8(const std_msgs::String::ConstPtr& msg){
  			if(sub_5_11_flag == 1 && sub_6_11_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node11 last from node8, intercepted: [%s]", msg->data.c_str());
				pub_11_16.publish(msg);
				pub_11_15.publish(msg);
				pub_11_12.publish(msg);
				sub_5_11_flag = 0;
				sub_6_11_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node11, from node8 intercepted: [%s]", msg->data.c_str());
  				sub_8_11_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_11_16;
		ros::Publisher pub_11_15;
		ros::Publisher pub_11_12;
		int sub_5_11_flag;
  		ros::Subscriber sub_5_11;
		int sub_6_11_flag;
  		ros::Subscriber sub_6_11;
		int sub_8_11_flag;
  		ros::Subscriber sub_8_11;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node11");
  	Node11 node11;
  	ros::spin();
  	return 0;
  }

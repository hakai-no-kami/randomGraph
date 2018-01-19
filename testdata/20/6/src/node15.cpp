
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.012346, 0.005);
  class Node15{
  	public:
  		Node15(){
			sub_9_15_flag = 0;
  			sub_9_15 = n.subscribe("topic_9_15", 1, &Node15::middlemanCallback9,this);
			sub_10_15_flag = 0;
  			sub_10_15 = n.subscribe("topic_10_15", 1, &Node15::middlemanCallback10,this);
			sub_14_15_flag = 0;
  			sub_14_15 = n.subscribe("topic_14_15", 1, &Node15::middlemanCallback14,this);
			pub_15_18 = n.advertise<std_msgs::String>("topic_15_18", 1);
			pub_15_17 = n.advertise<std_msgs::String>("topic_15_17", 1);
			pub_15_16 = n.advertise<std_msgs::String>("topic_15_16", 1);
		}
		void middlemanCallback9(const std_msgs::String::ConstPtr& msg){
  			if(sub_10_15_flag == 1 && sub_14_15_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node15 last from node9, intercepted: [%s]", msg->data.c_str());
				pub_15_18.publish(msg);
				pub_15_17.publish(msg);
				pub_15_16.publish(msg);
				sub_10_15_flag = 0;
				sub_14_15_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node15, from node9 intercepted: [%s]", msg->data.c_str());
  				sub_9_15_flag = 1;
  			}
  		}
		void middlemanCallback10(const std_msgs::String::ConstPtr& msg){
  			if(sub_9_15_flag == 1 && sub_14_15_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node15 last from node10, intercepted: [%s]", msg->data.c_str());
				pub_15_18.publish(msg);
				pub_15_17.publish(msg);
				pub_15_16.publish(msg);
				sub_9_15_flag = 0;
				sub_14_15_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node15, from node10 intercepted: [%s]", msg->data.c_str());
  				sub_10_15_flag = 1;
  			}
  		}
		void middlemanCallback14(const std_msgs::String::ConstPtr& msg){
  			if(sub_9_15_flag == 1 && sub_10_15_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node15 last from node14, intercepted: [%s]", msg->data.c_str());
				pub_15_18.publish(msg);
				pub_15_17.publish(msg);
				pub_15_16.publish(msg);
				sub_9_15_flag = 0;
				sub_10_15_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node15, from node14 intercepted: [%s]", msg->data.c_str());
  				sub_14_15_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_15_18;
		ros::Publisher pub_15_17;
		ros::Publisher pub_15_16;
		int sub_9_15_flag;
  		ros::Subscriber sub_9_15;
		int sub_10_15_flag;
  		ros::Subscriber sub_10_15;
		int sub_14_15_flag;
  		ros::Subscriber sub_14_15;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node15");
  	Node15 node15;
  	ros::spin();
  	return 0;
  }

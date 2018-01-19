
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.027795, 0.005);
  class Node15{
  	public:
  		Node15(){
			sub_10_15_flag = 0;
  			sub_10_15 = n.subscribe("topic_10_15", 1, &Node15::middlemanCallback10,this);
			sub_11_15_flag = 0;
  			sub_11_15 = n.subscribe("topic_11_15", 1, &Node15::middlemanCallback11,this);
			sub_12_15_flag = 0;
  			sub_12_15 = n.subscribe("topic_12_15", 1, &Node15::middlemanCallback12,this);
			sub_13_15_flag = 0;
  			sub_13_15 = n.subscribe("topic_13_15", 1, &Node15::middlemanCallback13,this);
			pub_15_16 = n.advertise<std_msgs::String>("topic_15_16", 1);
		}
		void middlemanCallback10(const std_msgs::String::ConstPtr& msg){
  			if(sub_11_15_flag == 1 && sub_12_15_flag == 1 && sub_13_15_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node15 last from node10, intercepted: [%s]", msg->data.c_str());
				pub_15_16.publish(msg);
				sub_11_15_flag = 0;
				sub_12_15_flag = 0;
				sub_13_15_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node15, from node10 intercepted: [%s]", msg->data.c_str());
  				sub_10_15_flag = 1;
  			}
  		}
		void middlemanCallback11(const std_msgs::String::ConstPtr& msg){
  			if(sub_10_15_flag == 1 && sub_12_15_flag == 1 && sub_13_15_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node15 last from node11, intercepted: [%s]", msg->data.c_str());
				pub_15_16.publish(msg);
				sub_10_15_flag = 0;
				sub_12_15_flag = 0;
				sub_13_15_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node15, from node11 intercepted: [%s]", msg->data.c_str());
  				sub_11_15_flag = 1;
  			}
  		}
		void middlemanCallback12(const std_msgs::String::ConstPtr& msg){
  			if(sub_10_15_flag == 1 && sub_11_15_flag == 1 && sub_13_15_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node15 last from node12, intercepted: [%s]", msg->data.c_str());
				pub_15_16.publish(msg);
				sub_10_15_flag = 0;
				sub_11_15_flag = 0;
				sub_13_15_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node15, from node12 intercepted: [%s]", msg->data.c_str());
  				sub_12_15_flag = 1;
  			}
  		}
		void middlemanCallback13(const std_msgs::String::ConstPtr& msg){
  			if(sub_10_15_flag == 1 && sub_11_15_flag == 1 && sub_12_15_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node15 last from node13, intercepted: [%s]", msg->data.c_str());
				pub_15_16.publish(msg);
				sub_10_15_flag = 0;
				sub_11_15_flag = 0;
				sub_12_15_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node15, from node13 intercepted: [%s]", msg->data.c_str());
  				sub_13_15_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_15_16;
		int sub_10_15_flag;
  		ros::Subscriber sub_10_15;
		int sub_11_15_flag;
  		ros::Subscriber sub_11_15;
		int sub_12_15_flag;
  		ros::Subscriber sub_12_15;
		int sub_13_15_flag;
  		ros::Subscriber sub_13_15;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node15");
  	Node15 node15;
  	ros::spin();
  	return 0;
  }

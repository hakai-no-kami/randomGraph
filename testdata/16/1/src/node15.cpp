
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.015650, 0.005);
  class Node15{
  	public:
  		Node15(){
			sub_3_15_flag = 0;
  			sub_3_15 = n.subscribe("topic_3_15", 1, &Node15::middlemanCallback3,this);
			sub_12_15_flag = 0;
  			sub_12_15 = n.subscribe("topic_12_15", 1, &Node15::middlemanCallback12,this);
			sub_13_15_flag = 0;
  			sub_13_15 = n.subscribe("topic_13_15", 1, &Node15::middlemanCallback13,this);
			sub_14_15_flag = 0;
  			sub_14_15 = n.subscribe("topic_14_15", 1, &Node15::middlemanCallback14,this);
			pub_15_16 = n.advertise<std_msgs::String>("topic_15_16", 1);
		}
		void middlemanCallback3(const std_msgs::String::ConstPtr& msg){
  			if(sub_12_15_flag == 1 && sub_13_15_flag == 1 && sub_14_15_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node15 last from node3, intercepted: [%s]", msg->data.c_str());
				pub_15_16.publish(msg);
				sub_12_15_flag = 0;
				sub_13_15_flag = 0;
				sub_14_15_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node15, from node3 intercepted: [%s]", msg->data.c_str());
  				sub_3_15_flag = 1;
  			}
  		}
		void middlemanCallback12(const std_msgs::String::ConstPtr& msg){
  			if(sub_3_15_flag == 1 && sub_13_15_flag == 1 && sub_14_15_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node15 last from node12, intercepted: [%s]", msg->data.c_str());
				pub_15_16.publish(msg);
				sub_3_15_flag = 0;
				sub_13_15_flag = 0;
				sub_14_15_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node15, from node12 intercepted: [%s]", msg->data.c_str());
  				sub_12_15_flag = 1;
  			}
  		}
		void middlemanCallback13(const std_msgs::String::ConstPtr& msg){
  			if(sub_3_15_flag == 1 && sub_12_15_flag == 1 && sub_14_15_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node15 last from node13, intercepted: [%s]", msg->data.c_str());
				pub_15_16.publish(msg);
				sub_3_15_flag = 0;
				sub_12_15_flag = 0;
				sub_14_15_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node15, from node13 intercepted: [%s]", msg->data.c_str());
  				sub_13_15_flag = 1;
  			}
  		}
		void middlemanCallback14(const std_msgs::String::ConstPtr& msg){
  			if(sub_3_15_flag == 1 && sub_12_15_flag == 1 && sub_13_15_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node15 last from node14, intercepted: [%s]", msg->data.c_str());
				pub_15_16.publish(msg);
				sub_3_15_flag = 0;
				sub_12_15_flag = 0;
				sub_13_15_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node15, from node14 intercepted: [%s]", msg->data.c_str());
  				sub_14_15_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_15_16;
		int sub_3_15_flag;
  		ros::Subscriber sub_3_15;
		int sub_12_15_flag;
  		ros::Subscriber sub_12_15;
		int sub_13_15_flag;
  		ros::Subscriber sub_13_15;
		int sub_14_15_flag;
  		ros::Subscriber sub_14_15;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node15");
  	Node15 node15;
  	ros::spin();
  	return 0;
  }

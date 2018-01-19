
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.023764, 0.005);
  class Node15{
  	public:
  		Node15(){
			sub_8_15_flag = 0;
  			sub_8_15 = n.subscribe("topic_8_15", 1, &Node15::middlemanCallback8,this);
			sub_10_15_flag = 0;
  			sub_10_15 = n.subscribe("topic_10_15", 1, &Node15::middlemanCallback10,this);
			sub_12_15_flag = 0;
  			sub_12_15 = n.subscribe("topic_12_15", 1, &Node15::middlemanCallback12,this);
			pub_15_19 = n.advertise<std_msgs::String>("topic_15_19", 1);
		}
		void middlemanCallback8(const std_msgs::String::ConstPtr& msg){
  			if(sub_10_15_flag == 1 && sub_12_15_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node15 last from node8, intercepted: [%s]", msg->data.c_str());
				pub_15_19.publish(msg);
				sub_10_15_flag = 0;
				sub_12_15_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node15, from node8 intercepted: [%s]", msg->data.c_str());
  				sub_8_15_flag = 1;
  			}
  		}
		void middlemanCallback10(const std_msgs::String::ConstPtr& msg){
  			if(sub_8_15_flag == 1 && sub_12_15_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node15 last from node10, intercepted: [%s]", msg->data.c_str());
				pub_15_19.publish(msg);
				sub_8_15_flag = 0;
				sub_12_15_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node15, from node10 intercepted: [%s]", msg->data.c_str());
  				sub_10_15_flag = 1;
  			}
  		}
		void middlemanCallback12(const std_msgs::String::ConstPtr& msg){
  			if(sub_8_15_flag == 1 && sub_10_15_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node15 last from node12, intercepted: [%s]", msg->data.c_str());
				pub_15_19.publish(msg);
				sub_8_15_flag = 0;
				sub_10_15_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node15, from node12 intercepted: [%s]", msg->data.c_str());
  				sub_12_15_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_15_19;
		int sub_8_15_flag;
  		ros::Subscriber sub_8_15;
		int sub_10_15_flag;
  		ros::Subscriber sub_10_15;
		int sub_12_15_flag;
  		ros::Subscriber sub_12_15;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node15");
  	Node15 node15;
  	ros::spin();
  	return 0;
  }

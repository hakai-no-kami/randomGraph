
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.016678, 0.005);
  class Node15{
  	public:
  		Node15(){
			sub_5_15_flag = 0;
  			sub_5_15 = n.subscribe("topic_5_15", 1, &Node15::middlemanCallback5,this);
			sub_11_15_flag = 0;
  			sub_11_15 = n.subscribe("topic_11_15", 1, &Node15::middlemanCallback11,this);
			sub_12_15_flag = 0;
  			sub_12_15 = n.subscribe("topic_12_15", 1, &Node15::middlemanCallback12,this);
			pub_15_18 = n.advertise<std_msgs::String>("topic_15_18", 1);
			pub_15_17 = n.advertise<std_msgs::String>("topic_15_17", 1);
		}
		void middlemanCallback5(const std_msgs::String::ConstPtr& msg){
  			if(sub_11_15_flag == 1 && sub_12_15_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node15 last from node5, intercepted: [%s]", msg->data.c_str());
				pub_15_18.publish(msg);
				pub_15_17.publish(msg);
				sub_11_15_flag = 0;
				sub_12_15_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node15, from node5 intercepted: [%s]", msg->data.c_str());
  				sub_5_15_flag = 1;
  			}
  		}
		void middlemanCallback11(const std_msgs::String::ConstPtr& msg){
  			if(sub_5_15_flag == 1 && sub_12_15_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node15 last from node11, intercepted: [%s]", msg->data.c_str());
				pub_15_18.publish(msg);
				pub_15_17.publish(msg);
				sub_5_15_flag = 0;
				sub_12_15_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node15, from node11 intercepted: [%s]", msg->data.c_str());
  				sub_11_15_flag = 1;
  			}
  		}
		void middlemanCallback12(const std_msgs::String::ConstPtr& msg){
  			if(sub_5_15_flag == 1 && sub_11_15_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node15 last from node12, intercepted: [%s]", msg->data.c_str());
				pub_15_18.publish(msg);
				pub_15_17.publish(msg);
				sub_5_15_flag = 0;
				sub_11_15_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node15, from node12 intercepted: [%s]", msg->data.c_str());
  				sub_12_15_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_15_18;
		ros::Publisher pub_15_17;
		int sub_5_15_flag;
  		ros::Subscriber sub_5_15;
		int sub_11_15_flag;
  		ros::Subscriber sub_11_15;
		int sub_12_15_flag;
  		ros::Subscriber sub_12_15;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node15");
  	Node15 node15;
  	ros::spin();
  	return 0;
  }

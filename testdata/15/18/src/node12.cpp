
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.019491, 0.005);
  class Node12{
  	public:
  		Node12(){
			sub_6_12_flag = 0;
  			sub_6_12 = n.subscribe("topic_6_12", 1, &Node12::middlemanCallback6,this);
			sub_8_12_flag = 0;
  			sub_8_12 = n.subscribe("topic_8_12", 1, &Node12::middlemanCallback8,this);
			pub_12_14 = n.advertise<std_msgs::String>("topic_12_14", 1);
			pub_12_13 = n.advertise<std_msgs::String>("topic_12_13", 1);
		}
		void middlemanCallback6(const std_msgs::String::ConstPtr& msg){
  			if(sub_8_12_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node12 last from node6, intercepted: [%s]", msg->data.c_str());
				pub_12_14.publish(msg);
				pub_12_13.publish(msg);
				sub_8_12_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node12, from node6 intercepted: [%s]", msg->data.c_str());
  				sub_6_12_flag = 1;
  			}
  		}
		void middlemanCallback8(const std_msgs::String::ConstPtr& msg){
  			if(sub_6_12_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node12 last from node8, intercepted: [%s]", msg->data.c_str());
				pub_12_14.publish(msg);
				pub_12_13.publish(msg);
				sub_6_12_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node12, from node8 intercepted: [%s]", msg->data.c_str());
  				sub_8_12_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_12_14;
		ros::Publisher pub_12_13;
		int sub_6_12_flag;
  		ros::Subscriber sub_6_12;
		int sub_8_12_flag;
  		ros::Subscriber sub_8_12;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node12");
  	Node12 node12;
  	ros::spin();
  	return 0;
  }

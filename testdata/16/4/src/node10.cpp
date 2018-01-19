
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.013487, 0.005);
  class Node10{
  	public:
  		Node10(){
			sub_1_10_flag = 0;
  			sub_1_10 = n.subscribe("topic_1_10", 1, &Node10::middlemanCallback1,this);
			sub_5_10_flag = 0;
  			sub_5_10 = n.subscribe("topic_5_10", 1, &Node10::middlemanCallback5,this);
			sub_6_10_flag = 0;
  			sub_6_10 = n.subscribe("topic_6_10", 1, &Node10::middlemanCallback6,this);
			pub_10_13 = n.advertise<std_msgs::String>("topic_10_13", 1);
		}
		void middlemanCallback1(const std_msgs::String::ConstPtr& msg){
  			if(sub_5_10_flag == 1 && sub_6_10_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node10 last from node1, intercepted: [%s]", msg->data.c_str());
				pub_10_13.publish(msg);
				sub_5_10_flag = 0;
				sub_6_10_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node10, from node1 intercepted: [%s]", msg->data.c_str());
  				sub_1_10_flag = 1;
  			}
  		}
		void middlemanCallback5(const std_msgs::String::ConstPtr& msg){
  			if(sub_1_10_flag == 1 && sub_6_10_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node10 last from node5, intercepted: [%s]", msg->data.c_str());
				pub_10_13.publish(msg);
				sub_1_10_flag = 0;
				sub_6_10_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node10, from node5 intercepted: [%s]", msg->data.c_str());
  				sub_5_10_flag = 1;
  			}
  		}
		void middlemanCallback6(const std_msgs::String::ConstPtr& msg){
  			if(sub_1_10_flag == 1 && sub_5_10_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node10 last from node6, intercepted: [%s]", msg->data.c_str());
				pub_10_13.publish(msg);
				sub_1_10_flag = 0;
				sub_5_10_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node10, from node6 intercepted: [%s]", msg->data.c_str());
  				sub_6_10_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_10_13;
		int sub_1_10_flag;
  		ros::Subscriber sub_1_10;
		int sub_5_10_flag;
  		ros::Subscriber sub_5_10;
		int sub_6_10_flag;
  		ros::Subscriber sub_6_10;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node10");
  	Node10 node10;
  	ros::spin();
  	return 0;
  }


  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.016978, 0.005);
  class Node16{
  	public:
  		Node16(){
			sub_6_16_flag = 0;
  			sub_6_16 = n.subscribe("topic_6_16", 1, &Node16::middlemanCallback6,this);
			sub_8_16_flag = 0;
  			sub_8_16 = n.subscribe("topic_8_16", 1, &Node16::middlemanCallback8,this);
			sub_13_16_flag = 0;
  			sub_13_16 = n.subscribe("topic_13_16", 1, &Node16::middlemanCallback13,this);
			sub_14_16_flag = 0;
  			sub_14_16 = n.subscribe("topic_14_16", 1, &Node16::middlemanCallback14,this);
			pub_16_17 = n.advertise<std_msgs::String>("topic_16_17", 1);
		}
		void middlemanCallback6(const std_msgs::String::ConstPtr& msg){
  			if(sub_8_16_flag == 1 && sub_13_16_flag == 1 && sub_14_16_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node16 last from node6, intercepted: [%s]", msg->data.c_str());
				pub_16_17.publish(msg);
				sub_8_16_flag = 0;
				sub_13_16_flag = 0;
				sub_14_16_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node16, from node6 intercepted: [%s]", msg->data.c_str());
  				sub_6_16_flag = 1;
  			}
  		}
		void middlemanCallback8(const std_msgs::String::ConstPtr& msg){
  			if(sub_6_16_flag == 1 && sub_13_16_flag == 1 && sub_14_16_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node16 last from node8, intercepted: [%s]", msg->data.c_str());
				pub_16_17.publish(msg);
				sub_6_16_flag = 0;
				sub_13_16_flag = 0;
				sub_14_16_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node16, from node8 intercepted: [%s]", msg->data.c_str());
  				sub_8_16_flag = 1;
  			}
  		}
		void middlemanCallback13(const std_msgs::String::ConstPtr& msg){
  			if(sub_6_16_flag == 1 && sub_8_16_flag == 1 && sub_14_16_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node16 last from node13, intercepted: [%s]", msg->data.c_str());
				pub_16_17.publish(msg);
				sub_6_16_flag = 0;
				sub_8_16_flag = 0;
				sub_14_16_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node16, from node13 intercepted: [%s]", msg->data.c_str());
  				sub_13_16_flag = 1;
  			}
  		}
		void middlemanCallback14(const std_msgs::String::ConstPtr& msg){
  			if(sub_6_16_flag == 1 && sub_8_16_flag == 1 && sub_13_16_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node16 last from node14, intercepted: [%s]", msg->data.c_str());
				pub_16_17.publish(msg);
				sub_6_16_flag = 0;
				sub_8_16_flag = 0;
				sub_13_16_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node16, from node14 intercepted: [%s]", msg->data.c_str());
  				sub_14_16_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_16_17;
		int sub_6_16_flag;
  		ros::Subscriber sub_6_16;
		int sub_8_16_flag;
  		ros::Subscriber sub_8_16;
		int sub_13_16_flag;
  		ros::Subscriber sub_13_16;
		int sub_14_16_flag;
  		ros::Subscriber sub_14_16;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node16");
  	Node16 node16;
  	ros::spin();
  	return 0;
  }

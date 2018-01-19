
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.016287, 0.005);
  class Node16{
  	public:
  		Node16(){
			sub_8_16_flag = 0;
  			sub_8_16 = n.subscribe("topic_8_16", 1, &Node16::middlemanCallback8,this);
			sub_9_16_flag = 0;
  			sub_9_16 = n.subscribe("topic_9_16", 1, &Node16::middlemanCallback9,this);
			sub_11_16_flag = 0;
  			sub_11_16 = n.subscribe("topic_11_16", 1, &Node16::middlemanCallback11,this);
			sub_12_16_flag = 0;
  			sub_12_16 = n.subscribe("topic_12_16", 1, &Node16::middlemanCallback12,this);
			sub_13_16_flag = 0;
  			sub_13_16 = n.subscribe("topic_13_16", 1, &Node16::middlemanCallback13,this);
			pub_16_17 = n.advertise<std_msgs::String>("topic_16_17", 1);
		}
		void middlemanCallback8(const std_msgs::String::ConstPtr& msg){
  			if(sub_9_16_flag == 1 && sub_11_16_flag == 1 && sub_12_16_flag == 1 && sub_13_16_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node16 last from node8, intercepted: [%s]", msg->data.c_str());
				pub_16_17.publish(msg);
				sub_9_16_flag = 0;
				sub_11_16_flag = 0;
				sub_12_16_flag = 0;
				sub_13_16_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node16, from node8 intercepted: [%s]", msg->data.c_str());
  				sub_8_16_flag = 1;
  			}
  		}
		void middlemanCallback9(const std_msgs::String::ConstPtr& msg){
  			if(sub_8_16_flag == 1 && sub_11_16_flag == 1 && sub_12_16_flag == 1 && sub_13_16_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node16 last from node9, intercepted: [%s]", msg->data.c_str());
				pub_16_17.publish(msg);
				sub_8_16_flag = 0;
				sub_11_16_flag = 0;
				sub_12_16_flag = 0;
				sub_13_16_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node16, from node9 intercepted: [%s]", msg->data.c_str());
  				sub_9_16_flag = 1;
  			}
  		}
		void middlemanCallback11(const std_msgs::String::ConstPtr& msg){
  			if(sub_8_16_flag == 1 && sub_9_16_flag == 1 && sub_12_16_flag == 1 && sub_13_16_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node16 last from node11, intercepted: [%s]", msg->data.c_str());
				pub_16_17.publish(msg);
				sub_8_16_flag = 0;
				sub_9_16_flag = 0;
				sub_12_16_flag = 0;
				sub_13_16_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node16, from node11 intercepted: [%s]", msg->data.c_str());
  				sub_11_16_flag = 1;
  			}
  		}
		void middlemanCallback12(const std_msgs::String::ConstPtr& msg){
  			if(sub_8_16_flag == 1 && sub_9_16_flag == 1 && sub_11_16_flag == 1 && sub_13_16_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node16 last from node12, intercepted: [%s]", msg->data.c_str());
				pub_16_17.publish(msg);
				sub_8_16_flag = 0;
				sub_9_16_flag = 0;
				sub_11_16_flag = 0;
				sub_13_16_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node16, from node12 intercepted: [%s]", msg->data.c_str());
  				sub_12_16_flag = 1;
  			}
  		}
		void middlemanCallback13(const std_msgs::String::ConstPtr& msg){
  			if(sub_8_16_flag == 1 && sub_9_16_flag == 1 && sub_11_16_flag == 1 && sub_12_16_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node16 last from node13, intercepted: [%s]", msg->data.c_str());
				pub_16_17.publish(msg);
				sub_8_16_flag = 0;
				sub_9_16_flag = 0;
				sub_11_16_flag = 0;
				sub_12_16_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node16, from node13 intercepted: [%s]", msg->data.c_str());
  				sub_13_16_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_16_17;
		int sub_8_16_flag;
  		ros::Subscriber sub_8_16;
		int sub_9_16_flag;
  		ros::Subscriber sub_9_16;
		int sub_11_16_flag;
  		ros::Subscriber sub_11_16;
		int sub_12_16_flag;
  		ros::Subscriber sub_12_16;
		int sub_13_16_flag;
  		ros::Subscriber sub_13_16;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node16");
  	Node16 node16;
  	ros::spin();
  	return 0;
  }

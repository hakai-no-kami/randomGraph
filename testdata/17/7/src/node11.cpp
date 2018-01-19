
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.015382, 0.005);
  class Node11{
  	public:
  		Node11(){
			sub_1_11_flag = 0;
  			sub_1_11 = n.subscribe("topic_1_11", 1, &Node11::middlemanCallback1,this);
			sub_2_11_flag = 0;
  			sub_2_11 = n.subscribe("topic_2_11", 1, &Node11::middlemanCallback2,this);
			sub_7_11_flag = 0;
  			sub_7_11 = n.subscribe("topic_7_11", 1, &Node11::middlemanCallback7,this);
			sub_8_11_flag = 0;
  			sub_8_11 = n.subscribe("topic_8_11", 1, &Node11::middlemanCallback8,this);
			sub_10_11_flag = 0;
  			sub_10_11 = n.subscribe("topic_10_11", 1, &Node11::middlemanCallback10,this);
			pub_11_13 = n.advertise<std_msgs::String>("topic_11_13", 1);
			pub_11_12 = n.advertise<std_msgs::String>("topic_11_12", 1);
		}
		void middlemanCallback1(const std_msgs::String::ConstPtr& msg){
  			if(sub_2_11_flag == 1 && sub_7_11_flag == 1 && sub_8_11_flag == 1 && sub_10_11_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node11 last from node1, intercepted: [%s]", msg->data.c_str());
				pub_11_13.publish(msg);
				pub_11_12.publish(msg);
				sub_2_11_flag = 0;
				sub_7_11_flag = 0;
				sub_8_11_flag = 0;
				sub_10_11_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node11, from node1 intercepted: [%s]", msg->data.c_str());
  				sub_1_11_flag = 1;
  			}
  		}
		void middlemanCallback2(const std_msgs::String::ConstPtr& msg){
  			if(sub_1_11_flag == 1 && sub_7_11_flag == 1 && sub_8_11_flag == 1 && sub_10_11_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node11 last from node2, intercepted: [%s]", msg->data.c_str());
				pub_11_13.publish(msg);
				pub_11_12.publish(msg);
				sub_1_11_flag = 0;
				sub_7_11_flag = 0;
				sub_8_11_flag = 0;
				sub_10_11_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node11, from node2 intercepted: [%s]", msg->data.c_str());
  				sub_2_11_flag = 1;
  			}
  		}
		void middlemanCallback7(const std_msgs::String::ConstPtr& msg){
  			if(sub_1_11_flag == 1 && sub_2_11_flag == 1 && sub_8_11_flag == 1 && sub_10_11_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node11 last from node7, intercepted: [%s]", msg->data.c_str());
				pub_11_13.publish(msg);
				pub_11_12.publish(msg);
				sub_1_11_flag = 0;
				sub_2_11_flag = 0;
				sub_8_11_flag = 0;
				sub_10_11_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node11, from node7 intercepted: [%s]", msg->data.c_str());
  				sub_7_11_flag = 1;
  			}
  		}
		void middlemanCallback8(const std_msgs::String::ConstPtr& msg){
  			if(sub_1_11_flag == 1 && sub_2_11_flag == 1 && sub_7_11_flag == 1 && sub_10_11_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node11 last from node8, intercepted: [%s]", msg->data.c_str());
				pub_11_13.publish(msg);
				pub_11_12.publish(msg);
				sub_1_11_flag = 0;
				sub_2_11_flag = 0;
				sub_7_11_flag = 0;
				sub_10_11_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node11, from node8 intercepted: [%s]", msg->data.c_str());
  				sub_8_11_flag = 1;
  			}
  		}
		void middlemanCallback10(const std_msgs::String::ConstPtr& msg){
  			if(sub_1_11_flag == 1 && sub_2_11_flag == 1 && sub_7_11_flag == 1 && sub_8_11_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node11 last from node10, intercepted: [%s]", msg->data.c_str());
				pub_11_13.publish(msg);
				pub_11_12.publish(msg);
				sub_1_11_flag = 0;
				sub_2_11_flag = 0;
				sub_7_11_flag = 0;
				sub_8_11_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node11, from node10 intercepted: [%s]", msg->data.c_str());
  				sub_10_11_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_11_13;
		ros::Publisher pub_11_12;
		int sub_1_11_flag;
  		ros::Subscriber sub_1_11;
		int sub_2_11_flag;
  		ros::Subscriber sub_2_11;
		int sub_7_11_flag;
  		ros::Subscriber sub_7_11;
		int sub_8_11_flag;
  		ros::Subscriber sub_8_11;
		int sub_10_11_flag;
  		ros::Subscriber sub_10_11;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node11");
  	Node11 node11;
  	ros::spin();
  	return 0;
  }

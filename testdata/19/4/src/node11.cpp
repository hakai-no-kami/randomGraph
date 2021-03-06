
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.017346, 0.005);
  class Node11{
  	public:
  		Node11(){
			sub_3_11_flag = 0;
  			sub_3_11 = n.subscribe("topic_3_11", 1, &Node11::middlemanCallback3,this);
			sub_4_11_flag = 0;
  			sub_4_11 = n.subscribe("topic_4_11", 1, &Node11::middlemanCallback4,this);
			sub_5_11_flag = 0;
  			sub_5_11 = n.subscribe("topic_5_11", 1, &Node11::middlemanCallback5,this);
			sub_6_11_flag = 0;
  			sub_6_11 = n.subscribe("topic_6_11", 1, &Node11::middlemanCallback6,this);
			sub_7_11_flag = 0;
  			sub_7_11 = n.subscribe("topic_7_11", 1, &Node11::middlemanCallback7,this);
			sub_8_11_flag = 0;
  			sub_8_11 = n.subscribe("topic_8_11", 1, &Node11::middlemanCallback8,this);
			pub_11_13 = n.advertise<std_msgs::String>("topic_11_13", 1);
			pub_11_12 = n.advertise<std_msgs::String>("topic_11_12", 1);
		}
		void middlemanCallback3(const std_msgs::String::ConstPtr& msg){
  			if(sub_4_11_flag == 1 && sub_5_11_flag == 1 && sub_6_11_flag == 1 && sub_7_11_flag == 1 && sub_8_11_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node11 last from node3, intercepted: [%s]", msg->data.c_str());
				pub_11_13.publish(msg);
				pub_11_12.publish(msg);
				sub_4_11_flag = 0;
				sub_5_11_flag = 0;
				sub_6_11_flag = 0;
				sub_7_11_flag = 0;
				sub_8_11_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node11, from node3 intercepted: [%s]", msg->data.c_str());
  				sub_3_11_flag = 1;
  			}
  		}
		void middlemanCallback4(const std_msgs::String::ConstPtr& msg){
  			if(sub_3_11_flag == 1 && sub_5_11_flag == 1 && sub_6_11_flag == 1 && sub_7_11_flag == 1 && sub_8_11_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node11 last from node4, intercepted: [%s]", msg->data.c_str());
				pub_11_13.publish(msg);
				pub_11_12.publish(msg);
				sub_3_11_flag = 0;
				sub_5_11_flag = 0;
				sub_6_11_flag = 0;
				sub_7_11_flag = 0;
				sub_8_11_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node11, from node4 intercepted: [%s]", msg->data.c_str());
  				sub_4_11_flag = 1;
  			}
  		}
		void middlemanCallback5(const std_msgs::String::ConstPtr& msg){
  			if(sub_3_11_flag == 1 && sub_4_11_flag == 1 && sub_6_11_flag == 1 && sub_7_11_flag == 1 && sub_8_11_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node11 last from node5, intercepted: [%s]", msg->data.c_str());
				pub_11_13.publish(msg);
				pub_11_12.publish(msg);
				sub_3_11_flag = 0;
				sub_4_11_flag = 0;
				sub_6_11_flag = 0;
				sub_7_11_flag = 0;
				sub_8_11_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node11, from node5 intercepted: [%s]", msg->data.c_str());
  				sub_5_11_flag = 1;
  			}
  		}
		void middlemanCallback6(const std_msgs::String::ConstPtr& msg){
  			if(sub_3_11_flag == 1 && sub_4_11_flag == 1 && sub_5_11_flag == 1 && sub_7_11_flag == 1 && sub_8_11_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node11 last from node6, intercepted: [%s]", msg->data.c_str());
				pub_11_13.publish(msg);
				pub_11_12.publish(msg);
				sub_3_11_flag = 0;
				sub_4_11_flag = 0;
				sub_5_11_flag = 0;
				sub_7_11_flag = 0;
				sub_8_11_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node11, from node6 intercepted: [%s]", msg->data.c_str());
  				sub_6_11_flag = 1;
  			}
  		}
		void middlemanCallback7(const std_msgs::String::ConstPtr& msg){
  			if(sub_3_11_flag == 1 && sub_4_11_flag == 1 && sub_5_11_flag == 1 && sub_6_11_flag == 1 && sub_8_11_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node11 last from node7, intercepted: [%s]", msg->data.c_str());
				pub_11_13.publish(msg);
				pub_11_12.publish(msg);
				sub_3_11_flag = 0;
				sub_4_11_flag = 0;
				sub_5_11_flag = 0;
				sub_6_11_flag = 0;
				sub_8_11_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node11, from node7 intercepted: [%s]", msg->data.c_str());
  				sub_7_11_flag = 1;
  			}
  		}
		void middlemanCallback8(const std_msgs::String::ConstPtr& msg){
  			if(sub_3_11_flag == 1 && sub_4_11_flag == 1 && sub_5_11_flag == 1 && sub_6_11_flag == 1 && sub_7_11_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node11 last from node8, intercepted: [%s]", msg->data.c_str());
				pub_11_13.publish(msg);
				pub_11_12.publish(msg);
				sub_3_11_flag = 0;
				sub_4_11_flag = 0;
				sub_5_11_flag = 0;
				sub_6_11_flag = 0;
				sub_7_11_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node11, from node8 intercepted: [%s]", msg->data.c_str());
  				sub_8_11_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_11_13;
		ros::Publisher pub_11_12;
		int sub_3_11_flag;
  		ros::Subscriber sub_3_11;
		int sub_4_11_flag;
  		ros::Subscriber sub_4_11;
		int sub_5_11_flag;
  		ros::Subscriber sub_5_11;
		int sub_6_11_flag;
  		ros::Subscriber sub_6_11;
		int sub_7_11_flag;
  		ros::Subscriber sub_7_11;
		int sub_8_11_flag;
  		ros::Subscriber sub_8_11;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node11");
  	Node11 node11;
  	ros::spin();
  	return 0;
  }


  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.023013, 0.005);
  class Node14{
  	public:
  		Node14(){
			sub_1_14_flag = 0;
  			sub_1_14 = n.subscribe("topic_1_14", 1, &Node14::middlemanCallback1,this);
			sub_8_14_flag = 0;
  			sub_8_14 = n.subscribe("topic_8_14", 1, &Node14::middlemanCallback8,this);
			sub_9_14_flag = 0;
  			sub_9_14 = n.subscribe("topic_9_14", 1, &Node14::middlemanCallback9,this);
			sub_10_14_flag = 0;
  			sub_10_14 = n.subscribe("topic_10_14", 1, &Node14::middlemanCallback10,this);
			sub_12_14_flag = 0;
  			sub_12_14 = n.subscribe("topic_12_14", 1, &Node14::middlemanCallback12,this);
			sub_13_14_flag = 0;
  			sub_13_14 = n.subscribe("topic_13_14", 1, &Node14::middlemanCallback13,this);
			pub_14_15 = n.advertise<std_msgs::String>("topic_14_15", 1);
		}
		void middlemanCallback1(const std_msgs::String::ConstPtr& msg){
  			if(sub_8_14_flag == 1 && sub_9_14_flag == 1 && sub_10_14_flag == 1 && sub_12_14_flag == 1 && sub_13_14_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node14 last from node1, intercepted: [%s]", msg->data.c_str());
				pub_14_15.publish(msg);
				sub_8_14_flag = 0;
				sub_9_14_flag = 0;
				sub_10_14_flag = 0;
				sub_12_14_flag = 0;
				sub_13_14_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node14, from node1 intercepted: [%s]", msg->data.c_str());
  				sub_1_14_flag = 1;
  			}
  		}
		void middlemanCallback8(const std_msgs::String::ConstPtr& msg){
  			if(sub_1_14_flag == 1 && sub_9_14_flag == 1 && sub_10_14_flag == 1 && sub_12_14_flag == 1 && sub_13_14_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node14 last from node8, intercepted: [%s]", msg->data.c_str());
				pub_14_15.publish(msg);
				sub_1_14_flag = 0;
				sub_9_14_flag = 0;
				sub_10_14_flag = 0;
				sub_12_14_flag = 0;
				sub_13_14_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node14, from node8 intercepted: [%s]", msg->data.c_str());
  				sub_8_14_flag = 1;
  			}
  		}
		void middlemanCallback9(const std_msgs::String::ConstPtr& msg){
  			if(sub_1_14_flag == 1 && sub_8_14_flag == 1 && sub_10_14_flag == 1 && sub_12_14_flag == 1 && sub_13_14_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node14 last from node9, intercepted: [%s]", msg->data.c_str());
				pub_14_15.publish(msg);
				sub_1_14_flag = 0;
				sub_8_14_flag = 0;
				sub_10_14_flag = 0;
				sub_12_14_flag = 0;
				sub_13_14_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node14, from node9 intercepted: [%s]", msg->data.c_str());
  				sub_9_14_flag = 1;
  			}
  		}
		void middlemanCallback10(const std_msgs::String::ConstPtr& msg){
  			if(sub_1_14_flag == 1 && sub_8_14_flag == 1 && sub_9_14_flag == 1 && sub_12_14_flag == 1 && sub_13_14_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node14 last from node10, intercepted: [%s]", msg->data.c_str());
				pub_14_15.publish(msg);
				sub_1_14_flag = 0;
				sub_8_14_flag = 0;
				sub_9_14_flag = 0;
				sub_12_14_flag = 0;
				sub_13_14_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node14, from node10 intercepted: [%s]", msg->data.c_str());
  				sub_10_14_flag = 1;
  			}
  		}
		void middlemanCallback12(const std_msgs::String::ConstPtr& msg){
  			if(sub_1_14_flag == 1 && sub_8_14_flag == 1 && sub_9_14_flag == 1 && sub_10_14_flag == 1 && sub_13_14_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node14 last from node12, intercepted: [%s]", msg->data.c_str());
				pub_14_15.publish(msg);
				sub_1_14_flag = 0;
				sub_8_14_flag = 0;
				sub_9_14_flag = 0;
				sub_10_14_flag = 0;
				sub_13_14_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node14, from node12 intercepted: [%s]", msg->data.c_str());
  				sub_12_14_flag = 1;
  			}
  		}
		void middlemanCallback13(const std_msgs::String::ConstPtr& msg){
  			if(sub_1_14_flag == 1 && sub_8_14_flag == 1 && sub_9_14_flag == 1 && sub_10_14_flag == 1 && sub_12_14_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node14 last from node13, intercepted: [%s]", msg->data.c_str());
				pub_14_15.publish(msg);
				sub_1_14_flag = 0;
				sub_8_14_flag = 0;
				sub_9_14_flag = 0;
				sub_10_14_flag = 0;
				sub_12_14_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node14, from node13 intercepted: [%s]", msg->data.c_str());
  				sub_13_14_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_14_15;
		int sub_1_14_flag;
  		ros::Subscriber sub_1_14;
		int sub_8_14_flag;
  		ros::Subscriber sub_8_14;
		int sub_9_14_flag;
  		ros::Subscriber sub_9_14;
		int sub_10_14_flag;
  		ros::Subscriber sub_10_14;
		int sub_12_14_flag;
  		ros::Subscriber sub_12_14;
		int sub_13_14_flag;
  		ros::Subscriber sub_13_14;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node14");
  	Node14 node14;
  	ros::spin();
  	return 0;
  }

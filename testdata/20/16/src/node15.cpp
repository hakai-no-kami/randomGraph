
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.029862, 0.005);
  class Node15{
  	public:
  		Node15(){
			sub_2_15_flag = 0;
  			sub_2_15 = n.subscribe("topic_2_15", 1, &Node15::middlemanCallback2,this);
			sub_6_15_flag = 0;
  			sub_6_15 = n.subscribe("topic_6_15", 1, &Node15::middlemanCallback6,this);
			sub_9_15_flag = 0;
  			sub_9_15 = n.subscribe("topic_9_15", 1, &Node15::middlemanCallback9,this);
			sub_10_15_flag = 0;
  			sub_10_15 = n.subscribe("topic_10_15", 1, &Node15::middlemanCallback10,this);
			sub_14_15_flag = 0;
  			sub_14_15 = n.subscribe("topic_14_15", 1, &Node15::middlemanCallback14,this);
			pub_15_18 = n.advertise<std_msgs::String>("topic_15_18", 1);
		}
		void middlemanCallback2(const std_msgs::String::ConstPtr& msg){
  			if(sub_6_15_flag == 1 && sub_9_15_flag == 1 && sub_10_15_flag == 1 && sub_14_15_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node15 last from node2, intercepted: [%s]", msg->data.c_str());
				pub_15_18.publish(msg);
				sub_6_15_flag = 0;
				sub_9_15_flag = 0;
				sub_10_15_flag = 0;
				sub_14_15_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node15, from node2 intercepted: [%s]", msg->data.c_str());
  				sub_2_15_flag = 1;
  			}
  		}
		void middlemanCallback6(const std_msgs::String::ConstPtr& msg){
  			if(sub_2_15_flag == 1 && sub_9_15_flag == 1 && sub_10_15_flag == 1 && sub_14_15_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node15 last from node6, intercepted: [%s]", msg->data.c_str());
				pub_15_18.publish(msg);
				sub_2_15_flag = 0;
				sub_9_15_flag = 0;
				sub_10_15_flag = 0;
				sub_14_15_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node15, from node6 intercepted: [%s]", msg->data.c_str());
  				sub_6_15_flag = 1;
  			}
  		}
		void middlemanCallback9(const std_msgs::String::ConstPtr& msg){
  			if(sub_2_15_flag == 1 && sub_6_15_flag == 1 && sub_10_15_flag == 1 && sub_14_15_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node15 last from node9, intercepted: [%s]", msg->data.c_str());
				pub_15_18.publish(msg);
				sub_2_15_flag = 0;
				sub_6_15_flag = 0;
				sub_10_15_flag = 0;
				sub_14_15_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node15, from node9 intercepted: [%s]", msg->data.c_str());
  				sub_9_15_flag = 1;
  			}
  		}
		void middlemanCallback10(const std_msgs::String::ConstPtr& msg){
  			if(sub_2_15_flag == 1 && sub_6_15_flag == 1 && sub_9_15_flag == 1 && sub_14_15_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node15 last from node10, intercepted: [%s]", msg->data.c_str());
				pub_15_18.publish(msg);
				sub_2_15_flag = 0;
				sub_6_15_flag = 0;
				sub_9_15_flag = 0;
				sub_14_15_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node15, from node10 intercepted: [%s]", msg->data.c_str());
  				sub_10_15_flag = 1;
  			}
  		}
		void middlemanCallback14(const std_msgs::String::ConstPtr& msg){
  			if(sub_2_15_flag == 1 && sub_6_15_flag == 1 && sub_9_15_flag == 1 && sub_10_15_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node15 last from node14, intercepted: [%s]", msg->data.c_str());
				pub_15_18.publish(msg);
				sub_2_15_flag = 0;
				sub_6_15_flag = 0;
				sub_9_15_flag = 0;
				sub_10_15_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node15, from node14 intercepted: [%s]", msg->data.c_str());
  				sub_14_15_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_15_18;
		int sub_2_15_flag;
  		ros::Subscriber sub_2_15;
		int sub_6_15_flag;
  		ros::Subscriber sub_6_15;
		int sub_9_15_flag;
  		ros::Subscriber sub_9_15;
		int sub_10_15_flag;
  		ros::Subscriber sub_10_15;
		int sub_14_15_flag;
  		ros::Subscriber sub_14_15;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node15");
  	Node15 node15;
  	ros::spin();
  	return 0;
  }

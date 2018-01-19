
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.022393, 0.005);
  class Node15{
  	public:
  		Node15(){
			sub_6_15_flag = 0;
  			sub_6_15 = n.subscribe("topic_6_15", 1, &Node15::middlemanCallback6,this);
			sub_8_15_flag = 0;
  			sub_8_15 = n.subscribe("topic_8_15", 1, &Node15::middlemanCallback8,this);
			sub_9_15_flag = 0;
  			sub_9_15 = n.subscribe("topic_9_15", 1, &Node15::middlemanCallback9,this);
			sub_11_15_flag = 0;
  			sub_11_15 = n.subscribe("topic_11_15", 1, &Node15::middlemanCallback11,this);
			pub_15_19 = n.advertise<std_msgs::String>("topic_15_19", 1);
		}
		void middlemanCallback6(const std_msgs::String::ConstPtr& msg){
  			if(sub_8_15_flag == 1 && sub_9_15_flag == 1 && sub_11_15_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node15 last from node6, intercepted: [%s]", msg->data.c_str());
				pub_15_19.publish(msg);
				sub_8_15_flag = 0;
				sub_9_15_flag = 0;
				sub_11_15_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node15, from node6 intercepted: [%s]", msg->data.c_str());
  				sub_6_15_flag = 1;
  			}
  		}
		void middlemanCallback8(const std_msgs::String::ConstPtr& msg){
  			if(sub_6_15_flag == 1 && sub_9_15_flag == 1 && sub_11_15_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node15 last from node8, intercepted: [%s]", msg->data.c_str());
				pub_15_19.publish(msg);
				sub_6_15_flag = 0;
				sub_9_15_flag = 0;
				sub_11_15_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node15, from node8 intercepted: [%s]", msg->data.c_str());
  				sub_8_15_flag = 1;
  			}
  		}
		void middlemanCallback9(const std_msgs::String::ConstPtr& msg){
  			if(sub_6_15_flag == 1 && sub_8_15_flag == 1 && sub_11_15_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node15 last from node9, intercepted: [%s]", msg->data.c_str());
				pub_15_19.publish(msg);
				sub_6_15_flag = 0;
				sub_8_15_flag = 0;
				sub_11_15_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node15, from node9 intercepted: [%s]", msg->data.c_str());
  				sub_9_15_flag = 1;
  			}
  		}
		void middlemanCallback11(const std_msgs::String::ConstPtr& msg){
  			if(sub_6_15_flag == 1 && sub_8_15_flag == 1 && sub_9_15_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node15 last from node11, intercepted: [%s]", msg->data.c_str());
				pub_15_19.publish(msg);
				sub_6_15_flag = 0;
				sub_8_15_flag = 0;
				sub_9_15_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node15, from node11 intercepted: [%s]", msg->data.c_str());
  				sub_11_15_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_15_19;
		int sub_6_15_flag;
  		ros::Subscriber sub_6_15;
		int sub_8_15_flag;
  		ros::Subscriber sub_8_15;
		int sub_9_15_flag;
  		ros::Subscriber sub_9_15;
		int sub_11_15_flag;
  		ros::Subscriber sub_11_15;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node15");
  	Node15 node15;
  	ros::spin();
  	return 0;
  }

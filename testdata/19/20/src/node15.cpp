
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.028846, 0.005);
  class Node15{
  	public:
  		Node15(){
			sub_2_15_flag = 0;
  			sub_2_15 = n.subscribe("topic_2_15", 1, &Node15::middlemanCallback2,this);
			sub_5_15_flag = 0;
  			sub_5_15 = n.subscribe("topic_5_15", 1, &Node15::middlemanCallback5,this);
			sub_9_15_flag = 0;
  			sub_9_15 = n.subscribe("topic_9_15", 1, &Node15::middlemanCallback9,this);
			sub_13_15_flag = 0;
  			sub_13_15 = n.subscribe("topic_13_15", 1, &Node15::middlemanCallback13,this);
			pub_15_18 = n.advertise<std_msgs::String>("topic_15_18", 1);
		}
		void middlemanCallback2(const std_msgs::String::ConstPtr& msg){
  			if(sub_5_15_flag == 1 && sub_9_15_flag == 1 && sub_13_15_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node15 last from node2, intercepted: [%s]", msg->data.c_str());
				pub_15_18.publish(msg);
				sub_5_15_flag = 0;
				sub_9_15_flag = 0;
				sub_13_15_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node15, from node2 intercepted: [%s]", msg->data.c_str());
  				sub_2_15_flag = 1;
  			}
  		}
		void middlemanCallback5(const std_msgs::String::ConstPtr& msg){
  			if(sub_2_15_flag == 1 && sub_9_15_flag == 1 && sub_13_15_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node15 last from node5, intercepted: [%s]", msg->data.c_str());
				pub_15_18.publish(msg);
				sub_2_15_flag = 0;
				sub_9_15_flag = 0;
				sub_13_15_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node15, from node5 intercepted: [%s]", msg->data.c_str());
  				sub_5_15_flag = 1;
  			}
  		}
		void middlemanCallback9(const std_msgs::String::ConstPtr& msg){
  			if(sub_2_15_flag == 1 && sub_5_15_flag == 1 && sub_13_15_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node15 last from node9, intercepted: [%s]", msg->data.c_str());
				pub_15_18.publish(msg);
				sub_2_15_flag = 0;
				sub_5_15_flag = 0;
				sub_13_15_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node15, from node9 intercepted: [%s]", msg->data.c_str());
  				sub_9_15_flag = 1;
  			}
  		}
		void middlemanCallback13(const std_msgs::String::ConstPtr& msg){
  			if(sub_2_15_flag == 1 && sub_5_15_flag == 1 && sub_9_15_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node15 last from node13, intercepted: [%s]", msg->data.c_str());
				pub_15_18.publish(msg);
				sub_2_15_flag = 0;
				sub_5_15_flag = 0;
				sub_9_15_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node15, from node13 intercepted: [%s]", msg->data.c_str());
  				sub_13_15_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_15_18;
		int sub_2_15_flag;
  		ros::Subscriber sub_2_15;
		int sub_5_15_flag;
  		ros::Subscriber sub_5_15;
		int sub_9_15_flag;
  		ros::Subscriber sub_9_15;
		int sub_13_15_flag;
  		ros::Subscriber sub_13_15;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node15");
  	Node15 node15;
  	ros::spin();
  	return 0;
  }

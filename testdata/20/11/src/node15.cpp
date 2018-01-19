
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.019149, 0.005);
  class Node15{
  	public:
  		Node15(){
			sub_5_15_flag = 0;
  			sub_5_15 = n.subscribe("topic_5_15", 1, &Node15::middlemanCallback5,this);
			sub_7_15_flag = 0;
  			sub_7_15 = n.subscribe("topic_7_15", 1, &Node15::middlemanCallback7,this);
			sub_11_15_flag = 0;
  			sub_11_15 = n.subscribe("topic_11_15", 1, &Node15::middlemanCallback11,this);
			sub_14_15_flag = 0;
  			sub_14_15 = n.subscribe("topic_14_15", 1, &Node15::middlemanCallback14,this);
			pub_15_18 = n.advertise<std_msgs::String>("topic_15_18", 1);
			pub_15_17 = n.advertise<std_msgs::String>("topic_15_17", 1);
			pub_15_16 = n.advertise<std_msgs::String>("topic_15_16", 1);
		}
		void middlemanCallback5(const std_msgs::String::ConstPtr& msg){
  			if(sub_7_15_flag == 1 && sub_11_15_flag == 1 && sub_14_15_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node15 last from node5, intercepted: [%s]", msg->data.c_str());
				pub_15_18.publish(msg);
				pub_15_17.publish(msg);
				pub_15_16.publish(msg);
				sub_7_15_flag = 0;
				sub_11_15_flag = 0;
				sub_14_15_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node15, from node5 intercepted: [%s]", msg->data.c_str());
  				sub_5_15_flag = 1;
  			}
  		}
		void middlemanCallback7(const std_msgs::String::ConstPtr& msg){
  			if(sub_5_15_flag == 1 && sub_11_15_flag == 1 && sub_14_15_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node15 last from node7, intercepted: [%s]", msg->data.c_str());
				pub_15_18.publish(msg);
				pub_15_17.publish(msg);
				pub_15_16.publish(msg);
				sub_5_15_flag = 0;
				sub_11_15_flag = 0;
				sub_14_15_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node15, from node7 intercepted: [%s]", msg->data.c_str());
  				sub_7_15_flag = 1;
  			}
  		}
		void middlemanCallback11(const std_msgs::String::ConstPtr& msg){
  			if(sub_5_15_flag == 1 && sub_7_15_flag == 1 && sub_14_15_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node15 last from node11, intercepted: [%s]", msg->data.c_str());
				pub_15_18.publish(msg);
				pub_15_17.publish(msg);
				pub_15_16.publish(msg);
				sub_5_15_flag = 0;
				sub_7_15_flag = 0;
				sub_14_15_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node15, from node11 intercepted: [%s]", msg->data.c_str());
  				sub_11_15_flag = 1;
  			}
  		}
		void middlemanCallback14(const std_msgs::String::ConstPtr& msg){
  			if(sub_5_15_flag == 1 && sub_7_15_flag == 1 && sub_11_15_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node15 last from node14, intercepted: [%s]", msg->data.c_str());
				pub_15_18.publish(msg);
				pub_15_17.publish(msg);
				pub_15_16.publish(msg);
				sub_5_15_flag = 0;
				sub_7_15_flag = 0;
				sub_11_15_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node15, from node14 intercepted: [%s]", msg->data.c_str());
  				sub_14_15_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_15_18;
		ros::Publisher pub_15_17;
		ros::Publisher pub_15_16;
		int sub_5_15_flag;
  		ros::Subscriber sub_5_15;
		int sub_7_15_flag;
  		ros::Subscriber sub_7_15;
		int sub_11_15_flag;
  		ros::Subscriber sub_11_15;
		int sub_14_15_flag;
  		ros::Subscriber sub_14_15;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node15");
  	Node15 node15;
  	ros::spin();
  	return 0;
  }

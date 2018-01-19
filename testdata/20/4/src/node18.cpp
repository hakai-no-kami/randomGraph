
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.011635, 0.005);
  class Node18{
  	public:
  		Node18(){
			sub_6_18_flag = 0;
  			sub_6_18 = n.subscribe("topic_6_18", 1, &Node18::middlemanCallback6,this);
			sub_10_18_flag = 0;
  			sub_10_18 = n.subscribe("topic_10_18", 1, &Node18::middlemanCallback10,this);
			sub_16_18_flag = 0;
  			sub_16_18 = n.subscribe("topic_16_18", 1, &Node18::middlemanCallback16,this);
			sub_17_18_flag = 0;
  			sub_17_18 = n.subscribe("topic_17_18", 1, &Node18::middlemanCallback17,this);
			pub_18_20 = n.advertise<std_msgs::String>("topic_18_20", 1);
		}
		void middlemanCallback6(const std_msgs::String::ConstPtr& msg){
  			if(sub_10_18_flag == 1 && sub_16_18_flag == 1 && sub_17_18_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node18 last from node6, intercepted: [%s]", msg->data.c_str());
				pub_18_20.publish(msg);
				sub_10_18_flag = 0;
				sub_16_18_flag = 0;
				sub_17_18_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node18, from node6 intercepted: [%s]", msg->data.c_str());
  				sub_6_18_flag = 1;
  			}
  		}
		void middlemanCallback10(const std_msgs::String::ConstPtr& msg){
  			if(sub_6_18_flag == 1 && sub_16_18_flag == 1 && sub_17_18_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node18 last from node10, intercepted: [%s]", msg->data.c_str());
				pub_18_20.publish(msg);
				sub_6_18_flag = 0;
				sub_16_18_flag = 0;
				sub_17_18_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node18, from node10 intercepted: [%s]", msg->data.c_str());
  				sub_10_18_flag = 1;
  			}
  		}
		void middlemanCallback16(const std_msgs::String::ConstPtr& msg){
  			if(sub_6_18_flag == 1 && sub_10_18_flag == 1 && sub_17_18_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node18 last from node16, intercepted: [%s]", msg->data.c_str());
				pub_18_20.publish(msg);
				sub_6_18_flag = 0;
				sub_10_18_flag = 0;
				sub_17_18_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node18, from node16 intercepted: [%s]", msg->data.c_str());
  				sub_16_18_flag = 1;
  			}
  		}
		void middlemanCallback17(const std_msgs::String::ConstPtr& msg){
  			if(sub_6_18_flag == 1 && sub_10_18_flag == 1 && sub_16_18_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node18 last from node17, intercepted: [%s]", msg->data.c_str());
				pub_18_20.publish(msg);
				sub_6_18_flag = 0;
				sub_10_18_flag = 0;
				sub_16_18_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node18, from node17 intercepted: [%s]", msg->data.c_str());
  				sub_17_18_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_18_20;
		int sub_6_18_flag;
  		ros::Subscriber sub_6_18;
		int sub_10_18_flag;
  		ros::Subscriber sub_10_18;
		int sub_16_18_flag;
  		ros::Subscriber sub_16_18;
		int sub_17_18_flag;
  		ros::Subscriber sub_17_18;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node18");
  	Node18 node18;
  	ros::spin();
  	return 0;
  }

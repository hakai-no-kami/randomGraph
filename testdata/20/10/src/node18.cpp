
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.015103, 0.005);
  class Node18{
  	public:
  		Node18(){
			sub_1_18_flag = 0;
  			sub_1_18 = n.subscribe("topic_1_18", 1, &Node18::middlemanCallback1,this);
			sub_15_18_flag = 0;
  			sub_15_18 = n.subscribe("topic_15_18", 1, &Node18::middlemanCallback15,this);
			sub_16_18_flag = 0;
  			sub_16_18 = n.subscribe("topic_16_18", 1, &Node18::middlemanCallback16,this);
			pub_18_19 = n.advertise<std_msgs::String>("topic_18_19", 1);
		}
		void middlemanCallback1(const std_msgs::String::ConstPtr& msg){
  			if(sub_15_18_flag == 1 && sub_16_18_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node18 last from node1, intercepted: [%s]", msg->data.c_str());
				pub_18_19.publish(msg);
				sub_15_18_flag = 0;
				sub_16_18_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node18, from node1 intercepted: [%s]", msg->data.c_str());
  				sub_1_18_flag = 1;
  			}
  		}
		void middlemanCallback15(const std_msgs::String::ConstPtr& msg){
  			if(sub_1_18_flag == 1 && sub_16_18_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node18 last from node15, intercepted: [%s]", msg->data.c_str());
				pub_18_19.publish(msg);
				sub_1_18_flag = 0;
				sub_16_18_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node18, from node15 intercepted: [%s]", msg->data.c_str());
  				sub_15_18_flag = 1;
  			}
  		}
		void middlemanCallback16(const std_msgs::String::ConstPtr& msg){
  			if(sub_1_18_flag == 1 && sub_15_18_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node18 last from node16, intercepted: [%s]", msg->data.c_str());
				pub_18_19.publish(msg);
				sub_1_18_flag = 0;
				sub_15_18_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node18, from node16 intercepted: [%s]", msg->data.c_str());
  				sub_16_18_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_18_19;
		int sub_1_18_flag;
  		ros::Subscriber sub_1_18;
		int sub_15_18_flag;
  		ros::Subscriber sub_15_18;
		int sub_16_18_flag;
  		ros::Subscriber sub_16_18;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node18");
  	Node18 node18;
  	ros::spin();
  	return 0;
  }

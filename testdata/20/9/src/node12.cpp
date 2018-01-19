
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.011050, 0.005);
  class Node12{
  	public:
  		Node12(){
			sub_2_12_flag = 0;
  			sub_2_12 = n.subscribe("topic_2_12", 1, &Node12::middlemanCallback2,this);
			sub_8_12_flag = 0;
  			sub_8_12 = n.subscribe("topic_8_12", 1, &Node12::middlemanCallback8,this);
			sub_10_12_flag = 0;
  			sub_10_12 = n.subscribe("topic_10_12", 1, &Node12::middlemanCallback10,this);
			pub_12_19 = n.advertise<std_msgs::String>("topic_12_19", 1);
			pub_12_18 = n.advertise<std_msgs::String>("topic_12_18", 1);
		}
		void middlemanCallback2(const std_msgs::String::ConstPtr& msg){
  			if(sub_8_12_flag == 1 && sub_10_12_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node12 last from node2, intercepted: [%s]", msg->data.c_str());
				pub_12_19.publish(msg);
				pub_12_18.publish(msg);
				sub_8_12_flag = 0;
				sub_10_12_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node12, from node2 intercepted: [%s]", msg->data.c_str());
  				sub_2_12_flag = 1;
  			}
  		}
		void middlemanCallback8(const std_msgs::String::ConstPtr& msg){
  			if(sub_2_12_flag == 1 && sub_10_12_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node12 last from node8, intercepted: [%s]", msg->data.c_str());
				pub_12_19.publish(msg);
				pub_12_18.publish(msg);
				sub_2_12_flag = 0;
				sub_10_12_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node12, from node8 intercepted: [%s]", msg->data.c_str());
  				sub_8_12_flag = 1;
  			}
  		}
		void middlemanCallback10(const std_msgs::String::ConstPtr& msg){
  			if(sub_2_12_flag == 1 && sub_8_12_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node12 last from node10, intercepted: [%s]", msg->data.c_str());
				pub_12_19.publish(msg);
				pub_12_18.publish(msg);
				sub_2_12_flag = 0;
				sub_8_12_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node12, from node10 intercepted: [%s]", msg->data.c_str());
  				sub_10_12_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_12_19;
		ros::Publisher pub_12_18;
		int sub_2_12_flag;
  		ros::Subscriber sub_2_12;
		int sub_8_12_flag;
  		ros::Subscriber sub_8_12;
		int sub_10_12_flag;
  		ros::Subscriber sub_10_12;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node12");
  	Node12 node12;
  	ros::spin();
  	return 0;
  }

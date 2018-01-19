
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.024645, 0.005);
  class Node14{
  	public:
  		Node14(){
			sub_6_14_flag = 0;
  			sub_6_14 = n.subscribe("topic_6_14", 1, &Node14::middlemanCallback6,this);
			sub_10_14_flag = 0;
  			sub_10_14 = n.subscribe("topic_10_14", 1, &Node14::middlemanCallback10,this);
			sub_12_14_flag = 0;
  			sub_12_14 = n.subscribe("topic_12_14", 1, &Node14::middlemanCallback12,this);
			pub_14_17 = n.advertise<std_msgs::String>("topic_14_17", 1);
			pub_14_16 = n.advertise<std_msgs::String>("topic_14_16", 1);
		}
		void middlemanCallback6(const std_msgs::String::ConstPtr& msg){
  			if(sub_10_14_flag == 1 && sub_12_14_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node14 last from node6, intercepted: [%s]", msg->data.c_str());
				pub_14_17.publish(msg);
				pub_14_16.publish(msg);
				sub_10_14_flag = 0;
				sub_12_14_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node14, from node6 intercepted: [%s]", msg->data.c_str());
  				sub_6_14_flag = 1;
  			}
  		}
		void middlemanCallback10(const std_msgs::String::ConstPtr& msg){
  			if(sub_6_14_flag == 1 && sub_12_14_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node14 last from node10, intercepted: [%s]", msg->data.c_str());
				pub_14_17.publish(msg);
				pub_14_16.publish(msg);
				sub_6_14_flag = 0;
				sub_12_14_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node14, from node10 intercepted: [%s]", msg->data.c_str());
  				sub_10_14_flag = 1;
  			}
  		}
		void middlemanCallback12(const std_msgs::String::ConstPtr& msg){
  			if(sub_6_14_flag == 1 && sub_10_14_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node14 last from node12, intercepted: [%s]", msg->data.c_str());
				pub_14_17.publish(msg);
				pub_14_16.publish(msg);
				sub_6_14_flag = 0;
				sub_10_14_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node14, from node12 intercepted: [%s]", msg->data.c_str());
  				sub_12_14_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_14_17;
		ros::Publisher pub_14_16;
		int sub_6_14_flag;
  		ros::Subscriber sub_6_14;
		int sub_10_14_flag;
  		ros::Subscriber sub_10_14;
		int sub_12_14_flag;
  		ros::Subscriber sub_12_14;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node14");
  	Node14 node14;
  	ros::spin();
  	return 0;
  }

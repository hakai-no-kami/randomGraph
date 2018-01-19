
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.027687, 0.005);
  class Node13{
  	public:
  		Node13(){
			sub_6_13_flag = 0;
  			sub_6_13 = n.subscribe("topic_6_13", 1, &Node13::middlemanCallback6,this);
			sub_8_13_flag = 0;
  			sub_8_13 = n.subscribe("topic_8_13", 1, &Node13::middlemanCallback8,this);
			sub_9_13_flag = 0;
  			sub_9_13 = n.subscribe("topic_9_13", 1, &Node13::middlemanCallback9,this);
			pub_13_19 = n.advertise<std_msgs::String>("topic_13_19", 1);
			pub_13_17 = n.advertise<std_msgs::String>("topic_13_17", 1);
		}
		void middlemanCallback6(const std_msgs::String::ConstPtr& msg){
  			if(sub_8_13_flag == 1 && sub_9_13_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node13 last from node6, intercepted: [%s]", msg->data.c_str());
				pub_13_19.publish(msg);
				pub_13_17.publish(msg);
				sub_8_13_flag = 0;
				sub_9_13_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node13, from node6 intercepted: [%s]", msg->data.c_str());
  				sub_6_13_flag = 1;
  			}
  		}
		void middlemanCallback8(const std_msgs::String::ConstPtr& msg){
  			if(sub_6_13_flag == 1 && sub_9_13_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node13 last from node8, intercepted: [%s]", msg->data.c_str());
				pub_13_19.publish(msg);
				pub_13_17.publish(msg);
				sub_6_13_flag = 0;
				sub_9_13_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node13, from node8 intercepted: [%s]", msg->data.c_str());
  				sub_8_13_flag = 1;
  			}
  		}
		void middlemanCallback9(const std_msgs::String::ConstPtr& msg){
  			if(sub_6_13_flag == 1 && sub_8_13_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node13 last from node9, intercepted: [%s]", msg->data.c_str());
				pub_13_19.publish(msg);
				pub_13_17.publish(msg);
				sub_6_13_flag = 0;
				sub_8_13_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node13, from node9 intercepted: [%s]", msg->data.c_str());
  				sub_9_13_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_13_19;
		ros::Publisher pub_13_17;
		int sub_6_13_flag;
  		ros::Subscriber sub_6_13;
		int sub_8_13_flag;
  		ros::Subscriber sub_8_13;
		int sub_9_13_flag;
  		ros::Subscriber sub_9_13;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node13");
  	Node13 node13;
  	ros::spin();
  	return 0;
  }

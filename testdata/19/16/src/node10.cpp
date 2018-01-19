
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.011012, 0.005);
  class Node10{
  	public:
  		Node10(){
			sub_4_10_flag = 0;
  			sub_4_10 = n.subscribe("topic_4_10", 1, &Node10::middlemanCallback4,this);
			sub_6_10_flag = 0;
  			sub_6_10 = n.subscribe("topic_6_10", 1, &Node10::middlemanCallback6,this);
			sub_9_10_flag = 0;
  			sub_9_10 = n.subscribe("topic_9_10", 1, &Node10::middlemanCallback9,this);
			pub_10_15 = n.advertise<std_msgs::String>("topic_10_15", 1);
		}
		void middlemanCallback4(const std_msgs::String::ConstPtr& msg){
  			if(sub_6_10_flag == 1 && sub_9_10_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node10 last from node4, intercepted: [%s]", msg->data.c_str());
				pub_10_15.publish(msg);
				sub_6_10_flag = 0;
				sub_9_10_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node10, from node4 intercepted: [%s]", msg->data.c_str());
  				sub_4_10_flag = 1;
  			}
  		}
		void middlemanCallback6(const std_msgs::String::ConstPtr& msg){
  			if(sub_4_10_flag == 1 && sub_9_10_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node10 last from node6, intercepted: [%s]", msg->data.c_str());
				pub_10_15.publish(msg);
				sub_4_10_flag = 0;
				sub_9_10_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node10, from node6 intercepted: [%s]", msg->data.c_str());
  				sub_6_10_flag = 1;
  			}
  		}
		void middlemanCallback9(const std_msgs::String::ConstPtr& msg){
  			if(sub_4_10_flag == 1 && sub_6_10_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node10 last from node9, intercepted: [%s]", msg->data.c_str());
				pub_10_15.publish(msg);
				sub_4_10_flag = 0;
				sub_6_10_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node10, from node9 intercepted: [%s]", msg->data.c_str());
  				sub_9_10_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_10_15;
		int sub_4_10_flag;
  		ros::Subscriber sub_4_10;
		int sub_6_10_flag;
  		ros::Subscriber sub_6_10;
		int sub_9_10_flag;
  		ros::Subscriber sub_9_10;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node10");
  	Node10 node10;
  	ros::spin();
  	return 0;
  }

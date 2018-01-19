
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.014529, 0.005);
  class Node15{
  	public:
  		Node15(){
			sub_4_15_flag = 0;
  			sub_4_15 = n.subscribe("topic_4_15", 1, &Node15::middlemanCallback4,this);
			sub_13_15_flag = 0;
  			sub_13_15 = n.subscribe("topic_13_15", 1, &Node15::middlemanCallback13,this);
			pub_15_16 = n.advertise<std_msgs::String>("topic_15_16", 1);
		}
		void middlemanCallback4(const std_msgs::String::ConstPtr& msg){
  			if(sub_13_15_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node15 last from node4, intercepted: [%s]", msg->data.c_str());
				pub_15_16.publish(msg);
				sub_13_15_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node15, from node4 intercepted: [%s]", msg->data.c_str());
  				sub_4_15_flag = 1;
  			}
  		}
		void middlemanCallback13(const std_msgs::String::ConstPtr& msg){
  			if(sub_4_15_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node15 last from node13, intercepted: [%s]", msg->data.c_str());
				pub_15_16.publish(msg);
				sub_4_15_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node15, from node13 intercepted: [%s]", msg->data.c_str());
  				sub_13_15_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_15_16;
		int sub_4_15_flag;
  		ros::Subscriber sub_4_15;
		int sub_13_15_flag;
  		ros::Subscriber sub_13_15;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node15");
  	Node15 node15;
  	ros::spin();
  	return 0;
  }

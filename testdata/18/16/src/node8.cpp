
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.019017, 0.005);
  class Node8{
  	public:
  		Node8(){
			sub_2_8_flag = 0;
  			sub_2_8 = n.subscribe("topic_2_8", 1, &Node8::middlemanCallback2,this);
			sub_6_8_flag = 0;
  			sub_6_8 = n.subscribe("topic_6_8", 1, &Node8::middlemanCallback6,this);
			pub_8_13 = n.advertise<std_msgs::String>("topic_8_13", 1);
			pub_8_12 = n.advertise<std_msgs::String>("topic_8_12", 1);
			pub_8_10 = n.advertise<std_msgs::String>("topic_8_10", 1);
		}
		void middlemanCallback2(const std_msgs::String::ConstPtr& msg){
  			if(sub_6_8_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node8 last from node2, intercepted: [%s]", msg->data.c_str());
				pub_8_13.publish(msg);
				pub_8_12.publish(msg);
				pub_8_10.publish(msg);
				sub_6_8_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node8, from node2 intercepted: [%s]", msg->data.c_str());
  				sub_2_8_flag = 1;
  			}
  		}
		void middlemanCallback6(const std_msgs::String::ConstPtr& msg){
  			if(sub_2_8_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node8 last from node6, intercepted: [%s]", msg->data.c_str());
				pub_8_13.publish(msg);
				pub_8_12.publish(msg);
				pub_8_10.publish(msg);
				sub_2_8_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node8, from node6 intercepted: [%s]", msg->data.c_str());
  				sub_6_8_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_8_13;
		ros::Publisher pub_8_12;
		ros::Publisher pub_8_10;
		int sub_2_8_flag;
  		ros::Subscriber sub_2_8;
		int sub_6_8_flag;
  		ros::Subscriber sub_6_8;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node8");
  	Node8 node8;
  	ros::spin();
  	return 0;
  }

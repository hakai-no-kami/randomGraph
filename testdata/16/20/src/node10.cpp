
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.027152, 0.005);
  class Node10{
  	public:
  		Node10(){
			sub_2_10_flag = 0;
  			sub_2_10 = n.subscribe("topic_2_10", 1, &Node10::middlemanCallback2,this);
			sub_8_10_flag = 0;
  			sub_8_10 = n.subscribe("topic_8_10", 1, &Node10::middlemanCallback8,this);
			pub_10_12 = n.advertise<std_msgs::String>("topic_10_12", 1);
		}
		void middlemanCallback2(const std_msgs::String::ConstPtr& msg){
  			if(sub_8_10_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node10 last from node2, intercepted: [%s]", msg->data.c_str());
				pub_10_12.publish(msg);
				sub_8_10_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node10, from node2 intercepted: [%s]", msg->data.c_str());
  				sub_2_10_flag = 1;
  			}
  		}
		void middlemanCallback8(const std_msgs::String::ConstPtr& msg){
  			if(sub_2_10_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node10 last from node8, intercepted: [%s]", msg->data.c_str());
				pub_10_12.publish(msg);
				sub_2_10_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node10, from node8 intercepted: [%s]", msg->data.c_str());
  				sub_8_10_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_10_12;
		int sub_2_10_flag;
  		ros::Subscriber sub_2_10;
		int sub_8_10_flag;
  		ros::Subscriber sub_8_10;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node10");
  	Node10 node10;
  	ros::spin();
  	return 0;
  }

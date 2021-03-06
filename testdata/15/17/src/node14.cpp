
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.026479, 0.005);
  class Node14{
  	public:
  		Node14(){
			sub_11_14_flag = 0;
  			sub_11_14 = n.subscribe("topic_11_14", 1, &Node14::middlemanCallback11,this);
			sub_13_14_flag = 0;
  			sub_13_14 = n.subscribe("topic_13_14", 1, &Node14::middlemanCallback13,this);
			pub_14_15 = n.advertise<std_msgs::String>("topic_14_15", 1);
		}
		void middlemanCallback11(const std_msgs::String::ConstPtr& msg){
  			if(sub_13_14_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node14 last from node11, intercepted: [%s]", msg->data.c_str());
				pub_14_15.publish(msg);
				sub_13_14_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node14, from node11 intercepted: [%s]", msg->data.c_str());
  				sub_11_14_flag = 1;
  			}
  		}
		void middlemanCallback13(const std_msgs::String::ConstPtr& msg){
  			if(sub_11_14_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node14 last from node13, intercepted: [%s]", msg->data.c_str());
				pub_14_15.publish(msg);
				sub_11_14_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node14, from node13 intercepted: [%s]", msg->data.c_str());
  				sub_13_14_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_14_15;
		int sub_11_14_flag;
  		ros::Subscriber sub_11_14;
		int sub_13_14_flag;
  		ros::Subscriber sub_13_14;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node14");
  	Node14 node14;
  	ros::spin();
  	return 0;
  }

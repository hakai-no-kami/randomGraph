
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.027262, 0.005);
  class Node14{
  	public:
  		Node14(){
			sub_5_14_flag = 0;
  			sub_5_14 = n.subscribe("topic_5_14", 1, &Node14::middlemanCallback5,this);
			sub_12_14_flag = 0;
  			sub_12_14 = n.subscribe("topic_12_14", 1, &Node14::middlemanCallback12,this);
			pub_14_15 = n.advertise<std_msgs::String>("topic_14_15", 1);
		}
		void middlemanCallback5(const std_msgs::String::ConstPtr& msg){
  			if(sub_12_14_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node14 last from node5, intercepted: [%s]", msg->data.c_str());
				pub_14_15.publish(msg);
				sub_12_14_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node14, from node5 intercepted: [%s]", msg->data.c_str());
  				sub_5_14_flag = 1;
  			}
  		}
		void middlemanCallback12(const std_msgs::String::ConstPtr& msg){
  			if(sub_5_14_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node14 last from node12, intercepted: [%s]", msg->data.c_str());
				pub_14_15.publish(msg);
				sub_5_14_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node14, from node12 intercepted: [%s]", msg->data.c_str());
  				sub_12_14_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_14_15;
		int sub_5_14_flag;
  		ros::Subscriber sub_5_14;
		int sub_12_14_flag;
  		ros::Subscriber sub_12_14;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node14");
  	Node14 node14;
  	ros::spin();
  	return 0;
  }


  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.022963, 0.005);
  class Node3{
  	public:
  		Node3(){
			sub_1_3_flag = 0;
  			sub_1_3 = n.subscribe("topic_1_3", 1, &Node3::middlemanCallback1,this);
			pub_3_5 = n.advertise<std_msgs::String>("topic_3_5", 1);
			pub_3_4 = n.advertise<std_msgs::String>("topic_3_4", 1);
		}
		void middlemanCallback1(const std_msgs::String::ConstPtr& msg){
  			if( true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node3 last from node1, intercepted: [%s]", msg->data.c_str());
				pub_3_5.publish(msg);
				pub_3_4.publish(msg);
			}
  			else{
  				ROS_INFO("I'm node3, from node1 intercepted: [%s]", msg->data.c_str());
  				sub_1_3_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_3_5;
		ros::Publisher pub_3_4;
		int sub_1_3_flag;
  		ros::Subscriber sub_1_3;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node3");
  	Node3 node3;
  	ros::spin();
  	return 0;
  }

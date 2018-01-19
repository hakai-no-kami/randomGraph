
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.018695, 0.005);
  class Node3{
  	public:
  		Node3(){
			sub_0_3_flag = 0;
  			sub_0_3 = n.subscribe("topic_0_3", 1, &Node3::middlemanCallback0,this);
			pub_3_9 = n.advertise<std_msgs::String>("topic_3_9", 1);
			pub_3_6 = n.advertise<std_msgs::String>("topic_3_6", 1);
		}
		void middlemanCallback0(const std_msgs::String::ConstPtr& msg){
  			if( true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node3 last from node0, intercepted: [%s]", msg->data.c_str());
				pub_3_9.publish(msg);
				pub_3_6.publish(msg);
			}
  			else{
  				ROS_INFO("I'm node3, from node0 intercepted: [%s]", msg->data.c_str());
  				sub_0_3_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_3_9;
		ros::Publisher pub_3_6;
		int sub_0_3_flag;
  		ros::Subscriber sub_0_3;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node3");
  	Node3 node3;
  	ros::spin();
  	return 0;
  }


  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.028174, 0.005);
  class Node4{
  	public:
  		Node4(){
			sub_1_4_flag = 0;
  			sub_1_4 = n.subscribe("topic_1_4", 1, &Node4::middlemanCallback1,this);
			pub_4_10 = n.advertise<std_msgs::String>("topic_4_10", 1);
			pub_4_7 = n.advertise<std_msgs::String>("topic_4_7", 1);
			pub_4_6 = n.advertise<std_msgs::String>("topic_4_6", 1);
		}
		void middlemanCallback1(const std_msgs::String::ConstPtr& msg){
  			if( true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node4 last from node1, intercepted: [%s]", msg->data.c_str());
				pub_4_10.publish(msg);
				pub_4_7.publish(msg);
				pub_4_6.publish(msg);
			}
  			else{
  				ROS_INFO("I'm node4, from node1 intercepted: [%s]", msg->data.c_str());
  				sub_1_4_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_4_10;
		ros::Publisher pub_4_7;
		ros::Publisher pub_4_6;
		int sub_1_4_flag;
  		ros::Subscriber sub_1_4;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node4");
  	Node4 node4;
  	ros::spin();
  	return 0;
  }

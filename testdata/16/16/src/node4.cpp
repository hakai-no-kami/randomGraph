
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.015663, 0.005);
  class Node4{
  	public:
  		Node4(){
			sub_0_4_flag = 0;
  			sub_0_4 = n.subscribe("topic_0_4", 1, &Node4::middlemanCallback0,this);
			pub_4_9 = n.advertise<std_msgs::String>("topic_4_9", 1);
			pub_4_7 = n.advertise<std_msgs::String>("topic_4_7", 1);
			pub_4_5 = n.advertise<std_msgs::String>("topic_4_5", 1);
		}
		void middlemanCallback0(const std_msgs::String::ConstPtr& msg){
  			if( true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node4 last from node0, intercepted: [%s]", msg->data.c_str());
				pub_4_9.publish(msg);
				pub_4_7.publish(msg);
				pub_4_5.publish(msg);
			}
  			else{
  				ROS_INFO("I'm node4, from node0 intercepted: [%s]", msg->data.c_str());
  				sub_0_4_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_4_9;
		ros::Publisher pub_4_7;
		ros::Publisher pub_4_5;
		int sub_0_4_flag;
  		ros::Subscriber sub_0_4;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node4");
  	Node4 node4;
  	ros::spin();
  	return 0;
  }

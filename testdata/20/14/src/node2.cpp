
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.020190, 0.005);
  class Node2{
  	public:
  		Node2(){
			sub_0_2_flag = 0;
  			sub_0_2 = n.subscribe("topic_0_2", 1, &Node2::middlemanCallback0,this);
			pub_2_8 = n.advertise<std_msgs::String>("topic_2_8", 1);
			pub_2_4 = n.advertise<std_msgs::String>("topic_2_4", 1);
			pub_2_3 = n.advertise<std_msgs::String>("topic_2_3", 1);
		}
		void middlemanCallback0(const std_msgs::String::ConstPtr& msg){
  			if( true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node2 last from node0, intercepted: [%s]", msg->data.c_str());
				pub_2_8.publish(msg);
				pub_2_4.publish(msg);
				pub_2_3.publish(msg);
			}
  			else{
  				ROS_INFO("I'm node2, from node0 intercepted: [%s]", msg->data.c_str());
  				sub_0_2_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_2_8;
		ros::Publisher pub_2_4;
		ros::Publisher pub_2_3;
		int sub_0_2_flag;
  		ros::Subscriber sub_0_2;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node2");
  	Node2 node2;
  	ros::spin();
  	return 0;
  }

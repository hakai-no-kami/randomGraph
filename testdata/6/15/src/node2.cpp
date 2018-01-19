
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.028395, 0.005);
  class Node2{
  	public:
  		Node2(){
			sub_1_2_flag = 0;
  			sub_1_2 = n.subscribe("topic_1_2", 1, &Node2::middlemanCallback1,this);
			pub_2_5 = n.advertise<std_msgs::String>("topic_2_5", 1);
			pub_2_4 = n.advertise<std_msgs::String>("topic_2_4", 1);
		}
		void middlemanCallback1(const std_msgs::String::ConstPtr& msg){
  			if( true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node2 last from node1, intercepted: [%s]", msg->data.c_str());
				pub_2_5.publish(msg);
				pub_2_4.publish(msg);
			}
  			else{
  				ROS_INFO("I'm node2, from node1 intercepted: [%s]", msg->data.c_str());
  				sub_1_2_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_2_5;
		ros::Publisher pub_2_4;
		int sub_1_2_flag;
  		ros::Subscriber sub_1_2;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node2");
  	Node2 node2;
  	ros::spin();
  	return 0;
  }


  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.024441, 0.005);
  class Node5{
  	public:
  		Node5(){
			sub_3_5_flag = 0;
  			sub_3_5 = n.subscribe("topic_3_5", 1, &Node5::middlemanCallback3,this);
			pub_5_11 = n.advertise<std_msgs::String>("topic_5_11", 1);
			pub_5_8 = n.advertise<std_msgs::String>("topic_5_8", 1);
		}
		void middlemanCallback3(const std_msgs::String::ConstPtr& msg){
  			if( true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node5 last from node3, intercepted: [%s]", msg->data.c_str());
				pub_5_11.publish(msg);
				pub_5_8.publish(msg);
			}
  			else{
  				ROS_INFO("I'm node5, from node3 intercepted: [%s]", msg->data.c_str());
  				sub_3_5_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_5_11;
		ros::Publisher pub_5_8;
		int sub_3_5_flag;
  		ros::Subscriber sub_3_5;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node5");
  	Node5 node5;
  	ros::spin();
  	return 0;
  }

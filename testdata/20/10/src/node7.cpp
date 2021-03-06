
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.022444, 0.005);
  class Node7{
  	public:
  		Node7(){
			sub_5_7_flag = 0;
  			sub_5_7 = n.subscribe("topic_5_7", 1, &Node7::middlemanCallback5,this);
			pub_7_13 = n.advertise<std_msgs::String>("topic_7_13", 1);
			pub_7_12 = n.advertise<std_msgs::String>("topic_7_12", 1);
			pub_7_10 = n.advertise<std_msgs::String>("topic_7_10", 1);
		}
		void middlemanCallback5(const std_msgs::String::ConstPtr& msg){
  			if( true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node7 last from node5, intercepted: [%s]", msg->data.c_str());
				pub_7_13.publish(msg);
				pub_7_12.publish(msg);
				pub_7_10.publish(msg);
			}
  			else{
  				ROS_INFO("I'm node7, from node5 intercepted: [%s]", msg->data.c_str());
  				sub_5_7_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_7_13;
		ros::Publisher pub_7_12;
		ros::Publisher pub_7_10;
		int sub_5_7_flag;
  		ros::Subscriber sub_5_7;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node7");
  	Node7 node7;
  	ros::spin();
  	return 0;
  }

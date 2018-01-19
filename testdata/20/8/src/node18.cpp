
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.029144, 0.005);
  class Node18{
  	public:
  		Node18(){
			sub_13_18_flag = 0;
  			sub_13_18 = n.subscribe("topic_13_18", 1, &Node18::middlemanCallback13,this);
			pub_18_20 = n.advertise<std_msgs::String>("topic_18_20", 1);
		}
		void middlemanCallback13(const std_msgs::String::ConstPtr& msg){
  			if( true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node18 last from node13, intercepted: [%s]", msg->data.c_str());
				pub_18_20.publish(msg);
			}
  			else{
  				ROS_INFO("I'm node18, from node13 intercepted: [%s]", msg->data.c_str());
  				sub_13_18_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_18_20;
		int sub_13_18_flag;
  		ros::Subscriber sub_13_18;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node18");
  	Node18 node18;
  	ros::spin();
  	return 0;
  }


  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.018977, 0.005);
  class Node18{
  	public:
  		Node18(){
			sub_0_18_flag = 0;
  			sub_0_18 = n.subscribe("topic_0_18", 1, &Node18::middlemanCallback0,this);
			pub_18_19 = n.advertise<std_msgs::String>("topic_18_19", 1);
		}
		void middlemanCallback0(const std_msgs::String::ConstPtr& msg){
  			if( true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node18 last from node0, intercepted: [%s]", msg->data.c_str());
				pub_18_19.publish(msg);
			}
  			else{
  				ROS_INFO("I'm node18, from node0 intercepted: [%s]", msg->data.c_str());
  				sub_0_18_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_18_19;
		int sub_0_18_flag;
  		ros::Subscriber sub_0_18;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node18");
  	Node18 node18;
  	ros::spin();
  	return 0;
  }

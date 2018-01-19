
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.017081, 0.005);
  class Node6{
  	public:
  		Node6(){
			sub_0_6_flag = 0;
  			sub_0_6 = n.subscribe("topic_0_6", 1, &Node6::middlemanCallback0,this);
			pub_6_7 = n.advertise<std_msgs::String>("topic_6_7", 1);
		}
		void middlemanCallback0(const std_msgs::String::ConstPtr& msg){
  			if( true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node6 last from node0, intercepted: [%s]", msg->data.c_str());
				pub_6_7.publish(msg);
			}
  			else{
  				ROS_INFO("I'm node6, from node0 intercepted: [%s]", msg->data.c_str());
  				sub_0_6_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_6_7;
		int sub_0_6_flag;
  		ros::Subscriber sub_0_6;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node6");
  	Node6 node6;
  	ros::spin();
  	return 0;
  }

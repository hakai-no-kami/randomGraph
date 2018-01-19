
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.014974, 0.005);
  class Node9{
  	public:
  		Node9(){
			sub_0_9_flag = 0;
  			sub_0_9 = n.subscribe("topic_0_9", 1, &Node9::middlemanCallback0,this);
			pub_9_18 = n.advertise<std_msgs::String>("topic_9_18", 1);
			pub_9_15 = n.advertise<std_msgs::String>("topic_9_15", 1);
		}
		void middlemanCallback0(const std_msgs::String::ConstPtr& msg){
  			if( true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node9 last from node0, intercepted: [%s]", msg->data.c_str());
				pub_9_18.publish(msg);
				pub_9_15.publish(msg);
			}
  			else{
  				ROS_INFO("I'm node9, from node0 intercepted: [%s]", msg->data.c_str());
  				sub_0_9_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_9_18;
		ros::Publisher pub_9_15;
		int sub_0_9_flag;
  		ros::Subscriber sub_0_9;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node9");
  	Node9 node9;
  	ros::spin();
  	return 0;
  }

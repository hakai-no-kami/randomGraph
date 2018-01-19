
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.012666, 0.005);
  class Node9{
  	public:
  		Node9(){
			sub_1_9_flag = 0;
  			sub_1_9 = n.subscribe("topic_1_9", 1, &Node9::middlemanCallback1,this);
			pub_9_13 = n.advertise<std_msgs::String>("topic_9_13", 1);
			pub_9_12 = n.advertise<std_msgs::String>("topic_9_12", 1);
			pub_9_11 = n.advertise<std_msgs::String>("topic_9_11", 1);
		}
		void middlemanCallback1(const std_msgs::String::ConstPtr& msg){
  			if( true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node9 last from node1, intercepted: [%s]", msg->data.c_str());
				pub_9_13.publish(msg);
				pub_9_12.publish(msg);
				pub_9_11.publish(msg);
			}
  			else{
  				ROS_INFO("I'm node9, from node1 intercepted: [%s]", msg->data.c_str());
  				sub_1_9_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_9_13;
		ros::Publisher pub_9_12;
		ros::Publisher pub_9_11;
		int sub_1_9_flag;
  		ros::Subscriber sub_1_9;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node9");
  	Node9 node9;
  	ros::spin();
  	return 0;
  }

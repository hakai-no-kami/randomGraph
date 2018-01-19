
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.023041, 0.005);
  class Node6{
  	public:
  		Node6(){
			sub_2_6_flag = 0;
  			sub_2_6 = n.subscribe("topic_2_6", 1, &Node6::middlemanCallback2,this);
			pub_6_9 = n.advertise<std_msgs::String>("topic_6_9", 1);
			pub_6_8 = n.advertise<std_msgs::String>("topic_6_8", 1);
			pub_6_7 = n.advertise<std_msgs::String>("topic_6_7", 1);
		}
		void middlemanCallback2(const std_msgs::String::ConstPtr& msg){
  			if( true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node6 last from node2, intercepted: [%s]", msg->data.c_str());
				pub_6_9.publish(msg);
				pub_6_8.publish(msg);
				pub_6_7.publish(msg);
			}
  			else{
  				ROS_INFO("I'm node6, from node2 intercepted: [%s]", msg->data.c_str());
  				sub_2_6_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_6_9;
		ros::Publisher pub_6_8;
		ros::Publisher pub_6_7;
		int sub_2_6_flag;
  		ros::Subscriber sub_2_6;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node6");
  	Node6 node6;
  	ros::spin();
  	return 0;
  }

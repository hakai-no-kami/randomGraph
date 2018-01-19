
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.017553, 0.005);
  class Node1{
  	public:
  		Node1(){
			sub_0_1_flag = 0;
  			sub_0_1 = n.subscribe("topic_0_1", 1, &Node1::middlemanCallback0,this);
			pub_1_4 = n.advertise<std_msgs::String>("topic_1_4", 1);
			pub_1_3 = n.advertise<std_msgs::String>("topic_1_3", 1);
			pub_1_2 = n.advertise<std_msgs::String>("topic_1_2", 1);
		}
		void middlemanCallback0(const std_msgs::String::ConstPtr& msg){
  			if( true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node1 last from node0, intercepted: [%s]", msg->data.c_str());
				pub_1_4.publish(msg);
				pub_1_3.publish(msg);
				pub_1_2.publish(msg);
			}
  			else{
  				ROS_INFO("I'm node1, from node0 intercepted: [%s]", msg->data.c_str());
  				sub_0_1_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_1_4;
		ros::Publisher pub_1_3;
		ros::Publisher pub_1_2;
		int sub_0_1_flag;
  		ros::Subscriber sub_0_1;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node1");
  	Node1 node1;
  	ros::spin();
  	return 0;
  }

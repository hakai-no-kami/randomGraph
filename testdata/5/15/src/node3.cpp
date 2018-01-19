
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.017928, 0.005);
  class Node3{
  	public:
  		Node3(){
			sub_2_3_flag = 0;
  			sub_2_3 = n.subscribe("topic_2_3", 1, &Node3::middlemanCallback2,this);
			pub_3_5 = n.advertise<std_msgs::String>("topic_3_5", 1);
		}
		void middlemanCallback2(const std_msgs::String::ConstPtr& msg){
  			if( true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node3 last from node2, intercepted: [%s]", msg->data.c_str());
				pub_3_5.publish(msg);
			}
  			else{
  				ROS_INFO("I'm node3, from node2 intercepted: [%s]", msg->data.c_str());
  				sub_2_3_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_3_5;
		int sub_2_3_flag;
  		ros::Subscriber sub_2_3;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node3");
  	Node3 node3;
  	ros::spin();
  	return 0;
  }


  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.014548, 0.005);
  class Node13{
  	public:
  		Node13(){
			sub_11_13_flag = 0;
  			sub_11_13 = n.subscribe("topic_11_13", 1, &Node13::middlemanCallback11,this);
			pub_13_14 = n.advertise<std_msgs::String>("topic_13_14", 1);
		}
		void middlemanCallback11(const std_msgs::String::ConstPtr& msg){
  			if( true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node13 last from node11, intercepted: [%s]", msg->data.c_str());
				pub_13_14.publish(msg);
			}
  			else{
  				ROS_INFO("I'm node13, from node11 intercepted: [%s]", msg->data.c_str());
  				sub_11_13_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_13_14;
		int sub_11_13_flag;
  		ros::Subscriber sub_11_13;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node13");
  	Node13 node13;
  	ros::spin();
  	return 0;
  }

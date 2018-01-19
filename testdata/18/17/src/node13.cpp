
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.019439, 0.005);
  class Node13{
  	public:
  		Node13(){
			sub_5_13_flag = 0;
  			sub_5_13 = n.subscribe("topic_5_13", 1, &Node13::middlemanCallback5,this);
			pub_13_15 = n.advertise<std_msgs::String>("topic_13_15", 1);
			pub_13_14 = n.advertise<std_msgs::String>("topic_13_14", 1);
		}
		void middlemanCallback5(const std_msgs::String::ConstPtr& msg){
  			if( true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node13 last from node5, intercepted: [%s]", msg->data.c_str());
				pub_13_15.publish(msg);
				pub_13_14.publish(msg);
			}
  			else{
  				ROS_INFO("I'm node13, from node5 intercepted: [%s]", msg->data.c_str());
  				sub_5_13_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_13_15;
		ros::Publisher pub_13_14;
		int sub_5_13_flag;
  		ros::Subscriber sub_5_13;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node13");
  	Node13 node13;
  	ros::spin();
  	return 0;
  }

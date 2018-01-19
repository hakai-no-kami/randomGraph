
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.013822, 0.005);
  class Node10{
  	public:
  		Node10(){
			sub_7_10_flag = 0;
  			sub_7_10 = n.subscribe("topic_7_10", 1, &Node10::middlemanCallback7,this);
			pub_10_14 = n.advertise<std_msgs::String>("topic_10_14", 1);
		}
		void middlemanCallback7(const std_msgs::String::ConstPtr& msg){
  			if( true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node10 last from node7, intercepted: [%s]", msg->data.c_str());
				pub_10_14.publish(msg);
			}
  			else{
  				ROS_INFO("I'm node10, from node7 intercepted: [%s]", msg->data.c_str());
  				sub_7_10_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_10_14;
		int sub_7_10_flag;
  		ros::Subscriber sub_7_10;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node10");
  	Node10 node10;
  	ros::spin();
  	return 0;
  }

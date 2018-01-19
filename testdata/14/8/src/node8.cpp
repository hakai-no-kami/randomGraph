
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.029162, 0.005);
  class Node8{
  	public:
  		Node8(){
			sub_5_8_flag = 0;
  			sub_5_8 = n.subscribe("topic_5_8", 1, &Node8::middlemanCallback5,this);
			pub_8_12 = n.advertise<std_msgs::String>("topic_8_12", 1);
		}
		void middlemanCallback5(const std_msgs::String::ConstPtr& msg){
  			if( true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node8 last from node5, intercepted: [%s]", msg->data.c_str());
				pub_8_12.publish(msg);
			}
  			else{
  				ROS_INFO("I'm node8, from node5 intercepted: [%s]", msg->data.c_str());
  				sub_5_8_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_8_12;
		int sub_5_8_flag;
  		ros::Subscriber sub_5_8;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node8");
  	Node8 node8;
  	ros::spin();
  	return 0;
  }

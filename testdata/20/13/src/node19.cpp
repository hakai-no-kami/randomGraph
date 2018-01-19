
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.017817, 0.005);
  class Node19{
  	public:
  		Node19(){
			sub_0_19_flag = 0;
  			sub_0_19 = n.subscribe("topic_0_19", 1, &Node19::middlemanCallback0,this);
			pub_19_20 = n.advertise<std_msgs::String>("topic_19_20", 1);
		}
		void middlemanCallback0(const std_msgs::String::ConstPtr& msg){
  			if( true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node19 last from node0, intercepted: [%s]", msg->data.c_str());
				pub_19_20.publish(msg);
			}
  			else{
  				ROS_INFO("I'm node19, from node0 intercepted: [%s]", msg->data.c_str());
  				sub_0_19_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_19_20;
		int sub_0_19_flag;
  		ros::Subscriber sub_0_19;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node19");
  	Node19 node19;
  	ros::spin();
  	return 0;
  }

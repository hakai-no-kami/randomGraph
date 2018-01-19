
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.018345, 0.005);
  class Node17{
  	public:
  		Node17(){
			sub_0_17_flag = 0;
  			sub_0_17 = n.subscribe("topic_0_17", 1, &Node17::middlemanCallback0,this);
			pub_17_18 = n.advertise<std_msgs::String>("topic_17_18", 1);
		}
		void middlemanCallback0(const std_msgs::String::ConstPtr& msg){
  			if( true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node17 last from node0, intercepted: [%s]", msg->data.c_str());
				pub_17_18.publish(msg);
			}
  			else{
  				ROS_INFO("I'm node17, from node0 intercepted: [%s]", msg->data.c_str());
  				sub_0_17_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_17_18;
		int sub_0_17_flag;
  		ros::Subscriber sub_0_17;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node17");
  	Node17 node17;
  	ros::spin();
  	return 0;
  }

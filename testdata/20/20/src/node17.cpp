
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.011948, 0.005);
  class Node17{
  	public:
  		Node17(){
			sub_15_17_flag = 0;
  			sub_15_17 = n.subscribe("topic_15_17", 1, &Node17::middlemanCallback15,this);
			pub_17_18 = n.advertise<std_msgs::String>("topic_17_18", 1);
		}
		void middlemanCallback15(const std_msgs::String::ConstPtr& msg){
  			if( true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node17 last from node15, intercepted: [%s]", msg->data.c_str());
				pub_17_18.publish(msg);
			}
  			else{
  				ROS_INFO("I'm node17, from node15 intercepted: [%s]", msg->data.c_str());
  				sub_15_17_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_17_18;
		int sub_15_17_flag;
  		ros::Subscriber sub_15_17;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node17");
  	Node17 node17;
  	ros::spin();
  	return 0;
  }

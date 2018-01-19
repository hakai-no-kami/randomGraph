
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.022390, 0.005);
  class Node4{
  	public:
  		Node4(){
			sub_3_4_flag = 0;
  			sub_3_4 = n.subscribe("topic_3_4", 1, &Node4::middlemanCallback3,this);
			pub_4_8 = n.advertise<std_msgs::String>("topic_4_8", 1);
			pub_4_7 = n.advertise<std_msgs::String>("topic_4_7", 1);
		}
		void middlemanCallback3(const std_msgs::String::ConstPtr& msg){
  			if( true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node4 last from node3, intercepted: [%s]", msg->data.c_str());
				pub_4_8.publish(msg);
				pub_4_7.publish(msg);
			}
  			else{
  				ROS_INFO("I'm node4, from node3 intercepted: [%s]", msg->data.c_str());
  				sub_3_4_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_4_8;
		ros::Publisher pub_4_7;
		int sub_3_4_flag;
  		ros::Subscriber sub_3_4;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node4");
  	Node4 node4;
  	ros::spin();
  	return 0;
  }

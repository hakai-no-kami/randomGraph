
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.017275, 0.005);
  class Node8{
  	public:
  		Node8(){
			sub_3_8_flag = 0;
  			sub_3_8 = n.subscribe("topic_3_8", 1, &Node8::middlemanCallback3,this);
			sub_6_8_flag = 0;
  			sub_6_8 = n.subscribe("topic_6_8", 1, &Node8::middlemanCallback6,this);
			pub_8_9 = n.advertise<std_msgs::String>("topic_8_9", 1);
		}
		void middlemanCallback3(const std_msgs::String::ConstPtr& msg){
  			if(sub_6_8_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node8 last from node3, intercepted: [%s]", msg->data.c_str());
				pub_8_9.publish(msg);
				sub_6_8_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node8, from node3 intercepted: [%s]", msg->data.c_str());
  				sub_3_8_flag = 1;
  			}
  		}
		void middlemanCallback6(const std_msgs::String::ConstPtr& msg){
  			if(sub_3_8_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node8 last from node6, intercepted: [%s]", msg->data.c_str());
				pub_8_9.publish(msg);
				sub_3_8_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node8, from node6 intercepted: [%s]", msg->data.c_str());
  				sub_6_8_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_8_9;
		int sub_3_8_flag;
  		ros::Subscriber sub_3_8;
		int sub_6_8_flag;
  		ros::Subscriber sub_6_8;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node8");
  	Node8 node8;
  	ros::spin();
  	return 0;
  }

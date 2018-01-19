
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.029397, 0.005);
  class Node5{
  	public:
  		Node5(){
			sub_3_5_flag = 0;
  			sub_3_5 = n.subscribe("topic_3_5", 1, &Node5::middlemanCallback3,this);
			sub_4_5_flag = 0;
  			sub_4_5 = n.subscribe("topic_4_5", 1, &Node5::middlemanCallback4,this);
			pub_5_6 = n.advertise<std_msgs::String>("topic_5_6", 1);
		}
		void middlemanCallback3(const std_msgs::String::ConstPtr& msg){
  			if(sub_4_5_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node5 last from node3, intercepted: [%s]", msg->data.c_str());
				pub_5_6.publish(msg);
				sub_4_5_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node5, from node3 intercepted: [%s]", msg->data.c_str());
  				sub_3_5_flag = 1;
  			}
  		}
		void middlemanCallback4(const std_msgs::String::ConstPtr& msg){
  			if(sub_3_5_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node5 last from node4, intercepted: [%s]", msg->data.c_str());
				pub_5_6.publish(msg);
				sub_3_5_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node5, from node4 intercepted: [%s]", msg->data.c_str());
  				sub_4_5_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_5_6;
		int sub_3_5_flag;
  		ros::Subscriber sub_3_5;
		int sub_4_5_flag;
  		ros::Subscriber sub_4_5;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node5");
  	Node5 node5;
  	ros::spin();
  	return 0;
  }

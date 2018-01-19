
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.027545, 0.005);
  class Node3{
  	public:
  		Node3(){
			sub_1_3_flag = 0;
  			sub_1_3 = n.subscribe("topic_1_3", 1, &Node3::middlemanCallback1,this);
			sub_2_3_flag = 0;
  			sub_2_3 = n.subscribe("topic_2_3", 1, &Node3::middlemanCallback2,this);
			pub_3_7 = n.advertise<std_msgs::String>("topic_3_7", 1);
			pub_3_6 = n.advertise<std_msgs::String>("topic_3_6", 1);
			pub_3_4 = n.advertise<std_msgs::String>("topic_3_4", 1);
		}
		void middlemanCallback1(const std_msgs::String::ConstPtr& msg){
  			if(sub_2_3_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node3 last from node1, intercepted: [%s]", msg->data.c_str());
				pub_3_7.publish(msg);
				pub_3_6.publish(msg);
				pub_3_4.publish(msg);
				sub_2_3_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node3, from node1 intercepted: [%s]", msg->data.c_str());
  				sub_1_3_flag = 1;
  			}
  		}
		void middlemanCallback2(const std_msgs::String::ConstPtr& msg){
  			if(sub_1_3_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node3 last from node2, intercepted: [%s]", msg->data.c_str());
				pub_3_7.publish(msg);
				pub_3_6.publish(msg);
				pub_3_4.publish(msg);
				sub_1_3_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node3, from node2 intercepted: [%s]", msg->data.c_str());
  				sub_2_3_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_3_7;
		ros::Publisher pub_3_6;
		ros::Publisher pub_3_4;
		int sub_1_3_flag;
  		ros::Subscriber sub_1_3;
		int sub_2_3_flag;
  		ros::Subscriber sub_2_3;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node3");
  	Node3 node3;
  	ros::spin();
  	return 0;
  }

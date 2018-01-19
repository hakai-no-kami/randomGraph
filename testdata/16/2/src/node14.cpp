
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.026788, 0.005);
  class Node14{
  	public:
  		Node14(){
			sub_2_14_flag = 0;
  			sub_2_14 = n.subscribe("topic_2_14", 1, &Node14::middlemanCallback2,this);
			sub_8_14_flag = 0;
  			sub_8_14 = n.subscribe("topic_8_14", 1, &Node14::middlemanCallback8,this);
			sub_12_14_flag = 0;
  			sub_12_14 = n.subscribe("topic_12_14", 1, &Node14::middlemanCallback12,this);
			sub_13_14_flag = 0;
  			sub_13_14 = n.subscribe("topic_13_14", 1, &Node14::middlemanCallback13,this);
			pub_14_16 = n.advertise<std_msgs::String>("topic_14_16", 1);
		}
		void middlemanCallback2(const std_msgs::String::ConstPtr& msg){
  			if(sub_8_14_flag == 1 && sub_12_14_flag == 1 && sub_13_14_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node14 last from node2, intercepted: [%s]", msg->data.c_str());
				pub_14_16.publish(msg);
				sub_8_14_flag = 0;
				sub_12_14_flag = 0;
				sub_13_14_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node14, from node2 intercepted: [%s]", msg->data.c_str());
  				sub_2_14_flag = 1;
  			}
  		}
		void middlemanCallback8(const std_msgs::String::ConstPtr& msg){
  			if(sub_2_14_flag == 1 && sub_12_14_flag == 1 && sub_13_14_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node14 last from node8, intercepted: [%s]", msg->data.c_str());
				pub_14_16.publish(msg);
				sub_2_14_flag = 0;
				sub_12_14_flag = 0;
				sub_13_14_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node14, from node8 intercepted: [%s]", msg->data.c_str());
  				sub_8_14_flag = 1;
  			}
  		}
		void middlemanCallback12(const std_msgs::String::ConstPtr& msg){
  			if(sub_2_14_flag == 1 && sub_8_14_flag == 1 && sub_13_14_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node14 last from node12, intercepted: [%s]", msg->data.c_str());
				pub_14_16.publish(msg);
				sub_2_14_flag = 0;
				sub_8_14_flag = 0;
				sub_13_14_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node14, from node12 intercepted: [%s]", msg->data.c_str());
  				sub_12_14_flag = 1;
  			}
  		}
		void middlemanCallback13(const std_msgs::String::ConstPtr& msg){
  			if(sub_2_14_flag == 1 && sub_8_14_flag == 1 && sub_12_14_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node14 last from node13, intercepted: [%s]", msg->data.c_str());
				pub_14_16.publish(msg);
				sub_2_14_flag = 0;
				sub_8_14_flag = 0;
				sub_12_14_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node14, from node13 intercepted: [%s]", msg->data.c_str());
  				sub_13_14_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_14_16;
		int sub_2_14_flag;
  		ros::Subscriber sub_2_14;
		int sub_8_14_flag;
  		ros::Subscriber sub_8_14;
		int sub_12_14_flag;
  		ros::Subscriber sub_12_14;
		int sub_13_14_flag;
  		ros::Subscriber sub_13_14;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node14");
  	Node14 node14;
  	ros::spin();
  	return 0;
  }

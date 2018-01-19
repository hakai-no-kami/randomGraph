
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.017265, 0.005);
  class Node14{
  	public:
  		Node14(){
			sub_7_14_flag = 0;
  			sub_7_14 = n.subscribe("topic_7_14", 1, &Node14::middlemanCallback7,this);
			sub_8_14_flag = 0;
  			sub_8_14 = n.subscribe("topic_8_14", 1, &Node14::middlemanCallback8,this);
			sub_10_14_flag = 0;
  			sub_10_14 = n.subscribe("topic_10_14", 1, &Node14::middlemanCallback10,this);
			sub_11_14_flag = 0;
  			sub_11_14 = n.subscribe("topic_11_14", 1, &Node14::middlemanCallback11,this);
			sub_13_14_flag = 0;
  			sub_13_14 = n.subscribe("topic_13_14", 1, &Node14::middlemanCallback13,this);
			pub_14_16 = n.advertise<std_msgs::String>("topic_14_16", 1);
		}
		void middlemanCallback7(const std_msgs::String::ConstPtr& msg){
  			if(sub_8_14_flag == 1 && sub_10_14_flag == 1 && sub_11_14_flag == 1 && sub_13_14_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node14 last from node7, intercepted: [%s]", msg->data.c_str());
				pub_14_16.publish(msg);
				sub_8_14_flag = 0;
				sub_10_14_flag = 0;
				sub_11_14_flag = 0;
				sub_13_14_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node14, from node7 intercepted: [%s]", msg->data.c_str());
  				sub_7_14_flag = 1;
  			}
  		}
		void middlemanCallback8(const std_msgs::String::ConstPtr& msg){
  			if(sub_7_14_flag == 1 && sub_10_14_flag == 1 && sub_11_14_flag == 1 && sub_13_14_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node14 last from node8, intercepted: [%s]", msg->data.c_str());
				pub_14_16.publish(msg);
				sub_7_14_flag = 0;
				sub_10_14_flag = 0;
				sub_11_14_flag = 0;
				sub_13_14_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node14, from node8 intercepted: [%s]", msg->data.c_str());
  				sub_8_14_flag = 1;
  			}
  		}
		void middlemanCallback10(const std_msgs::String::ConstPtr& msg){
  			if(sub_7_14_flag == 1 && sub_8_14_flag == 1 && sub_11_14_flag == 1 && sub_13_14_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node14 last from node10, intercepted: [%s]", msg->data.c_str());
				pub_14_16.publish(msg);
				sub_7_14_flag = 0;
				sub_8_14_flag = 0;
				sub_11_14_flag = 0;
				sub_13_14_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node14, from node10 intercepted: [%s]", msg->data.c_str());
  				sub_10_14_flag = 1;
  			}
  		}
		void middlemanCallback11(const std_msgs::String::ConstPtr& msg){
  			if(sub_7_14_flag == 1 && sub_8_14_flag == 1 && sub_10_14_flag == 1 && sub_13_14_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node14 last from node11, intercepted: [%s]", msg->data.c_str());
				pub_14_16.publish(msg);
				sub_7_14_flag = 0;
				sub_8_14_flag = 0;
				sub_10_14_flag = 0;
				sub_13_14_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node14, from node11 intercepted: [%s]", msg->data.c_str());
  				sub_11_14_flag = 1;
  			}
  		}
		void middlemanCallback13(const std_msgs::String::ConstPtr& msg){
  			if(sub_7_14_flag == 1 && sub_8_14_flag == 1 && sub_10_14_flag == 1 && sub_11_14_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node14 last from node13, intercepted: [%s]", msg->data.c_str());
				pub_14_16.publish(msg);
				sub_7_14_flag = 0;
				sub_8_14_flag = 0;
				sub_10_14_flag = 0;
				sub_11_14_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node14, from node13 intercepted: [%s]", msg->data.c_str());
  				sub_13_14_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_14_16;
		int sub_7_14_flag;
  		ros::Subscriber sub_7_14;
		int sub_8_14_flag;
  		ros::Subscriber sub_8_14;
		int sub_10_14_flag;
  		ros::Subscriber sub_10_14;
		int sub_11_14_flag;
  		ros::Subscriber sub_11_14;
		int sub_13_14_flag;
  		ros::Subscriber sub_13_14;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node14");
  	Node14 node14;
  	ros::spin();
  	return 0;
  }

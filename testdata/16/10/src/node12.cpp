
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.026080, 0.005);
  class Node12{
  	public:
  		Node12(){
			sub_3_12_flag = 0;
  			sub_3_12 = n.subscribe("topic_3_12", 1, &Node12::middlemanCallback3,this);
			sub_4_12_flag = 0;
  			sub_4_12 = n.subscribe("topic_4_12", 1, &Node12::middlemanCallback4,this);
			sub_6_12_flag = 0;
  			sub_6_12 = n.subscribe("topic_6_12", 1, &Node12::middlemanCallback6,this);
			sub_7_12_flag = 0;
  			sub_7_12 = n.subscribe("topic_7_12", 1, &Node12::middlemanCallback7,this);
			sub_9_12_flag = 0;
  			sub_9_12 = n.subscribe("topic_9_12", 1, &Node12::middlemanCallback9,this);
			sub_11_12_flag = 0;
  			sub_11_12 = n.subscribe("topic_11_12", 1, &Node12::middlemanCallback11,this);
			pub_12_16 = n.advertise<std_msgs::String>("topic_12_16", 1);
		}
		void middlemanCallback3(const std_msgs::String::ConstPtr& msg){
  			if(sub_4_12_flag == 1 && sub_6_12_flag == 1 && sub_7_12_flag == 1 && sub_9_12_flag == 1 && sub_11_12_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node12 last from node3, intercepted: [%s]", msg->data.c_str());
				pub_12_16.publish(msg);
				sub_4_12_flag = 0;
				sub_6_12_flag = 0;
				sub_7_12_flag = 0;
				sub_9_12_flag = 0;
				sub_11_12_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node12, from node3 intercepted: [%s]", msg->data.c_str());
  				sub_3_12_flag = 1;
  			}
  		}
		void middlemanCallback4(const std_msgs::String::ConstPtr& msg){
  			if(sub_3_12_flag == 1 && sub_6_12_flag == 1 && sub_7_12_flag == 1 && sub_9_12_flag == 1 && sub_11_12_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node12 last from node4, intercepted: [%s]", msg->data.c_str());
				pub_12_16.publish(msg);
				sub_3_12_flag = 0;
				sub_6_12_flag = 0;
				sub_7_12_flag = 0;
				sub_9_12_flag = 0;
				sub_11_12_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node12, from node4 intercepted: [%s]", msg->data.c_str());
  				sub_4_12_flag = 1;
  			}
  		}
		void middlemanCallback6(const std_msgs::String::ConstPtr& msg){
  			if(sub_3_12_flag == 1 && sub_4_12_flag == 1 && sub_7_12_flag == 1 && sub_9_12_flag == 1 && sub_11_12_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node12 last from node6, intercepted: [%s]", msg->data.c_str());
				pub_12_16.publish(msg);
				sub_3_12_flag = 0;
				sub_4_12_flag = 0;
				sub_7_12_flag = 0;
				sub_9_12_flag = 0;
				sub_11_12_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node12, from node6 intercepted: [%s]", msg->data.c_str());
  				sub_6_12_flag = 1;
  			}
  		}
		void middlemanCallback7(const std_msgs::String::ConstPtr& msg){
  			if(sub_3_12_flag == 1 && sub_4_12_flag == 1 && sub_6_12_flag == 1 && sub_9_12_flag == 1 && sub_11_12_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node12 last from node7, intercepted: [%s]", msg->data.c_str());
				pub_12_16.publish(msg);
				sub_3_12_flag = 0;
				sub_4_12_flag = 0;
				sub_6_12_flag = 0;
				sub_9_12_flag = 0;
				sub_11_12_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node12, from node7 intercepted: [%s]", msg->data.c_str());
  				sub_7_12_flag = 1;
  			}
  		}
		void middlemanCallback9(const std_msgs::String::ConstPtr& msg){
  			if(sub_3_12_flag == 1 && sub_4_12_flag == 1 && sub_6_12_flag == 1 && sub_7_12_flag == 1 && sub_11_12_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node12 last from node9, intercepted: [%s]", msg->data.c_str());
				pub_12_16.publish(msg);
				sub_3_12_flag = 0;
				sub_4_12_flag = 0;
				sub_6_12_flag = 0;
				sub_7_12_flag = 0;
				sub_11_12_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node12, from node9 intercepted: [%s]", msg->data.c_str());
  				sub_9_12_flag = 1;
  			}
  		}
		void middlemanCallback11(const std_msgs::String::ConstPtr& msg){
  			if(sub_3_12_flag == 1 && sub_4_12_flag == 1 && sub_6_12_flag == 1 && sub_7_12_flag == 1 && sub_9_12_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node12 last from node11, intercepted: [%s]", msg->data.c_str());
				pub_12_16.publish(msg);
				sub_3_12_flag = 0;
				sub_4_12_flag = 0;
				sub_6_12_flag = 0;
				sub_7_12_flag = 0;
				sub_9_12_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node12, from node11 intercepted: [%s]", msg->data.c_str());
  				sub_11_12_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_12_16;
		int sub_3_12_flag;
  		ros::Subscriber sub_3_12;
		int sub_4_12_flag;
  		ros::Subscriber sub_4_12;
		int sub_6_12_flag;
  		ros::Subscriber sub_6_12;
		int sub_7_12_flag;
  		ros::Subscriber sub_7_12;
		int sub_9_12_flag;
  		ros::Subscriber sub_9_12;
		int sub_11_12_flag;
  		ros::Subscriber sub_11_12;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node12");
  	Node12 node12;
  	ros::spin();
  	return 0;
  }

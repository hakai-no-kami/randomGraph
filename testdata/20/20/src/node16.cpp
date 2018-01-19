
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.029231, 0.005);
  class Node16{
  	public:
  		Node16(){
			sub_1_16_flag = 0;
  			sub_1_16 = n.subscribe("topic_1_16", 1, &Node16::middlemanCallback1,this);
			sub_3_16_flag = 0;
  			sub_3_16 = n.subscribe("topic_3_16", 1, &Node16::middlemanCallback3,this);
			sub_6_16_flag = 0;
  			sub_6_16 = n.subscribe("topic_6_16", 1, &Node16::middlemanCallback6,this);
			sub_10_16_flag = 0;
  			sub_10_16 = n.subscribe("topic_10_16", 1, &Node16::middlemanCallback10,this);
			sub_11_16_flag = 0;
  			sub_11_16 = n.subscribe("topic_11_16", 1, &Node16::middlemanCallback11,this);
			sub_14_16_flag = 0;
  			sub_14_16 = n.subscribe("topic_14_16", 1, &Node16::middlemanCallback14,this);
			sub_15_16_flag = 0;
  			sub_15_16 = n.subscribe("topic_15_16", 1, &Node16::middlemanCallback15,this);
			pub_16_20 = n.advertise<std_msgs::String>("topic_16_20", 1);
		}
		void middlemanCallback1(const std_msgs::String::ConstPtr& msg){
  			if(sub_3_16_flag == 1 && sub_6_16_flag == 1 && sub_10_16_flag == 1 && sub_11_16_flag == 1 && sub_14_16_flag == 1 && sub_15_16_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node16 last from node1, intercepted: [%s]", msg->data.c_str());
				pub_16_20.publish(msg);
				sub_3_16_flag = 0;
				sub_6_16_flag = 0;
				sub_10_16_flag = 0;
				sub_11_16_flag = 0;
				sub_14_16_flag = 0;
				sub_15_16_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node16, from node1 intercepted: [%s]", msg->data.c_str());
  				sub_1_16_flag = 1;
  			}
  		}
		void middlemanCallback3(const std_msgs::String::ConstPtr& msg){
  			if(sub_1_16_flag == 1 && sub_6_16_flag == 1 && sub_10_16_flag == 1 && sub_11_16_flag == 1 && sub_14_16_flag == 1 && sub_15_16_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node16 last from node3, intercepted: [%s]", msg->data.c_str());
				pub_16_20.publish(msg);
				sub_1_16_flag = 0;
				sub_6_16_flag = 0;
				sub_10_16_flag = 0;
				sub_11_16_flag = 0;
				sub_14_16_flag = 0;
				sub_15_16_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node16, from node3 intercepted: [%s]", msg->data.c_str());
  				sub_3_16_flag = 1;
  			}
  		}
		void middlemanCallback6(const std_msgs::String::ConstPtr& msg){
  			if(sub_1_16_flag == 1 && sub_3_16_flag == 1 && sub_10_16_flag == 1 && sub_11_16_flag == 1 && sub_14_16_flag == 1 && sub_15_16_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node16 last from node6, intercepted: [%s]", msg->data.c_str());
				pub_16_20.publish(msg);
				sub_1_16_flag = 0;
				sub_3_16_flag = 0;
				sub_10_16_flag = 0;
				sub_11_16_flag = 0;
				sub_14_16_flag = 0;
				sub_15_16_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node16, from node6 intercepted: [%s]", msg->data.c_str());
  				sub_6_16_flag = 1;
  			}
  		}
		void middlemanCallback10(const std_msgs::String::ConstPtr& msg){
  			if(sub_1_16_flag == 1 && sub_3_16_flag == 1 && sub_6_16_flag == 1 && sub_11_16_flag == 1 && sub_14_16_flag == 1 && sub_15_16_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node16 last from node10, intercepted: [%s]", msg->data.c_str());
				pub_16_20.publish(msg);
				sub_1_16_flag = 0;
				sub_3_16_flag = 0;
				sub_6_16_flag = 0;
				sub_11_16_flag = 0;
				sub_14_16_flag = 0;
				sub_15_16_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node16, from node10 intercepted: [%s]", msg->data.c_str());
  				sub_10_16_flag = 1;
  			}
  		}
		void middlemanCallback11(const std_msgs::String::ConstPtr& msg){
  			if(sub_1_16_flag == 1 && sub_3_16_flag == 1 && sub_6_16_flag == 1 && sub_10_16_flag == 1 && sub_14_16_flag == 1 && sub_15_16_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node16 last from node11, intercepted: [%s]", msg->data.c_str());
				pub_16_20.publish(msg);
				sub_1_16_flag = 0;
				sub_3_16_flag = 0;
				sub_6_16_flag = 0;
				sub_10_16_flag = 0;
				sub_14_16_flag = 0;
				sub_15_16_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node16, from node11 intercepted: [%s]", msg->data.c_str());
  				sub_11_16_flag = 1;
  			}
  		}
		void middlemanCallback14(const std_msgs::String::ConstPtr& msg){
  			if(sub_1_16_flag == 1 && sub_3_16_flag == 1 && sub_6_16_flag == 1 && sub_10_16_flag == 1 && sub_11_16_flag == 1 && sub_15_16_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node16 last from node14, intercepted: [%s]", msg->data.c_str());
				pub_16_20.publish(msg);
				sub_1_16_flag = 0;
				sub_3_16_flag = 0;
				sub_6_16_flag = 0;
				sub_10_16_flag = 0;
				sub_11_16_flag = 0;
				sub_15_16_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node16, from node14 intercepted: [%s]", msg->data.c_str());
  				sub_14_16_flag = 1;
  			}
  		}
		void middlemanCallback15(const std_msgs::String::ConstPtr& msg){
  			if(sub_1_16_flag == 1 && sub_3_16_flag == 1 && sub_6_16_flag == 1 && sub_10_16_flag == 1 && sub_11_16_flag == 1 && sub_14_16_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node16 last from node15, intercepted: [%s]", msg->data.c_str());
				pub_16_20.publish(msg);
				sub_1_16_flag = 0;
				sub_3_16_flag = 0;
				sub_6_16_flag = 0;
				sub_10_16_flag = 0;
				sub_11_16_flag = 0;
				sub_14_16_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node16, from node15 intercepted: [%s]", msg->data.c_str());
  				sub_15_16_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_16_20;
		int sub_1_16_flag;
  		ros::Subscriber sub_1_16;
		int sub_3_16_flag;
  		ros::Subscriber sub_3_16;
		int sub_6_16_flag;
  		ros::Subscriber sub_6_16;
		int sub_10_16_flag;
  		ros::Subscriber sub_10_16;
		int sub_11_16_flag;
  		ros::Subscriber sub_11_16;
		int sub_14_16_flag;
  		ros::Subscriber sub_14_16;
		int sub_15_16_flag;
  		ros::Subscriber sub_15_16;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node16");
  	Node16 node16;
  	ros::spin();
  	return 0;
  }

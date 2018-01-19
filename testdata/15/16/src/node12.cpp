
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.017758, 0.005);
  class Node12{
  	public:
  		Node12(){
			sub_4_12_flag = 0;
  			sub_4_12 = n.subscribe("topic_4_12", 1, &Node12::middlemanCallback4,this);
			sub_8_12_flag = 0;
  			sub_8_12 = n.subscribe("topic_8_12", 1, &Node12::middlemanCallback8,this);
			sub_9_12_flag = 0;
  			sub_9_12 = n.subscribe("topic_9_12", 1, &Node12::middlemanCallback9,this);
			sub_10_12_flag = 0;
  			sub_10_12 = n.subscribe("topic_10_12", 1, &Node12::middlemanCallback10,this);
			pub_12_14 = n.advertise<std_msgs::String>("topic_12_14", 1);
			pub_12_13 = n.advertise<std_msgs::String>("topic_12_13", 1);
		}
		void middlemanCallback4(const std_msgs::String::ConstPtr& msg){
  			if(sub_8_12_flag == 1 && sub_9_12_flag == 1 && sub_10_12_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node12 last from node4, intercepted: [%s]", msg->data.c_str());
				pub_12_14.publish(msg);
				pub_12_13.publish(msg);
				sub_8_12_flag = 0;
				sub_9_12_flag = 0;
				sub_10_12_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node12, from node4 intercepted: [%s]", msg->data.c_str());
  				sub_4_12_flag = 1;
  			}
  		}
		void middlemanCallback8(const std_msgs::String::ConstPtr& msg){
  			if(sub_4_12_flag == 1 && sub_9_12_flag == 1 && sub_10_12_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node12 last from node8, intercepted: [%s]", msg->data.c_str());
				pub_12_14.publish(msg);
				pub_12_13.publish(msg);
				sub_4_12_flag = 0;
				sub_9_12_flag = 0;
				sub_10_12_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node12, from node8 intercepted: [%s]", msg->data.c_str());
  				sub_8_12_flag = 1;
  			}
  		}
		void middlemanCallback9(const std_msgs::String::ConstPtr& msg){
  			if(sub_4_12_flag == 1 && sub_8_12_flag == 1 && sub_10_12_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node12 last from node9, intercepted: [%s]", msg->data.c_str());
				pub_12_14.publish(msg);
				pub_12_13.publish(msg);
				sub_4_12_flag = 0;
				sub_8_12_flag = 0;
				sub_10_12_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node12, from node9 intercepted: [%s]", msg->data.c_str());
  				sub_9_12_flag = 1;
  			}
  		}
		void middlemanCallback10(const std_msgs::String::ConstPtr& msg){
  			if(sub_4_12_flag == 1 && sub_8_12_flag == 1 && sub_9_12_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node12 last from node10, intercepted: [%s]", msg->data.c_str());
				pub_12_14.publish(msg);
				pub_12_13.publish(msg);
				sub_4_12_flag = 0;
				sub_8_12_flag = 0;
				sub_9_12_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node12, from node10 intercepted: [%s]", msg->data.c_str());
  				sub_10_12_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_12_14;
		ros::Publisher pub_12_13;
		int sub_4_12_flag;
  		ros::Subscriber sub_4_12;
		int sub_8_12_flag;
  		ros::Subscriber sub_8_12;
		int sub_9_12_flag;
  		ros::Subscriber sub_9_12;
		int sub_10_12_flag;
  		ros::Subscriber sub_10_12;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node12");
  	Node12 node12;
  	ros::spin();
  	return 0;
  }

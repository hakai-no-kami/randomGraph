
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.024051, 0.005);
  class Node12{
  	public:
  		Node12(){
			sub_1_12_flag = 0;
  			sub_1_12 = n.subscribe("topic_1_12", 1, &Node12::middlemanCallback1,this);
			sub_5_12_flag = 0;
  			sub_5_12 = n.subscribe("topic_5_12", 1, &Node12::middlemanCallback5,this);
			sub_9_12_flag = 0;
  			sub_9_12 = n.subscribe("topic_9_12", 1, &Node12::middlemanCallback9,this);
			pub_12_18 = n.advertise<std_msgs::String>("topic_12_18", 1);
		}
		void middlemanCallback1(const std_msgs::String::ConstPtr& msg){
  			if(sub_5_12_flag == 1 && sub_9_12_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node12 last from node1, intercepted: [%s]", msg->data.c_str());
				pub_12_18.publish(msg);
				sub_5_12_flag = 0;
				sub_9_12_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node12, from node1 intercepted: [%s]", msg->data.c_str());
  				sub_1_12_flag = 1;
  			}
  		}
		void middlemanCallback5(const std_msgs::String::ConstPtr& msg){
  			if(sub_1_12_flag == 1 && sub_9_12_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node12 last from node5, intercepted: [%s]", msg->data.c_str());
				pub_12_18.publish(msg);
				sub_1_12_flag = 0;
				sub_9_12_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node12, from node5 intercepted: [%s]", msg->data.c_str());
  				sub_5_12_flag = 1;
  			}
  		}
		void middlemanCallback9(const std_msgs::String::ConstPtr& msg){
  			if(sub_1_12_flag == 1 && sub_5_12_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node12 last from node9, intercepted: [%s]", msg->data.c_str());
				pub_12_18.publish(msg);
				sub_1_12_flag = 0;
				sub_5_12_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node12, from node9 intercepted: [%s]", msg->data.c_str());
  				sub_9_12_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_12_18;
		int sub_1_12_flag;
  		ros::Subscriber sub_1_12;
		int sub_5_12_flag;
  		ros::Subscriber sub_5_12;
		int sub_9_12_flag;
  		ros::Subscriber sub_9_12;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node12");
  	Node12 node12;
  	ros::spin();
  	return 0;
  }

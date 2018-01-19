
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.020987, 0.005);
  class Node14{
  	public:
  		Node14(){
			sub_9_14_flag = 0;
  			sub_9_14 = n.subscribe("topic_9_14", 1, &Node14::middlemanCallback9,this);
			sub_11_14_flag = 0;
  			sub_11_14 = n.subscribe("topic_11_14", 1, &Node14::middlemanCallback11,this);
			sub_12_14_flag = 0;
  			sub_12_14 = n.subscribe("topic_12_14", 1, &Node14::middlemanCallback12,this);
			pub_14_16 = n.advertise<std_msgs::String>("topic_14_16", 1);
			pub_14_15 = n.advertise<std_msgs::String>("topic_14_15", 1);
		}
		void middlemanCallback9(const std_msgs::String::ConstPtr& msg){
  			if(sub_11_14_flag == 1 && sub_12_14_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node14 last from node9, intercepted: [%s]", msg->data.c_str());
				pub_14_16.publish(msg);
				pub_14_15.publish(msg);
				sub_11_14_flag = 0;
				sub_12_14_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node14, from node9 intercepted: [%s]", msg->data.c_str());
  				sub_9_14_flag = 1;
  			}
  		}
		void middlemanCallback11(const std_msgs::String::ConstPtr& msg){
  			if(sub_9_14_flag == 1 && sub_12_14_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node14 last from node11, intercepted: [%s]", msg->data.c_str());
				pub_14_16.publish(msg);
				pub_14_15.publish(msg);
				sub_9_14_flag = 0;
				sub_12_14_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node14, from node11 intercepted: [%s]", msg->data.c_str());
  				sub_11_14_flag = 1;
  			}
  		}
		void middlemanCallback12(const std_msgs::String::ConstPtr& msg){
  			if(sub_9_14_flag == 1 && sub_11_14_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node14 last from node12, intercepted: [%s]", msg->data.c_str());
				pub_14_16.publish(msg);
				pub_14_15.publish(msg);
				sub_9_14_flag = 0;
				sub_11_14_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node14, from node12 intercepted: [%s]", msg->data.c_str());
  				sub_12_14_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_14_16;
		ros::Publisher pub_14_15;
		int sub_9_14_flag;
  		ros::Subscriber sub_9_14;
		int sub_11_14_flag;
  		ros::Subscriber sub_11_14;
		int sub_12_14_flag;
  		ros::Subscriber sub_12_14;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node14");
  	Node14 node14;
  	ros::spin();
  	return 0;
  }

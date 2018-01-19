
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.025494, 0.005);
  class Node12{
  	public:
  		Node12(){
			sub_5_12_flag = 0;
  			sub_5_12 = n.subscribe("topic_5_12", 1, &Node12::middlemanCallback5,this);
			sub_7_12_flag = 0;
  			sub_7_12 = n.subscribe("topic_7_12", 1, &Node12::middlemanCallback7,this);
			pub_12_15 = n.advertise<std_msgs::String>("topic_12_15", 1);
		}
		void middlemanCallback5(const std_msgs::String::ConstPtr& msg){
  			if(sub_7_12_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node12 last from node5, intercepted: [%s]", msg->data.c_str());
				pub_12_15.publish(msg);
				sub_7_12_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node12, from node5 intercepted: [%s]", msg->data.c_str());
  				sub_5_12_flag = 1;
  			}
  		}
		void middlemanCallback7(const std_msgs::String::ConstPtr& msg){
  			if(sub_5_12_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node12 last from node7, intercepted: [%s]", msg->data.c_str());
				pub_12_15.publish(msg);
				sub_5_12_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node12, from node7 intercepted: [%s]", msg->data.c_str());
  				sub_7_12_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_12_15;
		int sub_5_12_flag;
  		ros::Subscriber sub_5_12;
		int sub_7_12_flag;
  		ros::Subscriber sub_7_12;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node12");
  	Node12 node12;
  	ros::spin();
  	return 0;
  }

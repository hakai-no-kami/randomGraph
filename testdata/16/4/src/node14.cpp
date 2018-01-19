
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.025742, 0.005);
  class Node14{
  	public:
  		Node14(){
			sub_7_14_flag = 0;
  			sub_7_14 = n.subscribe("topic_7_14", 1, &Node14::middlemanCallback7,this);
			sub_13_14_flag = 0;
  			sub_13_14 = n.subscribe("topic_13_14", 1, &Node14::middlemanCallback13,this);
			pub_14_15 = n.advertise<std_msgs::String>("topic_14_15", 1);
		}
		void middlemanCallback7(const std_msgs::String::ConstPtr& msg){
  			if(sub_13_14_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node14 last from node7, intercepted: [%s]", msg->data.c_str());
				pub_14_15.publish(msg);
				sub_13_14_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node14, from node7 intercepted: [%s]", msg->data.c_str());
  				sub_7_14_flag = 1;
  			}
  		}
		void middlemanCallback13(const std_msgs::String::ConstPtr& msg){
  			if(sub_7_14_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node14 last from node13, intercepted: [%s]", msg->data.c_str());
				pub_14_15.publish(msg);
				sub_7_14_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node14, from node13 intercepted: [%s]", msg->data.c_str());
  				sub_13_14_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_14_15;
		int sub_7_14_flag;
  		ros::Subscriber sub_7_14;
		int sub_13_14_flag;
  		ros::Subscriber sub_13_14;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node14");
  	Node14 node14;
  	ros::spin();
  	return 0;
  }

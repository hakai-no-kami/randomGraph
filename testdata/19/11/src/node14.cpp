
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.010806, 0.005);
  class Node14{
  	public:
  		Node14(){
			sub_9_14_flag = 0;
  			sub_9_14 = n.subscribe("topic_9_14", 1, &Node14::middlemanCallback9,this);
			sub_13_14_flag = 0;
  			sub_13_14 = n.subscribe("topic_13_14", 1, &Node14::middlemanCallback13,this);
			pub_14_17 = n.advertise<std_msgs::String>("topic_14_17", 1);
			pub_14_16 = n.advertise<std_msgs::String>("topic_14_16", 1);
		}
		void middlemanCallback9(const std_msgs::String::ConstPtr& msg){
  			if(sub_13_14_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node14 last from node9, intercepted: [%s]", msg->data.c_str());
				pub_14_17.publish(msg);
				pub_14_16.publish(msg);
				sub_13_14_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node14, from node9 intercepted: [%s]", msg->data.c_str());
  				sub_9_14_flag = 1;
  			}
  		}
		void middlemanCallback13(const std_msgs::String::ConstPtr& msg){
  			if(sub_9_14_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node14 last from node13, intercepted: [%s]", msg->data.c_str());
				pub_14_17.publish(msg);
				pub_14_16.publish(msg);
				sub_9_14_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node14, from node13 intercepted: [%s]", msg->data.c_str());
  				sub_13_14_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_14_17;
		ros::Publisher pub_14_16;
		int sub_9_14_flag;
  		ros::Subscriber sub_9_14;
		int sub_13_14_flag;
  		ros::Subscriber sub_13_14;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node14");
  	Node14 node14;
  	ros::spin();
  	return 0;
  }

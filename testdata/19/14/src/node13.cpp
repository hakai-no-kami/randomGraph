
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.017117, 0.005);
  class Node13{
  	public:
  		Node13(){
			sub_9_13_flag = 0;
  			sub_9_13 = n.subscribe("topic_9_13", 1, &Node13::middlemanCallback9,this);
			sub_11_13_flag = 0;
  			sub_11_13 = n.subscribe("topic_11_13", 1, &Node13::middlemanCallback11,this);
			pub_13_16 = n.advertise<std_msgs::String>("topic_13_16", 1);
			pub_13_15 = n.advertise<std_msgs::String>("topic_13_15", 1);
			pub_13_14 = n.advertise<std_msgs::String>("topic_13_14", 1);
		}
		void middlemanCallback9(const std_msgs::String::ConstPtr& msg){
  			if(sub_11_13_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node13 last from node9, intercepted: [%s]", msg->data.c_str());
				pub_13_16.publish(msg);
				pub_13_15.publish(msg);
				pub_13_14.publish(msg);
				sub_11_13_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node13, from node9 intercepted: [%s]", msg->data.c_str());
  				sub_9_13_flag = 1;
  			}
  		}
		void middlemanCallback11(const std_msgs::String::ConstPtr& msg){
  			if(sub_9_13_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node13 last from node11, intercepted: [%s]", msg->data.c_str());
				pub_13_16.publish(msg);
				pub_13_15.publish(msg);
				pub_13_14.publish(msg);
				sub_9_13_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node13, from node11 intercepted: [%s]", msg->data.c_str());
  				sub_11_13_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_13_16;
		ros::Publisher pub_13_15;
		ros::Publisher pub_13_14;
		int sub_9_13_flag;
  		ros::Subscriber sub_9_13;
		int sub_11_13_flag;
  		ros::Subscriber sub_11_13;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node13");
  	Node13 node13;
  	ros::spin();
  	return 0;
  }

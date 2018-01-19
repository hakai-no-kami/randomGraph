
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.017224, 0.005);
  class Node13{
  	public:
  		Node13(){
			sub_3_13_flag = 0;
  			sub_3_13 = n.subscribe("topic_3_13", 1, &Node13::middlemanCallback3,this);
			sub_8_13_flag = 0;
  			sub_8_13 = n.subscribe("topic_8_13", 1, &Node13::middlemanCallback8,this);
			sub_11_13_flag = 0;
  			sub_11_13 = n.subscribe("topic_11_13", 1, &Node13::middlemanCallback11,this);
			pub_13_18 = n.advertise<std_msgs::String>("topic_13_18", 1);
			pub_13_17 = n.advertise<std_msgs::String>("topic_13_17", 1);
			pub_13_14 = n.advertise<std_msgs::String>("topic_13_14", 1);
		}
		void middlemanCallback3(const std_msgs::String::ConstPtr& msg){
  			if(sub_8_13_flag == 1 && sub_11_13_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node13 last from node3, intercepted: [%s]", msg->data.c_str());
				pub_13_18.publish(msg);
				pub_13_17.publish(msg);
				pub_13_14.publish(msg);
				sub_8_13_flag = 0;
				sub_11_13_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node13, from node3 intercepted: [%s]", msg->data.c_str());
  				sub_3_13_flag = 1;
  			}
  		}
		void middlemanCallback8(const std_msgs::String::ConstPtr& msg){
  			if(sub_3_13_flag == 1 && sub_11_13_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node13 last from node8, intercepted: [%s]", msg->data.c_str());
				pub_13_18.publish(msg);
				pub_13_17.publish(msg);
				pub_13_14.publish(msg);
				sub_3_13_flag = 0;
				sub_11_13_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node13, from node8 intercepted: [%s]", msg->data.c_str());
  				sub_8_13_flag = 1;
  			}
  		}
		void middlemanCallback11(const std_msgs::String::ConstPtr& msg){
  			if(sub_3_13_flag == 1 && sub_8_13_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node13 last from node11, intercepted: [%s]", msg->data.c_str());
				pub_13_18.publish(msg);
				pub_13_17.publish(msg);
				pub_13_14.publish(msg);
				sub_3_13_flag = 0;
				sub_8_13_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node13, from node11 intercepted: [%s]", msg->data.c_str());
  				sub_11_13_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_13_18;
		ros::Publisher pub_13_17;
		ros::Publisher pub_13_14;
		int sub_3_13_flag;
  		ros::Subscriber sub_3_13;
		int sub_8_13_flag;
  		ros::Subscriber sub_8_13;
		int sub_11_13_flag;
  		ros::Subscriber sub_11_13;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node13");
  	Node13 node13;
  	ros::spin();
  	return 0;
  }


  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.013464, 0.005);
  class Node13{
  	public:
  		Node13(){
			sub_2_13_flag = 0;
  			sub_2_13 = n.subscribe("topic_2_13", 1, &Node13::middlemanCallback2,this);
			sub_4_13_flag = 0;
  			sub_4_13 = n.subscribe("topic_4_13", 1, &Node13::middlemanCallback4,this);
			sub_10_13_flag = 0;
  			sub_10_13 = n.subscribe("topic_10_13", 1, &Node13::middlemanCallback10,this);
			sub_12_13_flag = 0;
  			sub_12_13 = n.subscribe("topic_12_13", 1, &Node13::middlemanCallback12,this);
			pub_13_16 = n.advertise<std_msgs::String>("topic_13_16", 1);
			pub_13_15 = n.advertise<std_msgs::String>("topic_13_15", 1);
			pub_13_14 = n.advertise<std_msgs::String>("topic_13_14", 1);
		}
		void middlemanCallback2(const std_msgs::String::ConstPtr& msg){
  			if(sub_4_13_flag == 1 && sub_10_13_flag == 1 && sub_12_13_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node13 last from node2, intercepted: [%s]", msg->data.c_str());
				pub_13_16.publish(msg);
				pub_13_15.publish(msg);
				pub_13_14.publish(msg);
				sub_4_13_flag = 0;
				sub_10_13_flag = 0;
				sub_12_13_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node13, from node2 intercepted: [%s]", msg->data.c_str());
  				sub_2_13_flag = 1;
  			}
  		}
		void middlemanCallback4(const std_msgs::String::ConstPtr& msg){
  			if(sub_2_13_flag == 1 && sub_10_13_flag == 1 && sub_12_13_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node13 last from node4, intercepted: [%s]", msg->data.c_str());
				pub_13_16.publish(msg);
				pub_13_15.publish(msg);
				pub_13_14.publish(msg);
				sub_2_13_flag = 0;
				sub_10_13_flag = 0;
				sub_12_13_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node13, from node4 intercepted: [%s]", msg->data.c_str());
  				sub_4_13_flag = 1;
  			}
  		}
		void middlemanCallback10(const std_msgs::String::ConstPtr& msg){
  			if(sub_2_13_flag == 1 && sub_4_13_flag == 1 && sub_12_13_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node13 last from node10, intercepted: [%s]", msg->data.c_str());
				pub_13_16.publish(msg);
				pub_13_15.publish(msg);
				pub_13_14.publish(msg);
				sub_2_13_flag = 0;
				sub_4_13_flag = 0;
				sub_12_13_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node13, from node10 intercepted: [%s]", msg->data.c_str());
  				sub_10_13_flag = 1;
  			}
  		}
		void middlemanCallback12(const std_msgs::String::ConstPtr& msg){
  			if(sub_2_13_flag == 1 && sub_4_13_flag == 1 && sub_10_13_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node13 last from node12, intercepted: [%s]", msg->data.c_str());
				pub_13_16.publish(msg);
				pub_13_15.publish(msg);
				pub_13_14.publish(msg);
				sub_2_13_flag = 0;
				sub_4_13_flag = 0;
				sub_10_13_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node13, from node12 intercepted: [%s]", msg->data.c_str());
  				sub_12_13_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_13_16;
		ros::Publisher pub_13_15;
		ros::Publisher pub_13_14;
		int sub_2_13_flag;
  		ros::Subscriber sub_2_13;
		int sub_4_13_flag;
  		ros::Subscriber sub_4_13;
		int sub_10_13_flag;
  		ros::Subscriber sub_10_13;
		int sub_12_13_flag;
  		ros::Subscriber sub_12_13;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node13");
  	Node13 node13;
  	ros::spin();
  	return 0;
  }

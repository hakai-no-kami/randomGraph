
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.014852, 0.005);
  class Node18{
  	public:
  		Node18(){
			sub_12_18_flag = 0;
  			sub_12_18 = n.subscribe("topic_12_18", 1, &Node18::middlemanCallback12,this);
			sub_13_18_flag = 0;
  			sub_13_18 = n.subscribe("topic_13_18", 1, &Node18::middlemanCallback13,this);
			sub_14_18_flag = 0;
  			sub_14_18 = n.subscribe("topic_14_18", 1, &Node18::middlemanCallback14,this);
			sub_17_18_flag = 0;
  			sub_17_18 = n.subscribe("topic_17_18", 1, &Node18::middlemanCallback17,this);
			pub_18_20 = n.advertise<std_msgs::String>("topic_18_20", 1);
		}
		void middlemanCallback12(const std_msgs::String::ConstPtr& msg){
  			if(sub_13_18_flag == 1 && sub_14_18_flag == 1 && sub_17_18_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node18 last from node12, intercepted: [%s]", msg->data.c_str());
				pub_18_20.publish(msg);
				sub_13_18_flag = 0;
				sub_14_18_flag = 0;
				sub_17_18_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node18, from node12 intercepted: [%s]", msg->data.c_str());
  				sub_12_18_flag = 1;
  			}
  		}
		void middlemanCallback13(const std_msgs::String::ConstPtr& msg){
  			if(sub_12_18_flag == 1 && sub_14_18_flag == 1 && sub_17_18_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node18 last from node13, intercepted: [%s]", msg->data.c_str());
				pub_18_20.publish(msg);
				sub_12_18_flag = 0;
				sub_14_18_flag = 0;
				sub_17_18_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node18, from node13 intercepted: [%s]", msg->data.c_str());
  				sub_13_18_flag = 1;
  			}
  		}
		void middlemanCallback14(const std_msgs::String::ConstPtr& msg){
  			if(sub_12_18_flag == 1 && sub_13_18_flag == 1 && sub_17_18_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node18 last from node14, intercepted: [%s]", msg->data.c_str());
				pub_18_20.publish(msg);
				sub_12_18_flag = 0;
				sub_13_18_flag = 0;
				sub_17_18_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node18, from node14 intercepted: [%s]", msg->data.c_str());
  				sub_14_18_flag = 1;
  			}
  		}
		void middlemanCallback17(const std_msgs::String::ConstPtr& msg){
  			if(sub_12_18_flag == 1 && sub_13_18_flag == 1 && sub_14_18_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node18 last from node17, intercepted: [%s]", msg->data.c_str());
				pub_18_20.publish(msg);
				sub_12_18_flag = 0;
				sub_13_18_flag = 0;
				sub_14_18_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node18, from node17 intercepted: [%s]", msg->data.c_str());
  				sub_17_18_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_18_20;
		int sub_12_18_flag;
  		ros::Subscriber sub_12_18;
		int sub_13_18_flag;
  		ros::Subscriber sub_13_18;
		int sub_14_18_flag;
  		ros::Subscriber sub_14_18;
		int sub_17_18_flag;
  		ros::Subscriber sub_17_18;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node18");
  	Node18 node18;
  	ros::spin();
  	return 0;
  }

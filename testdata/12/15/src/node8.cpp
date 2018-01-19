
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.013892, 0.005);
  class Node8{
  	public:
  		Node8(){
			sub_1_8_flag = 0;
  			sub_1_8 = n.subscribe("topic_1_8", 1, &Node8::middlemanCallback1,this);
			sub_4_8_flag = 0;
  			sub_4_8 = n.subscribe("topic_4_8", 1, &Node8::middlemanCallback4,this);
			sub_5_8_flag = 0;
  			sub_5_8 = n.subscribe("topic_5_8", 1, &Node8::middlemanCallback5,this);
			sub_7_8_flag = 0;
  			sub_7_8 = n.subscribe("topic_7_8", 1, &Node8::middlemanCallback7,this);
			pub_8_10 = n.advertise<std_msgs::String>("topic_8_10", 1);
			pub_8_9 = n.advertise<std_msgs::String>("topic_8_9", 1);
		}
		void middlemanCallback1(const std_msgs::String::ConstPtr& msg){
  			if(sub_4_8_flag == 1 && sub_5_8_flag == 1 && sub_7_8_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node8 last from node1, intercepted: [%s]", msg->data.c_str());
				pub_8_10.publish(msg);
				pub_8_9.publish(msg);
				sub_4_8_flag = 0;
				sub_5_8_flag = 0;
				sub_7_8_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node8, from node1 intercepted: [%s]", msg->data.c_str());
  				sub_1_8_flag = 1;
  			}
  		}
		void middlemanCallback4(const std_msgs::String::ConstPtr& msg){
  			if(sub_1_8_flag == 1 && sub_5_8_flag == 1 && sub_7_8_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node8 last from node4, intercepted: [%s]", msg->data.c_str());
				pub_8_10.publish(msg);
				pub_8_9.publish(msg);
				sub_1_8_flag = 0;
				sub_5_8_flag = 0;
				sub_7_8_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node8, from node4 intercepted: [%s]", msg->data.c_str());
  				sub_4_8_flag = 1;
  			}
  		}
		void middlemanCallback5(const std_msgs::String::ConstPtr& msg){
  			if(sub_1_8_flag == 1 && sub_4_8_flag == 1 && sub_7_8_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node8 last from node5, intercepted: [%s]", msg->data.c_str());
				pub_8_10.publish(msg);
				pub_8_9.publish(msg);
				sub_1_8_flag = 0;
				sub_4_8_flag = 0;
				sub_7_8_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node8, from node5 intercepted: [%s]", msg->data.c_str());
  				sub_5_8_flag = 1;
  			}
  		}
		void middlemanCallback7(const std_msgs::String::ConstPtr& msg){
  			if(sub_1_8_flag == 1 && sub_4_8_flag == 1 && sub_5_8_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node8 last from node7, intercepted: [%s]", msg->data.c_str());
				pub_8_10.publish(msg);
				pub_8_9.publish(msg);
				sub_1_8_flag = 0;
				sub_4_8_flag = 0;
				sub_5_8_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node8, from node7 intercepted: [%s]", msg->data.c_str());
  				sub_7_8_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_8_10;
		ros::Publisher pub_8_9;
		int sub_1_8_flag;
  		ros::Subscriber sub_1_8;
		int sub_4_8_flag;
  		ros::Subscriber sub_4_8;
		int sub_5_8_flag;
  		ros::Subscriber sub_5_8;
		int sub_7_8_flag;
  		ros::Subscriber sub_7_8;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node8");
  	Node8 node8;
  	ros::spin();
  	return 0;
  }

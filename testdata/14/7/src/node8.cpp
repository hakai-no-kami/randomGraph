
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.018745, 0.005);
  class Node8{
  	public:
  		Node8(){
			sub_2_8_flag = 0;
  			sub_2_8 = n.subscribe("topic_2_8", 1, &Node8::middlemanCallback2,this);
			sub_3_8_flag = 0;
  			sub_3_8 = n.subscribe("topic_3_8", 1, &Node8::middlemanCallback3,this);
			sub_6_8_flag = 0;
  			sub_6_8 = n.subscribe("topic_6_8", 1, &Node8::middlemanCallback6,this);
			sub_7_8_flag = 0;
  			sub_7_8 = n.subscribe("topic_7_8", 1, &Node8::middlemanCallback7,this);
			pub_8_11 = n.advertise<std_msgs::String>("topic_8_11", 1);
			pub_8_10 = n.advertise<std_msgs::String>("topic_8_10", 1);
			pub_8_9 = n.advertise<std_msgs::String>("topic_8_9", 1);
		}
		void middlemanCallback2(const std_msgs::String::ConstPtr& msg){
  			if(sub_3_8_flag == 1 && sub_6_8_flag == 1 && sub_7_8_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node8 last from node2, intercepted: [%s]", msg->data.c_str());
				pub_8_11.publish(msg);
				pub_8_10.publish(msg);
				pub_8_9.publish(msg);
				sub_3_8_flag = 0;
				sub_6_8_flag = 0;
				sub_7_8_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node8, from node2 intercepted: [%s]", msg->data.c_str());
  				sub_2_8_flag = 1;
  			}
  		}
		void middlemanCallback3(const std_msgs::String::ConstPtr& msg){
  			if(sub_2_8_flag == 1 && sub_6_8_flag == 1 && sub_7_8_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node8 last from node3, intercepted: [%s]", msg->data.c_str());
				pub_8_11.publish(msg);
				pub_8_10.publish(msg);
				pub_8_9.publish(msg);
				sub_2_8_flag = 0;
				sub_6_8_flag = 0;
				sub_7_8_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node8, from node3 intercepted: [%s]", msg->data.c_str());
  				sub_3_8_flag = 1;
  			}
  		}
		void middlemanCallback6(const std_msgs::String::ConstPtr& msg){
  			if(sub_2_8_flag == 1 && sub_3_8_flag == 1 && sub_7_8_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node8 last from node6, intercepted: [%s]", msg->data.c_str());
				pub_8_11.publish(msg);
				pub_8_10.publish(msg);
				pub_8_9.publish(msg);
				sub_2_8_flag = 0;
				sub_3_8_flag = 0;
				sub_7_8_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node8, from node6 intercepted: [%s]", msg->data.c_str());
  				sub_6_8_flag = 1;
  			}
  		}
		void middlemanCallback7(const std_msgs::String::ConstPtr& msg){
  			if(sub_2_8_flag == 1 && sub_3_8_flag == 1 && sub_6_8_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node8 last from node7, intercepted: [%s]", msg->data.c_str());
				pub_8_11.publish(msg);
				pub_8_10.publish(msg);
				pub_8_9.publish(msg);
				sub_2_8_flag = 0;
				sub_3_8_flag = 0;
				sub_6_8_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node8, from node7 intercepted: [%s]", msg->data.c_str());
  				sub_7_8_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_8_11;
		ros::Publisher pub_8_10;
		ros::Publisher pub_8_9;
		int sub_2_8_flag;
  		ros::Subscriber sub_2_8;
		int sub_3_8_flag;
  		ros::Subscriber sub_3_8;
		int sub_6_8_flag;
  		ros::Subscriber sub_6_8;
		int sub_7_8_flag;
  		ros::Subscriber sub_7_8;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node8");
  	Node8 node8;
  	ros::spin();
  	return 0;
  }

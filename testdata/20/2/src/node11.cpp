
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.022082, 0.005);
  class Node11{
  	public:
  		Node11(){
			sub_1_11_flag = 0;
  			sub_1_11 = n.subscribe("topic_1_11", 1, &Node11::middlemanCallback1,this);
			sub_3_11_flag = 0;
  			sub_3_11 = n.subscribe("topic_3_11", 1, &Node11::middlemanCallback3,this);
			sub_4_11_flag = 0;
  			sub_4_11 = n.subscribe("topic_4_11", 1, &Node11::middlemanCallback4,this);
			sub_7_11_flag = 0;
  			sub_7_11 = n.subscribe("topic_7_11", 1, &Node11::middlemanCallback7,this);
			pub_11_15 = n.advertise<std_msgs::String>("topic_11_15", 1);
		}
		void middlemanCallback1(const std_msgs::String::ConstPtr& msg){
  			if(sub_3_11_flag == 1 && sub_4_11_flag == 1 && sub_7_11_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node11 last from node1, intercepted: [%s]", msg->data.c_str());
				pub_11_15.publish(msg);
				sub_3_11_flag = 0;
				sub_4_11_flag = 0;
				sub_7_11_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node11, from node1 intercepted: [%s]", msg->data.c_str());
  				sub_1_11_flag = 1;
  			}
  		}
		void middlemanCallback3(const std_msgs::String::ConstPtr& msg){
  			if(sub_1_11_flag == 1 && sub_4_11_flag == 1 && sub_7_11_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node11 last from node3, intercepted: [%s]", msg->data.c_str());
				pub_11_15.publish(msg);
				sub_1_11_flag = 0;
				sub_4_11_flag = 0;
				sub_7_11_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node11, from node3 intercepted: [%s]", msg->data.c_str());
  				sub_3_11_flag = 1;
  			}
  		}
		void middlemanCallback4(const std_msgs::String::ConstPtr& msg){
  			if(sub_1_11_flag == 1 && sub_3_11_flag == 1 && sub_7_11_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node11 last from node4, intercepted: [%s]", msg->data.c_str());
				pub_11_15.publish(msg);
				sub_1_11_flag = 0;
				sub_3_11_flag = 0;
				sub_7_11_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node11, from node4 intercepted: [%s]", msg->data.c_str());
  				sub_4_11_flag = 1;
  			}
  		}
		void middlemanCallback7(const std_msgs::String::ConstPtr& msg){
  			if(sub_1_11_flag == 1 && sub_3_11_flag == 1 && sub_4_11_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node11 last from node7, intercepted: [%s]", msg->data.c_str());
				pub_11_15.publish(msg);
				sub_1_11_flag = 0;
				sub_3_11_flag = 0;
				sub_4_11_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node11, from node7 intercepted: [%s]", msg->data.c_str());
  				sub_7_11_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_11_15;
		int sub_1_11_flag;
  		ros::Subscriber sub_1_11;
		int sub_3_11_flag;
  		ros::Subscriber sub_3_11;
		int sub_4_11_flag;
  		ros::Subscriber sub_4_11;
		int sub_7_11_flag;
  		ros::Subscriber sub_7_11;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node11");
  	Node11 node11;
  	ros::spin();
  	return 0;
  }


  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.020498, 0.005);
  class Node16{
  	public:
  		Node16(){
			sub_5_16_flag = 0;
  			sub_5_16 = n.subscribe("topic_5_16", 1, &Node16::middlemanCallback5,this);
			sub_10_16_flag = 0;
  			sub_10_16 = n.subscribe("topic_10_16", 1, &Node16::middlemanCallback10,this);
			sub_11_16_flag = 0;
  			sub_11_16 = n.subscribe("topic_11_16", 1, &Node16::middlemanCallback11,this);
			sub_15_16_flag = 0;
  			sub_15_16 = n.subscribe("topic_15_16", 1, &Node16::middlemanCallback15,this);
			pub_16_17 = n.advertise<std_msgs::String>("topic_16_17", 1);
		}
		void middlemanCallback5(const std_msgs::String::ConstPtr& msg){
  			if(sub_10_16_flag == 1 && sub_11_16_flag == 1 && sub_15_16_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node16 last from node5, intercepted: [%s]", msg->data.c_str());
				pub_16_17.publish(msg);
				sub_10_16_flag = 0;
				sub_11_16_flag = 0;
				sub_15_16_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node16, from node5 intercepted: [%s]", msg->data.c_str());
  				sub_5_16_flag = 1;
  			}
  		}
		void middlemanCallback10(const std_msgs::String::ConstPtr& msg){
  			if(sub_5_16_flag == 1 && sub_11_16_flag == 1 && sub_15_16_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node16 last from node10, intercepted: [%s]", msg->data.c_str());
				pub_16_17.publish(msg);
				sub_5_16_flag = 0;
				sub_11_16_flag = 0;
				sub_15_16_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node16, from node10 intercepted: [%s]", msg->data.c_str());
  				sub_10_16_flag = 1;
  			}
  		}
		void middlemanCallback11(const std_msgs::String::ConstPtr& msg){
  			if(sub_5_16_flag == 1 && sub_10_16_flag == 1 && sub_15_16_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node16 last from node11, intercepted: [%s]", msg->data.c_str());
				pub_16_17.publish(msg);
				sub_5_16_flag = 0;
				sub_10_16_flag = 0;
				sub_15_16_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node16, from node11 intercepted: [%s]", msg->data.c_str());
  				sub_11_16_flag = 1;
  			}
  		}
		void middlemanCallback15(const std_msgs::String::ConstPtr& msg){
  			if(sub_5_16_flag == 1 && sub_10_16_flag == 1 && sub_11_16_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node16 last from node15, intercepted: [%s]", msg->data.c_str());
				pub_16_17.publish(msg);
				sub_5_16_flag = 0;
				sub_10_16_flag = 0;
				sub_11_16_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node16, from node15 intercepted: [%s]", msg->data.c_str());
  				sub_15_16_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_16_17;
		int sub_5_16_flag;
  		ros::Subscriber sub_5_16;
		int sub_10_16_flag;
  		ros::Subscriber sub_10_16;
		int sub_11_16_flag;
  		ros::Subscriber sub_11_16;
		int sub_15_16_flag;
  		ros::Subscriber sub_15_16;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node16");
  	Node16 node16;
  	ros::spin();
  	return 0;
  }

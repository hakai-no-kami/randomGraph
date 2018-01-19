
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.028327, 0.005);
  class Node16{
  	public:
  		Node16(){
			sub_2_16_flag = 0;
  			sub_2_16 = n.subscribe("topic_2_16", 1, &Node16::middlemanCallback2,this);
			sub_11_16_flag = 0;
  			sub_11_16 = n.subscribe("topic_11_16", 1, &Node16::middlemanCallback11,this);
			sub_14_16_flag = 0;
  			sub_14_16 = n.subscribe("topic_14_16", 1, &Node16::middlemanCallback14,this);
			sub_15_16_flag = 0;
  			sub_15_16 = n.subscribe("topic_15_16", 1, &Node16::middlemanCallback15,this);
			pub_16_19 = n.advertise<std_msgs::String>("topic_16_19", 1);
			pub_16_18 = n.advertise<std_msgs::String>("topic_16_18", 1);
		}
		void middlemanCallback2(const std_msgs::String::ConstPtr& msg){
  			if(sub_11_16_flag == 1 && sub_14_16_flag == 1 && sub_15_16_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node16 last from node2, intercepted: [%s]", msg->data.c_str());
				pub_16_19.publish(msg);
				pub_16_18.publish(msg);
				sub_11_16_flag = 0;
				sub_14_16_flag = 0;
				sub_15_16_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node16, from node2 intercepted: [%s]", msg->data.c_str());
  				sub_2_16_flag = 1;
  			}
  		}
		void middlemanCallback11(const std_msgs::String::ConstPtr& msg){
  			if(sub_2_16_flag == 1 && sub_14_16_flag == 1 && sub_15_16_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node16 last from node11, intercepted: [%s]", msg->data.c_str());
				pub_16_19.publish(msg);
				pub_16_18.publish(msg);
				sub_2_16_flag = 0;
				sub_14_16_flag = 0;
				sub_15_16_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node16, from node11 intercepted: [%s]", msg->data.c_str());
  				sub_11_16_flag = 1;
  			}
  		}
		void middlemanCallback14(const std_msgs::String::ConstPtr& msg){
  			if(sub_2_16_flag == 1 && sub_11_16_flag == 1 && sub_15_16_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node16 last from node14, intercepted: [%s]", msg->data.c_str());
				pub_16_19.publish(msg);
				pub_16_18.publish(msg);
				sub_2_16_flag = 0;
				sub_11_16_flag = 0;
				sub_15_16_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node16, from node14 intercepted: [%s]", msg->data.c_str());
  				sub_14_16_flag = 1;
  			}
  		}
		void middlemanCallback15(const std_msgs::String::ConstPtr& msg){
  			if(sub_2_16_flag == 1 && sub_11_16_flag == 1 && sub_14_16_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node16 last from node15, intercepted: [%s]", msg->data.c_str());
				pub_16_19.publish(msg);
				pub_16_18.publish(msg);
				sub_2_16_flag = 0;
				sub_11_16_flag = 0;
				sub_14_16_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node16, from node15 intercepted: [%s]", msg->data.c_str());
  				sub_15_16_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_16_19;
		ros::Publisher pub_16_18;
		int sub_2_16_flag;
  		ros::Subscriber sub_2_16;
		int sub_11_16_flag;
  		ros::Subscriber sub_11_16;
		int sub_14_16_flag;
  		ros::Subscriber sub_14_16;
		int sub_15_16_flag;
  		ros::Subscriber sub_15_16;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node16");
  	Node16 node16;
  	ros::spin();
  	return 0;
  }

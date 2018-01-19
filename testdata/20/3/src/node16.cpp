
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.021945, 0.005);
  class Node16{
  	public:
  		Node16(){
			sub_3_16_flag = 0;
  			sub_3_16 = n.subscribe("topic_3_16", 1, &Node16::middlemanCallback3,this);
			sub_11_16_flag = 0;
  			sub_11_16 = n.subscribe("topic_11_16", 1, &Node16::middlemanCallback11,this);
			sub_12_16_flag = 0;
  			sub_12_16 = n.subscribe("topic_12_16", 1, &Node16::middlemanCallback12,this);
			pub_16_18 = n.advertise<std_msgs::String>("topic_16_18", 1);
		}
		void middlemanCallback3(const std_msgs::String::ConstPtr& msg){
  			if(sub_11_16_flag == 1 && sub_12_16_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node16 last from node3, intercepted: [%s]", msg->data.c_str());
				pub_16_18.publish(msg);
				sub_11_16_flag = 0;
				sub_12_16_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node16, from node3 intercepted: [%s]", msg->data.c_str());
  				sub_3_16_flag = 1;
  			}
  		}
		void middlemanCallback11(const std_msgs::String::ConstPtr& msg){
  			if(sub_3_16_flag == 1 && sub_12_16_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node16 last from node11, intercepted: [%s]", msg->data.c_str());
				pub_16_18.publish(msg);
				sub_3_16_flag = 0;
				sub_12_16_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node16, from node11 intercepted: [%s]", msg->data.c_str());
  				sub_11_16_flag = 1;
  			}
  		}
		void middlemanCallback12(const std_msgs::String::ConstPtr& msg){
  			if(sub_3_16_flag == 1 && sub_11_16_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node16 last from node12, intercepted: [%s]", msg->data.c_str());
				pub_16_18.publish(msg);
				sub_3_16_flag = 0;
				sub_11_16_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node16, from node12 intercepted: [%s]", msg->data.c_str());
  				sub_12_16_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_16_18;
		int sub_3_16_flag;
  		ros::Subscriber sub_3_16;
		int sub_11_16_flag;
  		ros::Subscriber sub_11_16;
		int sub_12_16_flag;
  		ros::Subscriber sub_12_16;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node16");
  	Node16 node16;
  	ros::spin();
  	return 0;
  }

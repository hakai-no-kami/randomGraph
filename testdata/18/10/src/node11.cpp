
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.019247, 0.005);
  class Node11{
  	public:
  		Node11(){
			sub_1_11_flag = 0;
  			sub_1_11 = n.subscribe("topic_1_11", 1, &Node11::middlemanCallback1,this);
			sub_5_11_flag = 0;
  			sub_5_11 = n.subscribe("topic_5_11", 1, &Node11::middlemanCallback5,this);
			pub_11_13 = n.advertise<std_msgs::String>("topic_11_13", 1);
			pub_11_12 = n.advertise<std_msgs::String>("topic_11_12", 1);
		}
		void middlemanCallback1(const std_msgs::String::ConstPtr& msg){
  			if(sub_5_11_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node11 last from node1, intercepted: [%s]", msg->data.c_str());
				pub_11_13.publish(msg);
				pub_11_12.publish(msg);
				sub_5_11_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node11, from node1 intercepted: [%s]", msg->data.c_str());
  				sub_1_11_flag = 1;
  			}
  		}
		void middlemanCallback5(const std_msgs::String::ConstPtr& msg){
  			if(sub_1_11_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node11 last from node5, intercepted: [%s]", msg->data.c_str());
				pub_11_13.publish(msg);
				pub_11_12.publish(msg);
				sub_1_11_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node11, from node5 intercepted: [%s]", msg->data.c_str());
  				sub_5_11_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_11_13;
		ros::Publisher pub_11_12;
		int sub_1_11_flag;
  		ros::Subscriber sub_1_11;
		int sub_5_11_flag;
  		ros::Subscriber sub_5_11;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node11");
  	Node11 node11;
  	ros::spin();
  	return 0;
  }


  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.021305, 0.005);
  class Node11{
  	public:
  		Node11(){
			sub_2_11_flag = 0;
  			sub_2_11 = n.subscribe("topic_2_11", 1, &Node11::middlemanCallback2,this);
			sub_3_11_flag = 0;
  			sub_3_11 = n.subscribe("topic_3_11", 1, &Node11::middlemanCallback3,this);
			sub_10_11_flag = 0;
  			sub_10_11 = n.subscribe("topic_10_11", 1, &Node11::middlemanCallback10,this);
			pub_11_14 = n.advertise<std_msgs::String>("topic_11_14", 1);
		}
		void middlemanCallback2(const std_msgs::String::ConstPtr& msg){
  			if(sub_3_11_flag == 1 && sub_10_11_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node11 last from node2, intercepted: [%s]", msg->data.c_str());
				pub_11_14.publish(msg);
				sub_3_11_flag = 0;
				sub_10_11_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node11, from node2 intercepted: [%s]", msg->data.c_str());
  				sub_2_11_flag = 1;
  			}
  		}
		void middlemanCallback3(const std_msgs::String::ConstPtr& msg){
  			if(sub_2_11_flag == 1 && sub_10_11_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node11 last from node3, intercepted: [%s]", msg->data.c_str());
				pub_11_14.publish(msg);
				sub_2_11_flag = 0;
				sub_10_11_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node11, from node3 intercepted: [%s]", msg->data.c_str());
  				sub_3_11_flag = 1;
  			}
  		}
		void middlemanCallback10(const std_msgs::String::ConstPtr& msg){
  			if(sub_2_11_flag == 1 && sub_3_11_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node11 last from node10, intercepted: [%s]", msg->data.c_str());
				pub_11_14.publish(msg);
				sub_2_11_flag = 0;
				sub_3_11_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node11, from node10 intercepted: [%s]", msg->data.c_str());
  				sub_10_11_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_11_14;
		int sub_2_11_flag;
  		ros::Subscriber sub_2_11;
		int sub_3_11_flag;
  		ros::Subscriber sub_3_11;
		int sub_10_11_flag;
  		ros::Subscriber sub_10_11;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node11");
  	Node11 node11;
  	ros::spin();
  	return 0;
  }

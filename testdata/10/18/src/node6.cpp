
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.021068, 0.005);
  class Node6{
  	public:
  		Node6(){
			sub_2_6_flag = 0;
  			sub_2_6 = n.subscribe("topic_2_6", 1, &Node6::middlemanCallback2,this);
			sub_4_6_flag = 0;
  			sub_4_6 = n.subscribe("topic_4_6", 1, &Node6::middlemanCallback4,this);
			sub_5_6_flag = 0;
  			sub_5_6 = n.subscribe("topic_5_6", 1, &Node6::middlemanCallback5,this);
			pub_6_8 = n.advertise<std_msgs::String>("topic_6_8", 1);
			pub_6_7 = n.advertise<std_msgs::String>("topic_6_7", 1);
		}
		void middlemanCallback2(const std_msgs::String::ConstPtr& msg){
  			if(sub_4_6_flag == 1 && sub_5_6_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node6 last from node2, intercepted: [%s]", msg->data.c_str());
				pub_6_8.publish(msg);
				pub_6_7.publish(msg);
				sub_4_6_flag = 0;
				sub_5_6_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node6, from node2 intercepted: [%s]", msg->data.c_str());
  				sub_2_6_flag = 1;
  			}
  		}
		void middlemanCallback4(const std_msgs::String::ConstPtr& msg){
  			if(sub_2_6_flag == 1 && sub_5_6_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node6 last from node4, intercepted: [%s]", msg->data.c_str());
				pub_6_8.publish(msg);
				pub_6_7.publish(msg);
				sub_2_6_flag = 0;
				sub_5_6_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node6, from node4 intercepted: [%s]", msg->data.c_str());
  				sub_4_6_flag = 1;
  			}
  		}
		void middlemanCallback5(const std_msgs::String::ConstPtr& msg){
  			if(sub_2_6_flag == 1 && sub_4_6_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node6 last from node5, intercepted: [%s]", msg->data.c_str());
				pub_6_8.publish(msg);
				pub_6_7.publish(msg);
				sub_2_6_flag = 0;
				sub_4_6_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node6, from node5 intercepted: [%s]", msg->data.c_str());
  				sub_5_6_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_6_8;
		ros::Publisher pub_6_7;
		int sub_2_6_flag;
  		ros::Subscriber sub_2_6;
		int sub_4_6_flag;
  		ros::Subscriber sub_4_6;
		int sub_5_6_flag;
  		ros::Subscriber sub_5_6;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node6");
  	Node6 node6;
  	ros::spin();
  	return 0;
  }


  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.010771, 0.005);
  class Node9{
  	public:
  		Node9(){
			sub_3_9_flag = 0;
  			sub_3_9 = n.subscribe("topic_3_9", 1, &Node9::middlemanCallback3,this);
			sub_5_9_flag = 0;
  			sub_5_9 = n.subscribe("topic_5_9", 1, &Node9::middlemanCallback5,this);
			sub_8_9_flag = 0;
  			sub_8_9 = n.subscribe("topic_8_9", 1, &Node9::middlemanCallback8,this);
			pub_9_14 = n.advertise<std_msgs::String>("topic_9_14", 1);
		}
		void middlemanCallback3(const std_msgs::String::ConstPtr& msg){
  			if(sub_5_9_flag == 1 && sub_8_9_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node9 last from node3, intercepted: [%s]", msg->data.c_str());
				pub_9_14.publish(msg);
				sub_5_9_flag = 0;
				sub_8_9_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node9, from node3 intercepted: [%s]", msg->data.c_str());
  				sub_3_9_flag = 1;
  			}
  		}
		void middlemanCallback5(const std_msgs::String::ConstPtr& msg){
  			if(sub_3_9_flag == 1 && sub_8_9_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node9 last from node5, intercepted: [%s]", msg->data.c_str());
				pub_9_14.publish(msg);
				sub_3_9_flag = 0;
				sub_8_9_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node9, from node5 intercepted: [%s]", msg->data.c_str());
  				sub_5_9_flag = 1;
  			}
  		}
		void middlemanCallback8(const std_msgs::String::ConstPtr& msg){
  			if(sub_3_9_flag == 1 && sub_5_9_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node9 last from node8, intercepted: [%s]", msg->data.c_str());
				pub_9_14.publish(msg);
				sub_3_9_flag = 0;
				sub_5_9_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node9, from node8 intercepted: [%s]", msg->data.c_str());
  				sub_8_9_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_9_14;
		int sub_3_9_flag;
  		ros::Subscriber sub_3_9;
		int sub_5_9_flag;
  		ros::Subscriber sub_5_9;
		int sub_8_9_flag;
  		ros::Subscriber sub_8_9;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node9");
  	Node9 node9;
  	ros::spin();
  	return 0;
  }

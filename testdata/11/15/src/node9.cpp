
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.021742, 0.005);
  class Node9{
  	public:
  		Node9(){
			sub_3_9_flag = 0;
  			sub_3_9 = n.subscribe("topic_3_9", 1, &Node9::middlemanCallback3,this);
			sub_6_9_flag = 0;
  			sub_6_9 = n.subscribe("topic_6_9", 1, &Node9::middlemanCallback6,this);
			sub_7_9_flag = 0;
  			sub_7_9 = n.subscribe("topic_7_9", 1, &Node9::middlemanCallback7,this);
			pub_9_11 = n.advertise<std_msgs::String>("topic_9_11", 1);
		}
		void middlemanCallback3(const std_msgs::String::ConstPtr& msg){
  			if(sub_6_9_flag == 1 && sub_7_9_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node9 last from node3, intercepted: [%s]", msg->data.c_str());
				pub_9_11.publish(msg);
				sub_6_9_flag = 0;
				sub_7_9_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node9, from node3 intercepted: [%s]", msg->data.c_str());
  				sub_3_9_flag = 1;
  			}
  		}
		void middlemanCallback6(const std_msgs::String::ConstPtr& msg){
  			if(sub_3_9_flag == 1 && sub_7_9_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node9 last from node6, intercepted: [%s]", msg->data.c_str());
				pub_9_11.publish(msg);
				sub_3_9_flag = 0;
				sub_7_9_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node9, from node6 intercepted: [%s]", msg->data.c_str());
  				sub_6_9_flag = 1;
  			}
  		}
		void middlemanCallback7(const std_msgs::String::ConstPtr& msg){
  			if(sub_3_9_flag == 1 && sub_6_9_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node9 last from node7, intercepted: [%s]", msg->data.c_str());
				pub_9_11.publish(msg);
				sub_3_9_flag = 0;
				sub_6_9_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node9, from node7 intercepted: [%s]", msg->data.c_str());
  				sub_7_9_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_9_11;
		int sub_3_9_flag;
  		ros::Subscriber sub_3_9;
		int sub_6_9_flag;
  		ros::Subscriber sub_6_9;
		int sub_7_9_flag;
  		ros::Subscriber sub_7_9;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node9");
  	Node9 node9;
  	ros::spin();
  	return 0;
  }

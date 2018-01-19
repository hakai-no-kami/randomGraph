
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.013927, 0.005);
  class Node9{
  	public:
  		Node9(){
			sub_4_9_flag = 0;
  			sub_4_9 = n.subscribe("topic_4_9", 1, &Node9::middlemanCallback4,this);
			sub_6_9_flag = 0;
  			sub_6_9 = n.subscribe("topic_6_9", 1, &Node9::middlemanCallback6,this);
			pub_9_10 = n.advertise<std_msgs::String>("topic_9_10", 1);
		}
		void middlemanCallback4(const std_msgs::String::ConstPtr& msg){
  			if(sub_6_9_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node9 last from node4, intercepted: [%s]", msg->data.c_str());
				pub_9_10.publish(msg);
				sub_6_9_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node9, from node4 intercepted: [%s]", msg->data.c_str());
  				sub_4_9_flag = 1;
  			}
  		}
		void middlemanCallback6(const std_msgs::String::ConstPtr& msg){
  			if(sub_4_9_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node9 last from node6, intercepted: [%s]", msg->data.c_str());
				pub_9_10.publish(msg);
				sub_4_9_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node9, from node6 intercepted: [%s]", msg->data.c_str());
  				sub_6_9_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_9_10;
		int sub_4_9_flag;
  		ros::Subscriber sub_4_9;
		int sub_6_9_flag;
  		ros::Subscriber sub_6_9;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node9");
  	Node9 node9;
  	ros::spin();
  	return 0;
  }


  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.016813, 0.005);
  class Node7{
  	public:
  		Node7(){
			sub_2_7_flag = 0;
  			sub_2_7 = n.subscribe("topic_2_7", 1, &Node7::middlemanCallback2,this);
			sub_6_7_flag = 0;
  			sub_6_7 = n.subscribe("topic_6_7", 1, &Node7::middlemanCallback6,this);
			pub_7_19 = n.advertise<std_msgs::String>("topic_7_19", 1);
		}
		void middlemanCallback2(const std_msgs::String::ConstPtr& msg){
  			if(sub_6_7_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node7 last from node2, intercepted: [%s]", msg->data.c_str());
				pub_7_19.publish(msg);
				sub_6_7_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node7, from node2 intercepted: [%s]", msg->data.c_str());
  				sub_2_7_flag = 1;
  			}
  		}
		void middlemanCallback6(const std_msgs::String::ConstPtr& msg){
  			if(sub_2_7_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node7 last from node6, intercepted: [%s]", msg->data.c_str());
				pub_7_19.publish(msg);
				sub_2_7_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node7, from node6 intercepted: [%s]", msg->data.c_str());
  				sub_6_7_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_7_19;
		int sub_2_7_flag;
  		ros::Subscriber sub_2_7;
		int sub_6_7_flag;
  		ros::Subscriber sub_6_7;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node7");
  	Node7 node7;
  	ros::spin();
  	return 0;
  }

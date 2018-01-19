
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.029057, 0.005);
  class Node14{
  	public:
  		Node14(){
			sub_3_14_flag = 0;
  			sub_3_14 = n.subscribe("topic_3_14", 1, &Node14::middlemanCallback3,this);
			sub_9_14_flag = 0;
  			sub_9_14 = n.subscribe("topic_9_14", 1, &Node14::middlemanCallback9,this);
			sub_12_14_flag = 0;
  			sub_12_14 = n.subscribe("topic_12_14", 1, &Node14::middlemanCallback12,this);
			pub_14_19 = n.advertise<std_msgs::String>("topic_14_19", 1);
		}
		void middlemanCallback3(const std_msgs::String::ConstPtr& msg){
  			if(sub_9_14_flag == 1 && sub_12_14_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node14 last from node3, intercepted: [%s]", msg->data.c_str());
				pub_14_19.publish(msg);
				sub_9_14_flag = 0;
				sub_12_14_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node14, from node3 intercepted: [%s]", msg->data.c_str());
  				sub_3_14_flag = 1;
  			}
  		}
		void middlemanCallback9(const std_msgs::String::ConstPtr& msg){
  			if(sub_3_14_flag == 1 && sub_12_14_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node14 last from node9, intercepted: [%s]", msg->data.c_str());
				pub_14_19.publish(msg);
				sub_3_14_flag = 0;
				sub_12_14_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node14, from node9 intercepted: [%s]", msg->data.c_str());
  				sub_9_14_flag = 1;
  			}
  		}
		void middlemanCallback12(const std_msgs::String::ConstPtr& msg){
  			if(sub_3_14_flag == 1 && sub_9_14_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node14 last from node12, intercepted: [%s]", msg->data.c_str());
				pub_14_19.publish(msg);
				sub_3_14_flag = 0;
				sub_9_14_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node14, from node12 intercepted: [%s]", msg->data.c_str());
  				sub_12_14_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_14_19;
		int sub_3_14_flag;
  		ros::Subscriber sub_3_14;
		int sub_9_14_flag;
  		ros::Subscriber sub_9_14;
		int sub_12_14_flag;
  		ros::Subscriber sub_12_14;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node14");
  	Node14 node14;
  	ros::spin();
  	return 0;
  }

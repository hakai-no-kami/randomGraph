
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.013552, 0.005);
  class Node17{
  	public:
  		Node17(){
			sub_13_17_flag = 0;
  			sub_13_17 = n.subscribe("topic_13_17", 1, &Node17::middlemanCallback13,this);
			sub_14_17_flag = 0;
  			sub_14_17 = n.subscribe("topic_14_17", 1, &Node17::middlemanCallback14,this);
			sub_16_17_flag = 0;
  			sub_16_17 = n.subscribe("topic_16_17", 1, &Node17::middlemanCallback16,this);
			pub_17_19 = n.advertise<std_msgs::String>("topic_17_19", 1);
		}
		void middlemanCallback13(const std_msgs::String::ConstPtr& msg){
  			if(sub_14_17_flag == 1 && sub_16_17_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node17 last from node13, intercepted: [%s]", msg->data.c_str());
				pub_17_19.publish(msg);
				sub_14_17_flag = 0;
				sub_16_17_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node17, from node13 intercepted: [%s]", msg->data.c_str());
  				sub_13_17_flag = 1;
  			}
  		}
		void middlemanCallback14(const std_msgs::String::ConstPtr& msg){
  			if(sub_13_17_flag == 1 && sub_16_17_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node17 last from node14, intercepted: [%s]", msg->data.c_str());
				pub_17_19.publish(msg);
				sub_13_17_flag = 0;
				sub_16_17_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node17, from node14 intercepted: [%s]", msg->data.c_str());
  				sub_14_17_flag = 1;
  			}
  		}
		void middlemanCallback16(const std_msgs::String::ConstPtr& msg){
  			if(sub_13_17_flag == 1 && sub_14_17_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node17 last from node16, intercepted: [%s]", msg->data.c_str());
				pub_17_19.publish(msg);
				sub_13_17_flag = 0;
				sub_14_17_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node17, from node16 intercepted: [%s]", msg->data.c_str());
  				sub_16_17_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_17_19;
		int sub_13_17_flag;
  		ros::Subscriber sub_13_17;
		int sub_14_17_flag;
  		ros::Subscriber sub_14_17;
		int sub_16_17_flag;
  		ros::Subscriber sub_16_17;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node17");
  	Node17 node17;
  	ros::spin();
  	return 0;
  }

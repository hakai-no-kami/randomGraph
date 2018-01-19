
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.021652, 0.005);
  class Node17{
  	public:
  		Node17(){
			sub_9_17_flag = 0;
  			sub_9_17 = n.subscribe("topic_9_17", 1, &Node17::middlemanCallback9,this);
			sub_10_17_flag = 0;
  			sub_10_17 = n.subscribe("topic_10_17", 1, &Node17::middlemanCallback10,this);
			sub_16_17_flag = 0;
  			sub_16_17 = n.subscribe("topic_16_17", 1, &Node17::middlemanCallback16,this);
			pub_17_18 = n.advertise<std_msgs::String>("topic_17_18", 1);
		}
		void middlemanCallback9(const std_msgs::String::ConstPtr& msg){
  			if(sub_10_17_flag == 1 && sub_16_17_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node17 last from node9, intercepted: [%s]", msg->data.c_str());
				pub_17_18.publish(msg);
				sub_10_17_flag = 0;
				sub_16_17_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node17, from node9 intercepted: [%s]", msg->data.c_str());
  				sub_9_17_flag = 1;
  			}
  		}
		void middlemanCallback10(const std_msgs::String::ConstPtr& msg){
  			if(sub_9_17_flag == 1 && sub_16_17_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node17 last from node10, intercepted: [%s]", msg->data.c_str());
				pub_17_18.publish(msg);
				sub_9_17_flag = 0;
				sub_16_17_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node17, from node10 intercepted: [%s]", msg->data.c_str());
  				sub_10_17_flag = 1;
  			}
  		}
		void middlemanCallback16(const std_msgs::String::ConstPtr& msg){
  			if(sub_9_17_flag == 1 && sub_10_17_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node17 last from node16, intercepted: [%s]", msg->data.c_str());
				pub_17_18.publish(msg);
				sub_9_17_flag = 0;
				sub_10_17_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node17, from node16 intercepted: [%s]", msg->data.c_str());
  				sub_16_17_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_17_18;
		int sub_9_17_flag;
  		ros::Subscriber sub_9_17;
		int sub_10_17_flag;
  		ros::Subscriber sub_10_17;
		int sub_16_17_flag;
  		ros::Subscriber sub_16_17;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node17");
  	Node17 node17;
  	ros::spin();
  	return 0;
  }

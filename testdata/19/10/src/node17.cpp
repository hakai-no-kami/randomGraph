
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.010364, 0.005);
  class Node17{
  	public:
  		Node17(){
			sub_9_17_flag = 0;
  			sub_9_17 = n.subscribe("topic_9_17", 1, &Node17::middlemanCallback9,this);
			sub_12_17_flag = 0;
  			sub_12_17 = n.subscribe("topic_12_17", 1, &Node17::middlemanCallback12,this);
			sub_15_17_flag = 0;
  			sub_15_17 = n.subscribe("topic_15_17", 1, &Node17::middlemanCallback15,this);
			pub_17_18 = n.advertise<std_msgs::String>("topic_17_18", 1);
		}
		void middlemanCallback9(const std_msgs::String::ConstPtr& msg){
  			if(sub_12_17_flag == 1 && sub_15_17_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node17 last from node9, intercepted: [%s]", msg->data.c_str());
				pub_17_18.publish(msg);
				sub_12_17_flag = 0;
				sub_15_17_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node17, from node9 intercepted: [%s]", msg->data.c_str());
  				sub_9_17_flag = 1;
  			}
  		}
		void middlemanCallback12(const std_msgs::String::ConstPtr& msg){
  			if(sub_9_17_flag == 1 && sub_15_17_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node17 last from node12, intercepted: [%s]", msg->data.c_str());
				pub_17_18.publish(msg);
				sub_9_17_flag = 0;
				sub_15_17_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node17, from node12 intercepted: [%s]", msg->data.c_str());
  				sub_12_17_flag = 1;
  			}
  		}
		void middlemanCallback15(const std_msgs::String::ConstPtr& msg){
  			if(sub_9_17_flag == 1 && sub_12_17_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node17 last from node15, intercepted: [%s]", msg->data.c_str());
				pub_17_18.publish(msg);
				sub_9_17_flag = 0;
				sub_12_17_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node17, from node15 intercepted: [%s]", msg->data.c_str());
  				sub_15_17_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_17_18;
		int sub_9_17_flag;
  		ros::Subscriber sub_9_17;
		int sub_12_17_flag;
  		ros::Subscriber sub_12_17;
		int sub_15_17_flag;
  		ros::Subscriber sub_15_17;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node17");
  	Node17 node17;
  	ros::spin();
  	return 0;
  }

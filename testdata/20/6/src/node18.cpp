
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.013114, 0.005);
  class Node18{
  	public:
  		Node18(){
			sub_3_18_flag = 0;
  			sub_3_18 = n.subscribe("topic_3_18", 1, &Node18::middlemanCallback3,this);
			sub_5_18_flag = 0;
  			sub_5_18 = n.subscribe("topic_5_18", 1, &Node18::middlemanCallback5,this);
			sub_9_18_flag = 0;
  			sub_9_18 = n.subscribe("topic_9_18", 1, &Node18::middlemanCallback9,this);
			sub_13_18_flag = 0;
  			sub_13_18 = n.subscribe("topic_13_18", 1, &Node18::middlemanCallback13,this);
			sub_15_18_flag = 0;
  			sub_15_18 = n.subscribe("topic_15_18", 1, &Node18::middlemanCallback15,this);
			sub_17_18_flag = 0;
  			sub_17_18 = n.subscribe("topic_17_18", 1, &Node18::middlemanCallback17,this);
			pub_18_20 = n.advertise<std_msgs::String>("topic_18_20", 1);
		}
		void middlemanCallback3(const std_msgs::String::ConstPtr& msg){
  			if(sub_5_18_flag == 1 && sub_9_18_flag == 1 && sub_13_18_flag == 1 && sub_15_18_flag == 1 && sub_17_18_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node18 last from node3, intercepted: [%s]", msg->data.c_str());
				pub_18_20.publish(msg);
				sub_5_18_flag = 0;
				sub_9_18_flag = 0;
				sub_13_18_flag = 0;
				sub_15_18_flag = 0;
				sub_17_18_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node18, from node3 intercepted: [%s]", msg->data.c_str());
  				sub_3_18_flag = 1;
  			}
  		}
		void middlemanCallback5(const std_msgs::String::ConstPtr& msg){
  			if(sub_3_18_flag == 1 && sub_9_18_flag == 1 && sub_13_18_flag == 1 && sub_15_18_flag == 1 && sub_17_18_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node18 last from node5, intercepted: [%s]", msg->data.c_str());
				pub_18_20.publish(msg);
				sub_3_18_flag = 0;
				sub_9_18_flag = 0;
				sub_13_18_flag = 0;
				sub_15_18_flag = 0;
				sub_17_18_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node18, from node5 intercepted: [%s]", msg->data.c_str());
  				sub_5_18_flag = 1;
  			}
  		}
		void middlemanCallback9(const std_msgs::String::ConstPtr& msg){
  			if(sub_3_18_flag == 1 && sub_5_18_flag == 1 && sub_13_18_flag == 1 && sub_15_18_flag == 1 && sub_17_18_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node18 last from node9, intercepted: [%s]", msg->data.c_str());
				pub_18_20.publish(msg);
				sub_3_18_flag = 0;
				sub_5_18_flag = 0;
				sub_13_18_flag = 0;
				sub_15_18_flag = 0;
				sub_17_18_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node18, from node9 intercepted: [%s]", msg->data.c_str());
  				sub_9_18_flag = 1;
  			}
  		}
		void middlemanCallback13(const std_msgs::String::ConstPtr& msg){
  			if(sub_3_18_flag == 1 && sub_5_18_flag == 1 && sub_9_18_flag == 1 && sub_15_18_flag == 1 && sub_17_18_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node18 last from node13, intercepted: [%s]", msg->data.c_str());
				pub_18_20.publish(msg);
				sub_3_18_flag = 0;
				sub_5_18_flag = 0;
				sub_9_18_flag = 0;
				sub_15_18_flag = 0;
				sub_17_18_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node18, from node13 intercepted: [%s]", msg->data.c_str());
  				sub_13_18_flag = 1;
  			}
  		}
		void middlemanCallback15(const std_msgs::String::ConstPtr& msg){
  			if(sub_3_18_flag == 1 && sub_5_18_flag == 1 && sub_9_18_flag == 1 && sub_13_18_flag == 1 && sub_17_18_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node18 last from node15, intercepted: [%s]", msg->data.c_str());
				pub_18_20.publish(msg);
				sub_3_18_flag = 0;
				sub_5_18_flag = 0;
				sub_9_18_flag = 0;
				sub_13_18_flag = 0;
				sub_17_18_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node18, from node15 intercepted: [%s]", msg->data.c_str());
  				sub_15_18_flag = 1;
  			}
  		}
		void middlemanCallback17(const std_msgs::String::ConstPtr& msg){
  			if(sub_3_18_flag == 1 && sub_5_18_flag == 1 && sub_9_18_flag == 1 && sub_13_18_flag == 1 && sub_15_18_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node18 last from node17, intercepted: [%s]", msg->data.c_str());
				pub_18_20.publish(msg);
				sub_3_18_flag = 0;
				sub_5_18_flag = 0;
				sub_9_18_flag = 0;
				sub_13_18_flag = 0;
				sub_15_18_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node18, from node17 intercepted: [%s]", msg->data.c_str());
  				sub_17_18_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_18_20;
		int sub_3_18_flag;
  		ros::Subscriber sub_3_18;
		int sub_5_18_flag;
  		ros::Subscriber sub_5_18;
		int sub_9_18_flag;
  		ros::Subscriber sub_9_18;
		int sub_13_18_flag;
  		ros::Subscriber sub_13_18;
		int sub_15_18_flag;
  		ros::Subscriber sub_15_18;
		int sub_17_18_flag;
  		ros::Subscriber sub_17_18;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node18");
  	Node18 node18;
  	ros::spin();
  	return 0;
  }

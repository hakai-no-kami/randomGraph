
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include "unistd.h"
  #include <sstream>
  #include <random>
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> d(0.014237, 0.005);
  class Node19{
  	public:
  		Node19(){
			sub_9_19_flag = 0;
  			sub_9_19 = n.subscribe("topic_9_19", 1, &Node19::middlemanCallback9,this);
			sub_17_19_flag = 0;
  			sub_17_19 = n.subscribe("topic_17_19", 1, &Node19::middlemanCallback17,this);
			pub_19_20 = n.advertise<std_msgs::String>("topic_19_20", 1);
		}
		void middlemanCallback9(const std_msgs::String::ConstPtr& msg){
  			if(sub_17_19_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node19 last from node9, intercepted: [%s]", msg->data.c_str());
				pub_19_20.publish(msg);
				sub_17_19_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node19, from node9 intercepted: [%s]", msg->data.c_str());
  				sub_9_19_flag = 1;
  			}
  		}
		void middlemanCallback17(const std_msgs::String::ConstPtr& msg){
  			if(sub_9_19_flag == 1 &&  true){
  				usleep(d(gen)*1000000);
  				ROS_INFO("I'm node19 last from node17, intercepted: [%s]", msg->data.c_str());
				pub_19_20.publish(msg);
				sub_9_19_flag = 0;
			}
  			else{
  				ROS_INFO("I'm node19, from node17 intercepted: [%s]", msg->data.c_str());
  				sub_17_19_flag = 1;
  			}
  		}
	private:
  		ros::NodeHandle n; 
		ros::Publisher pub_19_20;
		int sub_9_19_flag;
  		ros::Subscriber sub_9_19;
		int sub_17_19_flag;
  		ros::Subscriber sub_17_19;
};
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node19");
  	Node19 node19;
  	ros::spin();
  	return 0;
  }

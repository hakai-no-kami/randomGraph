
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include <sstream>
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node1");
  	ros::NodeHandle n;
	ros::Publisher pub_1_4 = n.advertise<std_msgs::String>("topic_1_4", 1);
	ros::Publisher pub_1_2 = n.advertise<std_msgs::String>("topic_1_2", 1);
	ros::Rate loop_rate(2);
  	int count = 0;
  	while (ros::ok()){
  		std_msgs::String msg;
  		std::stringstream ss;
  		ss << "node1 sending " << count;
  		msg.data = ss.str();
  		ROS_INFO("%s", msg.data.c_str());
		pub_1_4.publish(msg);
		pub_1_2.publish(msg);
		ros::spinOnce();
  		loop_rate.sleep();
  		++count;
  	}
  	return 0;
  }

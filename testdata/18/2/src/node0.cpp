
  #include "ros/ros.h"
  #include "std_msgs/String.h"
  #include <sstream>
  int main(int argc, char **argv){
  	ros::init(argc, argv, "node0");
  	ros::NodeHandle n;
	ros::Publisher pub_0_2 = n.advertise<std_msgs::String>("topic_0_2", 1);
	ros::Publisher pub_0_1 = n.advertise<std_msgs::String>("topic_0_1", 1);
	ros::Rate loop_rate(2);
  	int count = 0;
  	while (ros::ok()){
  		std_msgs::String msg;
  		std::stringstream ss;
  		ss << "node0 sending " << count;
  		msg.data = ss.str();
  		ROS_INFO("%s", msg.data.c_str());
		pub_0_2.publish(msg);
		pub_0_1.publish(msg);
		ros::spinOnce();
  		loop_rate.sleep();
  		++count;
  	}
  	return 0;
  }

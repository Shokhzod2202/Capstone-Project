#include <ros/ros.h>
#include <std_msgs/String.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "traffic_light_server");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<std_msgs::String>("traffic_light_state", 10);

    ros::Rate rate(1); // Set the loop rate in Hz

    while(ros::ok())
    {
        // Generate a random traffic light state
        std::string traffic_light_state = (rand() % 2 == 0) ? "red" : "green";

        std_msgs::String msg;
        msg.data = traffic_light_state;

        pub.publish(msg);

        ros::spinOnce();
        rate.sleep();
    }

    return 0;
}

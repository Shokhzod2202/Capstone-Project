#include <ros/ros.h>
#include <std_msgs/String.h>

void trafficLightStateCallback(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("Traffic light state: %s", msg->data.c_str());
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "traffic_light_client");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("traffic_light_state", 10, trafficLightStateCallback);

    ros::Rate rate(1); // Set the loop rate in Hz

    while(ros::ok())
    {
        // Request the traffic light state by publishing an empty message
        ros::Publisher pub = nh.advertise<std_msgs::String>("traffic_light_request", 10);
        std_msgs::String msg;
        pub.publish(msg);

        ros::spinOnce();
        rate.sleep();
    }

    return 0;
}

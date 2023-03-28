#include <ros/ros.h>
#include <std_srvs/Empty.h>

bool getTrafficLightState(std_srvs::Empty::Request &req,
                          std_srvs::Empty::Response &res)
{
  // Implement logic to get the traffic light state
  bool hasCars = false; // Assume there are no cars

  if (hasCars) {
    ROS_INFO("Traffic light is RED");
  } else {
    ROS_INFO("Traffic light is GREEN");
  }

  res.success = true;
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "traffic_light_server");
  ros::NodeHandle nh;

  // Create a new service named "get_traffic_light_state"
  ros::ServiceServer service = nh.advertiseService("get_traffic_light_state", getTrafficLightState);

  ROS_INFO("Traffic light server is ready.");
  ros::spin();

  return 0;
}


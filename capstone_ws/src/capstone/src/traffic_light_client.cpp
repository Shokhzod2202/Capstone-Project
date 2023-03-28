#include <ros/ros.h>
#include <std_srvs/Empty.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "traffic_light_client");
  ros::NodeHandle nh;

  // Create a new service client named "get_traffic_light_state"
  ros::ServiceClient client = nh.serviceClient<std_srvs::Empty>("get_traffic_light_state");

  std_srvs::Empty srv;

  if (client.call(srv)) {
    ROS_INFO("Traffic light state: %s", srv.response.success ? "RED" : "GREEN");
  } else {
    ROS_ERROR("Failed to call service get_traffic_light_state");
    return 1;
  }

  return 0;
}


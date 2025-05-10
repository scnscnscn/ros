#include <ros/ros.h>
#include "turtlesim/Spawn.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc, argv, "turtlemaker");
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<turtlesim::Spawn>("spawn");
    
    turtlesim::Spawn spawn;
    spawn.request.x = 5.0;
    spawn.request.y = 5.0;
    spawn.request.name = "turtle2";
    spawn.request.theta = 0.0;
    if (client.call(spawn))
    {
        ROS_INFO("Spawned turtle2 at (5, 5)");
    }
    else
    {
        ROS_ERROR("Failed to call service spawn");
        return 1;
    }
    return 0;
}


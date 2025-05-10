#include <ros/ros.h>
#include "geometry_msgs/Twist.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "turtle_control");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1000);

    geometry_msgs::Twist msg;
    msg.linear.x = 2.0;
    msg.linear.y = 0.0;
    msg.linear.z = 0.0;

    msg.angular.x = 0.0;
    msg.angular.y = 0.0;
    msg.angular.z = 1.0;

    ros::Rate loop_rate(10);
    while (ros::ok())
    {
        pub.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();
    }
    ROS_INFO("Turtle control node is running.");
    ROS_INFO("Publishing velocity commands to turtle1.");
    return 0;
}

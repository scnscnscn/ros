#include "ros/ros.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"delete_param");
    ros::NodeHandle nh;

    // 1. 检查并删除 nh_int 参数
    bool exists_before1 = nh.hasParam("nh_int");
    ROS_INFO("第一次删除前 nh_int 是否存在: %d", exists_before1);

    bool r1 = nh.deleteParam("nh_int");
    ROS_INFO("第一次 nh.deleteParam(\"nh_int\") 结果: %d", r1);

    bool exists_after1 = nh.hasParam("nh_int");
    ROS_INFO("第一次删除后 nh_int 是否存在: %d", exists_after1);

    // 2. 再次尝试删除同一个参数 nh_int
    bool r2 = ros::param::del("nh_int");
    ROS_INFO("第二次 ros::param::del(\"nh_int\") 结果: %d", r2);

    bool exists_after2 = nh.hasParam("nh_int");
    ROS_INFO("第二次删除后 nh_int 是否存在: %d", exists_after2);

    // 3. 检查并删除 param_int 参数（与上面的 nh_int 是不同的参数）
    bool exists_before3 = nh.hasParam("param_int");
    ROS_INFO("删除前 param_int 是否存在: %d", exists_before3);

    bool r3 = ros::param::del("param_int");
    ROS_INFO("ros::param::del(\"param_int\") 结果: %d", r3);

    bool exists_after3 = nh.hasParam("param_int");
    ROS_INFO("删除后 param_int 是否存在: %d", exists_after3);

    return 0;
}
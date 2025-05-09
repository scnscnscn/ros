#include "ros/ros.h"
#include "service/AddInts.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");

    if (argc != 3)//包含程序名
    {
        ROS_ERROR("请提交两个整数");
        return 1;
    }

    ros::init(argc,argv,"AddInts_Client");
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<service::AddInts>("AddInts");

    ros::service::waitForService("AddInts");

    service::AddInts ai;
    ai.request.num1 = atoi(argv[1]);
    ai.request.num2 = atoi(argv[2]);
    bool flag = client.call(ai);

    if (flag)
    {
        ROS_INFO("请求正常处理,响应结果:%d",ai.response.sum);
    }
    else
    {
        ROS_ERROR("请求处理失败....");
        return 1;
    }

    return 0;
}
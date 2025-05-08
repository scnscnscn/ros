#include "ros/ros.h"
#include "topic/Person.h"

void doPerson(const topic::Person::ConstPtr& person_p){
    ROS_INFO("订阅的人信息:%s, %d, %.2f", person_p->name.c_str(), person_p->age, person_p->height);
}

int main(int argc, char *argv[])
{   
    setlocale(LC_ALL,"");

    ros::init(argc,argv,"listener_person");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe<topic::Person>("chatter_person",10,doPerson);

    ros::spin();    
    return 0;
}
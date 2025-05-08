
import rospy
from topic.msg import Person


if __name__ == "__main__":

    rospy.init_node("talker_person_p")
    pub = rospy.Publisher("chatter_person",Person,queue_size=10)
    p = Person()
    p.name = "葫芦娃"
    p.age = 18
    p.height = 0.75

    rate = rospy.Rate(1)
    while not rospy.is_shutdown():
        pub.publish(p)  
        rate.sleep()  
        rospy.loginfo("姓名:%s, 年龄:%d, 身高:%.2f",p.name, p.age, p.height)
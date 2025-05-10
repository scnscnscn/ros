from ast import Expression
import rospy
from turtlesim.srv import Spawn,SpawnRequest,SpawnResponse

if __name__ == "__main__":

    rospy.init_node("set_turtle_p")
    client = rospy.ServiceProxy("/spawn",Spawn)
    client.wait_for_service()

    req = SpawnRequest()
    req.x = 2.0
    req.y = 2.0
    req.theta = -1.57
    req.name = "my_turtle_p"
    try:
        response = client.call(req)
        # 6.处理响应
        rospy.loginfo("乌龟创建成功!，叫:%s",response.name)
    except Expression as identifier:
        rospy.loginfo("服务调用失败")
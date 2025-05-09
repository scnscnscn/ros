import rospy
from service.srv import *
import sys

if __name__ == "__main__":

    if len(sys.argv) != 3:
        rospy.logerr("请正确提交参数")
        sys.exit(1)

    rospy.init_node("AddInts_Client_p")
    client = rospy.ServiceProxy("AddInts",AddInts)

    client.wait_for_service()

    req = AddIntsRequest()
    req.num1 = int(sys.argv[1])
    req.num2 = int(sys.argv[2]) 

    resp = client.call(req)
    rospy.loginfo("响应结果:%d",resp.sum)
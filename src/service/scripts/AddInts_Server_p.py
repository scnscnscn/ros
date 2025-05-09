import rospy
from service.srv import AddInts,AddIntsRequest,AddIntsResponse

def doReq(req):
    sum = req.num1 + req.num2
    rospy.loginfo("提交的数据:num1 = %d, num2 = %d, sum = %d",req.num1, req.num2, sum)

    resp = AddIntsResponse(sum)
    return resp


if __name__ == "__main__":
    rospy.init_node("addints_server_p")
    server = rospy.Service("AddInts",AddInts,doReq)
    rospy.spin()
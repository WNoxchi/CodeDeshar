#!/usr/bin/env python  
import rospy

from std_msgs.msg import Int16
from project1_solution.msg import TwoInts

def callback(data):
  	rospy.loginfo(rospy.get_caller_id() + " Heard: %s", (data.a, data.b))
	sum = Int16(data.a + data.b)
	rospy.loginfo("Computing: {} + {} = {}".format(data.a, data.b, sum))

	pub = rospy.Publisher('sum', Int16, queue_size=10)
	pub.publish(sum)

def listener_talker():
	rospy.init_node('subscriber_node')
	#print('hey')
	rospy.Subscriber('two_ints', TwoInts, callback)
	#print('hey')
	rospy.spin() # keeps python from exiting until node is stopped

listener_talker()

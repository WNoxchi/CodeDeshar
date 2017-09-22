#### FINAL VERSION: #### #### #### #### #### #### #### #### #### #### #### ####
# Wayne Nixalo - 21-Sep-2017 21:28 - CSM.103X Robotics Project 1


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

#### SECOND VERSION: #### #### #### #### #### #### #### #### #### #### #### ####
#
# #!/usr/bin/env python
# import rospy
#
# from std_msgs.msg import Int16
# from project1_solution.msg import TwoInts
#
# def callback(data):
#   	rospy.loginfo(rospy.get_caller_id() + " Heard: %s", (data.a, data.b))
# 	sum = Int16(data.a + data.b)
# 	rospy.loginfo("Computing: {} + {} = {}".format(data.a, data.b, sum))
#
# def listener_talker():
# 	rospy.init_node('subscriber_node')
# 	rospy.Subscriber('two_ints', TwoInts, callback)
# 	rospy.spin() # keeps python from exiting until node is stopped
#
# 	pub = rospy.Publisher('sum', Int16, queue_size=10)
# 	rospy.init_node('publisher_node')
# 	rate = rospy.Rate(1)
# 	while not rospy.is_shutdown():
# 		pub.publish(callback.sum)
# 		print("publishing: ".format(sum))
#
# listener_talker()


#### FIRST VERSION: #### #### #### #### #### #### #### #### #### #### #### ####
# References:
# http://wiki.ros.org/ROS/Tutorials/WritingPublisherSubscriber%28python%29
# https://github.com/zzzdeb/csmm103_robotics/blob/master/pj1/project1_solution/scripts/solution.py
# https://github.com/slavaglaps/edx_robotics_project1/blob/master/src/insub/scripts/sub.py
# https://github.com/slavaglaps/edx_robotics_project1/blob/master/src/inpub/scripts/inpub.py

# #!/usr/bin/env python
# import rospy
#
# from std_msgs.msg import Int16
# from project1_solution.msg import TwoInts
#
# def callback(data):
# 	#rospy.loginfo(rospy.get_caller_id() + "Heard %s", data.data)
#   	rospy.loginfo(rospy.get_caller_id() + "Heard %s", (data.a, data.b))
# 	msg = Int16(data.a + data.b)
# 	rospy.loginfo("Computing: {} + {} = {}".format(data.a, data.b, msg))
#
# def listener():
# 	rospy.init_node('subscriber_node', anonymous=True)
# 	rospy.Subscriber('two_ints', TwoInts, callback)
# 	rospy.spin() # keeps python from exiting until node is stopped
#
# # def talker():
# # 	pub = rospy.Publisher('sum', Int16, queue_size=10)
# # 	rospy.init_node('publisher_node', anonymous=True)
# # 	rate = rospy.Rate(2)
# # 	while not rospy.is_shutdown():
# # 		msg = TwoInts()
# # 		msg.a = random.randint(1,100)
# # 		msg.b = random.randint(1,100)
# # 		rospy.loginfo("a: {}, b: {}".format(msg.a, msg.b))
# # 		pub.publish(msg)
#
# if __name__ == '__main__':
# 	listener()

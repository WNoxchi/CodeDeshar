# Wayne H Nixalo - 2017-Jul-10 20:19 - 2017-Jul-11 15:04|
# Udacity CS373 AI for Robotics - Final Project: Part 5: The Final Hunt
# ----------
# Part Five
#
# This time, the sensor measurements from the runaway Traxbot will be VERY
# noisy (about twice the target's stepsize). You will use this noisy stream
# of measurements to localize and catch the target.
#
# ----------
# YOUR JOB
#
# Complete the next_move function, similar to how you did last time.
#
# ----------
# GRADING
#
# Same as part 3 and 4. Again, try to catch the target in as few steps as possible.

from robot import *
from math import *
from matrix import *
import random

from KF import *

def next_move(hunter_position, hunter_heading, target_measurement, max_distance, OTHER = None):
    # This function will be called after each time the target moves.

    # The OTHER variable is a place for you to store any historical information about
    # the progress of the hunt (or maybe some localization information). Your return format
    # must be as follows in order to be graded properly.
    return turning, distance, OTHER

def next_move(hunter_position, hunter_heading, target_measurement, max_distance, OTHER = None):
    # This function will be called after each time the target moves.

    # initialize the EKF as usual
    if not OTHER:
        OTHER = [EKF(1.)]
        # near-optimal q-value (found earlier in find_good_Q.py)
        OTHER[0].Q = matrix([[0.0035*(r==c) for r in range(OTHER[0].Q.dimx)] \
                                        for c in range(OTHER[0].Q.dimy)])
    EKFtr = OTHER[0]

    # store the mean (center) and deviation (radius), along with point count
    if len(OTHER) < 2:
        OTHER.append([[0.,0.],[0.],[0.]])
    point = [target_measurement[0], target_measurement[1]]
    # update count
    OTHER[1][2][0] += 1
    # update mean
    OTHER[1][0][0] = (OTHER[1][0][0]*(OTHER[1][2][0]-1) + point[0])/OTHER[1][2][0]
    OTHER[1][0][1] = (OTHER[1][0][1]*(OTHER[1][2][0]-1) + point[1])/OTHER[1][2][0]
    # update avg deviation
    OTHER[1][1][0] = (OTHER[1][1][0]*(OTHER[1][2][0]-1) +
                            distance_between(OTHER[1][0], point)) / OTHER[1][2][0]
    # center is mean
    center = OTHER[1][0]
    # radius is avg devn
    radius = OTHER[1][1][0]
    # target estimate is point's intersection w/ circumference
    theta = atan2(point[1]-center[1], point[0]-center[0])
    x     = radius * cos(theta) + center[0]
    y     = radius * sin(theta) + center[1]
    targ_est = [x,y]


    # predict Runaway's current position
    targ_est = EKFtr.predict(targ_est)
    # predict Runaway's next position:
    targ_est = EKFtr.predict(targ_est)

    # Heuristic Loop
    steps_to_targ = distance_between(hunter_position, targ_est) / max_distance
    if steps_to_targ >= 1.:    # trial & error: 1.
        x = EKFtr.x.value[0][0]; y = EKFtr.x.value[1][0]
        h = EKFtr.x.value[2][0]; t = EKFtr.x.value[3][0]; d = EKFtr.x.value[4][0]
        for step in range(max(int(steps_to_targ), 1) + 1):  # trial&err: max() + 1
            x = x + d * cos(h + t)
            y = y + d * sin(h + t)
            h = h + t
        targ_est = [x, y]

    # get disance & bearing to target next-position estimate
    targ_dst = distance_between(hunter_position, targ_est)
    distance = min(max_distance, targ_dst)

    bearing  = get_heading(hunter_position, targ_est)
    turning  = angle_trunc(bearing - hunter_heading) # keep this within +- pi

    # The OTHER variable is a place for you to store any historical information about
    # the progress of the hunt (or maybe some localization information). Your return format
    # must be as follows in order to be graded properly.
    return turning, distance, OTHER

def distance_between(point1, point2):
    """Computes distance between point1 and point2. Points are (x, y) pairs."""
    x1, y1 = point1
    x2, y2 = point2
    return sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2)

def demo_grading(hunter_bot, target_bot, next_move_fcn, OTHER = None):
    """Returns True if your next_move_fcn successfully guides the hunter_bot
    to the target_bot. This function is here to help you understand how we
    will grade your submission."""
    max_distance = 0.97 * target_bot.distance # 0.97 is an example. It will change.
    separation_tolerance = 0.02 * target_bot.distance # hunter must be within 0.02 step size to catch target
    caught = False
    ctr = 0

    # We will use your next_move_fcn until we catch the target or time expires.
    while not caught and ctr < 1000:

        # Check to see if the hunter has caught the target.
        hunter_position = (hunter_bot.x, hunter_bot.y)
        target_position = (target_bot.x, target_bot.y)
        separation = distance_between(hunter_position, target_position)
        if separation < separation_tolerance:
            print "You got it right! It took you ", ctr, " steps to catch the target."
            caught = True

        # The target broadcasts its noisy measurement
        target_measurement = target_bot.sense()

        # This is where YOUR function will be called.
        turning, distance, OTHER = next_move_fcn(hunter_position, hunter_bot.heading, target_measurement, max_distance, OTHER)

        # Don't try to move faster than allowed!
        if distance > max_distance:
            distance = max_distance

        # We move the hunter according to your instructions
        hunter_bot.move(turning, distance)

        # The target continues its (nearly) circular motion.
        target_bot.move_in_circle()

        ctr += 1
        if ctr >= 1000:
            print "It took too many steps to catch the target."
    return caught


# def demo_grading(hunter_bot, target_bot, next_move_fcn, OTHER = None):
#     """Returns True if your next_move_fcn successfully guides the hunter_bot
#     to the target_bot. This function is here to help you understand how we
#     will grade your submission."""
#     max_distance = 0.97 * target_bot.distance # 0.98 is an example. It will change.
#     separation_tolerance = 0.02 * target_bot.distance # hunter must be within 0.02 step size to catch target
#     caught = False
#     ctr = 0
#     #For Visualization
#     import turtle
#     window = turtle.Screen()
#     window.bgcolor('white')
#     chaser_robot = turtle.Turtle()
#     chaser_robot.shape('arrow')
#     chaser_robot.color('blue')
#     chaser_robot.resizemode('user')
#     chaser_robot.shapesize(0.3, 0.3, 0.3)
#     broken_robot = turtle.Turtle()
#     broken_robot.shape('turtle')
#     broken_robot.color('green')
#     broken_robot.resizemode('user')
#     broken_robot.shapesize(0.3, 0.3, 0.3)
#     size_multiplier = 15.0 #change size of animation
#     chaser_robot.hideturtle()
#     chaser_robot.penup()
#     chaser_robot.goto(hunter_bot.x*size_multiplier, hunter_bot.y*size_multiplier-100)
#     chaser_robot.showturtle()
#     broken_robot.hideturtle()
#     broken_robot.penup()
#     broken_robot.goto(target_bot.x*size_multiplier, target_bot.y*size_multiplier-100)
#     broken_robot.showturtle()
#     measuredbroken_robot = turtle.Turtle()
#     measuredbroken_robot.shape('circle')
#     measuredbroken_robot.color('red')
#     measuredbroken_robot.penup()
#     measuredbroken_robot.resizemode('user')
#     measuredbroken_robot.shapesize(0.1, 0.1, 0.1)
#     broken_robot.pendown()
#     chaser_robot.pendown()
#     #End of Visualization
#     # We will use your next_move_fcn until we catch the target or time expires.
#     while not caught and ctr < 1000:
#         # Check to see if the hunter has caught the target.
#         hunter_position = (hunter_bot.x, hunter_bot.y)
#         target_position = (target_bot.x, target_bot.y)
#         separation = distance_between(hunter_position, target_position)
#         if separation < separation_tolerance:
#             print "You got it right! It took you ", ctr, " steps to catch the target."
#             caught = True
#
#         # The target broadcasts its noisy measurement
#         target_measurement = target_bot.sense()
#
#         # This is where YOUR function will be called.
#         turning, distance, OTHER = next_move_fcn(hunter_position, hunter_bot.heading, target_measurement, max_distance, OTHER)
#
#         # Don't try to move faster than allowed!
#         if distance > max_distance:
#             distance = max_distance
#
#         # We move the hunter according to your instructions
#         hunter_bot.move(turning, distance)
#
#         # The target continues its (nearly) circular motion.
#         target_bot.move_in_circle()
#         #Visualize it
#         measuredbroken_robot.setheading(target_bot.heading*180/pi)
#         measuredbroken_robot.goto(target_measurement[0]*size_multiplier, target_measurement[1]*size_multiplier-100)
#         measuredbroken_robot.stamp()
#         broken_robot.setheading(target_bot.heading*180/pi)
#         broken_robot.goto(target_bot.x*size_multiplier, target_bot.y*size_multiplier-100)
#         chaser_robot.setheading(hunter_bot.heading*180/pi)
#         chaser_robot.goto(hunter_bot.x*size_multiplier, hunter_bot.y*size_multiplier-100)
#         #End of visualization
#         ctr += 1
#         if ctr >= 1000:
#             print "It took too many steps to catch the target."
#     return caught


def angle_trunc(a):
    """This maps all angles to a domain of [-pi, pi]"""
    while a < 0.0:
        a += pi * 2
    return ((a + pi) % (pi * 2)) - pi

def get_heading(hunter_position, target_position):
    """Returns the angle, in radians, between the target and hunter positions"""
    hunter_x, hunter_y = hunter_position
    target_x, target_y = target_position
    heading = atan2(target_y - hunter_y, target_x - hunter_x)
    heading = angle_trunc(heading)
    return heading

def naive_next_move(hunter_position, hunter_heading, target_measurement, max_distance, OTHER):
    """This strategy always tries to steer the hunter directly towards where the target last
    said it was and then moves forwards at full speed. This strategy also keeps track of all
    the target measurements, hunter positions, and hunter headings over time, but it doesn't
    do anything with that information."""
    if not OTHER: # first time calling this function, set up my OTHER variables.
        measurements = [target_measurement]
        hunter_positions = [hunter_position]
        hunter_headings = [hunter_heading]
        OTHER = (measurements, hunter_positions, hunter_headings) # now I can keep track of history
    else: # not the first time, update my history
        OTHER[0].append(target_measurement)
        OTHER[1].append(hunter_position)
        OTHER[2].append(hunter_heading)
        measurements, hunter_positions, hunter_headings = OTHER # now I can always refer to these variables

    heading_to_target = get_heading(hunter_position, target_measurement)
    heading_difference = heading_to_target - hunter_heading
    turning =  heading_difference # turn towards the target
    distance = max_distance # full speed ahead!
    return turning, distance, OTHER

target = robot(0.0, 10.0, 0.0, 2*pi / 30, 1.5)
measurement_noise = 2.0*target.distance # VERY NOISY!!
target.set_noise(0.0, 0.0, measurement_noise)

hunter = robot(-10.0, -10.0, 0.0)

# print demo_grading(hunter, target, naive_next_move)
x = 0
for i in xrange(100):
    x += demo_grading(hunter, target, next_move)
print("Runs: 100, Caught: {}".format(x))

# OUTPUT:
# It took too many steps to catch the target. (x9)
# You got it right! It took you  713  steps to catch the target.
# It took too many steps to catch the target. (x90)
# Runs: 100, Caught: 1

# 2017-Jul-11 15:01
# NOTE: wow it actually caught it once. I can imagine another strategy that
#       uses point data to figure out the points on the circle the Target lands
#       on, and just picks the closest one and camps out there.
#     > May sound hack-ish... but ambush is a legit huntint tactic. Hunting
#       spiders, North American bait-&-hide deer hunters, Rebels & Insurgents,
#       goddamned Crocodiles.. etc. etc.
#     > I may do that later. Btw, the way you'd figure out the landing-points
#       is to log points until they complete a circle, logged by where they
#       intersect the circumference, and refine (average) them over time.

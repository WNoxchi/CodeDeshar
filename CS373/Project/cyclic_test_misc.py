# 2017-Jul-06 00:10 | 2017-Jul-06 17:40
# Work Scratch Pad for Project Part1: Noiseless Prediction

from math import *
import matplotlib.pyplot as plt

def distance_between(point1, point2):
    """Computes distance between point1 and point2. Points are (x, y) pairs."""
    x1, y1 = point1
    x2, y2 = point2
    return sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2)

def angle_trunc(a):
    while a < 0.0:
        a += pi * 2
    return ((a + pi) % (pi * 2)) - pi

# c0 = [4.,0.]
# c1 = [6.,1.]

p1 = [1,0]
p2 = [2,1]
# distance_between(p1,p2)
# 1.4142135623730951

d = distance_between(p1,p2)

x1,x2 = p1[0], p2[0]
y1,y2 = p1[1], p2[1]
th1 = atan2(y2-y1, x2-x1)
th2 = angle_trunc(2 * th1)

y3 = d * sin(th2) + y2
x3 = d * cos(th2) + x2

p3 = [x3,y3]

print(p3)

print(th2 * 180 / pi)




def estimate_next_pos(measurement, OTHER = None):
    """Estimate the next (x, y) position of the wandering Traxbot
    based on noisy (x, y) measurements."""

    # what I should do is have OTHER be an array of past coordinates.
    # this'll allow me to average out the noise.
    xy_estimate = measurement
    # want to use OTHER to get step-distance & turn angle information
    if not OTHER:
        # initial estimate
        OTHER = [xy_estimate]
    else:
        # use difference in coords to estimate relative turning angle
        x0, y0 = OTHER[0]
        x1, y1 = measurement
        angl_alt = atan2(y1-y0, x1-x0)
        angl_neu = angle_trunc(2 * angle_alt)
        # use turn angle estimate & distance btwn coords to update estimate
        dist = distance_between(OTHER, measurement)
        x2 = cos(angle_neu) * dist + x1
        y2 = sin(angle_neu) * dist + y2
        xy_estimate = [x2,y2]
        OTHER.append(xy_estimate)

    # You must return xy_estimate (x, y), and OTHER (even if it is None)
    # in this order for grading purposes.
    return xy_estimate, OTHER

measurements = [(3.2618187593136714, 5.248776670511476),
                (4.229518090705041, 6.394882252046046),
                (4.970144154070998, 7.699287493626686),
                (5.458475817106669, 9.117572439213015),
                (5.67788353071665, 10.601439096028392)]

OTHER = None
for i in xrange(2):
    estimate, other = estimate_next_pos(measurements[i], OTHER)
    print(estimate, other)




def estimate_next_pos(measurement, OTHER = None):
    """Estimate the next (x, y) position of the wandering Traxbot
    based on noisy (x, y) measurements."""

    xy_estimate = measurement
    # what I should do is have OTHER be an array of past coordinates.
    # this'll allow me to average out the noise.
    # want to use OTHER to get step-distance & turn angle information
    if not OTHER:
        # initial estimate
        OTHER = [measurement]
    else:
        # overwrite last OTHER coord estimate w/ actual measurement
        OTHER[-1] = measurement

        # use difference in coords to estimate relative turning angle
        x0, y0 = OTHER[-2]
        x1, y1 = measurement

        # NOTE: before I had x0,y0 = OTHER[0] (w/o overwriting last estimate)
        # In effect making the estimate always over compensate to get back
        # to the actual measurement.

        # average angle measurements
        angl_alt = atan2(y1-y0, x1-x0)
        for i in xrange(len(OTHER)-1, 0, -1):
            angl_alt += atan2(OTHER[i-1][1]-OTHER[i][1], OTHER[i-1][0]-OTHER[i][0])
        angl_alt /= len(OTHER)
        angl_neu = angle_trunc(2 * angl_alt)

        # use turn angle estimate & distance btwn coords to update estimate
        # average distance measurements
        dist = distance_between(OTHER[-1], measurement)
        for i in xrange(len(OTHER)-1, 0, -1):
            dist += distance_between(OTHER[i-1], OTHER[i])
        dist /= len(OTHER)

        # x1 = cos(angl_neu) * dist + x0
        # y1 = sin(angl_neu) * dist + y0

        x2 = cos(angl_neu) * dist + measurement[0]
        y2 = sin(angl_neu) * dist + measurement[1]

        # x3 = cos(angl_neu) * dist + x2
        # y3 = sin(angl_neu) * dist + y2

        xy_estimate = [x2,y2]

    OTHER.append(xy_estimate)

    ##########################      ##########################
    # math.atan2:
    # atan2(...)
    # atan2(y, x)
    #
    # Return the arc tangent (measured in radians) of y/x.
    # Unlike atan(y/x), the signs of both x and y are considered.
    ##########################      ##########################

    # You must return xy_estimate (x, y), and OTHER (even if it is None)
    # in this order for grading purposes.
    return xy_estimate, OTHER



def estimate_next_pos(measurement, OTHER = None):
    """Estimate the next (x, y) position of the wandering Traxbot
    based on noisy (x, y) measurements."""

    # first run
    if not OTHER:
        xy_estimate = measurement
        OTHER = [measurement]
    # subsequent runs
    else:
        dist = distance_between(measurement, OTHER[-1])
        angl = atan2(measurement[1]-OTHER[-1][1], measurement[0]-OTHER[-1][0])
        for i in xrange(len(OTHER)-1):
            dist += distance_between(OTHER[i+1], OTHER[i])
            angl += atan2(OTHER[i+1][1]-OTHER[i][1], OTHER[i+1][0]-OTHER[i][0])
        dist /= len(OTHER)
        angl /= len(OTHER)
        angl = angle_trunc(2*angl)

        xy_estimate = [measurement[0] + dist * cos(angl),
                       measurement[1] + dist * sin(angl)]

    OTHER.append(measurement)


    ##########################      ##########################
    # math.atan2:
    # atan2(...)
    # atan2(y, x)
    #
    # Return the arc tangent (measured in radians) of y/x.
    # Unlike atan(y/x), the signs of both x and y are considered.
    ##########################      ##########################

    # You must return xy_estimate (x, y), and OTHER (even if it is None)
    # in this order for grading purposes.
    return xy_estimate, OTHER


# another attempt at keeping an average instaed of all prevs steps in OTHER:
def estimate_next_pos(measurement, OTHER = None):
    """Estimate the next (x, y) position of the wandering Traxbot
    based on noisy (x, y) measurements."""
    # first run
    if not OTHER:
        xy_estimate = measurement
        OTHER = [measurement, 0]
    # subsequent runs
    else:
        dist = distance_between(measurement, OTHER[0])
        angl = atan2(measurement[1]-OTHER[0][1], measurement[0]-OTHER[0][0])
        angl = angle_trunc(2 * angl)

        xy_estimate = [measurement[0] + dist * cos(angl),
                       measurement[1] + dist * sin(angl)]
        OTHER[0] = measurement
        OTHER[1] = angl
    # You must return xy_estimate (x, y), and OTHER (even if it is None)
    # in this order for grading purposes.
    return xy_estimate, OTHER


# I'm looking at Jeremy Shannon's code because he's doing some things very
# similar to what I was doing. Such as the len(OTHER)-1 loops and the
# atan2(OTHER[i+1][1]-OTHER[i][1], ...etc
# From: https://github.com/jeremy-shannon/udacity-AI-for-robotics/blob/master/Project%20-%20Runaway%20Robot/studentMain1-noiselessPrediction.py
def estimate_next_pos(measurement, OTHER = None):
    """Estimate the next (x, y) position of the wandering Traxbot
    based on noisy (x, y) measurements."""
    # assume constant velocity, and a constant change in angle

    if not OTHER:
        OTHER = []
    avgdist = 0
    avgdtheta = 0
    OTHER.append(measurement)
    dist = []
    theta = []
    if len(OTHER) > 1:
        for i in range(len(OTHER)-1):
            dist.append(distance_between(OTHER[i+1],OTHER[i]))
            theta.append(atan2(OTHER[i+1][1]-OTHER[i][1], OTHER[i+1][0]-OTHER[i][0]))
    else:
        dist = [0]
        theta = [0]
    avgdist = sum(dist) / float(len(dist))
    dtheta = []
    if len(theta) > 1:
        for i in range(len(theta)-1):
            dtheta.append((theta[i+1]-theta[i])%(2*pi))
        avgdtheta = sum(dtheta) / float(len(dtheta))

    xy_estimate = (measurement[0]+avgdist*cos(theta[len(theta)-1]+avgdtheta), measurement[1]+avgdist*sin(theta[len(theta)-1]+avgdtheta))

    print "meas:", measurement
    print "est:", xy_estimate

    # You must return xy_estimate (x, y), and OTHER (even if it is None)
    # in this order for grading purposes.
    return xy_estimate, OTHER

# My function is evolving a bit.. removed a one-extra dinstance & angle addition
# However.. it looks like my method of calculating the new angle (just double
# the old angle!) may be the reason why my tracking error isn't improving:
# (stays at 0.742211877764, until it freaks out near the top wall).
# It doesn't seem to really be tracking, or at least ever getting better --
# just doing it's own thing. J.Shannon's `dtheta` var may be what's needed:
# Calculate the difference between angles & use that as the term added to angle
def estimate_next_pos(measurement, OTHER = None):
    """Estimate the next (x, y) position of the wandering Traxbot
    based on noisy (x, y) measurements."""
    # first run
    if not OTHER:
        OTHER = []
    OTHER.append(measurement)
    dist, angl = 0., 0.
    # subsequent runs
    if len(OTHER) > 1:
        # dist = distance_between(measurement, OTHER[-1])
        # angl = atan2(measurement[1]-OTHER[-1][1], measurement[0]-OTHER[-1][0])
        for i in xrange(len(OTHER)-1):
            dist += distance_between(OTHER[i+1], OTHER[i])
            angl += atan2(OTHER[i+1][1]-OTHER[i][1], OTHER[i+1][0]-OTHER[i][0])
    else:
        dist = 0
        angl = 0
    dist /= max(len(OTHER)-1, 1)
    angl /= max(len(OTHER)-1, 1)
    angl = angle_trunc(2*angl)

    xy_estimate = [measurement[0] + dist * cos(angl),
                   measurement[1] + dist * sin(angl)]

    # You must return xy_estimate (x, y), and OTHER (even if it is None)
    # in this order for grading purposes.
    return xy_estimate, OTHER
############   ###########
    # first run
    if not OTHER:
        OTHER = []
    OTHER.append(measurement)
    dist, angl, d_angl = 0., 0., 0.
    # subsequent runs
    if len(OTHER) > 1:
        # dist = distance_between(measurement, OTHER[-1])
        # angl = atan2(measurement[1]-OTHER[-1][1], measurement[0]-OTHER[-1][0])
        for i in xrange(len(OTHER)-1):
            dist += distance_between(OTHER[i+1], OTHER[i])
            angl += atan2(OTHER[i+1][1]-OTHER[i][1], OTHER[i+1][0]-OTHER[i][0])
    else:
        dist = 0
        angl = 0
    dist /= max(len(OTHER)-1, 1)
    angl /= max(len(OTHER)-1, 1)
    # angl = angle_trunc(2*angl)

    xy_estimate = [measurement[0] + dist * cos(angl),
                   measurement[1] + dist * sin(angl)]

    # You must return xy_estimate (x, y), and OTHER (even if it is None)
    # in this order for grading purposes.
    return xy_estimate, OTHER

####################### ####################### #######################
# Here's what I got working. What I don't like about it is space and computation
# time grow linearly with number of steps. So this would eventually crash any
# system running it. And that's the thing: there's no reason you can't keep
# a running average. The final version below this one does that.
# XXX: FIRST WORKING VERSION:
def estimate_next_pos(measurement, OTHER = None):
    """Estimate the next (x, y) position of the wandering Traxbot
    based on noisy (x, y) measurements."""
    # mean of all previous distances between position updates; angle between
    # last & current position updates + mean angle change between all updates.
    mean = lambda x : sum(x) / float(len(x))

    if not OTHER:
        OTHER = []
    dist, theta = [], []
    avgdist, avgdtheta = 0., 0.
    OTHER.append(measurement)
    if len(OTHER) > 1:
        for i in xrange(len(OTHER)-1):
            dist.append(distance_between(OTHER[i+1], OTHER[i]))
            theta.append(atan2(OTHER[i+1][1]-OTHER[i][1], OTHER[i+1][0]-OTHER[i][0]))
    else:
        dist, theta = [0.], [0.]
    avgdist  = mean(dist)

    dtheta = []
    if len(theta) > 1:
        for i in xrange(len(theta)-1):
            dtheta.append((theta[i+1]-theta[i]) % (2*pi))
        avgdtheta = mean(dtheta)

    xy_estimate = [measurement[0] + avgdist * cos(theta[-1] + avgdtheta),
                   measurement[1] + avgdist * sin(theta[-1] + avgdtheta)]

    # You must return xy_estimate (x, y), and OTHER (even if it is None)
    # in this order for grading purposes.
    return xy_estimate, OTHER

# OUTPUT:
# Test bot 1 successfully localized in 3 measurements.
# Test bot 2 successfully localized in 3 measurements.
# Test bot 3 successfully localized in 3 measurements.
# You got the BEST solution. Since the target robot is moving and sensing without noise, we can perfectly understand its motion with only three measurements!

# For some reason this version doesn't quite solve the problem properly...
# I'm going to leave my final answer as the above version for now.
# EDIT: yeah, I'm deffinitely not doing the d_theta & mean_dist updates
# correctly.
# XXX: FINAL WORKING VERSION:
def estimate_next_pos(measurement, OTHER = None):
    """Estimate the next (x, y) position of the wandering Traxbot
    based on noisy (x, y) measurements."""
    # mean of all previous distances between position updates; angle between
    # last & current position updates + mean angle change between all updates.

    mean_dist, angl, mean_d_angl = 0., 0., 0.
    if not OTHER: OTHER = [mean_d_angl]
    OTHER.append(measurement)
    if len(OTHER) > 2:
        mean_dist  += distance_between(OTHER[2], OTHER[1])
        angl       += atan2(OTHER[2][1]-OTHER[1][1], OTHER[2][0]-OTHER[1][0])
    mean_d_angl = (angl - OTHER[0]) % (2*pi)

    OTHER[0] = mean_d_angl;
    if len(OTHER) > 2:
        OTHER[1] = OTHER[2]
        OTHER.pop()
    xy_estimate = [measurement[0] + mean_dist * cos(angl + mean_d_angl),
                   measurement[1] + mean_dist * sin(angl + mean_d_angl)]

    # You must return xy_estimate (x, y), and OTHER (even if it is None)
    # in this order for grading purposes.
    return xy_estimate, OTHER

# OUTPUT:
# Test bot 1 successfully localized in 2 measurements.
# Test bot 2 successfully localized in 3 measurements.
# Test bot 3 successfully localized in 3 measurements.
# How did you localize it in fewer than 3 measurements? Something's fishy here...

# CS1156x - HW7.7
# WNx - 2017-Feb-10 21:39

from math import sqrt
from copy import copy
# constant
def h0(y1, y2):
    return float(y2+y1)/2
# linear
def h1(y1,y2,x1,x2, x):
    a = float(y2-y1)/(x2-x1)
    b = -(a*x1) + y1
    y = a*x + b
    return y

p = [sqrt(sqrt(3)+4),
     sqrt(sqrt(3)-1),
     sqrt(9+4*sqrt(6)),
     sqrt(9-sqrt(6))]

E_cv = []

# Select a p[i]:
for i in range(len(p)):
    points = [[-1,0],[p[i],1],[1,0]]
    e0, e1 = 0, 0
    # run 1-Out CrossValidation:
    for j in range(len(points)):
        checks = copy(points)
        out = checks.pop(j)
        h0_y = h0(checks[0][1], checks[1][1])
        h1_y = h1(checks[0][1], checks[1][1], checks[0][0], checks[1][0], out[0])
        e0 += (out[1] - h0_y)**2
        e1 += (out[1] - h1_y)**2
    # sum & average errors
    E_cv.append([e0/len(points), e1/len(points)])

# select p[i] corresp to lowest E_cv
print("Cross-Val Errors:\n")
for i in range(len(p)):
    print("p = {}: {}".format(p[i], E_cv[i]))

################################################################################
# OUTPUT:
# Cross-Val Errors:
#
# p = 2.39417017097: [0.5, 1.1350433676859415]
# p = 0.855599677167: [0.5, 64.66494840795228]
# p = 4.33566130724: [0.5, 0.5]
# p = 2.55939646347: [0.5, 0.9868839293305475]

# Waynes-MBP:HW6 WayNoxchi$ python3 -m cProfile -s time HW7.7.py
# Cross-Val Errors:
#
# p = 2.3941701709713277: [0.5, 1.1350433676859415]
# p = 0.8555996771673521: [0.5, 64.66494840795228]
# p = 4.335661307243996: [0.5, 0.5]
# p = 2.5593964634688433: [0.5, 0.9868839293305475]
#          383 function calls in 0.001 seconds

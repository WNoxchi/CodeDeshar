# WNixaloy - 15-Aug-2016 17:50
# 6.003 - Signals & Systems - 1: Discrete Time Systems - HW 1

# Use your favorite computer language to solve this recursion for the special
# case when the input r0[n] is held constant at 0.1m3/s, tank #1 is initially
# empty, and T = 1 second (see example code in box below). Make a plot of your
# solution for 0 < t < 60. Also plot the analytic result from part c on the same
# axes. Determine the maximum difference between the analytic and numerical results.

#from HW1 solutions:

# 6e:

# import math
# from pylab import*
#
# ya = []         # analytic
# for t in range(60):
#     ya.append(0.1 - 0.1*math.e**(-t/20.))
# print ya
# plot(range(60), ya,'r-')
#
# T = 1
# yn = [0]        # numerical
# for i in range(1, 60):
#     yn.append(yn[i-1]+T/20.*(0.1-yn[i-1]))
# print
# print yn
# stem(range(60), yn, 'b-', 'b.', 'r-')
#
# print
# print max([yn[i]-ya[i] for i in range(60)])
#
# show()

# 6f:

import math
from pylab import *

T = 1
r1 = [0]        #inital conditions
r2 = [0]
for i in range(1,60):
    r1.append(r1[i-1]+T/20.*(0.1-r1[i-1]))
    r2.append(r2[i-1]+T/10.*(r1[i]-r2[i-1]))
print
print r1
stem(range(60), r1, 'b-', 'b.', 'r-')
stem(range(60), r2, 'r-', 'r.', 'r-')

show()

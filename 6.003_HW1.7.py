# WNixaloy - 15-Aug-2016 18:50
# 6.003 - Signals & Systems - 1: Discrete Time Systems - HW 1

# plot the amount of drug in the blood as a function of day number for alpha = 1/2, 3/4, 7/8

# import math
# from pylab import *
#
# T = 1
# r1 = [0]        #inital conditions
# r2 = [0]
# for i in range(1,60):
#     r1.append(r1[i-1]+T/20.*(0.1-r1[i-1]))
#     r2.append(r2[i-1]+T/10.*(r1[i]-r2[i-1]))
# print
# print r1
# stem(range(60), r1, 'b-', 'b.', 'r-')
# stem(range(60), r2, 'r-', 'r.', 'r-')
#
# show()

import math
from pylab import *

a = 0.5
y = [1]
for i in range(1, 20):
    y.append(1 + a*y[i-1])
stem(range(20), y, 'b-', 'b.', 'r-')
show()

# -*- coding: utf-8 -*-
# CS1156x - Learning from Data
# Wayne Nixalo - 15-Oct-2016 14:10 - (Iter: 16:30) - 15-Oct-2016 17:16
# HW1.7: Perceptron Learning Algorithm - Version 3
# ------------------------------------------------------------------------------
# Outline:
#
# In each run:
#     ø   choose targ fn <-- cxa aghor = +1, other = -1
#     ø   choose inputs Xn as rand pts
#     ø   eval targ fn on each Xn
#
#     ø   Lelo PLA to find g:
#         >   start PLA w/ weight vec W = [0,0,0] <==> sign(0) = 0
#         >   At each Iteration:
#             ø   choose pt randmly frm set misclass pts & run PLA on it
# Yezi:
#     terah iteratns PLA to converge to g
#     disagreement btwn f & g
# ------------------------------------------------------------------------------
import numpy as np
import random

N, n = 10, 1000
count = 0

for _ in range(n):
    if (_/100 > 0 and _ % 100 == 0): print repr(_/10) + "%"
    # choose target Fn
    F = []
    for i in range(2):
        F.append([random.uniform(-1,1), random.uniform(-1,1)])

    # choose inputs Xn as randm pts
    X = []
    for i in range(N):
        X.append([1, random.uniform(-1,1), random.uniform(-1,1)])

    #  eval target Fn on each Xn
    Y = []
    for i in range(N):
        Y.append(np.sign((X[i][1]-F[0][0])*(F[1][1]-F[0][1])-(X[i][2]-F[0][1])*(F[1][0]-F[0][0])))

    # Use PLA to find g starting w/zeroed weight vec W
    W = [0,0,0]
    # each Iteration running PLA on random misclass'd point
    while 1:
        misclass = []
        count += 1
        for i in range(N):
            if np.sign((np.transpose(W)).dot(X[i])) != np.sign(Y[i]):
                misclass.append([X[i], Y[i]])
        if not misclass:
            break;
        index = np.random.randint(0, len(misclass))
        W = W + np.multiply(misclass[index][0], misclass[index][1])

# determine disagreement ratio between f/h and g
miss = 0
X = []
for i in range(n):
    X.append([1, random.uniform(-1,1), random.uniform(-1,1)])
    if np.sign((np.transpose(W)).dot(X[i])) != np.sign((X[i][1]-F[0][0])*(F[1][1]-F[0][1])-(X[i][2]-F[0][1])*(F[1][0]-F[0][0])):
        miss += 1
ratio = float(miss)/n

iteravg =  float(count)/n
print "------------------"
print ("Iteration Average: " + repr(iteravg))
print ("P[ƒ(x) ≠ g(x)]: " + repr(ratio))
# ------------------------------------------------------------------------------
# Sample Output:
# 10%
# 20%
# 30%
# 40%
# 50%
# 60%
# 70%
# 80%
# 90%
# ------------------
# Iteration Average: 10.179
# P[ƒ(x) ≠ g(x)]: 0.108

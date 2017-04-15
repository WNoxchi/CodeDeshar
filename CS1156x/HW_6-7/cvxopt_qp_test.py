# WNx - 2017-Feb-25 17:17   -   CS1156X Learning from Data
# example problem from Learning from Data e-Chap:8-28

# See gist.github.com/~ zibet/toysvm.py:
# https://gist.github.com/zibet/4f76b66feeb5aa24e124740081f241cb
# MIT CSAIL: Quadratic Programming with Python and CVXOPT:
# https://courses.csail.mit.edu/6.867/wiki/images/a/a7/Qp-cvxopt.pdf
# CS1156X HW7.8 discussion:
# https://courses.edx.org/courses/course-v1:CaltechX+CS_1156x+3T2016/discussion/forum/i4x-Caltech-CS156-course-Fall2016_Week7/threads/5820f6a05e3e4c05400002a9
# See ypeels @reply to @AlbertoRG1 post (1/2 way down) in discussion -- helped me figure out quadprog:
# https://courses.edx.org/courses/course-v1:CaltechX+CS_1156x+3T2016/discussion/forum/i4x-Caltech-CS156-course-Fall2016_Week7/threads/582a32fe7febe5052b00069a

import numpy as np
import cvxopt

X = [0.,0.],[2.,2.],[2.,0.],[3.,0.]
y = [-1.,-1.,1.,1.]
Qd = [[0.,0.,0.,0.],[0.,8.,-4.,-6.],[0.,-4.,4.,6.],[0.,-6.,6.,9.]]

X = np.array(X)
y = np.array(y)
Qd = np.array(Qd)
Ad = np.vstack((y, -y))
Ad = np.vstack((Ad, np.eye(4)))

N = len(X)
q = -np.ones(N)
G = -Ad
h = np.zeros(N+2)

################################## CVXOPT pkg ##################################

# without this fn, will raise:
#   ValueError: use of function valued P, G, A requires a user-provided kktsolver
def toMat(A):
    return cvxopt.matrix(A, tc='d')    # using numpy matrix wont work

Qd = toMat(Qd)
q = toMat(q)
G = toMat(G)
h = toMat(h)

sol = cvxopt.solvers.qp(Qd, q, G, h)
print(sol['x'])

# Output:
# Optimal solution found.
# [ 5.00e-01]
# [ 5.00e-01]
# [ 1.00e+00]
# [ 2.20e-08]

################################# QUADPROG pkg #################################

# Now how to make this work in QuadProg 0.1.6?
# import quadprog
#
# C = np.transpose(Ad)
# b = np.zeros(N+2)
# a = np.ones(N)
#
# # add a tiny bit to diagonal of Qd to make (+)semidefinite
# for i in range(N):
#     Qd[i][i] += 1e-9
#
# sol = quadprog.solve_qp(Qd, a, C, b, meq=1) # meq=1 seems optional for toy problem
# # for i in sol: print(i)
# print(sol[0])

# Output:
# Waynes-MBP:HW_6-7 WayNoxchi$ python3 cvxopt_qp_test.py
# [ 0.50000012  0.49999999  1.00000006  0.        ]





# Output:   (wrong; C constraint matx all fuxked up)
# Waynes-MBP:HW_6-7 WayNoxchi$ python3 cvxopt_qp_test.py
# [ -2.49999919e-01  -2.49999919e-01   1.43497350e-07   2.42889178e-08]

# CS1156x - Learning from Data - Final Exam - Support Vector Machines
# Wayne H Nixalo - 2017-Apr-02 22:46 - 2017-Apr-02 23:10
# Q 11:

import numpy as np

X = [[1,0],[0,1],[0,-1],[-1,0],[0,2],[0,-2],[-2,0]]
y = [-1, -1, -1, 1, 1, 1, 1]

y = np.array(y)

def Z(X):
    Z = []
    for i in range(len(X)):
        Z.append([X[i][1]**2 - 2*X[i][0] - 1, X[i][0]**2 - 2*X[i][1] + 1])
    return Z

z = Z(X)
# for i in range(len(z)):
#     print(z[i])
z = np.array(z)

z = np.hstack((np.ones((len(z), 1)), z))
print(z)

W = [[-.5, -1, 1], [-.5, 1, -1], [-.5, 1, 0], [-.5, 0, 1]]
W = np.array(W)

for i in range(len(W)):
    print(W[i])
    for k in range(len(z)):
        if np.sign(np.dot(W[i].T, z[k])) != y[k]:
            print("--FALSE")
        else:
            print("--TRUE")

# [c]: w1, w2, b: 1, 0, -0.5

# ##############################################################################
# 12: same training set, but instead of explicitly trsfm input space X, apply
#     HM SVM ALgo w/ Kernel: K(x, x`) = (1 + x.T.x`)^2. Set up the expsn for
#     L(α1,..α7) & solve for optimum α1,...α7 using QPpkg. # SVs you get is in
#     what range?

from sklearn.svm import SVC

X = np.array(X)
X = np.hstack((np.ones((len(X), 1)), X))
X = np.array(X)

coef0 = 1.      # the bias term in poln kernel
gamma = 1.      # the scaling factor in rbf kernel
C = 1e6     # using a high penalty to simulate a hard margin
Q = 2       # order of the poln kernel
kernel = 'poly'

clsfr = SVC(C, kernel, Q, gamma, coef0)
clsfr.fit(X, y)
print("\nQ12: Num. Support Vectors: ", sum(clsfr.n_support_))
print(clsfr.support_vectors_)

# [c]: 4-5


# ##############################################################################
# OUTPUT        Q11: [c]:(b,w1,w2)=(-.5,1,0) is the only one to score all TRUE
# ##############################################################################
# Waynes-MBP:Final WayNoxchi$ python3 FEx_SVM_11.py
# [[ 1. -3.  2.]
#  [ 1.  0. -1.]
#  [ 1.  0.  3.]
#  [ 1.  1.  2.]
#  [ 1.  3. -3.]
#  [ 1.  3.  5.]
#  [ 1.  3.  5.]]
# [-0.5 -1.   1. ]
# --FALSE
# --TRUE
# --FALSE
# --TRUE
# --FALSE
# --TRUE
# --TRUE
# [-0.5  1.  -1. ]
# --TRUE
# --FALSE
# --TRUE
# --FALSE
# --TRUE
# --FALSE
# --FALSE
# [-0.5  1.   0. ]
# --TRUE
# --TRUE
# --TRUE
# --TRUE
# --TRUE
# --TRUE
# --TRUE
# [-0.5  0.   1. ]
# --FALSE
# --TRUE
# --FALSE
# --TRUE
# --FALSE
# --TRUE
# --TRUE
#
# Q12: Num. Support Vectors:  5
# [[ 1.  0.  1.]
#  [ 1.  0. -1.]
#  [ 1. -1.  0.]
#  [ 1.  0.  2.]
#  [ 1.  0. -2.]]

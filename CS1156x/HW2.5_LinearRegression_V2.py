# CS1156x Learning From Data - HW 2.5 - Linear Regression
# Wayne H Nixalo - 22-Oct-2016 22:22 - 23-Oct-2016 03:05 (2.5) : 23-Oct-2016 11:43 (2.6)
# <>---------------------<>---------------------<>
# LinReg Algo rewritten to calc target fn using weight vector W = [w0,w1,w2]
# <>---------------------<>---------------------<>

import numpy as np

N = 100
n = 1000

# def LinReg(N, n):
Ein = []

for i in range(n):
    # create target fn F:
    F = [[0,0],[0,0]]
    while (F[0][0] == F[1][0] or F[0][1] == F[1][1]):  # ensure target points unique
        F = []
        for _ in range(2):
            F.append([np.random.uniform(-1,1), np.random.uniform(-1,1)])
    m = (F[0][1]-F[1][1])/(F[0][0]-F[1][0])                                         #   y = mx + c
    c = F[0][1] - m*F[0][0]                                                         #   0 = c + mx - y
    W = [c, m, -1]                                                                  #   0 = c + mx1 - x2 = w0 + w1*x1 + w2*x2

    # create data set X:
    X = []
    for _ in range(N):
        X.append([1, np.random.uniform(-1,1), np.random.uniform(-1,1)])

    # create Output vector Y:
    Y = []
    for _ in range(N):
        Y.append(np.sign(np.transpose(W).dot(X[_])))
    Y = np.array(Y)                                                                 #   ensuring Y is represented as a column vector, not simple list
    Y.shape = (N, 1)                                                                #   not necsry for computing Xpsiv, but needed for norm: ||Xw-y||

    # Compute PseudoInverse of X:
    Xpsv = np.linalg.inv(np.transpose(X).dot(X)).dot(np.transpose(X))               # eqvt cmd: np.pinv(X)

    # Compute LinReg weight vector:
    W = Xpsv.dot(Y)

    # Compute In-Sample Error:          Ein(W) = norm-squared / N
    #Ein.append(np.linalg.norm(np.mat(X).dot(W)-Y)**2/N)                             #   ensure X repr as matrix for numpy to do its work here
    Yw = []
    for _ in range(N):
        Yw.append(np.sign(np.transpose(W).dot(X[_])))       # make this monster look nice. Ein is fraction of misclass'd y's...
    Yw = np.array(Yw)
    Yw.shape = (N, 1)
    misclass = 0
    for _ in range(N):
        if Yw[_] != Y[_]:
            misclass += 1
    Ein.append(float(misclass)/N)

    # Computation Status:
    if (i%150==0): print("Computing... " + repr(i/10) + "%")

# Average In-Sample Error:
Ein = sum(Ein)/n
print "InSample Error: " + repr(Ein)

# <>---------------------<>
# HW2.6: Calculating OutSample Error:
# <>---------------------<>
N = 1000
gx = W
Eout = []
# Create new target fn, new dataset X, & outsample classfctn: Y; does gx match target W?
for i in range(n):
    # create target fn F:
    F = [[0,0],[0,0]]
    while (F[0][0] == F[1][0] or F[0][1] == F[1][1]):
        F = []
        for _ in range(2):
            F.append([np.random.uniform(-1,1), np.random.uniform(-1,1)])
    m = (F[0][1]-F[1][1])/(F[0][0]-F[1][0])
    c = F[0][1] - m*F[0][0]
    W = [c, m, -1]
    # create data set X:
    X = []
    for _ in range(N):
        X.append([1, np.random.uniform(-1,1), np.random.uniform(-1,1)])
    # create Output vector Y:
    Y = []
    for _ in range(N):
        Y.append(np.sign(np.transpose(W).dot(X[_])))
    Y = np.array(Y)
    # OutSample Classification
    Yw = []
    for _ in range(N):
        Yw.append(np.sign(np.transpose(gx).dot(X[_])))
    Yw = np.array(Yw)
    Yw.shape = (N, 1)
    misclass = 0
    for _ in range(N):
        if Yw[_] != Y[_]:
            misclass += 1
    Eout.append(float(misclass)/N)
    # Computation Status:
    if (i%150==0): print("Computing... " + repr(i/10) + "%")
Eout = sum(Eout)/n
print "OutSample Error: " + repr(Eout)

# -----------------
# Validating Target Vector:     #   sign(Wtx1) = sign(Wtx2) = 0     --- code later.. maybe

#debg checking insample error:
#    Z = np.mat(X).dot(W)-Y
#    EiZ = []
#    for _ in range(N):
#        EiZ.append(Z[_]**2)
#    Ein.append(sum(EiZ)/N)

#Alt weight vec comp:
    #W = np.dot(Xpsv, Y)

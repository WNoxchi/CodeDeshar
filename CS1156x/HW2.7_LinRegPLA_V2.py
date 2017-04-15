# CS1156x Learning From Data - HW 2.7 - Linear Regression -> PLA
# Wayne H Nixalo - 23-Oct-2016 11:43 - 23-Oct-2016 15:41
# <>---------------------<>---------------------<>
#
# <>---------------------<>---------------------<>
import numpy as np

def createTargetFn():
    F = [[0,0],[0,0]]
    while (F[0][0] == F[1][0] or F[0][1] == F[1][1]):
        F = []
        for _ in range(2):
            F.append([np.random.uniform(-1,1), np.random.uniform(-1,1)])
    m = (F[0][1]-F[1][1])/(F[0][0]-F[1][0])
    c = F[0][1] - m*F[0][0]
    return [c, m, -1]
def createDataSet(N):
    X = []
    for _ in range(N):
        X.append([1, np.random.uniform(-1,1), np.random.uniform(-1,1)])
    return X
def createOutpVec(W, X, N):
    Y = []
    for _ in range(N):
        Y.append(np.sign(np.transpose(W).dot(X[_])))
    Y = np.array(Y)
    Y.shape = (N, 1)
    return Y
def LinRegWVector(X, Y):
    Xpsv = np.linalg.inv(np.transpose(X).dot(X)).dot(np.transpose(X))
    return Xpsv.dot(Y)
def compute_Error(W, Y, N, X):
    Yw = []
    for _ in range(N):
        Yw.append(np.sign(np.transpose(W).dot(X[_])))
    Yw = np.array(Yw)
    Yw.shape = (N, 1)
    misclass = 0
    for _ in range(N):
        if Yw[_] != Y[_]:
            misclass += 1
    return float(misclass)/N
def LinReg(N,n, gx = []):
    Eio = True
    if gx == []: Eio = False
    E = []
    for i in range(n):
        W = createTargetFn()
        X = createDataSet(N)
        Y = createOutpVec(W, X, N)
        if not Eio:
            W = LinRegWVector(X, Y)
        elif Eio:
            W = gx
        E.append(compute_Error(W, Y, N, X))
        if (i%150==0): print("Computing... " + repr(i/10) + "%")
    E = sum(E)/n
    if Eio:
        print "OutSample Error: " + repr(E)
    elif not Eio:
        print "InSample Error: " + repr(E)
    return W

# gx = LinReg(100,1000)

# LinReg(1000, 1000, gx)

def PLA_WVector(N, X, Y, W = [0,0,0]):
    count = 0
    W = [-0.32818733,-1.13377105,-0.9228306]
    # w = [0,0,0]
    # for i in range(3): w[i] = W[i][0]
    # W = w
    while 1:
        misclass = []
        count += 1
        for _ in range(N):
            if np.sign((np.transpose(W)).dot(X[_])) != np.sign(Y[_]):
                misclass.append([X[_], Y[_]])
        if not misclass:
            W = [W,count]
            return W
        index = np.random.randint(0, len(misclass))
        W = W + np.multiply(misclass[index][0], misclass[index][1])
def PLA(N, n, gx = []):
    iterCount = 0
    Eio = True
    if gx == []: Eio = False
    E = []
    for i in range(n):
        W = createTargetFn()
        X = createDataSet(N)
        Y = createOutpVec(W, X, N)
        if not Eio:
            W = PLA_WVector(N, X, Y)
            iterCount += W[1]
            W = W[0]
        elif Eio:
            W = PLA_WVector(N, X, Y, gx)
            iterCount += W[1]
            W = W[0]
    print("PLA: Iteration Average: " + repr(iterCount/float(n)))

PLA(10, 1000)
# PLA(10, 1000)

# CS1156x Learning From Data - HW 2.7 - Linear Regression -> PLA
# Wayne H Nixalo - 23-Oct-2016 15:41 - 23-Oct-2016 21:19
# <>---------------------<>---------------------<>
# Version 4 - Working
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
    print("Linear Regression:")
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
        if (i == 0):  print("Computing... " + repr(i/10) + "%")
        elif (i%150==0): print("             " + repr(i/10) + "%")

    E = sum(E)/n
    if Eio:
        print "OutSample Error: " + repr(E)
    elif not Eio:
        print "InSample Error: " + repr(E)
    return W
def LinRegPLA(N, n, Wg = [0,0,0]):
    print("Linear Regression Perceptron:")
    iterations = 0
    for _ in range(n):
        # (1) gen target weight fn:
        Wf = createTargetFn()
        # (2) gen training set points:
        X = createDataSet(N)
        # (3) gen weight vector using Linear Regression:
        Y = createOutpVec(Wf, X, N)
        Wg = LinRegWVector(X, Y)
        Ww = []
        for i in range(3): Ww.append(Wg[i][0])
        Wg = Ww
        # (4) Perceptron:
        while True:
            iterations += 1
            misclass = []
            for i in range(N):
                if (np.sign(np.transpose(Wg).dot(X[i])) != np.sign(np.transpose(Wf).dot(X[i]))):
                    misclass.append(X[i])
            if not misclass:
                break;
            index = np.random.randint(0, len(misclass))
            Xi = misclass[index]
            Wg += np.multiply((np.sign(np.transpose(Wf).dot(Xi))), Xi)
        if (_ == 0):  print("Computing... " + repr(_/10) + "%")
        elif (_%150==0): print("             " + repr(_/10) + "%")

    print("Avg Iterations to Convergence: " + repr(iterations/float(n)))

gx = LinReg(100, 1000)
LinReg(100, 1000, gx)
LinRegPLA(10, 1000)

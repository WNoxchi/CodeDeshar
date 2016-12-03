# CS1156x Learning From Data - HW 2.10 - Linear Regression for Classification
# Wayne H Nixalo - 24-Oct-2016 23:36
# <>---------------------<>---------------------<>
# OutSample Error for h(x) frm Problem 9
# <>---------------------<>---------------------<>
import numpy as np

def createTrainingPoints(N):
    X = []
    for _ in range(N):
        X.append([1, np.random.uniform(-1,1), np.random.uniform(-1,1)])
    return X
def createDataLabels(N,X):
    Y = []
    for _ in range(N):
        Y.append(np.sign(X[_][1]**2 + X[_][2]**2 - 0.6))
    return Y
def createFeatureVector(N,X):
    Z = []
    for _ in range(N):
        Z.append([1, X[_][1], X[_][2], X[_][1]*X[_][2], X[_][1]**2, X[_][2]**2])
    return Z
def noisyDataLabels(N,Y):
    nY = []
    for _ in range(N):
        nY.append(Y[_])
    for _ in range(N/10):
        index = np.random.randint(0,N)
        nY[index] *= -1
    return nY
def LinRegWVec(Z,nY):
    W = []
    Xpsv = np.linalg.pinv(Z)
    W = Xpsv.dot(nY)
    return W
def computeError(W, Y, N, Z):
    miss = 0
    for _ in range(N):
        if (np.sign(np.transpose(W).dot(Z[_])) != np.sign(Y[_])):
            miss += 1
    return miss/float(N)

N, n = 1000, 1000
E = 0
# hypothesis from problem 9:
W = [-1,-0.05,0.08,0.13,1.5, 1.5]
for _ in range(n):
    X = createTrainingPoints(N)
    Y = createDataLabels(N,X)
    Z = createFeatureVector(N,X)
    nY = noisyDataLabels(N,Y)
    # W = LinRegWVec(Z, nY)
    # ComputeError
    E += computeError(W, Y, N, Z)
E /= n

print ("OutSample Error:" + repr(E))

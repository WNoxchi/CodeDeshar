# CS1156x Learning From Data - HW 2.7 - Linear Regression -> PLA
# Wayne H Nixalo - 23-Oct-2016 22:23 - 23-Oct-2016 23:37
# <>---------------------<>---------------------<>
# LinReg w/ 10% simultd Noise on X,y
# <>---------------------<>---------------------<>
import numpy as np

def createDataSet(N):
    X = []
    for _ in range(N):
        X.append([1, np.random.uniform(-1,1), np.random.uniform(-1,1)])
    return X
def createLabels(N, X):
    Y = []
    for _ in range(N):
        Y.append(np.sign(X[_][1]**2 + X[_][2]**2 - 0.6))
    return Y
def createDataMat(X, Y):
    A = []
    for _ in range(len(X)):
        A.append([X[_][1], X[_][2], Y[_]])
    return A
def LinRegWVec(X, Y):
    W = []
    Xpsv = np.linalg.pinv(X)
    W = Xpsv.dot(Y)
    return W
def compute_Error(W, A, X):
    miss = 0
    for _ in range(len(X)):
        if (np.sign(np.transpose(W).dot(X[_])) != np.sign(A[_][2])):
            miss += 1
    return float(miss)/len(X)

# N,n = 10,1
def LinRegNL(N, n):
    E = 0
    X = createDataSet(N)
    Y = createLabels(N, X)
    # Create DataMatrix:
    A = createDataMat(X, Y)
    # Sim Noise by flipping 10% of labels:
    for _ in range(N/10):
        index = np.random.randint(0, N)
        A[index][2] *= -1
    # Linear Regression:
    for _ in range(n):
        # W Vector:
        W = LinRegWVec(X, Y)
        # Calculate Error:
        E += compute_Error(W,A,X)
    E /= n
    return E

print LinRegNL(1000,1000)

# CS1156x Learning From Data - HW 2.9 - Linear Regression for Classification
# Wayne H Nixalo - 24-Oct-2016 18:41 - 24-Oct-2016 19:42
# <>---------------------<>---------------------<>
# LinReg w/ 10% simultd Noise on X,y | NonLinear Fn
# <>---------------------<>---------------------<>
import numpy as np
# Target Fn: f(x1, x2) = sign(x1^2 + x2^2 - 0.6)
N = 10

def createTrainingSet(N):
    X = []
    for _ in range(N):
        X.append([1, np.random.uniform(-1,1), np.random.uniform(-1,1)])
    return X
def createDataLabels(X):
    Y = []
    for _ in range(len(X)):
        Y.append(np.sign(X[_][1]**2 + X[_][2]**2 - 0.6))
    return Y
def createFeatureVec(X):
    # feature vector is hard-coded depending on problem
    Z = []
    for _ in range(len(X)):
        Z.append([1, X[_][1], X[_][2], X[_][1]*X[_][2], X[_][1]**2, X[_][2]**2])
    return Z
def createDataSet(Z, Y):
    # dimensions of A set by dim of Z & Y (hard-coded)
    A = []
    for _ in range(len(Z)):
        A.append([Z[_][1], Z[_][2], Z[_][3], Z[_][4], Z[_][5], Y[_]])
    return A
def simulateNoise(A):
    for _ in range(len(A)/10):
        index = np.random.randint(0, len(A))
        A[index][5] *= -1
    return A
# def LinRegWVec(A,Z):
#     y = []
#     for _ in range(len(Z)):
#         y.append(A[_][5])
#     print y
#     W = []
#     Xpsv = np.linalg.pinv(Z)
#     W = np.transpose(Xpsv).dot(y)
#     return W
def LinRegWVec(Z, Y):
        W = []
        Xpsv = np.linalg.pinv(Z)
        W = Xpsv.dot(Y)
        return W
def computeError(W, A, Z, Fn):
    miss = 0
    for _ in range(len(A)):
        if (np.sign(np.transpose(W).dot(Z[_])) != np.sign(Fn[0]*Z[_][0] + Fn[1]*Z[_][1] + Fn[2]*Z[_][2] + Fn[3]*Z[_][3] + Fn[4]*Z[_][4] + Fn[5]*Z[_][5])):
            miss += 1
    return float(miss)/len(A)

# def LinRegNL(N, n):
# Fn Choices:
Choices = ['a','b','c','d','e']
F = [[-1,-0.05,0.08,0.13,1.5, 1.5],
     [-1,-0.05,0.08,0.13,1.5, 15],
     [-1,-0.05,0.08,0.13,15,  1.5],
     [-1,-1.5, 0.08,0.13,0.05,0.05],
     [-1,-0.05,0.08,1.5, 0.15,0.15]]
E = [0,0,0,0,0]
X = createTrainingSet(N)
Y = createDataLabels(X)
Z = createFeatureVec(X)
A = createDataSet(Z, Y)
# Simulate 10% Noise
A = simulateNoise(A)
# Linear Regression
W = LinRegWVec(A,Z)
# Compute Error
for i in range(len(E)):
    E[i] = computeError(W, A, Z, F[i])
# Pick best Fn Choice
Emin = [E[0],Choices[0]]
for i in range(len(E)):
    if (E[i] < Emin[0]):
        Emin = [E[i],Choices[i]]
print Emin

# CS1156x Learning From Data - HW 2.9 - Linear Regression for Classification
# Wayne H Nixalo - 24-Oct-2016 19:43 - 24-Oct-2016 20:37
# <>---------------------<>---------------------<>
# LinReg w/ 10% simultd Noise on X,y | NonLinear Fn
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
    for _ in range(N//10):      # use // for int division
        index = np.random.randint(0,N)
        nY[index] *= -1
    return nY
def LinRegWVec(Z,nY):
    W = []
    Xpsv = np.linalg.pinv(Z)
    W = Xpsv.dot(nY)
    return W
def computeError(W, N, Z, Fn):
    miss = 0
    for _ in range(N):
        if (np.sign(np.transpose(W).dot(Z[_])) !=
                np.sign(Fn[0]*Z[_][0] + Fn[1]*Z[_][1] + Fn[2]*Z[_][2]
                + Fn[3]*Z[_][3] + Fn[4]*Z[_][4] + Fn[5]*Z[_][5])):
            miss += 1
    return miss/float(N)
def LinRegNL(N, n):
    # Fn Choices:
    Choices = ['a','b','c','d','e']
    F = [[-1,-0.05,0.08,0.13,1.5, 1.5],
         [-1,-0.05,0.08,0.13,1.5, 15],
         [-1,-0.05,0.08,0.13,15,  1.5],
         [-1,-1.5, 0.08,0.13,0.05,0.05],
         [-1,-0.05,0.08,1.5, 0.15,0.15]]
    E = [0,0,0,0,0]
    for _ in range(n):
        X = createTrainingPoints(N)
        Y = createDataLabels(N,X)
        Z = createFeatureVector(N,X)
        nY = noisyDataLabels(N,Y)
        W = LinRegWVec(Z, nY)
        # ComputeError
        for i in range(len(E)):
            E[i] += computeError(W, N, Z, F[i])
    for _ in range(len(E)):
        E[_] /= float(n)
    # Pick Answer:
    Emin = [E[0], Choices[0]]
    for _ in range(len(E)):
        if E[_] < Emin[0]:
            Emin[0] = E[_]
            Emin[1] = Choices[_]
    print ("Error & closest matching function:")
    print (Emin)

LinRegNL(1000,5)

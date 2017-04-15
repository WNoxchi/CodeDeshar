# CS1156x Learning From Data - HW 2.9 - Linear Regression for Classification
# Wayne H Nixalo - 24-Oct-2016 00:10-00:30|24-Oct-2016 14:55 - 24-Oct-2016 18:41
# <>---------------------<>---------------------<>
# LinReg w/ 10% simultd Noise on X,y | NonLinear Fn
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
def createFeatureVec(X):
    Z = []
    for _ in range(len(X)):
        Z.append([1, X[_][1], X[_][2], X[_][1]*X[_][2], X[_][1]**2, X[_][2]**2])
    return Z
def createDataMat(Z, Y):
    A = []
    for _ in range(len(Z)):
        A.append([Z[_][1], Z[_][2], Z[_][3], Z[_][4], Z[_][5], Y[_]])
    return A
def LinRegWVec(X, Y):
    W = []
    Xpsv = np.linalg.pinv(X)
    W = Xpsv.dot(Y)
    return W
def compute_Error(W, A, Z, fn):
    miss = 0
    for _ in range(len(A)):
        if (np.sign(fn[0]*1 + fn[1]*A[_][0] + fn[2]*A[_][1] + fn[3]*A[_][2]
                                            + fn[4]*A[_][3] + fn[5]*A[_][4])
                          != np.sign(A[_][5])):
            miss += 1
    return miss/float(len(A))

N,n = 10,1000
#def LinRegNL(N, n):
# Hypothesis Set
F = [[-1,-0.05,0.08,0.13,1.5, 1.5],
     [-1,-0.05,0.08,0.13,1.5, 15],
     [-1,-0.05,0.08,0.13,15,  1.5],
     [-1,-1.5, 0.08,0.13,0.05,0.05],
     [-1,-0.05,0.08,1.5, 0.15,0.15]]
E = [0,0,0,0,0]
for i in range(n):
    X = createDataSet(N)
    Y = createLabels(N, X)
    Z = createFeatureVec(X)
    # Linear Regression:
    # W Vector:
    W = LinRegWVec(Z, Y)
    # Create DataMatrix:
    A = createDataMat(Z, Y)
    # Sim Noise by flipping 10% of labels:
    for _ in range(N/10):
        index = np.random.randint(0, N)
        A[index][5] *= -1
    # Compare Labels to Functions:
    for _ in range(len(F)):
        E[_] += compute_Error(W, A, Z, F[_])
    if (i == 0):  print("Computing... " + repr(i/10) + "%")
    elif (i%150==0): print("             " + repr(i/10) + "%")
Answer = ['a','b','c','d','e']
for _ in range(len(E)):
    E[_] /= float(n)
Emin = [E[0],0]
for _ in range(len(E)):
    if E[_] < Emin:
        Emin = [E[_],_]
print (repr(Emin[0]) + " Answer: " + repr(Answer[Emin[1]]))


#LinRegNL(1000,1000)

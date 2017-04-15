# CS1156x Learning From Data - HW 2.5 - Linear Regression
# Wayne H Nixalo - 20-Oct-2016 17:11 - 20-Oct-2016 20:25 (2.5) - 20-Oct-2016 21:35 (2.6)
# <>---------------------<>---------------------<>
import numpy as np

# N = 10
# n = 1000

def LinReg(gx, n, N):
    Ein = [] # In-Sample Error
    Eout = [] # Out-Sample Error
    for i in range(n):
        #target fn F:
        F = []
        for _ in range(2):
            F.append([np.random.uniform(-1,1), np.random.uniform(-1,1)])
        #data set of inputs X:
        X = []
        for _ in range(N):
            X.append([1, np.random.uniform(-1,1), np.random.uniform(-1,1)])
        #output Y:
        Y = []
        for _ in range(N):
            Y.append([np.sign((X[_][1]-F[0][0])*(F[1][1]-F[0][1])-(X[_][2]-F[0][1])*(F[1][0]-F[0][0]))])
        # Calculate PseudoInverse of X:
        Xpsiv = np.linalg.inv(((np.transpose(X)).dot(X))).dot(np.transpose(X))
        W = Xpsiv.dot(Y);
        # Calculate In-Sample Error via Norm Squared / N:
        Ein.append((np.linalg.norm((np.mat(X).dot(np.mat(W)) - Y))**2)/N)
        # Calculate Out-Sample Error if prior g(x) passed in; Eout = misclass pts / total pts:
        if gx:
            misclass = 0
            for _ in range(N):
                if (np.sign(np.transpose(gx[0][1]).dot(X[_])) != np.sign(Y[_])):    # W vector is stored at gx[0][1]
                    misclass += 1
            Eout.append(float(misclass)/N)
        if (i == 0): print("Computing: LinReg(n = " + repr(n) + ", N = " + repr(N) + ") ...")
        elif (i%150==0): print(repr(i/10) + "%")

    Ein = np.sum(Ein)/n
    print ("In-Sample Error:  " + repr(Ein))
    if gx:
        Eout = np.sum(Eout)/n
        print ("Out-Sample Error: " + repr(Eout))
    # return g(x):[N,W] for next problem
    return [N, W]

gx = []
# Experiment 1 (HW2.5):
gx.append(LinReg(gx, n = 1000, N = 100))
# Experiment 2 (HW2.6):
# LinReg(gx, n = 1000, N = 1000)


# # debg
# print ("Matrix Xpsiv: d" + repr(Xpsiv.shape))
# print ("Matrix X    : d" + repr(np.mat(X).shape))
# print ("Vector W    : d" + repr(np.mat(W).shape))
# print W

# print gx[0][1]
# for _ in range(3):print gx[0][1][_]

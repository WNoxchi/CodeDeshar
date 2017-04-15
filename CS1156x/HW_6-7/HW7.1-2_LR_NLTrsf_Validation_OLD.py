# -*- coding: utf-8 -*-
# CS1156x Learning From Data - HW 7.1
# Wayne H Nixalo - 2017-Feb-10 13:31
# <>---------------------<>---------------------<>
# Linear Regression NL trsf w/ Validation Set
# <>---------------------<>---------------------<>
# program will be the same as HW6 except for splitting off the validation data
import numpy as np

# function to load in data file -- returns list of lists of floats
def loadData(filename):
    '''
    :param filename:
    :return returnArray, an array of arrays of floats:
    '''
    file = open(filename, 'r')
    filestring = file.readline()
    returnArray = []
    while filestring != '':
        line = []
        for s in filestring.split(' '):
            if s != '':
                line.append(float(s))
        returnArray.append(line)
        filestring = file.readline()
    file.close()
    return returnArray

# Φ(x1, x2) = (1, x1, x2, x1^2, x2^2, |x1-x2|, |x1+x2|)
def transformMatrix(X,k):
    Theta = lambda x1, x2 : [1, x1, x2, x1**2, x2**2, x1*x2, abs(x1-x2), abs(x1+x2)]
    Z = []
    for i in range(len(X)):
        x1, x2 = X[i][1], X[i][2]
        Z.append(Theta(x1,x2)[:k+1])        # a better way would be to not do unnecessary computations past k
    return np.array(Z)

def extractXYmats(D):
    X, Y = [], []
    for i in range(len(D)):
        X.append([1, D[i][0], D[i][1]])
        Y.append([D[i][2]])
    X, Y = np.array(X), np.array(Y)
    return X, Y

# Calculate InSample Error on Training Set:
def CalcEin(D, W, Z, Y):
    N, misclass = len(D), 0
    for i in range(N):
        if np.sign(np.transpose(W).dot(Z[i])) != np.sign(Y[i]):      # could use D[i][2] for Y[i] instead
           misclass += 1
    Ein = float(misclass)/N
    return Ein

# Compute W vector via PseudoInverse:
def computeW(Z):
    W = np.linalg.pinv(Z).dot(Y)
    return W

# Import trainint dataset
D = loadData('in.dta')

# separate data into training & validation sets
D_train = D[:25]
D_valid = D[25:]

# Compute H sets (W):
H = []
k = 3
for i in range(5):
    X,Y = extractXYmats(D_train)
    Z = transformMatrix(X, k+i)
    W = computeW(Z)
    H.append(W)

# Use Validation set to select H_k:
E = []
for i in range(5):
    X,Y = extractXYmats(D_valid)
    Z = transformMatrix(X, k+i)
    misclass = 0
    for j in range(len(D_valid)):
        if np.sign(np.transpose(H[i]).dot(Z[j])) != np.sign(Y[j]):
            misclass += 1
    E.append(float(misclass)/len(D_valid))

# Console Output:
print("HW 7.1:")
print("Hypothesis Sets: H_k; k: 3..7:\n--------------------------------------")
for i in range(len(H)):
    print("Error(H[k:{}]) = {}".format(3+i, E[i]))
    # print("H[k:{}]:\n{}\n".format(3+i, H[i]))

def printMinE(Error):
    K = []
    for i in range(len(Error)):
        K.append([Error[i], i+k])
    K = min(K)
    print("Minimum Error: E = {} at k = {}".format(K[0],K[1]))

printMinE(E)

################################################################################
# 7.2: Evaluate E_out classification error using out.tda on the 5 models to see
#      how well the validation set predicted the best of the 5.
################################################################################
# Calculate OutSample Error on Testing Set:
D = loadData('out.dta')
Eout = []
for i in range(5):
    X,Y = extractXYmats(D)
    Z = transformMatrix(X,k+i)
    misclass = 0
    for j in range(len(D)):
        if np.sign(np.transpose(H[i]).dot(Z[j])) != np.sign(Y[j]):
            misclass += 1
    Eout.append(float(misclass)/len(D))

print("\nHW 7.2:")
print("Applying to out-sample Data:\n----------------------------")
for i in range(len(H)):
    print("Error(H[k:{}]) = {}".format(3+i, Eout[i]))

printMinE(Eout)
# print(H)

################################################################################
# OUTPUT:
# Hypothesis Sets: H_k; k: 3..7:
# --------------------------------------
# Error(H[k:3]) = 0.3
# Error(H[k:4]) = 0.5
# Error(H[k:5]) = 0.2
# Error(H[k:6]) = 0.0
# Error(H[k:7]) = 0.1
# Minimum Error: Ein = 0.0 at k = 6
#
# Applying to out-sample Data:
# ----------------------------
# Error(H[k:3]) = 0.42
# Error(H[k:4]) = 0.416
# Error(H[k:5]) = 0.188
# Error(H[k:6]) = 0.084
# Error(H[k:7]) = 0.072
# Minimum Error: Ein = 0.072 at k = 7

################################################################################
# 7.3:    Rerverse the role of training and validation sets. Training with last
#         10 examples & validating with first 25.
# 7.4:    Eval out-sample error using out.dta on the 5 models.
################################################################################

# Import trainint dataset
D = loadData('in.dta')

# separate data into training & validation sets
D_train = D[:10]
D_valid = D[10:]

# Compute H sets (W):
H = []
k = 3
for i in range(5):
    X,Y = extractXYmats(D_train)
    Z = transformMatrix(X, k+i)
    W = computeW(Z)
    H.append(W)

# for h in H:
#     print(len(h))

# Use Validation set to select H_k:
E = []
for i in range(5):
    X,Y = extractXYmats(D_valid)
    Z = transformMatrix(X, k+i)
    misclass = 0
    for j in range(len(D_valid)):
        if np.sign(np.transpose(H[i]).dot(Z[j])) != np.sign(Y[j]):
            misclass += 1
    #     if i == 3:
    #         print(np.transpose(H[i]).dot(Z[j]), Y[j])
    #         print(np.sign(np.transpose(H[i]).dot(Z[j])) != np.sign(Y[j]))
    # if i == 3:
    #     print(misclass)
    #     print(float(misclass)/len(D_valid))
    E.append(float(misclass)/len(D_valid))
    # print(E)

# Console Output:
print("\nHW 7.3:")
print("Hypothesis Sets: H_k; k: 3..7:\n--------------------------------------")
for i in range(len(H)):
    print("Error(H[k:{}]) = {}".format(3+i, E[i]))
printMinE(E)

# outsample testing dataset
D = loadData('out.dta')

Eout = []
for i in range(5):
    X,Y = extractXYmats(D)
    Z = transformMatrix(X,k+i)
    misclass = 0
    for j in range(len(D)):
        if np.sign(np.transpose(H[i]).dot(Z[j])) != np.sign(Y[j]):
            misclass += 1
    Eout.append(float(misclass)/len(D))

print("\nHW 7.4:")
print("Applying to out-sample Data:\n----------------------------")
for i in range(len(H)):
    print("Error(H[k:{}]) = {}".format(3+i, Eout[i]))

printMinE(Eout)

################################################################################
# OUTPUT:
# HW 7.3, 7.4:
# Hypothesis Sets: H_k; k: 3..7:
# --------------------------------------
# Error(H[k:3]) = 0.2791666666666667
# Error(H[k:4]) = 0.275
# Error(H[k:5]) = 0.325
# Error(H[k:6]) = 0.2833333333333333
# Error(H[k:7]) = 0.2833333333333333
# Minimum Error: Ein = 0.275 at k = 4
#
# Applying to out-sample Data:
# ----------------------------
# Error(H[k:3]) = 0.268
# Error(H[k:4]) = 0.264
# Error(H[k:5]) = 0.312
# Error(H[k:6]) = 0.272
# Error(H[k:7]) = 0.272
# Minimum Error: Ein = 0.264 at k = 4

import numpy as np

# returns D
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

# returns Z
def extractFeatureSet(X,k):
    Theta = lambda x1, x2 : [1, x1, x2, x1**2, x2**2, x1*x2, abs(x1-x2), abs(x1+x2)]
    Z = []
    for i in range(len(X)):
        x1, x2 = X[i][1], X[i][2]
        Z.append(Theta(x1,x2)[:k+1])        # a better way would be to not do unnecessary computations past k
    return np.array(Z)

# returns X, Y
def extractXYmats(D):
    X, Y = [], []
    for i in range(len(D)):
        X.append([1, D[i][0], D[i][1]])
        Y.append([D[i][2]])
    X, Y = np.array(X), np.array(Y)
    return X, Y

# returns W
def computeW(Z, Y):
    W = np.linalg.pinv(Z).dot(Y)
    return W

# returns E
def calcError(D, W, Z):
    N, misclass = len(D), 0
    for i in range(N):
        if np.sign(np.transpose(W).dot(Z[i])) != np.sign(D[i][2]):
            misclass += 1
    return float(misclass)/N

# returns H, Zs
def trainLRM(D):
    k, lenTheta = 3, 8
    H = []
    X, Y = extractXYmats(D)
    for i in range(lenTheta - k):
        Z = extractFeatureSet(X, k+i)
        W = computeW(Z, Y)
        H.append(W)
    return H

# returns Es
def validLRM(D, H):
    k, lenTheta = 3, 8
    X, Y = extractXYmats(D)

    Z = []
    for i in range(lenTheta - k):
        Z.append(extractFeatureSet(X, k+i))

    errors = []
    for i in range(len(H)):
        errors.append(calcError(D, H[i], Z[i]))
    return errors


# HW 7.1 ################################
D = loadData('in.dta')
D_train =  D[:25]
D_valid = D[25:]

H = trainLRM(D_train)
E = validLRM(D_valid, H)

print("\nHW 7.1:")
print("Hypothesis Sets: H_k; k: 3..7:\n--------------------------------------")
for i in range(5):
    print("Error(H[k:{}]) = {}".format(3+i, E[i]))
mindex = np.argmin(E)
print("Minimum Error: E = {} at k = {}".format(E[mindex], 3 + mindex))

# HW 7.2 ################################
D = loadData('out.dta')
X, Y = extractXYmats(D)
Zs = []
for i in range(5):
    Zs.append(extractFeatureSet(X, 3+i))
E = validLRM(D, H)

print("\nHW 7.2:")
print("Applying to out-sample Data:\n--------------------------------------")
for i in range(5):
    print("Error(H[k:{}]) = {}".format(3+i, E[i]))
mindex = np.argmin(E)
print("Minimum Error: E = {} at k = {}".format(E[mindex], 3 + mindex))

# HW 7.3 ################################

D = loadData('in.dta')
D_train =  D[25:]
D_valid = D[:25]

H = trainLRM(D_train)
E = validLRM(D_valid, H)

print("\nHW 7.3:")
print("Hypothesis Sets: H_k; k: 3..7:\n--------------------------------------")
for i in range(5):
    print("Error(H[k:{}]) = {}".format(3+i, E[i]))
mindex = np.argmin(E)
print("Minimum Error: E = {} at k = {}".format(E[mindex], 3 + mindex))

# HW 7.4 ################################

D = loadData('out.dta')
X, Y = extractXYmats(D)
Zs = []
for i in range(5):
    Zs.append(extractFeatureSet(X, 3+i))
E = validLRM(D, H)

print("\nHW 7.4:")
print("Applying to out-sample Data:\n--------------------------------------")
for i in range(5):
    print("Error(H[k:{}]) = {}".format(3+i, E[i]))
mindex = np.argmin(E)
print("Minimum Error: E = {} at k = {}".format(E[mindex], 3 + mindex))


# # output:
#
# Waynes-MBP:HW_6-7 WayNoxchi$ python3 HW7test.py
#
# HW 7.1:
# Hypothesis Sets: H_k; k: 3..7:
# --------------------------------------
# Error(H[k:3]) = 0.3
# Error(H[k:4]) = 0.5
# Error(H[k:5]) = 0.2
# Error(H[k:6]) = 0.0
# Error(H[k:7]) = 0.1
# Minimum Error: E = 0.0 at k = 6
#
# HW 7.2:
# Applying to out-sample Data:
# --------------------------------------
# Error(H[k:3]) = 0.42
# Error(H[k:4]) = 0.416
# Error(H[k:5]) = 0.188
# Error(H[k:6]) = 0.084
# Error(H[k:7]) = 0.072
# Minimum Error: E = 0.072 at k = 7
#
# HW 7.3:
# Hypothesis Sets: H_k; k: 3..7:
# --------------------------------------
# Error(H[k:3]) = 0.28
# Error(H[k:4]) = 0.36
# Error(H[k:5]) = 0.2
# Error(H[k:6]) = 0.08
# Error(H[k:7]) = 0.12
# Minimum Error: E = 0.08 at k = 6
#
# HW 7.4:
# Applying to out-sample Data:
# --------------------------------------
# Error(H[k:3]) = 0.396
# Error(H[k:4]) = 0.388
# Error(H[k:5]) = 0.284
# Error(H[k:6]) = 0.192
# Error(H[k:7]) = 0.196
# Minimum Error: E = 0.192 at k = 6

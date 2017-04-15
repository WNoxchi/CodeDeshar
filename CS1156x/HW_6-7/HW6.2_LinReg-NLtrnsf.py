# CS1156x Learning From Data - HW 6.2 Regularization & Weight Decay - Linear Regression
# Wayne H Nixalo - 21-Dec-2016 16:45 - 17:15
# <>---------------------<>---------------------<>
# Linear Regression w/ NL trsf on datasets
# <>---------------------<>---------------------<>
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
def transformMatrix(X):
    Z = []
    for i in range(len(X)):
        x1, x2 = X[i][1], X[i][2]
        Z.append([1, x1, x2, x1**2, x2**2, x1*x2, abs(x1-x2), abs(x1+x2)])
    return np.array(Z)

# Import Training DataSet:
D = loadData('in.dta')

# Extract X and Y matrices:
X, Y = [], []
for i in range(len(D)):
    X.append([1, D[i][0], D[i][1]])
    Y.append([D[i][2]])
X, Y = np.array(X), np.array(Y)

# Create Transform Matrix Z:
Z = transformMatrix(X)

# print("ZtZ:\n{}".format(np.transpose(Z).dot(Z)))
print("Dim(ZtZ): {}".format(np.shape(np.transpose(Z).dot(Z))))

# Compute W vector via PseudoInverse:
W = np.linalg.pinv(Z).dot(Y)

# Calculate InSample Error on Training Set:
N, misclass = len(D), 0
for i in range(N):
    if np.sign(np.transpose(W).dot(Z[i])) != np.sign(Y[i]):      # could use D[i][2] for Y[i] instead
       misclass += 1
Ein = float(misclass)/N

# Calculate OutSample Error on Testing Set:
D = loadData('out.dta')
N, misclass = len(D), 0
# update new X & Y:
X, Y = [], []
for i in range(N):
    X.append([1, D[i][0], D[i][1]])
    Y.append([D[i][2]])
X, Y = np.array(X), np.array(Y)
Z = transformMatrix(X)

for i in range(N):
    if np.sign(np.transpose(W).dot(Z[i])) != np.sign(Y[i]):
        misclass += 1
Eout = float(misclass)/N

print("Ein: {}, Eout: {}".format(Ein, Eout))
print("W vector:\n{}".format(W))

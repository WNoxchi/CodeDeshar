# CS1156x Learning From Data - HW 6.3 - 6.6 Regularization & Weight Decay - Linear Regression
# Wayne H Nixalo - 21-Dec-2016 17:57 - 18:16 | 21:05 - 21:55
# <>---------------------<>---------------------<>---------------------<>
# Linear Regression w/ Weight Decay λ w/ NL trsf on datasets
# <>---------------------<>---------------------<>---------------------<>
# NOTE: code is mostly repackaged from HW6.2, now including weight decay
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

def LinRegWD(k):
    # Regularization parameters:
    if k is not None:
        λ = 10**k
    elif k is None:
        λ = 0
    print("k = {}, λ = {}".format(k, λ))

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

    # Compute W vector via PseudoInverse:
    W = (np.linalg.inv(np.transpose(Z).dot(Z) + np.multiply(λ, np.identity(len(Z[0]))))).dot(np.transpose(Z).dot(Y))
    # I will be a 8x8 sq-mat: len(Φ(x1, x2))

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

LinRegWD(None)
LinRegWD(-3)
LinRegWD(3)
for i in range(5):
    LinRegWD(-2+i)

# ============================================================================ #
# Terminal Output:
# Waynes-MacBook-Pro:HW6 WayNoxchi$ python3 HW6.3-6_LinReg-WtDecay-NLtrnsf.py
# k = None, λ = 0
# Ein: 0.02857142857142857, Eout: 0.084
# k = -3, λ = 0.001
# Ein: 0.02857142857142857, Eout: 0.08
# k = 3, λ = 1000
# Ein: 0.37142857142857144, Eout: 0.436
# k = -2, λ = 0.01
# Ein: 0.02857142857142857, Eout: 0.084
# k = -1, λ = 0.1
# Ein: 0.02857142857142857, Eout: 0.056
# k = 0, λ = 1
# Ein: 0.0, Eout: 0.092
# k = 1, λ = 10
# Ein: 0.05714285714285714, Eout: 0.124
# k = 2, λ = 100
# Ein: 0.2, Eout: 0.228

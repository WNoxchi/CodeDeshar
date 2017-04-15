# CS1156x Learning From Data - HW 2.7 - Linear Regression->PLA
# Wayne H Nixalo - 20-Oct-2016 21:48 - 20-Oct-2016 22:41
# <>---------------------<>---------------------<>
import numpy as np

def PLA(W, n, N):
    count = 0
    print ("Computing: PLA(W, n = " + repr(n) + ", N = " + repr(N) + ") ...")
    for _ in range(n):
        if (_/100 > 0 and _ % 100 == 0): print repr(_/10) + "%"
        # choose target Fn
        F = []
        for i in range(2):
            F.append([np.random.uniform(-1,1), np.random.uniform(-1,1)])

        # choose inputs Xn as randm pts
        X = []
        for i in range(N):
            X.append([1, np.random.uniform(-1,1), np.random.uniform(-1,1)])

        #  eval target Fn on each Xn
        Y = []
        for i in range(N):
            Y.append(np.sign((X[i][1]-F[0][0])*(F[1][1]-F[0][1])-(X[i][2]-F[0][1])*(F[1][0]-F[0][0])))

        # Use PLA to find g starting w/zeroed weight vec W if no W exists
        if len(W) == 0:
            W = [0,0,0]

        # each Iteration running PLA on random misclass'd point
        while 1:
            misclass = []
            count += 1
            for i in range(N):
                if np.sign((np.transpose(W)).dot(X[i])) != np.sign(Y[i]):
                    misclass.append([X[i], Y[i]])
            if not misclass:
                break;
            index = np.random.randint(0, len(misclass))
            W = W + np.multiply(misclass[index][0], misclass[index][1])

    # determine disagreement ratio between f/h and g
    miss = 0
    X = []
    for i in range(n):
        X.append([1, np.random.uniform(-1,1), np.random.uniform(-1,1)])
        if np.sign((np.transpose(W)).dot(X[i])) != np.sign((X[i][1]-F[0][0])*(F[1][1]-F[0][1])-(X[i][2]-F[0][1])*(F[1][0]-F[0][0])):
            miss += 1
    ratio = float(miss)/n

    iteravg =  float(count)/n
    print "------------------------------"
    print ("Iteration Average: " + repr(iteravg))
    print ("P[f(x) != g(x)]: " + repr(ratio))

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
gx.append(LinReg(gx, n = 1000, N = 1000))

# black magic fuckery to get weight vector into correct format for PLA fn:
W = gx[1][1]
w = [0,0,0]
for i in range(3):w[i] = W[i][0]
W = w

# Experiment 3 (HW2.7):
PLA(W, n = 1000, N = 10)




# debg:
# print gx[1][1]
# W = gx[1][1]
# print
# print ("W:"+repr(W))
# print "W[0]:"+repr(W[0])
# print "W[1]:"+repr(W[1])
# print
# print "W[0][0]:"+repr(W[0][0])
#
# w = [0,0,0]
# for i in range(3):w[i] = W[i][0]
# print w
# W = w
# print
# print W

# -*- coding: utf-8 -*-
# CS1156x Learning From Data - HW 5.8-9-10 - Logistic Regression
# Wayne H Nixalo - 01-Dec-2016 19:10 ---- 03-Dec-2016 16:49
# <>---------------------<>---------------------<>---------------------<>
# create target fn f, (probability), and dataset D to test LogReg.
# take f to be 0/1 probability so y is a deterministic fn of x.
# dim d = 2; X = [-1,1],[-1,1] w unifm problty of each x € X
# choose a line in plane as boundry btwn f(x) = 1 (where y is +1) and
# f(x) = 0 (where y is -1), by taking 2 random unifmly distrib points from X,
# and taking line passing through them as boundry btwn y = ±1. Pick N = 100 pts
# at random frm X, & eval the outputs y_n for each of these pts x_n
# ---------
# Run Logistic Regression w Stochastic Gradient Descent to find g, and estmt
# E_out (the cross entropy error) by generating sufficiently large, sepearate
# set of points to eval the error. Repeat exprmt for 100 runs w/ difnt targets
# & take the average. Initlz the weight vector of LogReg to all zeros in ea.
# run. Stop algo when ||w(t-1) - w(t)|| < 0.01, where w(t) denotes weight vec
# at end of epoch t. An epoch is a full pass through the N data points (use a
# random permutation of 1,2,•••,N to present the dat pts to the algo w/n each
# epoch, & use dfnt permutations for dfnt epochs. Use learning rate: 0.01.
# <>---------------------<>---------------------<>---------------------<>
import numpy as np
def createTargetFn():
    F = [[0,0],[0,0]]
    while (F[0][0] == F[1][0] or F[0][1] == F[1][1]):
        F = []
        for _ in range(2):
            F.append([np.random.uniform(-1,1), np.random.uniform(-1,1)])
    m = (F[0][1]-F[1][1])/(F[0][0]-F[1][0])
    c = F[0][1] - m*F[0][0]
    return [c, m, -1]
def createDataSet(N):
    X = []
    for _ in range(N):
        X.append([1, np.random.uniform(-1,1), np.random.uniform(-1,1)])
    return X
def generateLabels(X, N, f):
    Y = []
    for _ in range(N):
        # Y.append(np.sign(np.dot(X[_],f)))
        Y.append(np.sign(np.transpose(f).dot(X[_])))
        # if np.transpose(f).dot(X[_]) > 0:
        #     Y.append(1)
        # else:
        #     Y.append(0)
    return Y
# Cross Entropy Error
def crossEntropErr(W, Y, N, X):
    S = 0.0
    for _ in range(N):
        S += np.log(1 + np.exp(-Y[_]*np.transpose(W).dot(X[_])))
    # Y = np.array(Y)
    # X = np.array(X)
    # W = np.array(W)
    # return np.mean(np.log(1 + np.exp(-Y * np.expand_dims(np.dot(X, W), 1))))
    return S/N
# Euclidean Norm of w(t-1) - w(t)
def vecNormW(W):
    # norm, vec = 0, []
    # for _ in range(len(W[0])):
    #     vec.append(W[1][_]-W[0][_])
    # for _ in range(len(vec)):
    #     norm += vec[_]**2
    # return np.sqrt(norm)
    return np.linalg.norm(W[0]-W[1])
# ∇e = -(yn*xn)/(1 + exp{yn*wn.T.xn})
def calcGradE(yn, xn, w):
    xn = np.array(xn)
    w = np.array(w)
    return np.array((yn * xn) / (1 + np.exp(yn * np.transpose(w).dot(xn))))     #here's where my sign error was! Missing (-) sign on return
    # return np.divide(np.multiply(yn, xn),
    #                              (1 + np.exp(np.multiply(yn,
    #                                          np.transpose(w).dot(xn)))))
# to copy a Python list w/o convert to np.array() & w/o Python's madness
def vecCopy(vector):
    newvec = []
    for i in range(len(vector)):
        newvec.append(vector[i])
    return newvec

# Stochastic Gradient Descent
def SGD(nta, N, n, f):
    Eout, Epoch = 0, [0,0]
    for run in range(n):
        print('starting SGD run: {}/{}'.format(run+1,n))
        # create dataset D
        D = createDataSet(N)
        # gen labels yn
        Y = generateLabels(D,N,f)
        # package data pts & labels to keep ordered during epochs
        X = []
        for i in range(N):
            X.append([D[i]])
            X[i].append([Y[i]])
        # initialize weight vector; W[0]:w(t), W[1]:w(t-1)
        Wt0 = np.array([0.,0.,0.])
        Wt1 = np.array([0.,0.,0.])
        W = [Wt0,Wt1]   # place holder for W

        norm = 1
        # SGD Algorithm:
        while norm > nta:
            # update weight vector w(t-1) -> w(t)

            Wn = np.copy(Wt1)
            # x[0]: [xn], x[1]: [yn]
            for x in np.random.permutation(X):
                gradE = calcGradE(x[1][0], np.array(x[0]), Wt1 )
                Wn += nta * gradE   # looks like I had a sign error
            Wt0 = np.copy(Wn)
            # calc norm
            norm = np.linalg.norm(Wt1 - Wt0)
            # print('Wt1:{} , Wt0:{}'.format(Wt1,Wt0))
            Wt1 = np.copy(Wt0)

            Epoch[1] += 1
        print ('Run: {} , Epochs: {}'.format(run + 1, Epoch[1]))
        Epoch[0] += Epoch[1]
        Epoch[1] = 0

    return Wt0, Epoch[0]/n

# parameters
nta, N, n = 0.01, 100, 100

# create target fn f
f = createTargetFn()

# gen new test dataset & labels to det Cross Entropy Error:
tD = createDataSet(N)
tY = generateLabels(tD, N, f)

# run SGD to det weight vector
W, Epochs = SGD(nta, N, n, f)
Eout = crossEntropErr(W, tY, N, tD)

print('LogReg SGD final weight vector W: {}'.format(W))
print('Average Epochs: {}'.format(Epochs))
print('Eout: {}'.format(Eout))





# =========== DEV DUMP BELOW ===================================================

# big thanks to Robox at http://nbviewer.jupyter.org/github/tournami/Learning-From-Data-MOOC/blob/master/Homework%205.html
# whose code I used as a reference & realize mine's issue w deep copying lists.
# And to the CS1156x forums for this homework: https://courses.edx.org/courses/course-v1:CaltechX+CS_1156x+3T2016/discussion/forum/i4x-Caltech-CS156-course-Fall2016_Week5/threads/580e77c1cc52cb05ab00094c

    #     Eout += crossEntropErr(W[0], tY, tN, tD)
    #     print ('Eout at run {}: {}'.format(run+1, Eout/(run+1)))

    #
    # # average Eout over n runs:

    # Eout /= n
    # return Eout, Epoch[0]
#
# print(SGD(nta, N, n))




# # 1st Grad Desc Algo -- I think I was mixing up SGD w/ BGD
# # ∇Ein = -1/N * ∑((yn*xn)/(1+e^(yn*w(t)T.x))
# for x in np.random.permutation(X):
#     gradE += (np.multiply(x[1], x[0])
#               / (1 + np.e**(np.multiply(x[1],
#                             (np.transpose(W[0]).dot(x[0]))))))
# gradE = np.divide(-N, gradE)


# 1st SGD ALGO -- doesnt quite work:

# def SGD(nta, N, n):
#     Eout, Epoch = 0, [0,0]
#     for run in range(n):
#         print('starting SGD run: {}/{}'.format(run+1,n))
#         # create target fn f & dataset D
#         f = createTargetFn()
#         D = createDataSet(N)
#
#         # generate labels yn
#         Y = generateLabels(D,N,f)
#
#         # package up data points & labels (to keep ordered during epochs)
#         X = []
#         for i in range(N):
#             X.append([D[i]])
#             X[i].append([Y[i]])
#
#         # initialize weight vector; W[0]:w(t), W[1]:w(t-1)
#         W = [[0,0,0],[0,0,0]]
#
#         while vecNormW(W) > nta or Epoch[1] == 0:
#             W[1] = W[0]
#             # compute the gradient -- random permutation through X for each Epoch:
#             gradE = 0
#
#             # x[0] is data point xn; x[1] is label yn
#             for x in np.random.permutation(X):
#                 gradE += np.log(1 + np.e**(np.multiply(-x[1][0], np.transpose(W[0]).dot(x[0]))))/N
#
#                 W[0] = W[1] - np.multiply(nta, gradE)
#
#             Epoch[1] += 1
# #            print(vecNormW(W))
# #            gradE = np.divide(N, -gradE)
#
# #            print('∇Ein = {}'.format(gradE))
# #            print('||w(t-1) - w(t)|| = {}'.format(vecNormW(W)))
#
#             # update weights: w(t+1) = w(t) - η*∇Ein
# #            W[1] = W[0]
# #            W[0] = W[1] - np.multiply(nta, gradE)
#
#         # W[0] now = g -- use to find Eout -- gen new set of points & labels to test
#         tN = 10*N
#         tD = createDataSet(tN)
#         tY = generateLabels(tD, tN, f)
#         Eout += crossEntropErr(W[0], tY, tN, tD)
#         print ('Eout at run {}: {}'.format(run+1, Eout))
#
#         Epoch[0] += Epoch[1]
#         print('Epochs: {}'.format(Epoch[1]))
#         Epoch[1] = 0
#
#     # average Eout over n runs:
#     Epoch[0] /= float(n)
#     Eout /= n
#     return Eout, Epoch[0]


# 2nd version of SGD Algo:
# # SGD Algorithm:
# while vecNormW(W) > nta or Epoch[1] == 0:
#     # update weight vector w(t-1) -> w(t)
#     W[1] = W[0]
#     # x[0]: [xn], x[1]: [yn]
#     for x in np.random.permutation(X):
#         gradE = np.log(1 + np.e**(np.multiply(-x[1][0], np.transpose(W[0]).dot(x[0]))))
#         W[0] = W[1] - np.multiply(nta, gradE)
#
#     Epoch[1] += 1


# Almost working version of SGD. Epochs good; Cross Entrop Eout not working:

# def SGD(nta, N, n):
#     Eout, Epoch = 0, [0,0]
#     for run in range(n):
#         print('starting SGD run: {}/{}'.format(run+1,n))
#         # create target fn f & dataset D
#         f = createTargetFn()
#         D = createDataSet(N)
#         # gen labels yn
#         Y = generateLabels(D,N,f)
#         # package data pts & labels to keep ordered during epochs
#         X = []
#         for i in range(N):
#             X.append([D[i]])
#             X[i].append([Y[i]])
#         # initialize weight vector; W[0]:w(t), W[1]:w(t-1)
#         Wt0 = np.array([0.,0.,0.])
#         Wt1 = np.array([0.,0.,0.])
#         W = [Wt0,Wt1]   # place holder for W
#
#         norm = 1
#         # SGD Algorithm:
#         while norm > nta:
#             # update weight vector w(t-1) -> w(t)
#
#             Wn = np.copy(Wt1)
#             # x[0]: [xn], x[1]: [yn]
#             for x in np.random.permutation(X):
#                 gradE = calcGradE(x[1][0], np.array(x[0]), Wt1 )
#                 Wn += nta * gradE   # looks like I had a sign error
#             Wt0 = np.copy(Wn)
#             # calc norm
#             norm = np.linalg.norm(Wt1 - Wt0)
#             # print('Wt1:{} , Wt0:{}'.format(Wt1,Wt0))
#             Wt1 = np.copy(Wt0)
#
#             Epoch[1] += 1
#
#
#         # gen new test dataset & labels to det Cross Entropy Error:
#         tN = N*10
#         tD = createDataSet(tN)
#         tY = generateLabels(tD, tN, f)
#
#         Eout += crossEntropErr(W[0], tY, tN, tD)
#         print ('Eout at run {}: {}'.format(run+1, Eout/(run+1)))
#         print ('Epochs: {}'.format(Epoch[1]))
#         Epoch[0] += Epoch[1]
#         Epoch[1] = 0
#
#     # average Eout over n runs:
#     Epoch[0] /= n
#     Eout /= n
#     return Eout, Epoch[0]

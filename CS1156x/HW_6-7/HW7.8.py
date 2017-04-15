# Create target function f and dataset D on each run
# Take d = 2, choose rand lin in plane as f: randunifmpts: [-1,1]x[-1,1]
# One side of line: +1, other: -1
# Choose inputs x_n of datset as rand pts in X = [-1,1]x[-1,1]
# Eval f on all x_n to get output y_n. If all datpts on 1 side: discard & redo

# Wayne H Nixalo - 2017-Feb-26 20:27 | 2017-Feb-27 13:03 - 2017-Feb-27 14:45
# Finished: 2017-Feb-28 18:44

import random
from copy import copy
import numpy as np

from time import time

from cvxopt import matrix, solvers
from quadprog import solve_qp

# create target fn f
def targfn():
    f = []
    for i in range(2):
        f.append([random.uniform(-1,1), random.uniform(-1,1)])
    return f

# create input points x_n
def inputSet(N):
    X = []
    for i in range(N):
        X.append([1, random.uniform(-1,1), random.uniform(-1,1)])
    return np.array(X)

# eval f(x_n) = y_n -- discard & redo if all same sign
def labelSet(X, f):
    # x: (x0, y0); f: (x1,y1),(x2,y2); --> sign( (x0-x1)*(y2-y1)-(y0-y1)*(x2-x1) )
    Y = []
    sameside = True
    for i in range(len(X)):
        Y.append(np.sign((X[i][1]-f[0][0])*(f[1][1]-f[0][1])-(X[i][2]-f[0][1])*(f[1][0]-f[0][0])))
        if sameside:
            if Y[0] != Y[i]:
                sameside = False
    if sameside:
        return []
    return np.array(Y)

# generate label f(x) on indiv pt
def labelPt(x, f):
    # labeling function
    return ((x[1]-f[0][0])*(f[1][1]-f[0][1])-(x[2]-f[0][1])*(f[1][0]-f[0][0]))

# out-sample error
def errorTest(g, f, X):
    # N = len(X)
    misclass = 0
    for x in X:
        # if np.sign(np.dot(g, x)) != np.sign(labelPt(x, f)):     # np.dot(g, x) same as np.transpose(g).dot(x)
        if np.sign(np.transpose(g).dot(x)) != np.sign(labelPt(x, f)):
            misclass += 1
    return misclass

# Perceptron Learning Algorithm
def oldPLA(X, Y):
    N = len(X)
    # Use PLA to find g starting w/zeroed weight vec W
    W = [0,0,0]
    # each Iteration running PLA on random misclass'd point
    while 1:
        misclass = []
        # count += 1
        for i in range(N):
            if np.sign((np.transpose(W)).dot(X[i])) != np.sign(Y[i]):
                misclass.append([X[i], Y[i]])
        if not misclass:
            break;
        index = np.random.randint(0, len(misclass))
        W = W + np.multiply(misclass[index][0], misclass[index][1])

    return W

# Support Vector Machine (QP:Dual)
def SVM(X, f, QP = 'cvxopt'):

    RES = 1e-6              # num resolution, altho better to scale maxSV w/ it
    N = len(X)
    y = labelSet(X, f)
    X = np.delete(X, 0, axis=1)

    Qd = np.multiply(np.outer(y, y), np.inner(X, X))
    Ad = np.vstack((y, -y, np.eye(N)))

    if QP == 'cvxopt':
        # from cvxopt import solvers, matrix
        solvers.options['show_progress'] = False

        def cvxoptMat(M):
            return matrix(M, tc='d')

        q = -np.ones(N)
        h = np.zeros(N+2)

        Qd = cvxoptMat(Qd)
        G = -cvxoptMat(Ad)
        q = cvxoptMat(q)
        h = cvxoptMat(h)

        sln = solvers.qp(Qd, q, G, h)
        alpha = sln['x']

    elif QP == 'quadprog':
        # from quadprog import solve_qp

        a = np.ones(N)
        b = np.zeros(N+2)
        C = Ad.T

        # add to diagonal to ensure +semdef matx
        Qd += np.eye(N) * 1e-9

        sln = solve_qp(Qd, a, C, b, meq=1)
        alpha = sln[0]

    # compute weight & bias
    W = np.zeros(len(X[0]))
    for i in range(N):
        if alpha[i] > RES:        # may improve by scaling: np.max(alpha)*RES
            W += alpha[i] * y[i] * X[i].T
    s = np.argmax(alpha)          # using greatest sv (@ypeels & eChap: (8.24))
    b = y[s] - W.dot(X[s])        # np.transpose(W).dot(X[s]) is same as W.dot(X[s])

    g = np.hstack((b, W))

    return alpha, g

# HW7 - returns (ePLA, eSVM, ASVs, SVwin, runtime[ms])
def HW7_PLA_SVM(n, N):
    start = time()
    ePLA, eSVM, ASVs, SVwin = 0., 0., 0., 0.
    for run in range(n):
        X = inputSet(N)
        # ensure targfn splits the dataset
        y = []
        while len(y) == 0:
            f = targfn()
            y = labelSet(X, f)

        # g_pla = PLA(X, f)
        g_pla = oldPLA(X, y)
        SVs, g_svm = SVM(X, f)

        # count support vectors
        for sv in SVs:
            if sv > 1e-6:
                ASVs += 1

        Nt = 100*N
        Xtest = inputSet(Nt)
        eP = errorTest(g_pla, f, Xtest)/float(Nt)
        eS = errorTest(g_svm, f, Xtest)/float(Nt)

        if eS < eP:
            SVwin += 1
        ePLA += eP
        eSVM += eS

    runtime = time() - start
    return ePLA/n, eSVM/n, ASVs/n, SVwin/n, int(runtime*1000)

# Run SVM on the same data as PLA to find final hypothesis g_svm by solving:
#     min{w,b}: 1/2 w.T.w     sjt. yn(w.T.xn + b) >= 1
# using QP on the primal or dual problem. Meas disag btwn f & g_svm as
# P[f(x) != g_svm(x)], and count the #SVs each run.

# 8. For N = 10, repeat experiment for 1000 runs. How often g_svm better g_pla?
# N, n = 10, 1000
N, n = 10, 1000
ePLA, eSVM, ASVs, SVwin, runtime = HW7_PLA_SVM(n, N)
print("Dataset Size: {}, No. Runs: {}\nPLA Error = {}\nSVM Error = {}, Avg No. Support Vectors: {}\nRuntime: {} milliseconds."\
        .format(N, n, ePLA, eSVM, ASVs, runtime))
print("SVM had a better fn approximation than PLA on {}% of the runs.\n".format(round(SVwin*100)))

# 9. For N = 100, repeat expmt for 1000 runs. How often g_svm better g_pla?
N, n = 100, 1000
ePLA, eSVM, ASVs, SVwin, runtime = HW7_PLA_SVM(n, N)
print("Dataset Size: {}, No. Runs: {}\nPLA Error = {}\nSVM Error = {}, Avg No. Support Vectors: {}\nRuntime: {} milliseconds."\
        .format(N, n, ePLA, eSVM, ASVs, runtime))
print("SVM had a better fn approximation than PLA on {}% of the runs.\n".format(round(SVwin*100)))

################################################################################
############# New Terminal Output: ####### test set is 100x training set #######
# Waynes-MBP:HW_6-7 WayNoxchi$ python3 HW7.8.py
# Dataset Size: 10, No. Runs: 1000
# PLA Error = 0.10703000000000017
# SVM Error = 0.08900200000000007, Avg No. Support Vectors: 3.0
# Runtime: 11607 milliseconds.
# SVM had a better fn approximation than PLA on 64% of the runs.
#
# Dataset Size: 100, No. Runs: 1000
# PLA Error = 0.013663699999999992
# SVM Error = 0.011117700000000001, Avg No. Support Vectors: 3.228
# Runtime: 135201 milliseconds.
# SVM had a better fn approximation than PLA on 64% of the runs.
################################################################################

# NOTE: so looks like X and y can just be Python lists and I can still create
#       my Qd matx via NumPy. CVXOPT needs its own matrix formatting of the
#       matxs though, w/ tc='d' for real(double). QuadProg will need a little
#       added to Qd's diagonal to ensure (+)semidefinite.
#       Also: if you use '-' or '.T' on a vector, it must be a NumPy type, and
#             not a simply Python list.


########### Output when test set set to 1000 ###################################
# Waynes-MBP:HW_6-7 WayNoxchi$ python3 HW7.8.py
# Dataset Size: 10, No. Runs: 1000
# PLA Error = 0.10373800000000011
# SVM Error = 0.08791100000000003, Avg No. Support Vectors: 2.984
# Runtime: 11729 milliseconds.
# SVM had a better fn approximation than PLA on 62% of the runs.
#
# Dataset Size: 100, No. Runs: 1000
# PLA Error = 0.013402999999999958
# SVM Error = 0.010758999999999967, Avg No. Support Vectors: 3.217
# Runtime: 57260 milliseconds.
# SVM had a better fn approximation than PLA on 60% of the runs.

################################################################################
# This PLA yielded these results:
# # Perceptron Learning Algorithm
# def PLA(X, f):
#     N = len(X)
#     W = [0,0,0]
#
#     misclass = 1
#     while misclass:
#         misclass = []
#         for x in X:
#             if np.sign(np.transpose(W).dot(x)) != np.sign(labelPt(x, f)):
#                 misclass.append(x)
#         if misclass:
#             x = random.choice(misclass)
#             # W += np.multiply(labelPt(x, f), x)
#             W += labelPt(x,f) * x
#
#     return W

##### TERMINAL OUTPUT:    ##########################  ##########################
# Waynes-MBP:HW_6-7 WayNoxchi$ python3 HW7.8.py
# Dataset Size: 10, No. Runs: 1000
# PLA Error = 0.08248000000000007
# SVM Error = 0.09296000000000007, Avg No. Support Vectors: 2.954
# Runtime: 3296 milliseconds.
# SVM had a better fn approximation than PLA on 43% of the runs.
#
# Dataset Size: 100, No. Runs: 1000
# PLA Error = 0.009901999999999954
# SVM Error = 0.010321999999999954, Avg No. Support Vectors: 3.217
# Runtime: 36740 milliseconds.
# SVM had a better fn approximation than PLA on 46% of the runs.
##########################  ##########################  ########################

	# computing Qd using for loops:
	# Qd = []
	# for m in range(N):
	#    Q.append([])
	#	 for n in range(N):
	#	 	Q.append(np.multiply(y[m]*y[n], np.transpose(X[m]).dot(X[n])))

########################## Version 1.0 below (wrong):###########################
################################################################################
#
# import quadprog
# # import cvxopt
#
# def PLA_SVM(n):
#     # create target fn f
#     def targfn():
#         f = []
#         for i in range(2):
#             f.append([random.uniform(-1,1), random.uniform(-1,1)])
#         return f
#
#     # create input points x_n
#     def inputSet(N):
#         X = []
#         for i in range(N):
#             X.append([1, random.uniform(-1,1), random.uniform(-1,1)])
#         return np.array(X)
#
#     # eval f(x_n) = y_n -- discard & redo if all same sign
#     def labelSet(X):
#         # x: (x0, y0); f: (x1,y1),(x2,y2); --> sign( (x0-x1)*(y2-y1)-(y0-y1)*(x2-x1) )
#         Y = []
#         sameside = True
#         for i in range(len(X)):
#             Y.append(np.sign((X[i][1]-f[0][0])*(f[1][1]-f[0][1])-(X[i][2]-f[0][1])*(f[1][0]-f[0][0])))
#             if sameside:
#                 if Y[0] != Y[i]:
#                     sameside = False
#         if sameside:
#             return None
#         return np.array(Y)
#     def labelPt(x):
#         # labeling function
#         return ((x[1]-f[0][0])*(f[1][1]-f[0][1])-(x[2]-f[0][1])*(f[1][0]-f[0][0]))
#
#     SVMdika = 0
#     SVMs = 0
#
#     for run in range(n):
#         # ensure labels on both sides
#         N = 100
#         Y = None
#         while type(Y) == type(None):
#             f = targfn()
#             X = inputSet(N)
#             Y = labelSet(X)
#
#         # start PLA w 0-vector
#         W = [0,0,0]
#
#         # pick misclass pt for ea. PLA iter at random
#         misclass = 1
#         while misclass:
#             misclass = []
#             for i in range(len(X)):
#                 if np.sign(np.transpose(W).dot(X[i])) != np.sign(Y[i]):
#                     misclass.append(X[i])
#             if not misclass:
#                 break
#             # PLA:
#             x = random.choice(misclass)
#             W += np.multiply(labelPt(x), x)
#
#         # Final PLA hypothesis
#         g_PLA = copy(W)
#
#         # Measure disagreement btwn f & g_PLA -- here using large separate set of points
#         Xtest = inputSet(10*N)
#         miss = 0
#         for i in range(len(Xtest)):
#             if np.sign(np.transpose(g_PLA).dot(Xtest[i])) != np.sign(labelPt(Xtest[i])):
#                 miss += 1
#         disag = float(miss)/(10*N)
#         # print(disag)
#
#         # Run SVM on the same data:
#
#         # quadprog: min(x): 1/2 * x.T.Gx - a.T.x : C.T.x >= b
#         # cvxopt:   min(x): 1/2 * x.T.Px + q.T.x : Gx <= h , Ax == b
#
#         # Remove bias term for X datpts:
#         X1 = np.delete(X, 0, axis=1)
#
#         # Build Graham Matrix:
#         K = np.zeros(shape = (len(X1), len(X1)))
#         for i in range(len(X1)):
#             for j in range(len(X1)):
#                 K[i,j] = np.dot(X1[i], X1[j])
#         K *= np.outer(Y, Y)
#
#         # add a infinitesimal amt to diagonal of G mat to make Positive Definite
#         for i in range(len(K)):
#             K[i][i] += 1e-13
#
#         # I thought this had to be (-1).T, but apparently it's (+1).T
#         q = np.ones(len(X)) * 1
#
#         b = np.zeros(len(X))
#
#         # C constraint matrix for quadprog -- idky, but I'm chopping off the row just below top
#         C = np.vstack([np.transpose(Y), np.eye(len(Y), len(Y))])
#         C = np.delete(C, 1, axis=0)
#         # print(C)
#         # print(K)
#         # print(q)
#         # C = np.matrix(C)
#
#
#         # h for cvxopt
#         # h = np.ones(len(X)) * 1e20
#
#         # quadprog.solve_qo(G, a, C, b, meq, factorized)    -- meq = 1; not 0. idky
#         QPsoln = quadprog.solve_qp(K, q, C, b, meq=1)
#         QP_soln_vector = QPsoln[0]
#         Lagrangian_vector = QPsoln[4]
#
#         # QPsoln = cvxopt.solvers.qp(K, q, h, b)
#
#         # for i in QPsoln:
#         #     print("{}\n".format(i))
#
#         SVs = QPsoln[len(QPsoln) - 2]       # I think that index are the Support Vectors
#         # QPVector = QPsoln[0]
#         # for element in range(len(QPVector)):
#         #     if QPVector[element] < 1e-3:
#         #         QPVector[element] = 0.0
#         #
#         # print(QPVector)
#         # # print(QPsoln)
#
#         W = [0,0,0]
#         for v in range(len(SVs)):
#             if SVs[v] != 0:
#                 W += SVs[v] * Y[v] * X[v]
#                 SVMs += 1
#
#         SVmiss = 0
#         for i in range(len(Xtest)):
#             if np.sign(np.transpose(W).dot(Xtest[i])) != np.sign(labelPt(Xtest[i])):
#                 miss += 1
#         SVdisag = float(miss)/(10*N)
#
#         if SVdisag < disag:
#             SVMdika += 1
#
#         if run == n-1:
#             print("PLA g = {}, Eout = {}".format(g_PLA, disag))
#             print("SVM g = {}, Eout = {}".format(W, SVdisag))
#
#             print("SVM лучшее чем PLA in approximating f: {}".format(float(SVMdika)/n))
#             print("Average number Support Vectors: {}".format(float(SVMs)/n))
#
# PLA_SVM(1000)
#
# ##############################################################################
# OUTPUT:
#
# Waynes-MBP:HW_6-7 WayNoxchi$ python3 HW7.8.py
# PLA g = [ 0.1795502  -0.0311783   3.14983549], Eout = 0.017
# SVM g = [   2.32352634  -82.45186173  215.51324692], Eout = 0.117
# SVM лучшее чем PLA in approximating f: 0.0
# Average number Support Vectors: 41.828
# Waynes-MBP:HW_6-7 WayNoxchi$
#
#
#
#
#
#
# Waynes-MBP:HW_6-7 WayNoxchi$ python3 HW7.8.py
# PLA g = [-0.90690288  1.71624851 -0.40131806], Eout = 0.04
# SVM g = [-1.85978802 -0.19852864  1.84679903], Eout = 0.2
#
# PLA g = [ 0.15720871  0.61207816  0.48479675], Eout = 0.05
# SVM g = [-0.99842692  0.74381976  1.10020376], Eout = 0.64
#
# PLA g = [ 0.95073971 -1.52160963 -1.18922307], Eout = 0.13
# SVM g = [ 1.21838883 -4.59083355 -2.02056012], Eout = 0.19
#
# PLA g = [-0.00074843  0.13367617 -0.05823446], Eout = 0.16
# SVM g = [  2.30664196  14.20331385 -15.59415601], Eout = 0.37
#
# PLA g = [-1.29987197  0.29560115  1.77337268], Eout = 0.18
# SVM g = [ -4.16062107  71.52371103  97.92373744], Eout = 0.44

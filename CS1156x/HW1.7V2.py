# CS1156x - Learning from Data
# Wayne Nixalo -
# HW1.7: Perceptron Learning Algorithm - Version 2

import random
import numpy as np

def PLA(N, n):

    count = 0
    for _ in range(n):
        # Target function F
        F = []
        for i in range(2):
            F.append([random.uniform(-1, 1), random.uniform(-1, 1)])
        # X, Y, & W:
        X, Y, W = [], [], []
        for i in range(N):
            X.append([1, random.uniform(-1, 1), random.uniform(-1, 1)])
            Y.append(np.sign((X[i][1]-F[0][0])*(F[1][1]-F[0][1])-(X[i][2]-F[0][1])*(F[1][0]-F[0][0])))
            W.append([0,0,0])
        # do the PLA thing:
        convergence = 0
        while not convergence:
            count += 1
            i = np.random.randint(0,N)
            if (np.sign((np.transpose(W[i])).dot(X[i])) != np.sign(Y[i])):
                W[i] += np.multiply(Y[i], X[i])
            convergence = True
            for i in range(N):
                if (np.sign((np.transpose(W[i])).dot(X[i])) != np.sign(Y[i])):
                    convergence = False
    return float(count)/n

# CS1156x - Learning from Data
# Wayne Nixalo - 27-Sep-2016 19:49 - 28-Sep-2016 14:49
# HW1.7: Perceptron Learning Algorithm

import numpy as np
import matplotlib.pyplot as plt

# generate a random & uniform [-1,1]x[-1,1] space of N points
# generate a random function f by connecting 2 points of opposite sign

N = 100     #training set size
Iter = []

#Runs:
for k in range(1000):
    if (((k+1) % 50) == 0):
        print repr(int(100*(k+1)/float(1000))) + "% Complete"

    # Random Linear Target Function F:
    F = []
    for i in range(2):
        F.append([1, np.random.uniform(-1.0, 1.0), np.random.uniform(-1.0, 1.0)])
        # F.append(X[np.random.randint(0, N)])

    # Generate X points, x0 = 1:
    X = []
    #np.random.seed(0)
    for i in range(N):
        X.append([1, np.random.uniform(-1.0, 1.0), np.random.uniform(-1.0, 1.0)])

    # W 0 weight vector:
    W = []
    for i in range(N):
        W.append([0,0,0])

    # Training set Y (+/-):
    Y = []
    for i in range(N):
        Y.append(np.sign((F[1][1]-F[0][1])*(X[i][2]-F[0][2]) - (F[1][2]-F[0][2])*(X[i][1]-F[0][1])))

    # PLA Algorithm Iterations:
    for j in range(10000):
        # PLA - choose random point, update Wn if Yn disagree:
        index = np.random.randint(0,N)
        # if (np.sign(np.inner(W[index], X[index])) != (np.sign(Y[index]))):
        #     W[index] += np.multiply(Y[index], X[index])
        if (np.sign((np.transpose(W[index])).dot(X[index])) != (np.sign(Y[index]))):    #alt way
            W[index] += np.multiply(Y[index], X[index])

        convergence = True
        for i in range(N):
            if (np.sign(np.inner(W[i], X[i])) != (np.sign(Y[i]))):
                convergence = False
        if convergence == True:
            # print "Algorithm Converged. Iterations: " + repr(j+1)
            Iter.append(j+1)
            #print repr(j+1)
            break

# Sum & Average results:
Avg = 0
for i in range(len(Iter)):
    Avg += Iter[i]
Avg /= float(len(Iter))
#Avg /= float(N)
print "(N = " + repr(N) + ") Average Iterations to Convergence for " + repr(len(Iter)) + " runs: " + repr(Avg)
# print Iter
# print "Iterations Array Size: " + repr(len(Iter))
#print Avg

# Plot points
#for i in range(len(X)):
#    plt.plot(X[i][1], X[i][2], 'ro')
#for i in range(len(F)):
#    plt.plot(F[i][1], F[i][2], 'bo')
#plt.plot([F[0][1], F[1][1]], [F[0][2], F[1][2]], 'b')
#plt.axis([-1.2, 1.2, -1.2, 1.2])
##plt.axis([-5,5,-5,5])
#plt.show()


#Scrap Below ------------------------------------------------------------------

# some Output:

# ...
# Run 989
# Run 990
# Run 991
# Run 992
# Run 993
# Run 994
# Run 995
# Run 996
# Run 997
# Run 998
# Run 999
# Run 1000
# (N = 100) Average Iterations to Convergence for 998 runs: 502.45991983967934
#
# In [4]: %run ".../CS1156x/HW1.7.py"
# (N = 10) Average Iterations to Convergence for 1000 runs: 24.456


#Learning how to use random & rand.seed():

#np.random.seed(0)
#for i in range(10):
#    print np.random.randint(1,100)
#print"---"

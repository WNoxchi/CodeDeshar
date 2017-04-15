# Code-Along: https://nbviewer.jupyter.org/github/tournami/Learning-From-Data-MOOC/blob/master/Final.html
# to learn some new things  -   2017-Apr-03 14:03

import numpy as np
import matplotlib.pyplot as plt
from svmutil import *
from mlpy import LibSVM

f = lambda x : np.sign(x[1] - x[0] + 0.25*np.sin(np.pi * x[0]))

X = []
for i in range(100):
    X.append([np.random.uniform(-1,1), np.random.uniform(-1,1)])
y = [f(X[i]) for i in range(len(X))]

prob = svm_problem(y, X)
param = svm_parameter('-t 1 -c 10000 -d 2 -g 1 -r 1 -q')
m = svm_train(prob, param)

p_label, p_acc, p_val = svm_predict(y, X, m)

# num_support_vectors = len(m.get_SV())
# print("The number of support vectors is {}".format(num_support_vectors))

# problems 13-18
distance = lambda X, μk: np.linalg.norm(X - μk)
get_new_µk = lambda X: np.mean(X, axis=0)

# need to set this to raise the FloatingpointingError enclised when kmeans
# doesn't return cluster centers
np.seterr(all='raise')

# Create some sample code to implement Lloyd's algorithm and see whether it
# works by plotting the clusters and centers (white triangles).

K = 4
n = 25
N = n*K
σ = 0.1
µks = np.zeros((K,2))
X = np.zeros((N,2))
y = np.zeros((N,1))
for i in range(K):
    µks[i] = np.random.uniform(-1, 1, (1, 2))
    # this assigns sections of X in sets of 25
    X[i*n:(i+1)*(n)] = np.vstack((np.random.normal(loc=µks[i][0], scale=σ, size=n),
                                  np.random.normal(loc=µks[i][1], scale=σ, size=n))).T
    y[i*n:(i+1)*(n)] = i

tol = 1e-8
µk0 = X[np.random.choice(len(X), K, replace=False)]
distances = np.zeros((N,K))
µkt = µk0

try:    # to avoid rare times when kmeans doesn't return cluster centers
    while True:
        for i in range(K):
            distances[:,i] = distance(X, µkt[i])
        µk_id = np.argmin(distances, axis=1)
        µkt_1 = np.full(µkt.shape, np.nan)
        for k in range(K):
            if np.where(µk_id == k)[0].any():
                µk_idx = np.where(µk_id == k)[0]
                µkt_1[k] = get_new_µk(X[µk_idx])
        if np.all(µkt_1 - µkt < tol):
            break
        else:
            µkt = µkt_1
except FloatingPointError:
    pass

# plt.xlim((-2, 2))
# plt.ylim((-2, 2))
# plt.scatter(µkt[:,0], µkt[:,1], marker='^', c='white', s=500)
# plt.scatter(X[:,0], X[:,1], c=y)

# plt.show()

# Now create Lloyd's Algorithm that returns the cluster centers if given the
# data points and K number of clusters.
def kmeans(X, K):
    tol = 1e-8
    µk0 = X[np.random.choice(len(X), K, replace=False)]
    distances = np.zeros((N,K))
    µkt = µk0
    try:    # to avoid when kmeans doesn't return cluster centers
        while True:
            for i in range(K):
                distances[:,i] = distance(X, µkt[i])
            µk_id = np.argmin(distances, axis=1)
            µkt_1 = np.full(µkt.shape, np.nan)
            for k in range(K):
                if np.where(µk_id == k)[0].any():
                    µk_idx = np.where(µk_id == k)[0]
                    µkt_1[k] = get_new_µk(X[µk_idx])

            if np.all(µkt_1 - µkt < tol):
                break
            else:
                µkt = µkt_1
    except FloatingPointError:
        pass
    return µkt

# Create a function that creates a grid of test points to test Eout:
def make_grid(num_points = 100):
    """Creates a grid of points and in the space of [-1, 1] x [-1, 1]
       We will use this to get the area of the negative regions of f(x) & g(x)
       Args:
       num_points: represents the refinement of the grid
                   more points -> more precise area calculation
       returns: N x 2 array representing the space of the graph
    """

    line = np.linspace(-1, 1, num_points)
    grid = np.zeros((num_points, num_points, 2))

    for i in np.arange(num_points):
        for j in np.arange(num_points):
            grid[i,j] = np.array((line[i], line[j]))

    return grid.reshape(-1, 2)

# Some code to look at the true f(x) function
Xcontour = make_grid(50)
ycontour = np.where(Xcontour[:,1] - Xcontour[:, 0] + 0.25 * \
                    np.sin(np.pi * Xcontour[:, 0]) > 0, 1, -1)[:, np.newaxis]

xx, yy = np.meshgrid(np.linspace(-1, 1, len(Xcontour)),
                     np.linspace(-1, 1, len(Xcontour)))

Z = np.where(yy - xx + 0.25 * np.sin(np.pi * xx) > 0, 1, -1)
plt.contour(xx, yy, Z)
plt.title("The $f(x)$ function")

# plt.show()

# create N = 100 sample points from f(x)
N = 100
X = np.random.uniform(-1, 1, (N, 2))
y = np.where(X[:, 1] - X[:, 0] + 0.25 * np.sin(np.pi * X[:, 0]) > \
                                                        0, 1, -1)[:, np.newaxis]
plt.scatter(X[:, 0], X[:, 1], c=y)
# plt.show()

# Now let's implement our kmeans function and view the cluster centers
K = 9
µks = kmeans(X, K)
plt.scatter(µks[:,0], µks[:,1], marker='^', c='white', s=100)
plt.scatter(X[:,0], X[:,1], c=y)
# plt.show()

# Now let's create some sample code to implement our regular RBF Algorithm
# the algo takes X, y, γ, and K, and returns w
# from w we can calc Ein & Eout
N = 100
K = 9
γ = 1.5

X = np.random.uniform(-1, 1, (N, 2))
y = np.where(X[:,1] - X[:,0] + 0.25 * np.sin(np.pi * X[:,0]) > \
                                                        0, 1, -1)[:, np.newaxis]

φ = np.zeros((N, K))
µks = kmeans(X, K)

for j in range(K):
    for i in range(N):
        φ[i,j] = np.exp(-γ * np.linalg.norm(X[i] - µks[j]) ** 2)

w = np.dot(np.dot(np.linalg.inv(np.dot(φ.transpose(), φ)), φ.transpose()), y)

E_in = np.mean(np.where(np.dot(φ, w) > 0, 1, -1) != y)
print(E_in)

# Let's create our test points
Xtest = make_grid()
ytest = np.where(Xtest[:,1] - Xtest[:, 0] + 0.25 * \
                        np.sin(np.pi * Xtest[:,0]) > 0, 1, -1)[:, np.newaxis]
# And create a function for creating out random training points
def get_X_y_train(N=100):
    X = np.random.uniform(-1, 1, (N, 2))
    y = np.where(X[:, 1] - X[:, 0] + 0.25 * np.sin(np.pi * X[:, 0]) > \
                                                        0, 1, -1)[:, np.newaxis]
    return (X, y)

# And implement them them into a helper function that delivers Ein and Eout for
# the regular RBF algorithm
def get_Kmeans_error(Xtrain, ytrain, Xtest=Xtest, ytest=ytest, K=9, γ=1.5):
    Ntrain = len(Xtrain)
    φ_train = np.zeros((Ntrain, K))

    Ntest = len(Xtest)
    φ_test = np.zeros((Ntest, K))

    µks = kmeans(Xtrain, K)

    for j in range(K):
        for i in range(Ntrain):
            φ_train[i, j] = np.exp(-γ * np.linalg.norm(Xtrain[i] - µks[j]) **2)
        for i in range(Ntest):
            φ_test[i, j] = np.exp(-γ * np.linalg.norm(Xtest[i] - µks[j]) ** 2)

    w = np.dot(np.dot(np.linalg.inv(np.dot(φ_train.T, φ_train)), \
                                                            φ_train.T), y_train)
    E_in = np.mean(np.where(np.dot(φ_train, w) > 0, 1, -1) != ytrain)
    E_out = np.mean(np.where(np.dot(φ_test, w) > 0, 1, -1) != ytest)
    return E_in, E_out

# We create another helper function that delivers Ein and Eout for the SVM RBF
def get_SVM_error(Xtrain, ytrain, Xtest=Xtest, ytest=ytest, γ=1.5):
    svm = LibSVM(svm_type='c_svc', kernel_type='rbf', gamma=γ, C=10000)
    svm.learn(Xtrain, ytrain.ravel())
    E_in = np.mean(svm.pred(Xtrain)!=ytrain.ravel())
    E_out = np.mean(svm.pred(Xtest)!=ytest.ravel())

    return E_in, E_out

# Problem 13:
trials = 100
SVM_Eins_greater_than_0 = np.zeros(trials)
for i in range(trials):
    Xtrain, ytrain = get_X_y_train()
    SVM_Eins_greater_than_0[i] = get_SVM_error(Xtrain, ytrain)[0] > 0

print("I get a data set that is not seperable by the RBF kernel using "\
      "hard-margin SVM {}% of the time time".format(\
                                    np.mean(SVM_Eins_greater_than_0 * 100)))

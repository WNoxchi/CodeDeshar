# -*- coding: utf-8 -*-
# A reverse engineering job - see how soln works, what I did wrong, then update
# Wayne H Nixalo - CS1156x Learning from Data - 14-Oct-2016 11:36

#%matplotlib inline      # what does this line do?
import matplotlib.pyplot as plt
import numpy as np
from sklearn.linear_model import LinearRegression   # never seen this before

# Making random f(x) line function:
def make_weights_for_fx(points):
    """Creates the d=2 weight vector for f(x) from the random two points selected.
       Args:
            points: 2 x 2 array representing the two random points
       Returns:
            A 2-items tuple representing intercept & slope.
    """
    Lr = LinearRegression()
    x_vector = points[:, 0].reshape(-1,1)
    y_vector = points[:, 1].reshape(-1,1)
    Lr.fit(x_vector, y_vector)
    w0_f = Lr.intercept_[0]
    w1_f = Lr.coef_[0][0]
    return (w0_f, w1_f)

# Now make a function creating random points & labels
def create_random_points_and_labels(N, weights_fx):
    """Creates N random points in the space of [-1, 1] × [-1, 1] and then lables
       them based on what side of the line they land based on weights_fx.
    Args:
        N: Number of random points
        weights_fx: typle representing (intercept, slope) of f(x)
    Returns:
        A tuple of following items:
            X: an N x D array representing the coordinates of the points
            Y: an N x 1 array representing +1 or -1 depending on which side
               the points land laramca fx
    """
    X = np.random.uniform(-1, 1, (N,2))
    Y = X[:, 1] - X[:, 0] * weights_fx[1] - weights_fx[0] >= 0
    Y = np.where(Y, 1, -1)
    return(X, Y)

# Now for PLA to create g(x):
def make_weights_for_gx(X, Y):
    """Creates the d=2 weight vector for gx based on using PLA.
    Args:
        X: an N x D array representing coordinates of the points
        Y: an N x 1 array representing +1 or -1
    Returns:
        A tuple of the following items:
            w0_g: intercept of g(x)
            w1_g: slope of g(x)
            n: number of iterations needed for convergence
    """
    converged = False
    n = 0
    w_g = np.zeros(3)   # 0 weight vector
                        # for d=2 we need add extra dimension for intercept, ald: (1, x1, x2)
    while not converged:
        converged = True
        for i in range(len(X)):         # for-loop doesnt affect performance of algorithm vs random misclassd point
            if Y[i]*np.dot(w_g, np.hstack((1, X[i]))) <= 0:     # misclassified point
                n += 1
                w_g += Y[i]*np.hstack((1, X[i]))
                converged = False
    w0_g = -w_g[0]/w_g[2]
    w1_g = -w_g[1]/w_g[2]

    return (w0_g, w1_g, n)

# ----------------------------------
# Plotting helper functions:
def plot_points_and_lines(weights_fx, weights_gx, X, Y):
    line = np.linspace(-1, 1, 1001) #points from 0 - 1000
    plt.plot(line, line * weights_fx[1] + weights_fx[0], label="f(x)")   # makes f(x) line
    plt.plot(line, line * weights_gx[1] + weights_gx[0], label="g(x)")   # makes g(x) line
    plt.ylim(-1, 1)
    plt.xlim(-1, 1)
    plt.scatter(X[:, 0][Y==1], X[:, 1][Y==1], marker="o", c=("R"), label="+")
    plt.scatter(X[:, 0][Y==-1], X[:, 1][Y==-1], marker="o", c=("b"), label="-")
    plt.legend(loc="best")

def create_plot(N=10):
    """Creates a new random set of f(x), N points and g(x)"""
    two_random_points_for_line = np.random.uniform(-1, 1, (2, 2))
    w_fx = make_weights_for_fx(two_random_points_for_line)
    X, Y = create_random_points_and_labels(N, w_fx)
    w_gx = make_weights_for_gx(X, Y)
    plot_points_and_lines(w_fx, w_gx, X, Y)
    print("weights for fx - {}".format(w_fx))
    print("weights for gx - {}".format(w_gx))

# ----------------------------------
# Making a grid to get area below line:
def make_grid(num_points = 1001):
    """Creates grid of points in space of [−1, 1] × [−1, 1]
       Will use this to get area of negative regions of f(x) & g(x)
    Args:
        num_points: represents refinement of grid; more points ==> more precise area calculatn
    returns: N x 2 array represntng space of graph
    """
    line = np.linspace(-1, 1, 1001)
    grid = np.zeros((num_points, num_points, 2))
    for i in np.arange(num_points):
        for j in np.arange(num_points):
            grid[i,j] = np.array((line[i], line[j]))
    return grid.reshape(-1, 2)

# Now use grid to calculate area under f(x) & g(x) --- then take difference:
def get_disagreement(weights_fx, weights_gx, grid):
    """Calculates P[f(x) != g(x)] by taking absolute difference of areas of neg region
       (doesnt matter which region taken)
    Args:
        weights_fx: tuple representing (intercept, slope) of f(x)
        weights_gx: ..................................... of g(x)
        grid: N x 2 array representing spac eof graph
    returns: number btwn 0 & 1 representing probability
    """
    total_points = grid.shape[0]
    area_fx = (((grid[:, 1] - grid[:, 0] * weights_fx[1] - weights_fx[0]) <= 0) # sum of points in negative
               .sum() / total_points)                                           # region divided by total points
    area_gx = (((grid[:, 1] - grid[:, 0] * weights_gx[1] - weights_gx[0]) <= 0)
               .sum() / total_points)
    return abs(area_fx - area_gx)

# Createa function combining all previous functions & run them multiple times to get average disagreement:
def experiment(N = 100, trials = 1000):
    """Calculates PLA multiple times & gets avregae of:
            1) number of iterations needed for convergence
            2) Average P[f(x) != g(x)]
        args:
            N: number of data points
            trials: number of trials that are averaged
    """
    iters = np.zeros(trials)
    errors = np.zeros(trials)
    grid = make_grid()
    for trial in range(trials):
        two_random_points_for_line = np.random.uniform(-1, 1, (2, 2))
        w_fx = make_weights_for_fx(two_random_points_for_line)
        X, Y = create_random_points_and_labels(N, w_fx)
        w_gx = make_weights_for_gx(X, Y)
        iters[trial] = w_gx[2]
        errors[trial] = get_disagreement(w_fx, w_gx, grid)
    avg_iters = iters.mean()
    disagreement = errors.mean()

    print("It takes {0} iterations on average for the PLA " \
          "to converge fro N = {1} training points".format(int(avg_iters), N))
    print("P[f(x) != g(x)] is appx {0} for N = {1}".format(round(disagreement, 3), N))

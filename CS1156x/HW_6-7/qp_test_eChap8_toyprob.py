# (CS1156x community TA @ypeels):
# Here is a partial port of my MATLAB code to Python + quadprog, Problem 10
# harness omitted for brevity, and not tested on Problems 8-9. Please see the
# e-Chapter for details.        - book: Learning from Data

import numpy as np
import quadprog
SV_CUTOFF = 1e-6


def test_svm():
    '''toy problems from e-Chapter pp. 11, 28'''
    X = np.array([[0, 0], [2, 2], [2, 0], [3, 0]])
    y = np.array([[-1, -1, 1, 1]]).T
    w1 = svm_primal(X, y);
    [alpha, w2] = svm_dual(X, y);
    print ('primal qp', w1)
    print('dual qp', w2)
    print('dual alpha', alpha)


def svm_primal(X, y):
    '''training examples as rows of X. e-Chapter 8, pp. 9-10'''
    N, d = X.shape

    c = np.ones(N);
    p = np.zeros(d+1);
    Q = np.eye(d+1);
    Q[0, 0] = 0;
    A = np.concatenate([y, (y).dot(np.ones((1, d))) * X], axis=1) # outer prod.

    Q[0, 0] += 1e-256 # force it to be positive definite (cantankerous API)
    results = quadprog.solve_qp(G=Q, a=-p, C=A.T, b=c)
    return results[0]


def svm_dual(X, y):
    '''training examples as rows of X. e-Chapter 8, pp. 28, 30'''
    N, d = X.shape
    Xs = (y).dot(np.ones((1, d))) * X
    Qd = (Xs).dot(Xs.T)
    Ad = np.concatenate([y.T, np.eye(N)])
    pd = np.ones(N);
    cd = np.zeros(N+1);

    Qd += 1e-5 * np.eye(Qd.shape[0]) # force it to be positive definite
    results = quadprog.solve_qp(G=Qd, a=pd, C=Ad.T, b=cd, meq=1)
    alpha = results[0]

    w = np.zeros(d)
    for i in range(N):
        if alpha[i] > SV_CUTOFF * np.max(alpha):
            w += X[i, :].T * y[i] * alpha[i]

    # (8.24) recover bias from weights + largest support vector
    s = np.argmax(alpha)
    b = y[s] - (X[s, :]).dot(w)

    return [alpha, np.array([b[0], w[0], w[1]])]

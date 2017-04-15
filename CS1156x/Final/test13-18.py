# Wayne Hakan Nixalo  -   2017-Apr-06 20:22
import numpy as np
from sklearn.svm import SVC
import matplotlib.pyplot as plt

# target function
f = lambda x : np.sign(x[1] - x[0] + 0.25 * np.sin(np.pi * x[0]))

# Lloyd Algorithm -- Radial Basis Function
def LloydAlgo(X, K):
    N = len(X)
    converge = False

    # init centers µ to random pts in X space
    µ = np.random.uniform(-1,1,(K,2))
    # init clusters S = [center][distance]
    S = np.ones((N,2)) * -1

    # Algorithm Loop:
    while not converge:
        converge = True
        # fix µ, minimize x distances to µ's
        for i in range(N):
            for k in range(K):
                if np.linalg.norm(X[i] - µ[k]) < S[i][1] or S[i][1] == -1:
                    S[i][0] = k
                    S[i][1] = np.linalg.norm(X[i] - µ[k])
                    converge = False
        # fix S, minimize µ's
        for k in range(K):
            # empty cluster check
            if len(np.where(S[:,0]==k)[0]) == 0:
                return [], np.ones((N,2))*-1
            µ[k] = sum(X[np.where(S[:,0]==k)])/len(np.where(S[:,0]==k)[0])

    # return centers & clusters
    return µ, S

def RBF_13_18(N, K, γ, runs=100):
    empty_cluster_runs = 0
    separation_failure = 0
    win = 0
    successful_runs = 0

    Eout_HMSVM, Eout_KMLA = [0.,0.], [0.,0.]
    Ein_KMLA = [0.,0.]
    Ein_KMLA_Zero = 0

    for run in range(runs):
        # gen training data set
        X = np.random.uniform(-1,1, (N,2))
        y = np.zeros(N)
        for i in range(N): y[i] = f(X[i])

        # RBF Kernel Form
        RBF_HMSVM = SVC(np.inf, 'rbf', gamma=γ)
        RBF_HMSVM.fit(X,y)
        y_RBF = RBF_HMSVM.predict(X)

        # check separation
        Ein_HMSVM = 0.
        for i in range(N):
            if y_RBF[i] != y[i]: Ein_HMSVM += 1
        Ein_HMSVM /= N


        # RBF Standard Form (LA Kmeans)
        µ, S = LloydAlgo(X, K)

        # check empty centers
        empty_cluster = False
        for k in range(K):
            if k not in S[:,0]:
                empty_cluster = True
                break
        if empty_cluster: empty_cluster_runs += 1

        if not empty_cluster:
            # construct Φ matx:  Φ_ij = exp{γ*norm(xi - µj)**2}
            Φ = np.zeros((N,K))
            # print(Φ)
            for n in range(N):
                for k in range(K):
                    Φ[n][k] = np.exp(-γ*np.linalg.norm(X[n] - µ[k])**2)

            # add 1's col to compute bias term b = w0
            Φ = np.hstack((np.ones((N, 1)), Φ))
            # print(Φ)

            # weight vector is pinv(Φ)
            W_LA = np.linalg.pinv(Φ).dot(y)
            # print(W_LA)

            # separate bias term
            b = W_LA[0]
            W_LA = W_LA[1:]

            # Ein_KMLA for Q16-18
            Ein_KMLA[1] = 0.
            for n in range(N):
                WkΣ = 0.
                for k in range(K):
                    WkΣ += W_LA[k] * np.exp(-γ*np.linalg.norm(X[n]-µ[k])**2)
                if np.sign(WkΣ) != np.sign(y[n]):
                    Ein_KMLA[1] += 1
            # if Ein_KMLA[1] == 0:
            #     print("BANG!")

        # testing -- discard runs that fail to separate or empty clusters
        Eout_HMSVM[1] = 0.
        Eout_KMLA[1] = 0.
        if Ein_HMSVM == 0 and not empty_cluster:
            successful_runs += 1

            # test data set
            N_test = N*K
            X_test = np.random.uniform(-1,1,(N_test,2))
            y_test = np.zeros((N_test,1))
            for i in range(N_test):
                y_test[i] = f(X_test[i])

            # Eout for Hard-Margin Support Vector Machine RBF
            y_HMSVM = RBF_HMSVM.predict(X_test)
            for i in range(N_test):
                if np.sign(y_HMSVM[i]) != np.sign(y_test[i]):
                    Eout_HMSVM[1] += 1

            # Eout for Kmeans Lloyd Algorithm RBF
            for n in range(N_test):
                WkΣ = 0
                for k in range(K):
                    WkΣ += W_LA[k] * np.exp(-γ*np.linalg.norm(X_test[n]-µ[k])**2)
                if np.sign(WkΣ) != np.sign(y_test[n]):
                    Eout_KMLA[1] += 1
            # print(len(X_test))
            # Eout_KMLA = sum(np.where(W_LA.dot(X) != y, 1, 0)) / (N*K)

        elif Ein_HMSVM > 0: separation_failure += 1

        # data display for RBF Kernel Data Separation
        # if run==(runs-1):
        #     plt.xlim((-1.25,1.25))
        #     plt.ylim((-1.25,1.25))
        #     # plt.scatter(X[:,0], X[:,1], c=np.where(X[y==1], 'b', 'r'))
        #     for n in range(N):
        #         if y[n] == 1:
        #             color = 'b'
        #         else:
        #             color = 'r'
        #         plt.scatter(X[n][0],X[n][1],c=color)
        #
        #     plt.show()

        Eout_HMSVM[0] += Eout_HMSVM[1]
        Eout_KMLA[0]  += Eout_KMLA[1]
        if not empty_cluster:
            Ein_KMLA[0] += Ein_KMLA[1]
            if Ein_KMLA[1] == 0:
                Ein_KMLA_Zero += 1
        win += (Eout_HMSVM[1] < Eout_KMLA[1])

        # print(Eout_HMSVM,Eout_KMLA)

        # data display of results on final run:
        # if run == (runs-1):
            # plt.title('DATA SET')
            # plt.xlim((-1.25,1.25))
            # plt.ylim((-1.25,1.25))
            # for n in range(N_test):
            #     if y_test[n] == 1:
            #         color = 'r'
            #     else:
            #         color = 'b'
            #     plt.scatter(X_test[n][0],X_test[n][1],c=color)
            # # plt.show()
            #
            # plt.title('RBF: HM-SVM')
            # plt.xlim((-1.25,1.25))
            # plt.ylim((-1.25,1.25))
            # for n in range(N_test):
            #     if y_HMSVM[n] != y_test[n]:
            #         color = 'k'
            #     else:
            #         color = 'r'
            #     plt.scatter(X_test[n][0],X_test[n][1],c=color)
            # plt.show()
            #
            # plt.title('RBF: LA-KM')
            # plt.xlim((-1.25,1.25))
            # plt.ylim((-1.25,1.25))
            # for n in range(N):
            #     if S[n][0] == 0:
            #         color = 'k'
            #     if S[n][0] == 1:
            #         color = 'b'
            #     if S[n][0] == 2:
            #         color = 'g'
            #     if S[n][0] == 3:
            #         color = 'r'
            #     elif S[n][0] == 4:
            #         color = 'c'
            #     if S[n][0] == 5:
            #         color = 'm'
            #     if S[n][0] == 6:
            #         color = 'y'
            #     elif S[n][0] > 6:
            #         color = 'w'
            #     plt.scatter(X[n][0],X[n][1],c=color)
            # plt.show()

    return Eout_HMSVM[0]/(successful_runs*N_test), Eout_KMLA[0]/(\
                                            (successful_runs)*N_test), \
            empty_cluster_runs/runs, separation_failure/runs, win/successful_runs,\
            Ein_KMLA[0]/(successful_runs*N), Ein_KMLA_Zero/successful_runs

    # NOTE: HMSVM and KMLA outsample error ratios are averaged over total
    # succesful runs. Incidents of separation failure and empty clusters are
    # averaged over total runs. win is the proportion of succesful runs where
    # Eout HMSVM is less than Eout KMLA.

################################################################################
# 13: For γ = 1.5, how often do you get a data set that isn't separable by the
#     RBF kernel using HMSVM?

# section parameters
runs = 100
N = 100
K = 1
γ = 1

# ans = RBF_13_18(N, K, γ, runs)
# print("Eout|HMSVM: {}\nEout|KMLA: {}\nRatio Runs w/ empty clusters: {}\nRatio Runs w/ Separation Failure: {}\n".format(\
#         ans[0], ans[1], ans[2], ans[3]))

# OUTPUT:
# Eout|HMSVM: 0.029
# Eout|KMLA: 0.5009
# Ratio Runs w/ empty clusters: 0.0
# Ratio Runs w/ Separation Failure: 0.0

# [a]: ≤ 5% of the time

################################################################################
# 14: If we use K = 9 for regular RBF(KMLA) and γ = 1.5, how often does the
#     kernel form (HMSVM) beat the regular form? excluding empty cluster runs,
#     ito Eout?

K, γ = 9, 1.5

# ans = RBF_13_18(N, K, γ, runs)
# print("Eout|HMSVM: {}\nEout|KMLA: {}\nRatio Runs w/ empty clusters: {}\nRatio Runs w/ Separation Failure: {}\nRatio HMSVM beating KMLA: {}".format(\
#         ans[0], ans[1], ans[2], ans[3], ans[4]))

# OUT:
# Eout|HMSVM: 0.03278401997503121
# Eout|KMLA: 0.22350811485642946
# Ratio Runs w/ empty clusters: 0.11
# Ratio Runs w/ Separation Failure: 0.0
# Ratio HMSVM beating KMLA: 0.9662921348314607

# [e] > 75% of the tiem

################################################################################
# 15: What about for K = 12?

K = 12

# ans = RBF_13_18(N, K, γ, runs)
# print("Eout|HMSVM: {}\nEout|KMLA: {}\nRatio Runs w/ empty clusters: {}\nRatio Runs w/ Separation Failure: {}\nRatio HMSVM beating KMLA: {}".format(\
#         ans[0], ans[1], ans[2], ans[3], ans[4]))

# OUT:
# Eout|HMSVM: 0.029956709956709956
# Eout|KMLA: 0.22433982683982684
# Ratio Runs w/ empty clusters: 0.23
# Ratio Runs w/ Separation Failure: 0.0
# Ratio HMSVM beating KMLA: 0.948051948051948

# [e] > 90% of the time

################################################################################
# 16: Now we focus on regular RBF only, with γ = 1.5. If we go from K = 9
#     clusters to K = 12, (only 9 & 12), which of the following 5 cases happens
#     most often in your runs (excluding any empty clusters)?

K = 9
# ans = RBF_13_18(N, K, γ, runs)
# print("Ein|KMLA: {}\nEout|KMLA: {}\nRatio Runs w/ empty clusters: {}\n".format(\
#         ans[5], ans[1], ans[2]))
#
K = 12
# ans = RBF_13_18(N, K, γ, runs)
# print("Ein|KMLA: {}\nEout|KMLA: {}\nRatio Runs w/ empty clusters: {}\n".format(\
#         ans[5], ans[1], ans[2]))

# OUT:
# Ein|KMLA: 0.18922222222222224
# Eout|KMLA: 0.2001851851851852
# Ratio Runs w/ empty clusters: 0.1
#
# Ein|KMLA: 0.232
# Eout|KMLA: 0.24757291666666667
# Ratio Runs w/ empty clusters: 0.2

# [c] Both Ein and Eout go up

################################################################################
# 17: For regular RBF w/ K = 9, if we go from γ = 1.5 to γ = 2 (only 1.5 & 2),
#     which are true (excluding any runs w/ empty clusters)?

K, γ = 9, 1.5
# ans = RBF_13_18(N, K, γ, runs)
# print("Ein|KMLA: {}\nEout|KMLA: {}\nRatio Runs w/ empty clusters: {}\n".format(\
#         ans[5], ans[1], ans[2]))

γ = 2
# ans = RBF_13_18(N, K, γ, runs)
# print("Ein|KMLA: {}\nEout|KMLA: {}\nRatio Runs w/ empty clusters: {}\n".format(\
#         ans[5], ans[1], ans[2]))

# [d] Both Ein and Eout go down

################################################################################
# 18: What is the percentage of time that regular RBF achievs Ein = 0 w/ K = 9,
#     and γ = 1.5 (excluding any runs w/ empty clusters)?

K, γ = 9, 1.5
ans = RBF_13_18(N, K, γ, runs)
print("Percentage of Successful Runs with Ein KMLA = Zero: {}\n".format(ans[6]*100))

# Waynes-MBP:Final WayNoxchi$ python3 test13-18.py
# Percentage of Successful Runs with Ein KMLA = Zero: 0.0
#
# Waynes-MBP:Final WayNoxchi$ python3 test13-18.py
# BANG!
# Percentage of Successful Runs with Ein KMLA = Zero: 1.0309278350515463

# [a] ≤ 10% of the time

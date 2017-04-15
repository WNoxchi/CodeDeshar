# CS1156x - Learning from Data - Final Exam - Radial Basis Functions 13-18
# Wayne H Nixalo - 2017-Apr-03 11:44 ~~ 2017-Apr-07 15:22

################################################################################
# RBF regular form (Lloyd + pinv) w/ K centers:
#     sign(Σ[k=1->K]w_k*exp(-γ||x-μ_k||^2)+b)
# RBF kernel form (RBF kern in HM-SVM):
#     sign(Σ[α_n>0]α_n*y_n*exp(-γ||x-x_n||^2)+b)
# Input Space: X = [-1,1]x[-1,1] w/ unf P distrb
# Target:      f(x) = sign(x2 - x1 + 0.25*sin(π*x1))

# Iea. run, gen 100 training pts at random using target, & apply both RBF forms
# -- repeat expermt as many runs as needed to get stable answ
# -- if datset not separable in Z-space by RBF HMSVM, discard run, but keep
#    track of how often this happens.
# -- when using Lloyd's Algorithm, init centers to randm pts in X & iter until
#    there's no change btwn iters. If cluster bcms empty, discard run & repeat.
################################################################################
# sklearn.svm user guide: http://scikit-learn.org/stable/modules/svm.html
# see: https://courses.edx.org/courses/course-v1:CaltechX+CS_1156x+3T2016/discussion/forum/i4x-Caltech-CS156-course-Fall2016_Week9/threads/5841efb8e8180007f40000f9
# and: (@Robox) https://courses.edx.org/courses/course-v1:CaltechX+CS_1156x+3T2016/discussion/forum/users/1159523
# also: https://github.com/yoshi161mi/caltech_ML/blob/master/svm_poly.ipynb

# Wayne H Nixalo - 2017-Apr-04 17:35 | 2017-Apr-06 20:22 | 2017-Apr-07 15:18

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

ans = RBF_13_18(N, K, γ, runs)
print("Eout|HMSVM: {}\nEout|KMLA: {}\nRatio Runs w/ empty clusters: {}\nRatio Runs w/ Separation Failure: {}\n".format(\
        ans[0], ans[1], ans[2], ans[3]))

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

ans = RBF_13_18(N, K, γ, runs)
print("Eout|HMSVM: {}\nEout|KMLA: {}\nRatio Runs w/ empty clusters: {}\nRatio Runs w/ Separation Failure: {}\nRatio HMSVM beating KMLA: {}".format(\
        ans[0], ans[1], ans[2], ans[3], ans[4]))

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

ans = RBF_13_18(N, K, γ, runs)
print("Eout|HMSVM: {}\nEout|KMLA: {}\nRatio Runs w/ empty clusters: {}\nRatio Runs w/ Separation Failure: {}\nRatio HMSVM beating KMLA: {}".format(\
        ans[0], ans[1], ans[2], ans[3], ans[4]))

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
ans = RBF_13_18(N, K, γ, runs)
print("Ein|KMLA: {}\nEout|KMLA: {}\nRatio Runs w/ empty clusters: {}\n".format(\
        ans[5], ans[1], ans[2]))

K = 12
ans = RBF_13_18(N, K, γ, runs)
print("Ein|KMLA: {}\nEout|KMLA: {}\nRatio Runs w/ empty clusters: {}\n".format(\
        ans[5], ans[1], ans[2]))

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
ans = RBF_13_18(N, K, γ, runs)
print("Ein|KMLA: {}\nEout|KMLA: {}\nRatio Runs w/ empty clusters: {}\n".format(\
        ans[5], ans[1], ans[2]))

γ = 2
ans = RBF_13_18(N, K, γ, runs)
print("Ein|KMLA: {}\nEout|KMLA: {}\nRatio Runs w/ empty clusters: {}\n".format(\
        ans[5], ans[1], ans[2]))

# OUT:
# Ein|KMLA: 0.22680851063829788
# Eout|KMLA: 0.22940898345153665
# Ratio Runs w/ empty clusters: 0.06
#
# Ein|KMLA: 0.16620689655172413
# Eout|KMLA: 0.17476372924648786
# Ratio Runs w/ empty clusters: 0.13

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










################################################################################
# # FIRST ATTEMPT:
#
# import numpy as np
# from sklearn.svm import SVC
# import matplotlib.pyplot as plt
#
# # create 100 test points for Lloyd Algo RBF
#
# # Lloyd Algorithm - clusters & centers
# def LloydAlgo(X, K):
#     """Returns µk & Sk after convergence.
#     """
#     tol = 1e-4                      # tolerance factor to ensure convergence
#     N = len(X)
#
#     # init centers & clusters       cluster: S[[center, distance]]
#     S = -1 * np.ones((N, 2))         # init S as matx of center-indcs & distances
#     µ = np.zeros((K,2))             # µ initd as K-len random vector
#     for i in range(K): µ[i] = np.random.uniform(-1,1,(1,2))
#     # print(µ)
#
#     convergence = False
#
#     # print(µ)
#
#     while(not convergence):
#         convergence = True
#
#         # Fix µk, miz Sk
#         for i in range(N):      #   Sk <-- {xn:||xn-µk|| ≤ all ||xn-µl||}
#             for k in range(K):
#                 if np.linalg.norm(X[i] - µ[k]) < S[i][1] or S[i][1] == -1:
#                     S[i][1] = np.linalg.norm(X[i] - µ[k])
#                     S[i][0] = k
#                     convergence = False
#
#         # Fix Sk, minz µk
#         for k in range(K):      #   µk <-- 1/|Sk| * ∑{x∈Sk}xn
#             new_µ = sum(X[np.where(S[:,0]==k)]) / len(np.where(S[:,0]==k)[0])
#             # print(len(np.where(S[:,0]==k)[0]))
#             if np.linalg.norm(new_µ - µ[k]) > tol:
#                 µ[k] = new_µ
#                 convergence = False
#
#             # NOTE: new_µ is the mean of x's whose X idx corresponds to the
#             #       0 idxs of S that equal k.
#             #       If the difference between µ[k] & new_µ is greater than the
#             #       tolerance setting, µ[k] is set equal to new_µ.
#
#             # NOTE: so far I only know this indexing style: A[:,i] only works on
#             #       NumPy arrays: array([[..],...])
#
#     # print(µ)
#     # Return at local minimum
#     return µ, S
#
# # target function
# f = lambda x: np.sign(x[1] - x[0] + 0.25 * np.sin(np.pi * x[0]))
#
# N = 50
# K = 4       # num centers
# n = N//K
# γ = 1      # ya?
#
# run = 0
#
# # while (condition):  # TODO
#
#
# X = np.random.uniform(-1, 1, (N, 2))
# y = np.zeros((N, 1))
# for i in range(len(y)): y[i] = f(X[i])
#
# # RBF in Lloyd Algorithm:
# µ, S = LloydAlgo(X,K)
#
# # If a cluster becomes empty, discard run and repeat
# for i in range(N):
#     if S[i][1] == -1:
#         # restart = True
#         pass
# for k in range(K):
#     if k not in S[:,0]:
#         # restart = True
#         pass
#
# Φ = []
# for i in range(N):
#     Φ.append([])
#     for k in range(K):
#         Φ[i].append(np.exp(-γ*np.linalg.norm(X[i]-µ[k])**2))
# Φ = np.array(Φ)
#
# # add col of 1s to Φ to get bias b after pinv (b = w0)
# Φ = np.hstack((np.ones((N,1)), Φ))
#
# # w = (Φ.T.Φ)^-1 Φ.T.y
# w_LA = np.linalg.pinv(Φ).dot(y)
#
# # separate bias term from w
# b = w_LA[0]
# w_LA = w_LA[1:]
#
# # RBF in Kernel Form:
# RBFK = SVC(1e9, 'rbf', 2, γ)
#
# # NOTE: "... how often do you get a data set that is not separable by the RBF
# #       kernel (using hard-margin SVM)? Hint: Run the hard-margin SVM, then
# #       check that the solution has Ein = 0."
# #       ^-- so.. Ein != 0 ==> HMSVM failed to seperate data?

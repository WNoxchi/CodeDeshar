# 30-Oct-2016 16:28 ------------------------------------------------------------
# HW 4.1:
# import numpy as np
#
# def compN(ep = 0.05, d = 0.05, N0 = 1, dvc = 10, accuracy = 1):
#     """find closed form soln for N, recursively"""
#
#     N1 = 8 * np.log(8 * (2*N0)**dvc) / ep**2
#
#     if abs(N1 - N0) < accuracy:
#         return N1
#     else:
#         return compN(ep, d, N1, dvc, accuracy)

# 31-Oct-2016 16:42 - 31-Oct-2016 23:45 ----------------------------------------
# HW 4.2

# import numpy as np
# import matplotlib.pyplot as plt
#
# N = np.linspace(start = 1, stop = 5, dtype = "float64")
# dvc = 50
# d = 0.05
#
# LnmH = lambda N, dvc, d, C, a: dvc * np.log(a * N) + np.log(C) - np.log(d)
#
# OgVC = lambda N, dvc, d: np.sqrt((8.0/N) * LnmH(N, dvc, d, 4, 2))
# Rade = lambda N, dvc, d: np.sqrt((2 * LnmH(N, dvc, 1, 2*N, 1))/N) + np.sqrt((2.0/N) * np.log(1/d) + 1.0/N)
# PaVB = lambda N, dvc, d: (1 + np.sqrt(1 + N * LnmH(N, dvc, d, 6, 2)))/N
# Devo = lambda N, dvc, d: (2 + np.sqrt(4 + (2*N-4) * LnmH(N, dvc, d, 4, N))) / (2*N - 4)
#
# eps = [OgVC(N,dvc,d), Rade(N,dvc,d), PaVB(N,dvc,d), Devo(N,dvc,d)]
# epnames = ["Original VC Bound", "Rademacher Penalty Bound", "Parrondo & Van den Broek", "Devroye Bound"]
#
# plt.title("$\epsilon$ vs $N$")
# plt.xlabel("$N$")
# plt.ylabel("$\epsilon$")
#
# for i in range(4):
#     plt.plot(N, eps[i])
#     plt.legend(epnames, loc="best")
#
# plt.show()

# 02-Nov-2016 22:10 ------------------------------------------------------------
# HW 4.4-7
#
# import numpy as np
#
# K,a = 10000, 0
# points = []
# for i in range(K):
#     x1 = np.random.uniform(-1,1)
#     y1 = np.sin(np.pi * x1)
#     x2 = np.random.uniform(-1,1)
#     y2 = np.sin(np.pi * x2)
#     points.append([[x1,y2],[x2,y2]])
# # points: [index][1/2][x/y]
# for i in range(K):
#     x1, x2 = points[i][0][0], points[i][1][0]
#     y1, y2 = points[i][0][1], points[i][1][1]
#     a += (x1 * np.sin(np.pi * x1) + x2 * np.sin(np.pi * x2))/(x1**2 + x2**2)
# a /= K
# print a

# 03-Nov-2016 00:15 ------------------------------------------------------------
HW 4.4-7 Full:
import numpy as np

K = 10000

def calc_a_hat(K):
    a_hat_list = np.zeros(K)

    x1 = np.random.uniform(-1,1, K)
    x2 = np.random.uniform(-1,1, K)
    y1 = np.sin(np.pi*x1)
    y2 = np.sin(np.pi*x2)

    a_hat_list = (x1*y1 + x2*y2)/(x1**2 + x2**2)
    return a_hat_list

a_hat_list = calc_a_hat(K)
a_bar = np.mean(a_hat_list)

print("g_bar(x) = {}x".format(round(a_bar, 2)))

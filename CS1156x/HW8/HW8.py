# CS1156x - Learning from Data -- HW8
# Wayne H Nixalo - 2017-Mar-19 20:03 | 2017-Mar-21 23:34 - 2017-Mar-22 04:35 - 2017-Mar-22 17:46
# Using Sklearn (uses LIBSVM)
# LIBSVM from http://www.csie.ntu.edu.tw/~cjlin/libsvm/
# LIBSVM practical SVM guide: http://www.csie.ntu.edu.tw/~cjlin/papers/guide/guide.pdf

# Heavy-help; see: https://nbviewer.jupyter.org/github/yoshi161mi/caltech_ML/blob/master/week8_python3.ipynb
# See CS1156x HW8 Discussion: https://courses.edx.org/courses/course-v1:CaltechX+CS_1156x+3T2016/discussion/forum/i4x-Caltech-CS156-course-Fall2016_Week8/threads/58336dfd7febe5054c000a54

# Bit of a mess. But so be it.

import numpy as np
from sklearn.svm import SVC

# one vs all
def λ_vs_shadeg(labels, λ):
    λlabels = np.copy(labels)
    λlabels[labels == λ] = 1
    λlabels[labels != λ] = -1
    return λlabels

# one vs one
def λ_vs_ξ(features, labels, λ, ξ):
    λids = np.where(labels == λ)
    ξids = np.where(labels == ξ)
    λlabels = 1 * np.ones(len(λids[0]))
    ξlabels = -1 * np.ones(len(ξids[0]))
    return np.vstack((features[λids], features[ξids])), np.hstack((λlabels, ξlabels))


URL_train = "http://www.amlbook.com/data/zip/features.train"
URL_test = "http://www.amlbook.com/data/zip/features.test"

# URL_train = "features.train"
# URL_test = "features.test"

D = np.genfromtxt(URL_train, dtype=np.float)            # if not specd, will guess dtype
labels_train = D[:,0]
features_train = D[:,1:]

D = np.genfromtxt(URL_test, dtype=np.float)
labels_test = D[:,0]
features_test = D[:,1:]

################################################################################
##### POLYNOMIAL KERNELS -- polynom kernel K(xn, xm) = (1 + xn.T.xm)^Q
##### 8.2: With C = 0.01 and Q = 2, which classifier has highest Ein?

print("\nHW 8.2")

coef0 = 1.0                     # NOTE: K(xn,xm) = (1 + xn.T.xm)^Q; the '1'
γ = 1.0                         # scaling factor, gamma, within kernel function
C = 0.01                        # penalty factor
Q = 2                           # degree of polynomial kernel
kernel = 'poly'

maxClass = [None,0]

classifier = SVC(C, kernel, Q, γ, coef0)
# classifier = SVC(C=0.01, kernel="poly", degree=2, gamma=1.0, coef0=1.0)
for n in range(0,9,2):
    nlabels = λ_vs_shadeg(labels_train, n)
    classifier.fit(features_train, nlabels)
    result = (n, 1.0 - classifier.score(features_train, nlabels))
    print("{} {}".format(result[0],result[1]))
    if result[1] > maxClass[1]:
        maxClass = np.copy(result)

print("Max Ein: {} for classifier: {} versus all".format(maxClass[1], maxClass[0]))

################################################################################
##### 8.3: With C = 0.01 and Q = 2, which classifier has lowest Ein?

print("\nHW 8.3")

minClass = [None, 1.]

C = 0.01
Q = 2
for n in range(1,10,2):
    nlabels = λ_vs_shadeg(labels_train, n)
    classifier.fit(features_train, nlabels)

    result = (n, 1.0 - classifier.score(features_train, nlabels))
    print("{} {}".format(result[0],result[1]))

    if result[1] < minClass[1]:
        minClass = np.copy(result)

print("Min Ein: {} for classifier: {} versus all".format(minClass[0], minClass[1]))

################################################################################
##### 8.4: Comparing the two selected classifiers from 8.2 & 8.3, which value
##### is closest to different between the number of support vectors in the two?
print("\nHW 8.4")

hiLabels = λ_vs_shadeg(labels_train, maxClass[0])
loLabels = λ_vs_shadeg(labels_train, minClass[0])
classifier.fit(features_train, hiLabels)
# print(sum(classifier.n_support_))       # equivalent: # print(len(classifier.support_))
loSVs = sum(classifier.n_support_)
classifier.fit(features_train, loLabels)
hiSVs = sum(classifier.n_support_)

print("Low-Ein Classifier ({}): {} Support Vectors".format(minClass[0], loSVs))
print("Hi-Ein Classifier ({}):  {} Support Vectors".format(maxClass[0], hiSVs))
print("Difference: {}".format(abs(hiSVs - loSVs)))

################################################################################
##### 8.5: Consider the 1 versus 5 classifier w/ Q = 2, and C ∈ {0.001, 0.01, 0.1, 1}
##### Which statement is correct?
print("\nHW 8.5")

# Look for: # SVs laramca C; Eout laramca C; max C achieves lowest Ein?
# --> print: num SVs, Eout, Ein, C

λ, ξ = 1, 5
Q, C = 2, [0.001, 0.01, 0.1, 1]

features, labels = λ_vs_ξ(features_train, labels_train, 1, 5)
features_out, labels_out = λ_vs_ξ(features_test, labels_test, 1, 5)

print("C | Support Vectors | Ein | Eout")
for c in C:
    classifier = SVC(c, kernel, Q, γ, coef0)
    classifier.fit(features, labels)
    SVs = sum(classifier.n_support_)
    Ein = 1. - classifier.score(features, labels)
    Eout = 1. - classifier.score(features_out, labels_out)
    print("{} | {} | {} | {}".format(c, SVs, Ein, Eout))

################################################################################
##### 8.6: In the 1 vs 5 classifier, comparing Q = 2 w/ Q = 5,
##### Which statement is correct?
# [A] C = 0.0001, Ein is higher at Q = 5
# [B] C = 0.001, num of SVs is lower at Q = 5
# [C] C = 0.01, Ein is higher at Q = 5
# [D] C = 1, Eout is lower at Q = 5
print("\nHW 8.6")

Q, C = [2, 5], [0.0001, 0.001, 0.01, 1]

from texttable import Texttable   # https://pypi.python.org/pypi/texttable/0.8.7
table = Texttable()
table.set_precision(16)
table.add_rows([['C','Q','SVs','Ein','Eout']])

# print("C | Q | SVs | Ein | Eout")
for q in Q:
    for c in C:
        classifier = SVC(c, kernel, q, γ, coef0)
        classifier.fit(features, labels)
        SVs = sum(classifier.n_support_)
        Ein = 1. - classifier.score(features, labels)
        Eout = 1. - classifier.score(features_out, labels_out)
        # print("{} | {} | {} | {} | {}".format(c, q, SVs, Ein, Eout))
        table.add_row([c, q, SVs, Ein, Eout])

print(table.draw())

################################################################################
##### CROSS VALIDATION -- 10-fold cv for poly-kernel. Ecv is randvar that deps
##### on random partition of data ==> 100 runs w/ dfnt partitions. Base answer
##### on how many runs lead to particular choice.
##### 8.7: 1 vs 5 clsfr w/ Q = 2. Use Ecv to select C ∈ {0.0001, 0.001, 0.01, 0.1, 1}
##### If tie in Ecv: select smaller C. W/n 100 randm runs, which statmt correct?
################################################################################
##### 8.8: Again consider the 1 v 5 clsfr w/ Q = 2. For winning selection the
##### avg val of Ecv over 100 runs is closest to what?

# NOTE: there are multiple similar ways to do this. See link at top.

print("\n HW 8.7, HW 8.8")
from sklearn.model_selection import KFold

λ, ξ = 1, 5
Q, C = 2, [0.0001, 0.001, 0.01, 0.1, 1]
runs = 100
folds = 10
selections = {}

Ecv = {}

features, labels = λ_vs_ξ(features_train, labels_train, λ, ξ)
for r in range(runs):
    E = []
    KF = KFold(folds, shuffle=True)         # I may want to seed the rng
    for c in C:
        clsfr = SVC(c, kernel, Q, γ, coef0)
        e = 0
        for train_set, valid_set in KF.split(features):
            clsfr.fit(features[train_set], labels[train_set])
            e += np.sum(clsfr.predict(features[valid_set]) != labels[valid_set]) # <-- think youd need to divide by num features for Ecv avg in Q8.8
            # e += 1. - clsfr.score(features[valid_set], labels[valid_set]) # <-- oof this totally doesn't work.
        E.append(e)
        # keeping track of Ecv for Q8.8
        Ecv[c] = Ecv.get(c, 0) + e

    # select index of smallest Ecv
    select = np.argmin(E)

    # check for ties:
    ties = -1
    for i in range(len(E)):
        if E[i] == E[select]:
            ties += 1
    if ties > 0:
        # descend and select the lowest (last) tied index
        for i in range(len(E)):
            if E[len(E)-1-i] == E[select]:
                select = len(E)-1-i

    # NOTE: I am very very dumb. I'm getting 1...4 in my dict of selections bc
    # 0-index is never winning... it's never being entered into the dict...
    # SO.. I was getting the right answer the whole time.. ok, um.. cool then..

    selections[select] = selections.get(select, 0) + 1

for c in C: Ecv[c] /= (runs * len(features))

print("C : times selected\n{}".format(selections))
print("C : Ecv\n{}".format(Ecv))

################################################################################
##### RBF Kernel
##### 8.9 & 8.10: Consider the RBF Kernel K(xn, xm) = exp(-||xn-xm||^2) in the
##### SM SVM approach. Focus on 1v5 clsfr. Which C results in lowest Ein; Eout?

# λ, ξ, Q all same as before.
print("\n HW 8.9, HW 10")
C = [0.01, 1, 100, 1e4, 1e6]
Ein, Eout = [], []

for c in C:
    clsfr = SVC(C=c, kernel="rbf", gamma=γ)
    clsfr.fit(features, labels)
    Ein.append(1. - clsfr.score(features, labels))
    Eout.append(1. - clsfr.score(features_out, labels_out))

print("C:    {}\nEin:  {}\nEout: {}".format(C, Ein, Eout))

minEin = np.argmin(Ein)
minEout = np.argmin(Eout)

print("Lowest Ein: {} at C = {}".format(Ein[minEin], C[minEin]))
print("Lowest Eout: {} at C = {}".format(Eout[minEout], C[minEout]))

################################################################################
##### OUTPUT
#
# Waynes-MacBook-Pro:HW8 WayNoxchi$ python3 HW8.py
#
# HW 8.2
# 0 0.10588396653408316
# 2 0.10026059525442321
# 4 0.08942531888629812
# 6 0.09107118365107669
# 8 0.074338225209162
# Max Ein: 0.10588396653408316 for classifier: 0.0 versus all
#
# HW 8.3
# 1 0.014401316691811772
# 3 0.09024825126868741
# 5 0.07625840076807022
# 7 0.08846523110684401
# 9 0.08832807570977919
# Min Ein: 1.0 for classifier: 0.014401316691811772 versus all
#
# HW 8.4
# Low-Ein Classifier (1.0): 2179 Support Vectors
# Hi-Ein Classifier (0.0):  386 Support Vectors
# Difference: 1793
#
# HW 8.5
# C | Support Vectors | Ein | Eout
# 0.001 | 76 | 0.004484304932735439 | 0.01650943396226412
# 0.01 | 34 | 0.004484304932735439 | 0.018867924528301883
# 0.1 | 24 | 0.004484304932735439 | 0.018867924528301883
# 1 | 24 | 0.0032030749519538215 | 0.018867924528301883
#
# HW 8.6
# +--------------------+---+-----+--------------------+--------------------+
# |         C          | Q | SVs |        Ein         |        Eout        |
# +====================+===+=====+====================+====================+
# | 0.0001000000000000 | 2 | 236 | 0.0089686098654709 | 0.0165094339622641 |
# +--------------------+---+-----+--------------------+--------------------+
# | 0.0010000000000000 | 2 | 76  | 0.0044843049327354 | 0.0165094339622641 |
# +--------------------+---+-----+--------------------+--------------------+
# | 0.0100000000000000 | 2 | 34  | 0.0044843049327354 | 0.0188679245283019 |
# +--------------------+---+-----+--------------------+--------------------+
# | 1                  | 2 | 24  | 0.0032030749519538 | 0.0188679245283019 |
# +--------------------+---+-----+--------------------+--------------------+
# | 0.0001000000000000 | 5 | 26  | 0.0044843049327354 | 0.0188679245283019 |
# +--------------------+---+-----+--------------------+--------------------+
# | 0.0010000000000000 | 5 | 25  | 0.0044843049327354 | 0.0212264150943396 |
# +--------------------+---+-----+--------------------+--------------------+
# | 0.0100000000000000 | 5 | 23  | 0.0038436899423446 | 0.0212264150943396 |
# +--------------------+---+-----+--------------------+--------------------+
# | 1                  | 5 | 21  | 0.0032030749519538 | 0.0212264150943396 |
# +--------------------+---+-----+--------------------+--------------------+
#
#  HW 8.7, HW 8.8
# C : times selected
# {1: 47, 2: 31, 3: 12, 4: 10}
# C : Ecv
# {0.1: 0.0047277386290839208, 0.0001: 0.0097885970531710435, 0.01: 0.0046764894298526585, 0.001: 0.0047982062780269055, 1: 0.0047789878283151822}
#
#  HW 8.9, HW 10
# C:    [0.01, 1, 100, 10000.0, 1000000.0]
# Ein:  [0.0038436899423446302, 0.004484304932735439, 0.0032030749519538215, 0.0025624599615631238, 0.00064061499039080871]
# Eout: [0.023584905660377409, 0.021226415094339646, 0.018867924528301883, 0.023584905660377409, 0.023584905660377409]
# Lowest Ein: 0.0006406149903908087 at C = 1000000.0
# Lowest Eout: 0.018867924528301883 at C = 100
# Waynes-MacBook-Pro:HW8 WayNoxchi$


################################################################################
# NOTE: np.genfromtxt('url or path', dtype=?) will output a NumPy
# type array. Google for more info. You can quickly get parts of it by specing:
# D = np.genfromtxt('url'); X = D[:, :2], y = D[:, 2:]
# translation: D is an array of arrays (float). X is all arrays of D, and
# within: first 2 subarrays. Y is all arrays of D, and all subarrays after
# index 2.
# I think you can specfy a url, path, or if in same dir: a path.
# NOTE: this methd of copying is BY REFERENCE. Changes to D will affect X & y,
# and vice-versa!

# NOTE: one_vs_all only modifies labels, so you can just search for labels &
# change them. one_vs_one removes a portion of the dataset, so you need a
# slightly different approach: numpy.where(condition) returns all positions
# where the condition is True. To construct the new label vector, get the
# length of the vector by finding the length of the zero-index of the result of
# np.where() ~ the number of positions that evald to True. The vstack portion
# is self-explanatory; I haven't tested if a vstack for the 1d label vector
# would work;
# NOTE: you could do this all conventionally; I tried picking up black-magicary.


################################################################################
# NOTE: 8.7: ffs I'm trying to reinvent the wheel over here.
# sklearn.cross_validation already has a library called 'KFold'. Not sure how I
# should feel having it so easy, but I'll use it. I'll sleep now & pick up tmrw.
# 2017-Mar-22 04:33 AM
#
# K = len(features_train)//10
# Ecv = [0] * len(C)
# runs = 100
#
# ghost = []
# for i in range(len(features_train)):
#     ghost.append(np.hstack((labels_train[i], features_train[i])))
#
# train_set = []
# temp_set = []
# val_set = []
#
# for run in range(runs):
#
#     for k in range(K):
#         # take 1/10 out of ghost & into val_set. copy ghost to train_set
#         val_set.append(ghost.pop(np.random.choice(ghost, replace=False)))
#         train_set = copy(ghost)
#
#         # also copy temp_set into train_set
#         if len(temp_set) > 0:
#             for elem in temp_set: train_set.append(elem)
#
#         # do the thing
#         features, labels = λ_vs_ξ(train_set[:,1:], train_set[:,0], λ, ξ)
#         for c in range(len(C)):
#             clsfr = SVC(C[c], kernel, Q, γ, coef0)
#             clsfr.fit(features, labels)
#             Ecv[c] += clsfr.score(val_set[:,1:], val_set[:,0])
#
#         # copy val_set into temp_set. erase val_set
#         for elem in val_set: temp_set.append(elem)      # maybe I should use np.concatenate to keep in np format..
#         val_set = []
#
#     # play w/ pointers to avoid O(runs * N) cpu time:
#     for elem in temp_set: train_set.append(elem)
#     ghost = train_set
#     train_set, temp_set = [], []
#
# # average out cv errors
# for e in range(len(Ecv)):
#     Ecv[e] /= (K * runs)
#
# table = Texttable()
# table.precision = 10
# table.add_rows([['Q', 'C', 'Ecv']])
# for e in range(len(Ecv)):
#     table.add_row([Q, C[e], Ecv[e]])


################################################################################
# DUMP: my older standard way of doing business:
#
# # returns D
# def loadDat(filename):
#     """
#     :param filename:
#     :return returnArray, an array of arrays of floats:
#     """
#     file = open(filename, 'r')
#     filestring = file.readline()
#     returnArray = []
#     while filestring != '':
#         line = []
#         for s in filestring.split(' '):
#             if s != '':
#                 line.append(float(s))
#         returnArray.append(line)
#         filestring = file.readline()
#     file.close()
#     return returnArray
# # returns X, y
# def extractDat(D):
#     X, y = [], []
#     for i in range(len(D)):
#         X.append([[D[i][0], D[i][1]]])
#         y.append(D[i][2])
#     return np.array(X), np.array(y)
#
# D_train = loadDat('features.train')
# # D_test = loadDat('features.test')
#
# X, y = extractDat(D)
#
# Qd = np.multiply(np.outer(y, y), np.inner(X, X))

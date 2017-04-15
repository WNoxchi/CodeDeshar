# CS1156x - Learning from Data - Final Exam
# Wayne H Noxchi  -   2017-Apr-02 13:50 - 2017-Apr-02 21:24

# Regularized Linear Regression - questions 7-10

# Data format: digit | intensity | symmetry
# BinClsfr: 1v1, 1vA; use BinClsfrError for eval Ein & Eout

# Implement Regularized Least-Squares Linear Regression for Classification
# minz: (1/N) Σ[n=1 -> N] (w.T.z_n - y_n)^2 + (λ/N)*w.T.w

# a couple pointers from: (Robox): https://nbviewer.jupyter.org/github/tournami/Learning-From-Data-MOOC/blob/master/Final.html

import numpy as np

# one vs all binary classifier
def cxa_v_shadeg(labels, a):
    a_labels = np.copy(labels)
    a_labels[labels == a] = 1
    a_labels[labels != a] = -1
    return a_labels

# one vs one binary classifier
def cxa_v_cxa(features, labels, a, b):
    a_ids = np.where(labels == a)
    b_ids = np.where(labels == b)
    a_labels = np.ones(len(a_ids[0]))
    b_labels = np.ones(len(b_ids[0])) * -1
    return np.vstack((features[a_ids], features[b_ids])), \
            np.hstack((a_labels, b_labels))

# feature transform
def feature_trsf(X, mode=0):
    Z = []
    if not mode:
        for i in range(len(X)):
            Z.append([1, X[i][0], X[i][1]])
    else:
        for i in range(len(X)):
            Z.append([1, X[i][0], X[i][1], X[i][0]*X[i][1],
                        X[i][0]**2, X[i][1]**2])
    return np.array(Z)

# URL_train = "http://www.amlbook.com/data/zip/features.train"
# URL_test = "http://www.amlbook.com/data/zip/features.test"

# D_train = np.genfromtxt(URL_train)
# D_test = np.genfromtxt(URL_train)

URI_train = "features.train"
URI_test = "features.test"

D_train = np.genfromtxt(URI_train)
D_test = np.genfromtxt(URI_test)

# performs Regularized Linear Regression; 1vsAll or 1vs1
def FE_RLR(λ_reg, range_min, range_max, D_test, D_train, inc=1, trsf=0, shadeg=True):

    λ = λ_reg
    Error = [[],[]]

    # isolate feature & label sets
    features_train = D_train[:,1:]
    features_test = D_test[:,1:]
    labels_train = D_train[:,0]
    labels_test = D_test[:,0]

    if shadeg:
        # renaming for consistency; get Z
        X_train = features_train
        X_test = features_test
        Z_train = feature_trsf(X_train, trsf)
        Z_test = feature_trsf(X_test, trsf)

    # loop through choices, i
    for i in range(range_min, range_max+1, inc):
        # data formatting
        if not shadeg:
            a, b = range_min, range_max
            X_train, y_train = cxa_v_cxa(features_train, labels_train, a, b)
            X_test, y_test = cxa_v_cxa(features_test, labels_test, a, b)
            Z_train = feature_trsf(X_train, trsf)
            Z_test = feature_trsf(X_test, trsf)
        else:
            y_train = cxa_v_shadeg(labels_train, i)

        # math
        ZtZ = np.dot(Z_train.T, Z_train)
        λI = λ * np.eye(len(ZtZ))
        Wreg = np.dot(np.linalg.inv(ZtZ + λI), np.dot(Z_train.T, y_train))

        # display formatting
        if shadeg:
            terah = i
        else:
            terah = chr(a+ord('0')) + " v " + chr(b+ord('0'))

        # hypothesis error logging
        E = 0
        for n in range(len(Z_train)):
            if np.sign(np.dot(Wreg.T, Z_train[n])) != np.sign(y_train[n]):
                E += 1
        Error[0].append([terah, E/len(Z_train)])
        E = 0
        for n in range(len(Z_test)):
            if np.sign(np.dot(Wreg.T, Z_test[n])) != np.sign(y_train[n]):
                E += 1
        Error[1].append([terah, E/len(Z_test)])

        # only run once on a-v-b
        if not shadeg:
            break

    return Error

################################################################################
# 7: Set λ = 1, do not apply a feature transform. Which classifier has the
#    lowest Ein?

Error = FE_RLR(1, 5, 9, D_test, D_train)

from texttable import Texttable
table = Texttable()
table.set_precision(17)
table.add_rows([['λ', 'Terah-vs-Shadeg', 'Ein', 'Eout']])
for i in range(len(Error[0])):
    table.add_row([1, Error[0][i][0], Error[0][i][1], Error[1][i][1]])

print(table.draw())

# [d] 8-vs-All: Ein: 0.0743382..

################################################################################
# 8: Apply feature transform z = (1, x1, x2, x1x2, x1^2, x2^2) and set λ = 1
#    Which clsfr has lowest Eout?

Error = FE_RLR(1, 0, 4, D_test, D_train, trsf=1)

table = Texttable()
table.set_precision(17)
table.add_rows([['λ', 'Terah-vs-Shadeg', 'Ein', 'Eout']])
for i in range(len(Error[0])):
    table.add_row([1, Error[0][i][0], Error[0][i][1], Error[1][i][1]])

print(table.draw())

# [e] 4-vs-All: Eout: 0.0712506..

################################################################################
# 9: If we compare using the transform versus not using it, and apply that to
#    ‘0 versus all’ through ‘9 versus all’, which of the following statements
#    is correct for λ = 1?

Error = FE_RLR(1, 0, 9, D_test, D_train, trsf=0)
ErrorT = FE_RLR(1, 0, 9, D_test, D_train, trsf=1)

table = Texttable()
table.set_precision(12)
table.add_rows([['λ', 'Ter.', 'Ein[nT]','Ein[T]', 'Eout[nT]', 'Eout[T]']])
for i in range(len(Error[0])):
    table.add_row([1, Error[0][i][0], Error[0][i][1], ErrorT[0][i][1], \
                    Error[1][i][1], ErrorT[1][i][1]])

print(table.draw())


################################################################################
# 10. Train the ‘1 versus 5’ classifier with z = (1,x1,x2,x1x2,x1^2,x2^2) with
#     λ = 0.01 and λ = 1. Which of the following statements is correct?

Error = FE_RLR(0.01, 1, 5, D_test, D_train, trsf=1, shadeg=False)
ErrorT = FE_RLR(1, 1, 5, D_test, D_train, trsf=1, shadeg=False)

table = Texttable()
table.set_precision(17)
table.add_rows([['λ', 'Ter.', 'Ein', 'Eout']])
for i in range(len(Error[0])):
    table.add_row([0.01, Error[0][i][0], Error[0][i][1], Error[1][i][1]])
    table.add_row([1, ErrorT[0][i][0], ErrorT[0][i][1], ErrorT[1][i][1]])

print(table.draw())

# [a] Overfitting occurs (from λ = 1 to λ = 0.01)

################################################################################
# OUTPUT:
################################################################################
#
# Waynes-MBP:Final WayNoxchi$ python3 FEx_RLR_4-7.py
# 7:
# +---+-----------------+---------------------+---------------------+
# | λ | Terah-vs-Shadeg |         Ein         |        Eout         |
# +===+=================+=====================+=====================+
# | 1 | 5               | 0.07625840076807022 | 0.05132037867463876 |
# +---+-----------------+---------------------+---------------------+
# | 1 | 6               | 0.09107118365107666 | 0.08271051320378675 |
# +---+-----------------+---------------------+---------------------+
# | 1 | 7               | 0.08846523110684405 | 0.09068261086198307 |
# +---+-----------------+---------------------+---------------------+
# | 1 | 8               | 0.07433822520916199 | 0.07872446437468859 |
# +---+-----------------+---------------------+---------------------+
# | 1 | 9               | 0.08832807570977919 | 0.08420528151469855 |
# +---+-----------------+---------------------+---------------------+
# 8:
# +---+-----------------+---------------------+---------------------+
# | λ | Terah-vs-Shadeg |         Ein         |        Eout         |
# +===+=================+=====================+=====================+
# | 1 | 0               | 0.10231792621039638 | 0.26208271051320381 |
# +---+-----------------+---------------------+---------------------+
# | 1 | 1               | 0.01234398573583871 | 0.24165421026407574 |
# +---+-----------------+---------------------+---------------------+
# | 1 | 2               | 0.10026059525442327 | 0.11011459890383657 |
# +---+-----------------+---------------------+---------------------+
# | 1 | 3               | 0.09024825126868742 | 0.07424015944195317 |
# +---+-----------------+---------------------+---------------------+
# | 1 | 4               | 0.08942531888629818 | 0.07125062282012955 |
# +---+-----------------+---------------------+---------------------+
# 9:
# +---+------+----------------+----------------+----------------+----------------+
# | λ | Ter. |    Ein[nT]     |     Ein[T]     |    Eout[nT]    |    Eout[T]     |
# +===+======+================+================+================+================+
# | 1 | 0    | 0.109312851461 | 0.102317926210 | 0.257598405580 | 0.262082710513 |
# +---+------+----------------+----------------+----------------+----------------+
# | 1 | 1    | 0.015224249074 | 0.012343985736 | 0.237169905331 | 0.241654210264 |
# +---+------+----------------+----------------+----------------+----------------+
# | 1 | 2    | 0.100260595254 | 0.100260595254 | 0.110114598904 | 0.110114598904 |
# +---+------+----------------+----------------+----------------+----------------+
# | 1 | 3    | 0.090248251269 | 0.090248251269 | 0.074240159442 | 0.074240159442 |
# +---+------+----------------+----------------+----------------+----------------+
# | 1 | 4    | 0.089425318886 | 0.089425318886 | 0.071250622820 | 0.071250622820 |
# +---+------+----------------+----------------+----------------+----------------+
# | 1 | 5    | 0.076258400768 | 0.076258400768 | 0.051320378675 | 0.051818634778 |
# +---+------+----------------+----------------+----------------+----------------+
# | 1 | 6    | 0.091071183651 | 0.091071183651 | 0.082710513204 | 0.082710513204 |
# +---+------+----------------+----------------+----------------+----------------+
# | 1 | 7    | 0.088465231107 | 0.088465231107 | 0.090682610862 | 0.090682610862 |
# +---+------+----------------+----------------+----------------+----------------+
# | 1 | 8    | 0.074338225209 | 0.074338225209 | 0.078724464375 | 0.078724464375 |
# +---+------+----------------+----------------+----------------+----------------+
# | 1 | 9    | 0.088328075710 | 0.088328075710 | 0.084205281515 | 0.084205281515 |
# +---+------+----------------+----------------+----------------+----------------+
# 10:
# +---------------------+-------+---------------------+---------------------+
# |          λ          | Ter.  |         Ein         |        Eout         |
# +=====================+=======+=====================+=====================+
# | 0.01000000000000000 | 1 v 5 | 0.00448430493273543 | 0.40566037735849059 |
# +---------------------+-------+---------------------+---------------------+
# | 1                   | 1 v 5 | 0.00512491992312620 | 0.40330188679245282 |
# +---------------------+-------+---------------------+---------------------+

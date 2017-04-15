import numpy as np

training_data = np.genfromtxt('features.train', dtype=np.float)
test_data = np.genfromtxt('features.test', dtype=np.float)

train_features = training_data[:,1:3]
train_labels = training_data[:,0]
test_features = test_data[:,1:3]
test_labels = test_data[:,0]

def n_vs_all(labels, n):
    nlabels = np.copy(labels)
    nlabels[labels == n] = 1
    nlabels[labels != n] = -1
    return nlabels

def filter_m_vs_n(features, labels, m, n):
    mids = np.where(labels == m)
    nids = np.where(labels == n)
    mlabels = 1*np.ones(len(mids[0]))
    nlabels = -1*np.ones(len(nids[0]))
    return np.vstack((features[mids], features[nids])), np.hstack((mlabels, nlabels))

from sklearn import svm

def question2():
    clf = svm.SVC(C=0.01, kernel="poly", degree=2, gamma=1.0, coef0=1.0)
    for i in range(0,9,2):
        labels = n_vs_all(train_labels, i)
        clf.fit(train_features, labels)
        print(i, 1.0 - clf.score(train_features, labels))

question2()

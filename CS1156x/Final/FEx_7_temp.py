import numpy as np

trainURL = "http://www.amlbook.com/data/zip/features.train"
testURL  = "http://www.amlbook.com/data/zip/features.test"

D_train = np.genfromtxt(trainURL)
D_test  = np.genfromtxt(testURL)

def cxa_vs_shadeg(labels, λ):
    λlabels = np.copy(labels)
    λlabels[labels == λ] = 1
    λlabels[labels != λ] = -1
    return λlabels

def cxa_vs_cxa(features, labels, λ, ξ):
    λids = np.where(labels == λ)
    ξids = np.where(labels == ξ)
    λlabels = 1 * np.ones(len(λids[0]))
    ξlabels = -1 * np.ones(len(ξids[0]))
    return np.vstack((features[λids], features[ξids])), np.hstack((λlabels, ξlabels))

# takes labels y, features X, where Data[i] = [y[i], X[i][0], X[i][1]]
def feature_trsf(y, X):
    Z = []
    for i in range(len(X)):
        Z.append([y[i], X[i][0], X[i][1]])
    return np.array(Z)


features_train = D_train[:,1:]
features_test = D_test[:,1:]
labels_train = D_train[:,0]
labels_test = D_test[:,0]

λ = 1

Error = {"in":[], "out":[]}
for i in range(5, 10):
    y_train = cxa_vs_shadeg(labels_train, i)
    Z_train = feature_trsf(y_train, features_train)

    ZtZ = np.transpose(Z_train).dot(Z_train)
    λI = np.multiply(λ, np.eye(len(ZtZ)))
    Zty = np.transpose(Z_train).dot(y_train)
    Wreg = np.dot(np.linalg.inv(np.add(ZtZ, λI)), Zty)

    Wreg = np.dot(np.linalg.inv(np.dot(Z_train.T, Z_train) + λI),
                  (np.dot(Z_train.T, y_train)))

   # wreg = np.dot(
   #                np.dot(np.linalg.inv(np.dot(Ztrain.T, Ztrain) + λI),
   #                       Ztrain.T), ytrain)

    Ein = 0.
    for n in range(len(Z_train)):
        # print(Z_train[n])
        g = np.transpose(Wreg).dot(Z_train[n])
        print(g, y_train[n])
        if np.sign(g) != np.sign(y_train[n]):
            Ein += 1
    Ein /= len(Z_train)

    Eout = 0.
    t_labels = cxa_vs_shadeg(labels_test, i)
    t_features = feature_trsf(t_labels, features_test)
    for n in range(len(t_features)):
        g = np.transpose(Wreg).dot(t_features[n])
        if np.sign(g) != np.sign(t_labels[n]):
            Eout += 1
    Eout /= len(t_features)

    Error["in"].append([i, Ein])
    Error["out"].append([i, Eout])


    Error["in"].append([i, Ein])

print(Error)

    # t_labels = cxa_vs_shadeg(labels_test, i]

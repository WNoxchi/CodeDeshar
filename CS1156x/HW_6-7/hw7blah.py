from sklearn.linear_model import LinearRegression
import numpy as np

from sklearn.svm import SVC
from sklearn.linear_model import Perceptron

def create_fx():
    lin = LinearRegression()
    points = np.random.uniform(-1, 1, (2, 2))

    X = np.array([points[:, 0]]).T
    Y = np.array([points[:, 1]]).T

    lin.fit(X,Y)

    #from y = mx + c
    w0 = lin.intercept_[0] # c = y-intercept
    w1 = lin.coef_[0][0] # m = slope

    return (w0,w1)

def create_random_points_label(N,w0,w1):
    #from y1-mx1-c = 0 then the point is on the line
    #if y1-mx1-c >= 0 then the point is above the line -> label = 1
    #if y1-mx1-c < 0 then the point is below the line -> label = -1

    points = np.random.uniform(-1,1,(N,2))
    X1 = np.array([points[:, 0]]).T
    X2 = np.array([points[:, 1]]).T #x2 is y in the 2d space

    Y = ( X2 - w1*X1 - w0 >= 0 )
    Y = np.where(Y,1,-1)

    return (points,Y)
def error(Y_predict,Y_true):
    error = (Y_predict != Y_true).astype(int)
    return np.mean(error)

def run_test(times,N):
    count_sv = []
    Ein_pct = []
    Eout_pct = []
    Ein_svm = []
    Eout_svm = []

    for i in range(0,times):
        #generate test and train data
        w0,w1 = create_fx()
        while(True):
            X,Y = create_random_points_label(N,w0,w1) # train set of N points
            X_test,Y_test = create_random_points_label(N*5,w0,w1) #test set
            if -1 in Y and 1 in Y and -1 in Y_test and 1 in Y_test :
                break

        #SVM
        model = SVC(C=np.inf,kernel='linear')
        #model = SVC(C=np.inf,kernel='rbf')
        #model = SVC(C=np.inf,kernel='poly')
        #model = SVC(C=np.inf,kernel='sigmoid')
        #model = SVC(C=np.inf,kernel=lambda X,Y : np.dot(X, Y.T))
        model.fit(X,Y)
        Y_predict = np.array([model.predict(X)]).T
        Y_test_predict =  np.array([model.predict(X_test)]).T
        num_sv = np.size(model.support_)

        #store the test output
        count_sv.append(num_sv)
        Ein_svm.append(error(Y_predict,Y))
        Eout_svm.append(error(Y_test_predict,Y_test))

        #print("Ein =",error(Y_predict,Y))
        #print("Eout =",error(Y_test_predict,Y_test))

        #Perceptron
        model = Perceptron()
        model.fit(X,Y)
        Y_predict = np.array([model.predict(X)]).T
        Y_test_predict =  np.array([model.predict(X_test)]).T

        #store the test output
        Ein_pct.append(np.round(error(Y_predict,Y),2))
        Eout_pct.append(np.round(error(Y_test_predict,Y_test),2))

    print("avg number of support vectors =",np.mean(count_sv))

    Eout_pct = np.array(Eout_pct)
    Eout_svm = np.array(Eout_svm)

    print("N =",N,"SVM better than Perceptron for",np.mean((Eout_svm < Eout_pct).astype(int)))
    return Ein_pct,Eout_pct,Ein_svm,Eout_svm

Ein_pct,Eout_pct,Ein_svm,Eout_svm = run_test(1000,10) #1000 experiment, N = 100

Ein_pct,Eout_pct,Ein_svm,Eout_svm = run_test(1000,100) #1000 experiment, N = 100
#Ein_pct,Eout_pct,Ein_svm,Eout_svm = run_test(1000,1000) #1000 experiment, N = 1000

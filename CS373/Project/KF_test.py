# WNx - 2017-Jul-09 11:57
# trying to get a Kalman Filter working

# pulling strongly from: https://github.com/LujunWeng/runaway-robot/blob/master/common/predictor.py
# (see Kalman Filter)

from matrix import *
class KF:
    def __init__(self, sigma):
        self.x = matrix([[0.],  # hdg
                         [0.],  # trn
                         [0.]]) # dst
        self.P = matrix([[1000., 0., 0.],
                         [0., 1000., 0.],
                         [0., 0., 1000.]])
        # measurement uncertainty
        self.R = matrix([[sigma, 0.],
                        [0., sigma]])
        # next state function
        self.F = matrix([[1., 1., 0.],
                         [0., 1., 0.],
                         [0., 0., 1.]])
        # measurement function
        self.H = matrix([[1., 0., 0.],
                         [0., 0., 1.]])
        # identity matrix
        self.I = matrix([[1., 0., 0.],
                         [0., 1., 0.],
                         [0., 0., 1.]])
        self.keep = []
        self.u = matrix([[0.], [0.], [0.]])  # external motion

def predict_position():
    KFt = KF(1.)
    # KFt.z = matrix([[1.],[1.],[1.]])
    KFt.y = matrix([[1.],[1.]]) - KFt.H*KFt.x
    KFt.S = KFt.H*KFt.P*KFt.H.transpose() + KFt.R
    KFt.K = KFt.P*KFt.H.transpose()*KFt.S.inverse()
    KFt.x = KFt.x + KFt.K*KFt.y
    KFt.P = (KFt.I - KFt.K*KFt.H)*KFt.P

    KFt.x = KFt.F*KFt.x + KFt.u
    KFt.P = KFt.F*KFt.P*KFt.F.transpose()

    return KFt.x, KFt.P

pred = predict_position()
print(pred)

# OUTPUT:
# ([[0.9990009990009988], [0.0], [0.9990009990009988]],
#  [[1000.9990009990012, 1000.0, 0.0], [1000.0, 1000.0, 0.0], [0.0, 0.0, 0.9990009990011872]])

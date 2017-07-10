# Wayne H Nixalo - 2017-Jul-10 00:15
# thanks to LujunWeng https://github.com/LujunWeng/runaway-robot/blob/master/Part%202%20-%20Location%20with%20noise/studentMain.py
# taking apart his code was an impmortant part of learning how an EKF works.

from matrix import *
class EKF:
    def __init__(self, sigma):
        # State Matrix Estimate
        self.x = matrix([[0.],  # x
                         [0.],  # y
                         [0.],  # hdg
                         [0.],  # trn
                         [0.]]) # dst
        # Covariance Matrix Estimate
        self.P = matrix([[1e3, 0., 0., 0., 0.],
                         [ 0.,1e3, 0., 0., 0.],
                         [ 0., 0.,1e3, 0., 0.],
                         [ 0., 0., 0.,1e3, 0.],
                         [ 0., 0., 0., 0.,1e3]])
        # Measurement Uncertainty / Observation Covariance
        self.R = matrix([[sigma, 0.],
                         [0., sigma]])
        # Process Covariance (helps stop P->0)
        self.Q = matrix([[1e-2,  0.,  0.,  0.,  0.],
                         [  0.,1e-2,  0.,  0.,  0.],
                         [  0.,  0.,1e-2,  0.,  0.],
                         [  0.,  0.,  0.,1e-2,  0.],
                         [  0.,  0.,  0.,  0.,1e-2]])
        # Observation Matrix | Measurement Function
        self.H = matrix([[1., 0., 0., 0., 0.],
                         [0., 1., 0., 0., 0.]])
        # State Transition Matrix
        self.F = EKF.transitionMatrix(self.x)
        # Identity Matrix
        self.I = matrix([[]])
        self.I.identity(self.x.dimx)
        # External Motion
        self.u = matrix([[0.],[0.],[0.],[0.],[0.]])

    def predict(self, measurement):
        # state input
        z = matrix([[measurement[0]],
                    [measurement[1]]])
        # Measurement Update:
        y = z - self.H * self.x # Measurement Residual
        S = self.H * self.P * self.H.transpose() + self.R   # Residual Covariance
        K = self.P * self.H.transpose() * S.inverse() # (near-optimal) Kalman Gain
        self.x = self.x + K * y                 # updated State Estimate
        self.P = (self.I - K * self.H) * self.P # updated Covariance Estimate
        # Prediction Update:
        self.F = EKF.transitionMatrix(self.x)   # updated State Transition Matrix # QUESTION: after or before x?
        self.x = EKF.transitionFn(self.x)       # Predicted State Estimate
        self.P = self.F * self.P * self.F.transpose() + self.Q   # Predicted Covariance Estimate

        return [self.x.value[0][0], self.x.value[1][0]] # xy_estimate

    @staticmethod
    def transitionMatrix(state):
        h = state.value[2][0]; t = state.value[3][0]; d = state.value[4][0]
        return matrix([[1., 0., -d*sin(h+t),-d*sin(h+t), cos(h+t)],
                       [0., 1.,  d*cos(h+t), d*cos(h+t), sin(h+t)],
                       [0., 0.,          1.,         1.,       0.],
                       [0., 0.,          0.,         1.,       0.],
                       [0., 0.,          0.,         0.,       1.]])

    @staticmethod
    def transitionFn(state):
        x = state.value[0][0]; y = state.value[1][0]
        h = state.value[2][0]; t = state.value[3][0]; d = state.value[4][0]

        x = x + d * cos(h + t)
        y = y + d * sin(h + t)
        h = h + t

        return matrix([[x],[y],[h],[t],[d]])


# # the way a kalman filter works:
# # Measurement Update
# z = measurement
# y = z - H*x
# S = H*P*H.transpose() + R
# K = P*H.transpose*S.inverse()
# x = x + K*y
# P = (I-K*H)*P
# # Prediction Update
# x = F*x + u
# P = F*P*F.transpose()

# WH Nixalo - 2017-Jul-10 02:30
# Udacity CS373 - AI for Robotics
#
# I recently got an Extended Kalman Filter working to pass all 3 unit-tests for
# part 2 of the final project (Runaway Robot: Adding Noise). This is a little
# script to find a good value for the Q process-covariance matrix.

from studentMain_P2_Adding_Noise import *
# from KF import *

def est_pos_special(measurement, OTHER = None, qval=0.01):
    if not OTHER:
        OTHER = [EKF(1.)]
        ### Q is set here ###
        OTHER[0].Q = matrix([[qval * (r == c) for r in range(
                            OTHER[0].Q.dimx)] for c in range(OTHER[0].Q.dimy)])
    EKFilter = OTHER[0]
    xy_estimate = EKFilter.predict(measurement)
    return xy_estimate, OTHER

test_target = robot(2.1, 4.3, 0.5, 2*pi / 34.0, 1.5)
measurement_noise = 0.05 * test_target.distance
test_target.set_noise(0.0, 0.0, measurement_noise)

# demo_grading(est_pos_special, test_target, qval=0.001)
# demo_grading(estimate_next_pos, test_target, visualz=False)

def iterAvg(count, qval=0.01):
    wins = 1
    for i in range(9):
        cvrg, temp = demo_grading(est_pos_special, test_target, visualz=False, qval=qval)
        if cvrg:
            count += temp
            wins += 1
    return count / wins

def find_good_Q(runs=1):
    avg_best = 0.; avg_q = 0.
    for run in range(runs):
        resl = 0.001 # resolution
        fact = 10   # starting change factor
        best = 1000 # upperbound convergence
        qval = 1.   # value for Q's diagonal
        qold = 1.    # prevs q value
        print("--- Run: {} ---".format(run))
        # average the best of ten
        while abs(1 - fact) > resl:
            try:
                cvrg, count = demo_grading(est_pos_special, test_target, visualz=False, qval=qval)
                if cvrg and count < best:
                    count = iterAvg(count)
                    best = count
                    if qval > qold:
                        qold = qval
                        qval *= fact
                    else:
                        qold = qval
                        qval /= fact
                if not cvrg or count >= best:
                    if qval > qold:
                        qold = qval
                        qval /= fact
                    else:
                        qold = qval
                        qval *= fact
                    fact /= 2
            except ValueError:
                qval /= fact
            # NOTE: so I learned if q in Q is too large, you'll get a ValueError
            #       during Cholesky Factorization as part of inverting S. Adding too
            #       much to the diagonal of P causes S to be non-positive-definite.
            #       S = H*P*H.T+R
        avg_best += best; avg_q += qval

    avg_best /= runs; qval /= runs
    print("Best q value found: {}; yielding average convergence of {} steps.".format(
                                                                        qval, best))

find_good_Q(runs=100)

# Ran it twice, and looks like the best is q = 0.0035 ± 0.0015
# for 32 ≤ avg steps ≤ 51

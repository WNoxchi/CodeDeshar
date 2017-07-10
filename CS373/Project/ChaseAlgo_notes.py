################################################
# 2017-Jul-10 17:43
# CHASE ALGORITHM V1    ########################
#
# HUNTING LOOP:
#
# REPEAT UNTIL CAUGHT:
#     PREDICT WHERE RUNAWAY IS NOW
#
#     FOR (TARGET_DST / HUNTER_SPD):
#
#         PREDICT WHERE RUNAWAY WILL BE NEXT TIMESTEP
#
#     MOVE THERE
################################################












################################################
# 2017-Jul-10 16:45 / 2017-Jul-10 17:33
# CHASE ALGORITHM V0    ########################
#
# HUNTING LOOP:
#
# REPEAT UNTIL CAUGHT:
#     PREDICT WHERE RUNAWAY IS NOW
#         (EKF.predict)
#     PREDICT WHERE RUNAWAY WILL BE NEXT TIMESTEP
#         (EKF.predict)
#     MOVE THERE
#         -> dst = min(max_dst, targ_dst)
################################################

# This function will be called after each time the target moves.
def next_move(hunter_position, hunter_heading, target_measurement,
                                                    max_distance, OTHER = None):

    # initialize EKF as usual
    if not OTHER:
        OTHER = [EKF(1.)]
        # near-optimal q-value (found earlier in find_good_Q.py)
        OTHER[0].Q = matrix([[0.0035*(r==c) for r in range(OTHER[0].Q.dimx)] \
                                        for c in range(OTHER[0].Q.dimy)])
    EKFtr = OTHER[0]
    # predict Runaway's current position
    targ_est = EKFtr.predict(target_measurement)
    # predict Runaway's next position:  ### QUESTION: does this mess up the EKF?
    targ_est = EKFtr.predict(targ_est)

    # get disance & bearing to target next-position estimate
    targ_dst = distance_between(hunter_position, targ_est)
    distance = min(max_distance, targ_dst)

    bearing  = get_heading(hunter_position, targ_est)
    turning  = bearing - hunter_heading

    # The OTHER variable is a place for you to store any historical information about
    # the progress of the hunt (or maybe some localization information). Your return format
    # must be as follows in order to be graded properly.
    return turning, distance, OTHER

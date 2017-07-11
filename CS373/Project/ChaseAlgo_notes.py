################################################
# 2017-Jul-10 17:43 - 2017-Jul-10 20:07
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

def next_move(hunter_position, hunter_heading, target_measurement, max_distance, OTHER = None):
    # This function will be called after each time the target moves.

    # initialize the EKF as usual
    if not OTHER:
        OTHER = [EKF(1.)]
        # near-optimal q-value (found earlier in find_good_Q.py)
        OTHER[0].Q = matrix([[0.0035*(r==c) for r in range(OTHER[0].Q.dimx)] \
                                        for c in range(OTHER[0].Q.dimy)])
    EKFtr = OTHER[0]
    # predict Runaway's current position
    targ_est = EKFtr.predict(target_measurement)
    # predict Runaway's next position:
    targ_est = EKFtr.predict(targ_est)

    # Heuristic Loop
    steps_to_targ = distance_between(hunter_position, targ_est) / max_distance
    if steps_to_targ >= 1.:    # trial & error: 1.
        x = EKFtr.x.value[0][0]; y = EKFtr.x.value[1][0]
        h = EKFtr.x.value[2][0]; t = EKFtr.x.value[3][0]; d = EKFtr.x.value[4][0]
        for step in range(max(int(steps_to_targ), 1) + 1):  # trial&err: max() + 1
            x = x + d * cos(h + t)
            y = y + d * sin(h + t)
            h = h + t
        targ_est = [x, y]

    # get disance & bearing to target next-position estimate
    targ_dst = distance_between(hunter_position, targ_est)
    distance = min(max_distance, targ_dst)

    bearing  = get_heading(hunter_position, targ_est)
    turning  = angle_trunc(bearing - hunter_heading) # keep this within +- pi

    # The OTHER variable is a place for you to store any historical information about
    # the progress of the hunt (or maybe some localization information). Your return format
    # must be as follows in order to be graded properly.
    return turning, distance, OTHER

# former attempt at Heuristic loop:
    # if steps_to_targ >= 1:
    #     for step in range(max(int(steps_to_targ),1)):
    #         targ_est = EKFtr.predict(targ_est)
    # # Heuristic Loop:
    # for tstep in range():
    #     # predict Runaway's next position:
    #     targ_est = EKFtr.predict(targ_est)

# NOTE: I think a reason why using the EKF exclusively to predict positions
#       multiple steps into the future didn't work is noise. And this kind of
#       makes sense. There's a lot of matrix algebra making for very fine
#       calculations.. This is computationally expensive, but also I don't know
#       of any internal mechanism to surpress noise from positive feedback..
#     > On the otherhand, a very simple algorithm employed when more than one
#       step away from the target, does the job of closing the distance rapidly.
#       Then when in 'striking range' the EKF takes over and provides a high-
#       fidelity position estimate. Furthermore, the EKF builds state
#       information for the +0 and +1 time steps, handing that off to the
#       simple 'Long-Range' Algorithm.
#     > This feels right on 2 levels: first, in real life you use rough
#       estimates when far from your goal, whether you're running towards a
#       soccer ball or flying a plane to an airport. But once you're close,
#       "within striking range", you sort of 'switch' algorithms in your head,
#       and start making very fine adjustments while being hyper-aware of your
#       & your target's states. Secondly it feels right to build systems that
#       automatically switch between different algorithms as appropriate.

# NOTE: further notes: I actually got lucky before. The function had a hard
#       converging at all. What I added was a cut-off of separation 0.4, above
#       which, the function would use the Long-Range (LR) Algo, and below, EKF.
#       However THIS also wasn't good enough and provided slight improvement.
#       I increased the LR-udpate loop to be length max(steps_to_targ, 1) + 1
#       instead of just max(steps_to_targ,1). With this I was still getting
#       convergence on only ~ 3/5 of my runs. I took another look at the
#       graphical display and saw my Hunter was always about half a step ahead
#       of the Target. Algo-switch gearing was either 1.5 or 0.5, I think 0.5.
#       Average separation looked to be around 0.66.
#     > Changing the gear par to 1.0 and keeping loop max(..,1) + 1, I got
#       consistent convergence. Average separation in the close-in portion of
#       the chase seemd to be around 0.33 to 0.16.


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

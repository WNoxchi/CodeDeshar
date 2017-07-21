# 2017-Jul-10 21:57

# Dynamic Version of observation/averaging algorithm:

    # store the mean (center) and deviation (radius), along with point count
    if len(OTHER) < 2:
        OTHER.append([[0.,0.],[0.],[0.]])
    point = [target_measurement[0], target_measurement[1]]
    # update count
    OTHER[1][2][0] += 1
    # update mean
    OTHER[1][0][0] = (OTHER[1][0][0]*(OTHER[1][2][0]-1) + point[0])/OTHER[1][2][0]
    OTHER[1][0][1] = (OTHER[1][0][1]*(OTHER[1][2][0]-1) + point[1])/OTHER[1][2][0]
    # update avg deviation
    OTHER[1][1][0] = (OTHER[1][1][0]*(OTHER[1][2][0]-1) +
                            distance_between(OTHER[1][0], point)) / OTHER[1][2][0]
    # center is mean
    center = OTHER[1][0]
    # radius is avg devn
    radius = OTHER[1][1][0]
    # target estimate is point's intersection w/ circumference
    theta = atan2(point[1]-center[1], point[0]-center[0])
    x     = radius * cos(theta) + center[0]
    y     = radius * sin(theta) + center[1]
    targ_est = [x,y]



# Static-Test version of observation/averaging algorithm:
    # WAIT = 400
    #
    # # Cache the first 200 points:
    # if len(OTHER) < 2:
    #     OTHER.append([target_measurement])
    # else:
    #     OTHER[1].append(target_measurement)
    #
    # if len(OTHER[1]) < WAIT:
    #     return hunter_heading, 0, OTHER
    #
    # # if len(OTHER[1]) == WAIT:
    # # use the mean to find rough center of circle
    # x_mean = sum(OTHER[1][:][0]) / float(len(OTHER[1]))
    # y_mean = sum(OTHER[1][:][1]) / float(len(OTHER[1]))
    # center = [x_mean, y_mean]
    #
    # # use the variance to find the radius
    # radius = 0.
    # for i in range(len(OTHER[1])-1):
    #     radius += distance_between(OTHER[1][i], OTHER[1][i+1])
    # radius /= len(OTHER[1])
    #
    # # use trigonometry to find where the point maps onto the circle
    # point = [target_measurement[0], target_measurement[1]]
    # theta = atan2(point[1]-center[1],point[0]-center[0])
    # x = radius * cos(theta) + center[0]
    # y = radius * sin(theta) + center[1]
    # targ_est = [x,y]

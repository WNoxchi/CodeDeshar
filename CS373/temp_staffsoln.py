    dim = 2 * (num_landmarks + 1) # *2 bc 2D

    omega = matrix()
    omega.zero(dim, dim)
    ksi = matrix()
    ksi.zero(dim, 1)

    omega.value[0][0] = 1.
    omega.value[1][1] = 1.

    ksi.value[0][0] = world_size / 2.
    ksi.value[1][0] = world_size / 2.

    # process the data
    for k in range(len(data)):
        measurement = data[k][0]
        motion = data[k][1]

        # integrate the measurements
        for i in range(len(measurement)):
            # m is the index of the landmark coordinate in the matrix/vector
            m = 2 * (1 + measurement[i][0])

            # update the information matrix/vector based on the measurement
            for b in range(2):
                omega.value[b][b] += 1. / measurement_noise
                omega.value[m+b][m+b] += 1. / measurement_noise
                omega.value[b][m+b] += -1. / measurement_noise
                omega.value[m+b][b] += -1. / measurement_noise
                ksi.value[b][0] += -measurement[i][1+b] / measurement_noise
                ksi.value[m+b][0] += measurement[i][1+b] / measurement_noise

        # expand the information matrix and vector by one new position
        list = [0,1] + range(4, dim+2)
        omega = omega.expand(dim+2, dim+2, list, list)
        ksi = ksi.expand(dim+2, 1, list, [0])

        # update the information matrix/vector based on the robot motion
        for b in range(4):
            omega.value[b][b] += 1. / motion_noise
        for b in range(2):
            omega.value[b][b+2] += -1 / motion_noise
            omega.value[b+2][b] += -1./ motion_noise
            ksi.value[b][0] += -motion[b] / motion_noise
            ksi.value[b+2][0] += motion[b]/ motion_noise

        # now factor out the previous pose
        newlist = range(2, len(omega.value))
        a = omega.take([0,1], newlist)
        b = omega.take([0,1])
        c = ksi.take([0,1],[0])
        omega = omega.take(newlist) - a.transpose() * b.inverse() * a
        ksi = ksi.take(newlist, [0]) - a.transpose() * b.inverse() * c

    # compute best estimate
    Omega = omega
    mu = omega.inverse() * ksi

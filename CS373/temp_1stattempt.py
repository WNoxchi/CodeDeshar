dim = 2 * (num_landmarks + 1) # *2 bc 2D

omega = matrix()
omega.zero(dim, dim)
ksi = matrix()
ksi.zero(dim, 1)

omega.value[0][0] = 1.
omega.value[1][1] = 1.

ksi.value[0][0] = world_size / 2.
ksi.value[1][0] = world_size / 2.

for k in range(len(data)):

    # n: index of robot pose:
    n = 0

    motion = data[k][1]
    measurement = data[k][0]

    # let's see if doing it this way works:
    for i in range(len(measurement)):
        # m: index of landmrk coord in matx/vec
        m = 2 * (1 + measurement[i][0])
        # update info matx/vec based on measmnt
        for b in range(2):
            omega.value[n+b][n+b] += 1. / measurement_noise
            omega.value[m+b][m+b] += 1. / measurement_noise
            omega.value[n+b][m+b] += -1./ measurement_noise
            omega.value[m+b][n+b] += -1./ measurement_noise
            ksi.value[n+b][0]		+= -measurement[i][1 + b] / measurement_noise
            ksi.value[m+b][0]		+= measurement[i][1 + b] / measurement_noise

    # update motion:
# 	omega.expand(dim+1, dim+1, [row for row in range(1, dim)], [col for col in range(1, dim)])
# 	ksi.expand(dim+1, 1, [row for row in range(1, dim)], [0])
    indices = [0,1]
    for i in xrange(4, dim+2): indices.append(i)

    omega = omega.expand(dim+2, dim+2, indices)
    ksi = ksi.expand(dim+2, 1, indices, [0])

    # diagonals
    for b in range(4):
        omega.value[n+b][n+b] += 1. / motion_noise
    # off-diagnls
    for b in range(2):
        omega.value[n+b][n+b+2] += -1./ motion_noise
        omega.value[n+b+2][n+b] += -1./ motion_noise
        ksi.value[n+b  ][0] 	+= -motion[b]/ motion_noise
        ksi.value[n+b+2][0]	    += motion[b] / motion_noise

    # resize matrix/vector
    indices = [col for col in range(2, len(omega.value))]
# 	indices2 = [col for col in range(2, dim +2)]
# 	print(indices)
# 	print(indices2)

    A = omega.take([0,1],indices)
    B = omega.take([0,1])
    C = ksi.take([0,1],[0])
    omegaPrime = omega.take(indices)
    ksiPrime   = ksi.take(indices,[0])

# 	A = omega.take([0,1],[col for col in range(2, dim+2)])
# 	B = omega.take([0,1])
# 	C = ksi.take([0,1],[0])
# 	omegaPrime = omega.take([rowcol for rowcol in range(2, dim+2)])
# 	ksiPrime   = ksi.take([row for row in range(2, dim+2)],[0])

# 	print(omegaPrime.dimx, omegaPrime.dimy)

    omega = omegaPrime - A.transpose() * B.inverse() * A
    ksi   = ksiPrime - A.transpose() * B.inverse() * C

    omega.show("Om: ")
    ksi.show("ks: ")
    Omega = omega

    mu = Omega.inverse() * ksi

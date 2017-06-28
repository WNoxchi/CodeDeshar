# Wayne H Nixalo - 2017-Jun-23 03:31
# Udacity CS373 Robotic AI
# Lesson 6 - SLAM - Problem Set 6.1: Matrix Fill In
# <=--------------=--------------=--------------=--------------=--------------=>
import numpy as np

omega = np.zeros((5,5))
ksi = np.zeros((5,1))
# print(omega)
# print(ksi)

s_motn = 1.0
s_meas = 0.5

init_pos = 5
move1    = 7
move2    = 2

# initial position x0
omega[0][0] += 1.
ksi[0][0] += init_pos

# movements
# x0 moves to x1
omega[0][0] += 1. / s_motn; omega[1][1] += 1. / s_motn;
omega[0][1] += -1./ s_motn; omega[1][0] += -1./ s_motn;
ksi[0][0] += -move1 / s_motn; ksi[1][0] += move1 / s_motn

# x1 moves to x2
omega[1][1] += 1. / s_motn; omega[2][2] += 1. / s_motn;
omega[1][2] += -1./ s_motn; omega[2][1] += -1./ s_motn;
ksi[1][0] += -move2 / s_motn; ksi[2][0] += move2 / s_motn

# landmark measurements
# x0 sees L0
omega[0][0] += 1. / s_meas; omega[0][3] += -1./ s_meas;
omega[3][0] += -1./ s_meas; omega[3][3] += 1. / s_meas;
ksi[0][0] += -2 / s_meas; ksi[3][0] += 2 / s_meas

# x1 sees L1
omega[1][1] += 1. / s_meas; omega[1][4] += -1./ s_meas;
omega[4][1] += -1./ s_meas; omega[4][4] += 1. / s_meas;
ksi[1][0] += -4 / s_meas; ksi[4][0] += 4 / s_meas

# x2 sees L2
omega[2][2] += 1. / s_meas; omega[2][4] += -1./ s_meas;
omega[4][2] += -1./ s_meas; omega[4][4] += 1. / s_meas;
ksi[2][0] += -2 / s_meas; ksi[4][0] += 2 / s_meas

for row in range(len(omega)): print("Omega:", omega[row], " ksi:", ksi[row])

mu = np.linalg.inv(omega).dot(ksi)
print(mu)
# <=--------------=--------------=--------------=--------------=--------------=>
#
# OUTPUT:
# Omega: [ 4. -1.  0. -2.  0.]  ksi: [-6.]
# Omega: [-1.  4. -1.  0. -2.]  ksi: [-3.]
# Omega: [ 0. -1.  3.  0. -2.]  ksi: [-2.]
# Omega: [-2.  0.  0.  2.  0.]  ksi: [ 4.]
# Omega: [ 0. -2. -2.  0.  4.]  ksi: [ 12.]
# [[  5.]
#  [ 12.]
#  [ 14.]
#  [  7.]
#  [ 16.]]

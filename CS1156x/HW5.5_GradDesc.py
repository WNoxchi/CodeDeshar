# CS1156x Learning From Data - HW 5.5 - Gradient Descent
# Wayne H Nixalo - 28-Nov-2016 17:39|01-Dec-2016 15:47
# <>---------------------<>---------------------<>
# E(u,v) = (ue^v - 2ve^-2)^2; (u,v) = (1,1); η = 0.1
# <>---------------------<>---------------------<>
# 5.5: How many iterations does it take for error E(u,v) to fall beloow 10^-14?
# Use double position for accuracy

# nonlinear error surface: E(u,v) = (ue^v - 2ve^-2)^2
# starting point: (u,v) = (1,1)
# learning rate: η = 0.1

# Python's built-in float type uses double precision; NumPy can use np.float128

import numpy as np

# initialize error surface E(u,v,) = (ue^v-2ve^-u)^2
def E(u,v):
    return (u*np.e**v - 2*v*np.e**(-u))**2
def dEdu(u,v):
    return 2*(np.e**v + 2*v*np.e**(-u))*(u*np.e**v - 2*v*np.e**(-u))
def dEdv(u,v):
    return 2*(u*np.e**v - 2*v*np.e**(-u))*(u*np.e**v - 2*np.e**(-u))

# initialize Gradient Descent Algorithm:
iterations = 0
nta = 0.1
duE, dvE = 1,1
# w = [u,v]
w = [1,1]
Ein = E(w[0],w[1])
# descend until E < 10^-14:
while (Ein > 10e-14):
    # calculate partials & gradient:
    duE = dEdu(w[0],w[1])
    dvE = dEdv(w[0],w[1])
    # w = w - nta*∇E
    w[0] = w[0] - nta*duE
    w[1] = w[1] - nta*dvE
    Ein = E(w[0],w[1])

    iterations += 1
    if iterations % 1 == 0:
        print('Iterations: {} | Ein: {}'.format(iterations, Ein))

# OUTPUT
# Iterations: 1 | Ein: 1.1595097299694377
# Iterations: 2 | Ein: 1.0074074829626989
# Iterations: 3 | Ein: 0.09900912162725588
# Iterations: 4 | Ein: 0.00866064536281213
# Iterations: 5 | Ein: 0.00018175579172801659
# Iterations: 6 | Ein: 1.2972398478441872e-06
# Iterations: 7 | Ein: 7.291524698457968e-09
# Iterations: 8 | Ein: 4.0099978905617125e-11
# Iterations: 9 | Ein: 2.2016834484097367e-13
# Iterations: 10 | Ein: 1.2086833944220747e-15

#==============================================================================
# 5.7: 'Coordinate Descent' - 01-Dec-2016 17:34
#==============================================================================
# In each iteration: 2 steps: move along u & reduce Error, move alng v & red Er.
# What will Error E(u,v) be after 15 iterations? (30 steps)

# initialize 'Coordinate' Descent Algorithm:
iterations = 0
nta = 0.1
duE, dvE = 1,1
# w = [u,v]
w = [1,1]
Ein = E(w[0],w[1])

for _ in range(15):
    # calculate partials & gradient (step by step)
    # step along u & reduce Error:
    duE = dEdu(w[0],w[1])
    w[0] = w[0] - nta*duE
    Ein = E(w[0],w[1])
    # step along v & reduce Error:
    dvE = dEdv(w[0],w[1])
    w[1] = w[1] - nta*dvE
    Ein = E(w[0],w[1])

print('Coordinate Descent: Error after 15 iterations (30 steps):\nEin = {}'.format(Ein))

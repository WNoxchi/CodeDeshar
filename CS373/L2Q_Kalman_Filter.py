# CS373 Artificial Intelligence for Robotics
# Ls2: Kalman Filters
# L[λ]:Lamroy   -   WNx -   2017-Mar-28 21:38

# Write a program that will iteratively update and
# predict based on the location measurements
# and inferred motions shown below.

# 1-Dimensional Kalman Filter

def update(mean1, var1, mean2, var2):
    new_mean = float(var2 * mean1 + var1 * mean2) / (var1 + var2)
    new_var = 1./(1./var1 + 1./var2)
    return [new_mean, new_var]

def predict(mean1, var1, mean2, var2):
    new_mean = mean1 + mean2
    new_var = var1 + var2
    return [new_mean, new_var]

measurements = [5., 6., 7., 9., 10.]
motion = [1., 1., 2., 1., 1.]
measurement_sig = 4.
motion_sig = 2.
mu = 0.
sig = 10000.

#Please print out ONLY the final values of the mean
#and the variance in a list [mu, sig].

iterations = len(measurements)
for i in xrange(iterations):
    [mu, sig] = update(mu, sig, measurements[i], measurement_sig)
    [mu, sig] = predict(mu, sig, motion[i], motion_sig)

print [mu, sig]

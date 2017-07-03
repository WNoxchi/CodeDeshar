# Wayne Nixalo - 2017-Jul-02 21:37
# Udacity CS373 AI for Robotics
# Practice Exam Questions 3 & 4: Localization

# <•> Robot starts w/ unifm distrib. Measurement error = 0.1. Movement = exact.
#     3: Update probabilities to reflect a measurement of 'red'
#     4: Robot senses 'red', moves right & senses again. What is the
#        probability it senses 'red' again? Non-cyclic: if robot stops at wall.

from __future__ import division

# answer to PXQ4:
w = ['g','g','r','g','r']
p = [.1,.1,.9,.1,.9]
for i in range(len(p)):
	p[i] /= 2.1
print(p)	# answer to PXQ3

for i in range(len(p)-1):
	if w[i+1] == 'r':
		p[i] *= .9
	else:
		p[i] *= .1
p[-1] *= .9

print(sum(p))

# OUT:
# [0.047619047619047616, 0.047619047619047616, 0.42857142857142855, 0.047619047619047616, 0.42857142857142855]
# 0.519047619047619

# ############### trying to make this more general:
# NOTE: (not doing a good job; see L1Q_Sense_and_Move.py)

# initial pars
world = ['g','g','r','g','r']
move = [1]
meas = ['r','r']
meas_err = 0.1
move_err = 0

# setup prob distrib (unifm)
p = [1 / len(world) for elem in (world)]
print(p)

def sense(p, measurement):
	for i in range(len(p)):
		if measurement == world[i]:
			p[i] *= (1 - meas_err)
		elif measurement != world[i]:
			p[i] *= 1 - (1 - meas_err)
	# normalize
	s = sum(p)
	for i in range(len(p)):
		p[i] /= s
	return p

def sense_and_move(p, measurement, movement):
	for i in range(len(p) - movement):
		if measurement == world[i + movement]:
			p[i] *= (1 - meas_err)
		elif measurement != world[i + movement]:
			p[i] *= 1 - (1 - meas_err)
	if measurement == world[-1]:
		p[-1] *= (1 - meas_err)
	else:
		p[i] *= 1 - (1 - meas_err)
	return p

p = sense(p, meas[0])
print(p)
p = sense_and_move(p, meas[1], move[0])
print(p)

print(sum(p))

# OUT:
# [0.2, 0.2, 0.2, 0.2, 0.2]
# [0.04761904761904761, 0.04761904761904761, 0.4285714285714286, 0.04761904761904761, 0.4285714285714286]
# [0.00476190476190476, 0.04285714285714285, 0.04285714285714285, 0.04285714285714285, 0.38571428571428573]
# 0.519047619047619

# CS373 - Artificial Intelligence for Robotics - Udacity
# Wayne H Nixalo - 2017-Mar-24 19:36

# The function localize takes the following arguments:
#
# colors:
#        2D list, each entry either 'R' (for red cell) or 'G' (for green cell)
#
# measurements:
#        list of measurements taken by the robot, each entry either 'R' or 'G'
#
# motions:
#        list of actions taken by the robot, each entry of the form [dy,dx],
#        where dx refers to the change in the x-direction (positive meaning
#        movement to the right) and dy refers to the change in the y-direction
#        (positive meaning movement downward)
#        NOTE: the *first* coordinate is change in y; the *second* coordinate is
#              change in x
#
# sensor_right:
#        float between 0 and 1, giving the probability that any given
#        measurement is correct; the probability that the measurement is
#        incorrect is 1-sensor_right
#
# p_move:
#        float between 0 and 1, giving the probability that any given movement
#        command takes place; the probability that the movement command fails
#        (and the robot remains still) is 1-p_move; the robot will NOT overshoot
#        its destination in this exercise
#
# The function should RETURN (not just show or print) a 2D list (of the same
# dimensions as colors) that gives the probabilities that the robot occupies
# each cell in the world.
#
# Compute the probabilities by assuming the robot initially has a uniform
# probability of being in any cell.
#
# Also assume that at each step, the robot:
# 1) first makes a movement,
# 2) then takes a measurement.
#
# Motion:
#  [0,0] - stay
#  [0,1] - right
#  [0,-1] - left
#  [1,0] - down
#  [-1,0] - up

def localize(colors,measurements,motions,sensor_right,p_move):
    # initializes p to a uniform distribution over a grid of the same dimensions as colors
    pinit = 1.0 / float(len(colors)) / float(len(colors[0]))
    p = [[pinit for row in range(len(colors[0]))] for col in range(len(colors))]

    # >>> Insert your code here <<<
    # coded after looking at staff solution
    def sense(p, colors, Z):
        # init zero matrix
        aux = [[0.0 for col in range(len(p[0]))] for col in range(len(p))]
        s = 0.0

        # check hit & update matx
        for r in range(len(p)):
            for c in range(len(p[r])):
                hit = (Z == colors[r][c])
                # p<cell> * either< sensed_hit_correctly * hit OR sensed_hit_incorrectly * (1 - hit)>; Z == colors[r][c] ? hit = 1 : hit = 0
                aux[r][c] = p[r][c] * (sensor_right * hit + (1 - sensor_right) * (1-hit))
                s += aux[r][c]

        # scale
        for r in range(len(p)):
            for c in range(len(p[r])):
                aux[r][c] /= s

        return aux


    def move(p, motion):
        # init zero matrix
        aux = [[0.0 for col in range(len(p[0]))] for row in range(len(p))]

        # modulo motion for that axis, * p_move, + p_notmoving
        for r in range(len(p)):
            for c in range(len(p[r])):
                aux[r][c] = p[(r - motion[0]) % len(p)][(c - motion[1]) % len(p[r])] * p_move + p[r][c] * (1 - p_move)

        return aux

    # main loop
    for i in range(len(measurements)):
        p = move(p, motions[i])
        p = sense(p, colors, measurements[i])

    return p

def show(p):
    rows = ['[' + ','.join(map(lambda x: '{0:.5f}'.format(x),r)) + ']' for r in p]
    print '[' + ',\n '.join(rows) + ']'

#############################################################
# For the following test case, your output should be
# [[0.01105, 0.02464, 0.06799, 0.04472, 0.02465],
#  [0.00715, 0.01017, 0.08696, 0.07988, 0.00935],
#  [0.00739, 0.00894, 0.11272, 0.35350, 0.04065],
#  [0.00910, 0.00715, 0.01434, 0.04313, 0.03642]]
# (within a tolerance of +/- 0.001 for each entry)

colors = [['R','G','G','R','R'],
          ['R','R','G','R','R'],
          ['R','R','G','G','R'],
          ['R','R','R','R','R']]
measurements = ['G','G','G','G','G']
motions = [[0,0],[0,1],[1,0],[1,0],[0,1]]
p = localize(colors,measurements,motions,sensor_right = 0.7, p_move = 0.8)
show(p) # displays your answer







################################################################################
# # What I originally had:
#     # >>> Insert your code here <<<
#
#     # modified 1D sense & meas to 2D: A[i] -> A[row][col] | i <- col
#     def sense(p, Z):
#         q = []
#         for r in range(len(p)):
#             q.append([])
#             for c in range(len(p[r])):
#                 hit = (Z == colors[r][c])
#                 q[r].append(p[r][c] * (hit * sensor_right + (1-hit) * (1-sensor_right)))
#         s = 0
#         for i in range(len(q)): s += sum(q[i])
#         for r in range(len(q)):
#             for c in range(len(q)):
#                 q[r][c] /= s
#
#     def move(p, U):
#         q = []
#         for r in range(len(p)):
#             q.append([])
#             for c in range(len(p)):
#                 s = p_move * p[r][(c - U) % len(p[r])]
#                 s = s + (1 - p_move) * p[r][(c-U-1) % len(p[r])]
#                 s = s + (1 - p_move) * p[r][(c-U+1) % len(p[r])]
#                 q[r].append(s)
#         return q
#
#     # main loop
#     for i in range(len(measurements)):
#         p = sense(p, measurements[i])
#         p = move(p, motions[i])
#
# ################################################################################
#
# Reminder:
# Reference 1D sense and move functions developed during the lesson:
#
# def sense(p, Z):
#     q=[]
#     for i in range(len(p)):
#         hit = (Z == world[i])
#         q.append(p[i] * (hit * pHit + (1-hit) * pMiss))
#     s = sum(q)
#     for i in range(len(q)):
#         q[i] = q[i] / s
#     return q
#
# def move(p, U):
#     q = []
#     for i in range(len(p)):
#         s = pExact * p[(i-U) % len(p)]
#         s = s + pOvershoot * p[(i-U-1) % len(p)]
#         s = s + pUndershoot * p[(i-U+1) % len(p)]
#         q.append(s)
#     return q
# ################################################################################
# STAFF SOLUTION:
# sensor_wrong = 1.0 - sensor_right
# p_stay = 1.0 - p_move
#
# def sense(p, colors, measurement):
#     aux = [[0.0 for row in range(len(p[0]))] for col in range(len(p))]
#
#     s = 0.0
#     for i in range(len(p)):
#         for j in range(len(p[i])):
#             hit = (measurement == colors[i][j])
#             aux[i][j] = p[i][j] * (hit * sensor_right + (1-hit) * sensor_wrong)
#             s += aux[i][j]
#
#     for i in range(len(aux)):
#         for j in range(len(p[i])):
#             aux[i][j] /= s
#     return aux
#
# def move(p, motion):
#     aux = [[0.0 for row in range(len(p[0]))] for col in range(len(p))]
#
#     for i in range(len(p)):
#         for j in range(len(p[i])):
#             aux[i][j] = (p_move * p[(i - motion[0]) % len(p)][(j - motion[1]) % len(p[i])]) + (p_stay * p[i][j])
#     return aux
#
# def show(p):
#     for i in range(len(p)):
#         print p[i]
#
# pinit = 1.0 / float(len(colors)) / float(len(colors[0]))
# p = [[pinit for row in range(len(colors[0]))] for col in range(len(colors)]
#
# for k in range(len(measurements)):
#     p = move(p, motions[k])
#     p = sense(p, colors, measuresments[k])
#
# show(p)

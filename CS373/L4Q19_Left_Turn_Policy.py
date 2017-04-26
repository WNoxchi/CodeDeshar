# Dynamic Programming - Left Turn Policy
# WNx - 2017-Apr-25 16:21 - 2017-Apr-26 00:08
# See: https://classroom.udacity.com/courses/cs373/lessons/48646841/concepts/486468400923
# ----------
# User Instructions:
#
# Implement the function optimum_policy2D below.
#
# You are given a car in grid with initial state
# init. Your task is to compute and return the car's
# optimal path to the position specified in goal;
# the costs for each motion are as defined in cost.
#
# There are four motion directions: up, left, down, and right.
# Increasing the index in this array corresponds to making a
# a left turn, and decreasing the index corresponds to making a
# right turn.

forward = [[-1,  0], # go up
           [ 0, -1], # go left
           [ 1,  0], # go down
           [ 0,  1]] # go right
forward_name = ['up', 'left', 'down', 'right']

# action has 3 values: right turn, no turn, left turn
action = [-1, 0, 1]
action_name = ['R', '#', 'L']

# EXAMPLE INPUTS:
# grid format:
#     0 = navigable space
#     1 = unnavigable space
grid = [[1, 1, 1, 0, 0, 0],
        [1, 1, 1, 0, 1, 0],
        [0, 0, 0, 0, 0, 0],
        [1, 1, 1, 0, 1, 1],
        [1, 1, 1, 0, 1, 1]]

init = [4, 3, 0] # given in the form [row,col,direction]
                 # direction = 0: up
                 #             1: left
                 #             2: down
                 #             3: right

goal = [2, 0] # given in the form [row,col]

cost = [2, 1, 20] # cost has 3 values, corresponding to making
                  # a right turn, no turn, and a left turn

# EXAMPLE OUTPUT:
# calling optimum_policy2D with the given parameters should return
# [[' ', ' ', ' ', 'R', '#', 'R'],
#  [' ', ' ', ' ', '#', ' ', '#'],
#  ['*', '#', '#', '#', '#', 'R'],
#  [' ', ' ', ' ', '#', ' ', ' '],
#  [' ', ' ', ' ', '#', ' ', ' ']]
# ----------

# ----------------------------------------
# modify code below
# ----------------------------------------

# NOTE: this took me actually forever. basically a copy from memory of Udacity's
# code iot wrap my head around a 3D policy matrix.

def optimum_policy2D(grid,init,goal,cost):

    # value matrix
    # value = [[[999 for row in xrange(len(grid[0]))] for col in xrange(len(grid))],
    #          [[999 for row in xrange(len(grid[0]))] for col in xrange(len(grid))],
    #          [[999 for row in xrange(len(grid[0]))] for col in xrange(len(grid))],
    #          [[999 for row in xrange(len(grid[0]))] for col in xrange(len(grid))]]
    value = [[[999 for row in xrange(len(grid[0]))] for col in xrange(len(grid))] for plane in xrange(len(forward))]
    # 3D Policy Matrix
    # policy3D = [[[' ' for row in xrange(len(grid[0]))] for col in xrange(len(grid))],
    #             [[' ' for row in xrange(len(grid[0]))] for col in xrange(len(grid))],
    #             [[' ' for row in xrange(len(grid[0]))] for col in xrange(len(grid))],
    #             [[' ' for row in xrange(len(grid[0]))] for col in xrange(len(grid))]]
    policy3D = [[[' ' for row in xrange(len(grid[0]))] for col in xrange(len(grid))] for plane in xrange(len(forward))]
    # 2D Policy Matrix
    policy2D = [[' ' for row in xrange(len(grid[0]))] for col in xrange(len(grid))]

    change = True
    while change:
        change = False
        for r in xrange(len(grid)):
            for c in xrange(len(grid[0])):
                for orient in xrange(len(forward)):
                    if r == goal[0] and c == goal[1]:
                        if value[orient][r][c] > 0:
                            value[orient][r][c] = 0
                            policy3D[orient][r][c] = '*'
                            change = True
                    elif grid[r][c] == 0:
                        for a in xrange(len(action)):
                            o2 = (orient + action[a]) % 4
                            r2 = r + forward[o2][0]
                            c2 = c + forward[o2][1]
                            # check valid move
                            if r2 >= 0 and r2 < len(grid) and c2 >= 0 and \
                                    c2 < len(grid[r]) and grid[r2][c2] == 0:
                                v2 = value[o2][r2][c2] + cost[a]
                                if v2 < value[orient][r][c]:
                                    value[orient][r][c] = v2
                                    policy3D[orient][r][c] = action_name[a]
                                    change = True
    r = init[0]
    c = init[1]
    orient = init[2]

    policy2D[r][c] = policy3D[orient][r][c]
    while policy3D[orient][r][c] != '*':
        if policy3D[orient][r][c] == '#':
            o2 = orient
        elif policy3D[orient][r][c] == 'R':
            o2 = (orient - 1) % 4
        elif policy3D[orient][r][c] == 'L':
            o2 = (orient + 1) % 4
        r += forward[o2][0]
        c += forward[o2][1]
        orient = o2
        policy2D[r][c] = policy3D[orient][r][c]

    return policy2D


def optimum_policy2D_UDACITY(grid,init,goal,cost):

    policy2D = [[' ' for col in xrange(len(grid[0]))] for row \
                                                        in xrange(len(grid))]

    value= [[[999 for col in xrange(len(grid[0]))] for row in xrange(len(grid))],
            [[999 for col in xrange(len(grid[0]))] for row in xrange(len(grid))],
            [[999 for col in xrange(len(grid[0]))] for row in xrange(len(grid))],
            [[999 for col in xrange(len(grid[0]))] for row in xrange(len(grid))]]

    policy3D = [[[' ' for col in xrange(len(grid[0]))] for row in xrange(len(grid))],
                [[' ' for col in xrange(len(grid[0]))] for row in xrange(len(grid))],
                [[' ' for col in xrange(len(grid[0]))] for row in xrange(len(grid))],
                [[' ' for col in xrange(len(grid[0]))] for row in xrange(len(grid))]]

    change = True
    while change:
        change = False
        # go through all grid cells and calculate values
        for x in xrange(len(grid)):
            for y in xrange(len(grid[0])):
                for orientation in xrange(4):
                    if goal[0] == x and goal[1] == y:
                        if value[orientation][x][y] > 0:
                            change = True
                            value[orientation][x][y] = 0
                            policy3D[orientation][x][y] = '*'
                    elif grid[x][y] == 0:

                        # calculate the three ways to propagate value
                        for i in xrange(3):
                            o2 = (orientation + action[i]) % 4
                            x2 = x + forward[o2][0]
                            y2 = y + forward[o2][1]
                            # print "HEYA"
                            # print x2, y2, o2cs

                            if x2 >= 0 and x2 < len(grid) and y2 >= 0 \
                                and y2 < len(grid[0]) and grid[x2][y2] == 0:
                                v2 = value[o2][x2][y2] + cost[i]
                                if v2 < value[orientation][x][y]:
                                    # print "HEYA"
                                    value[orientation][x][y] = v2
                                    policy3D[orientation][x][y] = action_name[i]
                                    change = True
    x = init[0]
    y = init[1]
    orientation = init[2]

    # for plane in value:
    #     for row in plane:
    #         print row
    #     print
    # print

    # for plane in policy3D:
    #     for row in plane:
    #         print row
    #     print
    # print

    policy2D[x][y] = policy3D[orientation][x][y]
    while policy3D[orientation][x][y] != '*':
        if policy3D[orientation][x][y] == '#':
            o2 = orientation
        elif policy3D[orientation][x][y] == 'R':
            o2 = (orientation - 1) % 4
        elif policy3D[orientation][x][y] == 'L':
            o2 = (orientation + 1) % 4
        x = x + forward[o2][0]
        y = y + forward[o2][1]
        # print x, y, o2, orientation
        orientation = o2
        policy2D[x][y] = policy3D[orientation][x][y]

    for i in xrange(len(policy2D)):
        print policy2D[i]

    return policy2D

# TESTING:
policy2D = optimum_policy2D(grid, init, goal, cost)
for row in policy2D:
    print row

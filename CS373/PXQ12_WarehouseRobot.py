# Wayne Nixalo - 2017-Jul-03 01:18 - 2017-Jul-03 04:12
# Practice Exam Q 12: Warehouse Robot
# -------------------
# Background Information
#
# In this problem, you will build a planner that helps a robot
# find the shortest way in a warehouse filled with boxes
# that he has to pick up and deliver to a drop zone.
#
# For example:
#
# warehouse = [[ 1, 2, 3],
#              [ 0, 0, 0],
#              [ 0, 0, 0]]
# dropzone = [2,0]
# todo = [2, 1]
#
# The robot starts at the dropzone.
# The dropzone can be in any free corner of the warehouse map.
# todo is a list of boxes to be picked up and delivered to the dropzone.
#
# Robot can move diagonally, but the cost of a diagonal move is 1.5.
# The cost of moving one step horizontally or vertically is 1.
# So if the dropzone is at [2, 0], the cost to deliver box number 2
# would be 5.

# To pick up a box, the robot has to move into the same cell as the box.
# When the robot picks up a box, that cell becomes passable (marked 0)
# The robot can pick up only one box at a time and once picked up
# it has to return the box to the dropzone by moving onto the dropzone cell.
# Once the robot has stepped on the dropzone, the box is taken away,
# and it is free to continue with its todo list.
# Tasks must be executed in the order that they are given in the todo list.
# You may assume that in all warehouse maps, all boxes are
# reachable from beginning (the robot is not boxed in).

# -------------------
# User Instructions
#
# Design a planner (any kind you like, so long as it works!)
# in a function named plan() that takes as input three parameters:
# warehouse, dropzone, and todo. See parameter info below.
#
# Your function should RETURN the final, accumulated cost to do
# all tasks in the todo list in the given order, which should
# match with our answer. You may include print statements to show
# the optimum path, but that will have no effect on grading.
#
# Your solution must work for a variety of warehouse layouts and
# any length of todo list.
#
# Add your code at line 76.
#
# --------------------
# Parameter Info
#
# warehouse - a grid of values, where 0 means that the cell is passable,
# and a number 1 <= n <= 99 means that box n is located at that cell.
# dropzone - determines the robot's start location and the place to return boxes
# todo - list of tasks, containing box numbers that have to be picked up
#
# --------------------
# Testing
#
# You may use our test function below, solution_check(),
# to test your code for a variety of input parameters.

warehouse = [[ 1, 2, 3],
             [ 0, 0, 0],
             [ 0, 0, 0]]
dropzone = [2,0]
todo = [2, 1]

# ------------------------------------------
# plan - Returns cost to take all boxes in the todo list to dropzone
#
# ----------------------------------------
# modify code below
# ----------------------------------------
def optimum_path(grid, init, goal, visualize_policy=False):
    value = [[99 for row in xrange(len(grid[0]))] for col in xrange(len(grid))]
    policy= [['###' for col in xrange(len(grid[0]))] for row in xrange(len(grid))]
    change = True

    # Python passes datstructs by ref --> this'll remove boxes for me
    grid[goal[0]][goal[1]] = 0

    cost  = [1,1.5]
    direc = [[-1, 0], # N
             [-1, 1], # NE
             [ 0, 1], # E
             [ 1, 1], # NE
             [ 1, 0], # S
             [ 1,-1], # SW
             [ 0,-1], # W
             [-1,-1]] # NW
    # will use %2 to get cost from direction
    direc_graphic = [' ^ ',' ^>',' > ',' v>',' v ','<v ',' < ','<^ ']

    # optimal policy
    while change:
        change = False
        for r in xrange(len(grid)):
            for c in xrange(len(grid[r])):
                if goal[0] == r and goal[1] == c and value[r][c] > 0:
                    value[r][c] = 0
                    policy[r][c] = ' * '
                    change = True
                elif grid[r][c] == 0 or grid[r][c] == 'x':
                    for d in xrange(len(direc)):
                        r2 = r + direc[d][0]
                        c2 = c + direc[d][1]
                        # check in bounds
                        if r2 >= 0 and r2 < len(grid) and c2 >= 0 and \
                                c2 < len(grid[r2]) and grid[r2][c2] == 0:
                            v2 = value[r2][c2] + cost[d % 2]
                            # print(v2, value[r2][c2])
                            if v2 < value[r][c]:
                                change = True
                                value[r][c] = v2
                                policy[r][c] = direc_graphic[d]

    # now trace back from goal & return optimal path & cost
    path = [[],[]]
    path_cost = 0
    r, c = init[0], init[1]
    while (r,c) != (goal[0], goal[1]):
        move = policy[r][c]
        mv_idx = direc_graphic.index(move)
        path_cost += cost[mv_idx % 2]
        r += direc[mv_idx][0]
        c += direc[mv_idx][1]
        path[0].append(mv_idx)
        path[1].append((mv_idx + 4) % len(direc))
    # return-trip path: (2-way graphic)
    for i in range(len(path[0])):
        path[0][i] = direc_graphic[path[0][i]]
        path[1][i] = direc_graphic[path[1][i]]

    # for visualization:
    if visualize_policy:
        print("Pickup Policy:")
        for pol in policy: print(pol)

    # double the cost to acct for return trip
    return path, path_cost * 2

# box coordinate getter
def get_box_coords(box, warehouse):
    for r in range(len(warehouse)):
        for c in range(len(warehouse[r])):
            if warehouse[r][c] == box:
                box = [r,c]
                return box

def plan(warehouse, dropzone, todo):
    from copy import copy
    warehouse = copy(warehouse)
    paths = []
    for i in range(len(todo)):
        # get box coordinates
        box = get_box_coords(todo[i], warehouse)
        # get path & cost
        path, path_cost = optimum_path(warehouse, dropzone, box, visualize_policy=False)
        paths.append([path[0], path[1], path_cost])

    for do in range(len(todo)):
        print('Instructions: Box No. {}'.format(todo[do]))
        print('Pickup: {}'.format(paths[do][0]))
        print('Return: {}'.format(paths[do][1]))
        print('T.Cost: {}'.format(paths[do][2]))

    cost = sum([paths[idx][2] for idx in range(len(paths))])
    return cost

################# TESTING ##################

# ------------------------------------------
# solution check - Checks your plan function using
# data from list called test[]. Uncomment the call
# to solution_check to test your code.
#
def solution_check(test, epsilon = 0.00001):
    answer_list = []

    import time
    start = time.clock()
    correct_answers = 0
    for i in range(len(test[0])):
        user_cost = plan(test[0][i], test[1][i], test[2][i])
        true_cost = test[3][i]
        if abs(user_cost - true_cost) < epsilon:
            print "\nTest case", i+1, "passed!"
            answer_list.append(1)
            correct_answers += 1
            #print "#############################################"
        else:
            print "\nTest case ", i+1, "unsuccessful. Your answer ", user_cost, "was not within ", epsilon, "of ", true_cost
            answer_list.append(0)
    runtime =  time.clock() - start
    if runtime > 1:
        print "Your code is too slow, try to optimize it! Running time was: ", runtime
        return False
    if correct_answers == len(answer_list):
        print "\nYou passed all test cases!"
        return True
    else:
        print "\nYou passed", correct_answers, "of", len(answer_list), "test cases. Try to get them all!"
        return False
#Testing environment
# Test Case 1
warehouse1 = [[ 1, 2, 3],
             [ 0, 0, 0],
             [ 0, 0, 0]]
dropzone1 = [2,0]
todo1 = [2, 1]
true_cost1 = 9
# Test Case 2
warehouse2 = [[   1, 2, 3, 4],
              [   0, 0, 0, 0],
              [   5, 6, 7, 0],
              [ 'x', 0, 0, 8]]
dropzone2 = [3,0]
todo2 = [2, 5, 1]
true_cost2 = 21

# Test Case 3
warehouse3 = [[   1, 2,  3,  4, 5, 6,  7],
              [   0, 0,  0,  0, 0, 0,  0],
              [   8, 9, 10, 11, 0, 0,  0],
              [ 'x', 0,  0,  0, 0, 0, 12]]
dropzone3 = [3,0]
todo3 = [5, 10]
true_cost3 = 18

# Test Case 4
warehouse4 = [[ 1, 17, 5, 18,  9, 19,  13],
              [ 2,  0, 6,  0, 10,  0,  14],
              [ 3,  0, 7,  0, 11,  0,  15],
              [ 4,  0, 8,  0, 12,  0,  16],
              [ 0,  0, 0,  0,  0,  0, 'x']]
dropzone4 = [4,6]
todo4 = [13, 11, 6, 17]
true_cost4 = 41

testing_suite = [[warehouse1, warehouse2, warehouse3, warehouse4],
                 [dropzone1, dropzone2, dropzone3, dropzone4],
                 [todo1, todo2, todo3, todo4],
                 [true_cost1, true_cost2, true_cost3, true_cost4]]


#solution_check(testing_suite) #UNCOMMENT THIS LINE TO TEST YOUR CODE

# Some Output:
# Pickup Policy:
# ['###', ' * ', '###']
# [' ^>', ' ^ ', '<^ ']
# [' ^ ', ' ^ ', ' ^ ']
# Pickup Policy:
# [' * ', ' < ', '###']
# [' ^ ', '<^ ', ' < ']
# [' ^ ', ' ^ ', '<^ ']
# Instructions: Box No. 2
# Pickup: [' ^ ', ' ^>']
# Return: [' v ', '<v ']
# T.Cost: 5.0
# Instructions: Box No. 1
# Pickup: [' ^ ', ' ^ ']
# Return: [' v ', ' v ']
# T.Cost: 4
# 9.0

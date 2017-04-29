# CS373 - AI for Robotics - Udacity - Problem Set 4 - Dynamic Programming
# Wayne H Nixalo - Stochastic Motion - 2017-Apr-28 20:14 - 23:46

# --------------
# USER INSTRUCTIONS
#
# Write a function called stochastic_value that
# returns two grids. The first grid, value, should
# contain the computed value of each cell as shown
# in the video. The second grid, policy, should
# contain the optimum policy for each cell.
#
# --------------
# GRADING NOTES
#
# We will be calling your stochastic_value function
# with several different grids and different values
# of success_prob, collision_cost, and cost_step.
# In order to be marked correct, your function must
# RETURN (it does not have to print) two grids,
# value and policy.
#
# When grading your value grid, we will compare the
# value of each cell with the true value according
# to this model. If your answer for each cell
# is sufficiently close to the correct answer
# (within 0.001), you will be marked as correct.

delta = [[-1, 0 ], # go up
         [ 0, -1], # go left
         [ 1, 0 ], # go down
         [ 0, 1 ]] # go right

delta_name = ['^', '<', 'v', '>'] # Use these when creating your policy grid.

# ---------------------------------------------
#  Modify the function stochastic_value below
# ---------------------------------------------
def validrange(row, col, grid):
    if row < len(grid) and row >= 0 and col < len(grid[row]) and col >= 0 and grid[row][col] == 0:
        return True
    return False

def stochastic_value(grid,goal,cost_step,collision_cost,success_prob):
    failure_prob = (1.0 - success_prob)/2.0 # Probability(stepping left) = prob(stepping right) = failure_prob
    value = [[collision_cost for col in range(len(grid[0]))] for row in range(len(grid))]
    policy = [[' ' for col in range(len(grid[0]))] for row in range(len(grid))]

    change = True
    while change:
        change = False
        for r in xrange(len(grid)):
            for c in xrange(len(grid[r])):
                if r == goal[0] and c == goal[1]:
                    if value[r][c] > 0:
                        value[r][c] = 0
                        policy[r][c] = '*'
                        change = True
                elif grid[r][c] == 0:
                    for d in xrange(len(delta)):
                        v2 = cost_step
                        # for i in xrange(len(delta)): # <<NOTE: my mistake here
                        ## chance of going left/right, not also backwards.
                        for i in xrange(-1, 2):
                            d2 = (d + i) % len(delta)
                            r2 = r + delta[d2][0]
                            c2 = c + delta[d2][1]
                            # if d2 == d:
                            if i == 0:
                                p = success_prob
                            else:
                                p = failure_prob
                            if validrange(r2, c2, grid):
                                v2 += p * value[r2][c2]
                            else:
                                v2 += p * collision_cost
                        if v2 < value[r][c]:
                            value[r][c] = v2
                            policy[r][c] = delta_name[d]
                            change = True

    return value, policy

# ---------------------------------------------
#  Use the code below to test your solution
# ---------------------------------------------

grid = [[0, 0, 0, 0],
        [0, 0, 0, 0],
        [0, 0, 0, 0],
        [0, 1, 1, 0]]
goal = [0, len(grid[0])-1] # Goal is in top right corner
cost_step = 1
collision_cost = 100
success_prob = 0.5

value,policy = stochastic_value(grid,goal,cost_step,collision_cost,success_prob)
for row in value:
    print row
for row in policy:
    print row

# Expected outputs:
#
# [57.9029, 40.2784, 26.0665,  0.0000]
# [47.0547, 36.5722, 29.9937, 27.2698]
# [53.1715, 42.0228, 37.7755, 45.0916]
# [77.5858, 100.00, 100.00, 73.5458]
#
# ['>', 'v', 'v', '*']
# ['>', '>', '^', '<']
# ['>', '^', '^', '<']
# ['^', ' ', ' ', '^']








    # UDACITY SOLN | PREV ATTEMPT
    ############################################################################
    # change = True
    # while change:
    #     change = False
    #     for r in xrange(len(grid)):
    #         for c in xrange(len(grid[0])):
    #             if goal[0] == r and goal[1] == c:
    #                 if value[r][c] > 0:
    #                     value[r][c] = 0
    #                     policy[r][c] = '*'
    #                     change = True
    #             elif grid[r][c] == 0:
    #                 for d in xrange(len(delta)):
    #
    #                     ###### INSERT CODE BELOW THIS LINE
    #                     v2 = cost_step
    #                     # explore the different action outcomes
    #                     for i in xrange(-1, 2):
    #                         d2 = (d + i) % len(delta)
    #                         r2 = r + delta[d2][0]
    #                         c2 = c + delta[d2][1]
    #
    #                         if i == 0:
    #                             p2 = success_prob
    #                         else:
    #                             p2 = failure_prob
    #
    #                         if r2 >= 0 and r2 < len(grid) and c2 >= 0 and c2 < len(grid[0]) and grid[r2][c2] == 0:
    #                             v2 += p2 * value[r2][c2]
    #                         else:
    #                             v2 += p2 * collision_cost
    #
    #                     if v2 < value[r][c]:
    #                         change = True
    #                         value[r][c] = v2
    #                         policy[r][c] = delta_name[d]
    ############################################################################
    # change = True
    # while change:
    #     change = False
    #     for r in xrange(len(grid)):
    #         for c in xrange(len(grid[0])):
    #             if goal[0] == r and goal[1] == c:
    #                 if value[r][c] > 0:
    #                     value[r][c] = 0
    #                     policy[r][c] = '*'
    #                     change = True
    #             elif grid[r][c] == 0:
    #                 for d in xrange(len(delta)):
    #                     ####### INSERT CODE BELOW THIS LINE
    #                     v2 = cost_step
    #                     # explore different action outcomes
    #                     for i in xrange(-1, 2):
    #                         d2 = (d + i) % len(delta)
    #                         r2 = r + delta[d2][0]
    #                         c2 = c + delta[d2][1]
    #
    #                         if i == 0:
    #                             p2 = success_prob
    #                         else:
    #                             p2 = failure_prob
    #
    #                         if r2 >= 0 and r2 < len(grid) and c2 >= 0 and c2 < len(grid[0]) and grid[r2][c2] == 0:
    #                             v2 += p2 * value[r2][c2]
    #                         else:
    #                             v2 += p2 * collision_cost
    #
    #                     if v2 < value[r][c]:
    #                         change = True
    #                         value[r][c] = v2
    #                         policy[r][c] = delta_name[d]

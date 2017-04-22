Udacity CS373 AI for Robotics - Ls4 - Search - Q8: First Search Program
Wayne H Nixalo  - 2017-Apr-21 23:35

# ----------
# User Instructions:
#
# Define a function, search() that returns a list
# in the form of [optimal path length, row, col]. For
# the grid shown below, your function should output
# [11, 4, 5].
#
# If there is no valid path from the start point
# to the goal, your function should return the string
# 'fail'
# ----------

# Grid format:
#   0 = Navigable space
#   1 = Occupied space

grid = [[0, 0, 1, 0, 0, 0],
        [0, 0, 1, 0, 0, 0],
        [0, 0, 0, 0, 1, 0],
        [0, 0, 1, 1, 1, 0],
        [0, 0, 0, 0, 1, 0]]
init = [0, 0]
goal = [len(grid)-1, len(grid[0])-1]
cost = 1

delta = [[-1, 0], # go up
         [ 0,-1], # go left
         [ 1, 0], # go down
         [ 0, 1]] # go right

delta_name = ['^', '<', 'v', '>']

def search(grid,init,goal,cost):
    # ----------------------------------------
    # insert code here

    # hashtable keeps track of visited cells
    visit = {}
    for r in xrange(len(grid)):
        for c in xrange(len(grid[0])):
            visit[(r,c)] = False

    # initial vector
    path_vec = [[0,init[0],init[1]]]

    # pathfinding/branching algorithm:
    # for valid move available:
    #     if first valid: move self there
    #     else move copy of self there

    # run through decisions
    for d in range(len(delta)):
        # check decision valid
        dy = pathvec[0][0] + delta[d][0]
        dx = pathvec[0][1] + delta[d][1]
        if dy >= 0 and dy < len(grid) and dx >= 0 and dx < len(grid) \
                                                  and visit[(dy, dx)] == False:

    # ----------------------------------------

    return path

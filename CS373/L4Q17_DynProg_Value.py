# Dynamic Programming - Value Function
# WNx - 2017-Apr-25 15:09 - 2017-Apr-25 15:52
# ----------
# User Instructions:
#
# Create a function compute_value which returns
# a grid of values. The value of a cell is the minimum
# number of moves required to get from the cell to the goal.
#
# If a cell is a wall or it is impossible to reach the goal from a cell,
# assign that cell a value of 99.
# ----------

grid = [[0, 1, 0, 0, 0, 0],
        [0, 1, 0, 0, 0, 0],
        [0, 1, 0, 0, 0, 0],
        [0, 1, 0, 0, 0, 0],
        [0, 0, 0, 0, 1, 0]]
goal = [len(grid)-1, len(grid[0])-1]
cost = 1 # the cost associated with moving from a cell to an adjacent one

delta = [[-1, 0 ], # go up
         [ 0, -1], # go left
         [ 1, 0 ], # go down
         [ 0, 1 ]] # go right

delta_name = ['^', '<', 'v', '>']

def compute_value(grid,goal,cost):
    # ----------------------------------------
    # insert code below
    # ----------------------------------------
    cost_grid = [[99 for col in xrange(len(grid[0]))] for row in \
                                                            xrange(len(grid))]
    cost_grid[goal[0]][goal[1]] = 0

    path = [[0, goal[0], goal[1]]]
    visit = [[0 for col in xrange(len(grid[0]))] for row in xrange(len(grid))]
    visit[goal[0]][goal[1]] = 1

    while len(path) > 0:
        path.sort()
        move = path.pop(0)

        for d in xrange(len(delta)):
            dy = move[1] + delta[d][1]
            dx = move[2] + delta[d][0]
            ctgo = move[0] + cost

            # det decision valid
            if dy >= 0 and dx >= 0 and dy < len(grid) and dx < len(grid[0]) \
                                and visit[dy][dx] == 0 and grid[dy][dx] == 0:
                visit[dy][dx] = 1
                path.append([ctgo,dy,dx])
                cost_grid[dy][dx] = ctgo
                # if grid[dy][dx] == 1:
                #     cost_grid[dy][dx] = 99

    # make sure your function returns a grid of values as
    # demonstrated in the previous video.
    return cost_grid

# # UDACITY SOLUTION:
# def compute_value(grid, goal, cost):
#     value = [[99 for row in range(len(grid[0]))] for col in range(len(grid))]
#
#     change = True
#     while change:
#         change = False
#
#         for x in range(len(grid)):
#             for y in range(len(grid[0])):
#                 if goal[0] == x and goal[1] == y:
#                     if value[x][y] > 0:
#                         value[x][y] = 0
#                         change = True
#
#                 elif grid[x][y] == 0:
#                     for a in range(len(delta)):
#                         x2 = x + delta[a][0]
#                         y2 = y + delta[a][1]
#
#                         if x2 >= 0 and x2 < len(grid) and y2 >= 0 and y2 < len(grid[0]) \
#                                 and grid[x2][y2] == 0:
#                             v2 = value[x2][y2] + cost_step
#
#                             if v2 < value[x][y]:
#                                 change = True
#                                 value[x][y] = v2

# # test:
# cost_grid = compute_value(grid, goal, cost)
# for row in cost_grid:
#     print row
#
# print
#
# grid = [[0, 1, 0, 1, 0, 0],
#         [0, 1, 0, 1, 0, 0],
#         [0, 1, 0, 1, 0, 0],
#         [0, 1, 0, 1, 0, 0],
#         [0, 0, 0, 1, 0, 0]]
# goal = [len(grid)-1, len(grid[0])-1]
# cost_grid = compute_value(grid, goal, cost)
# for row in cost_grid:
#     print row

# NOTE: I basically used the machinery of L4Q8 - First Search Program, to move
# through every gridsquare and calculate it's cost to get there.

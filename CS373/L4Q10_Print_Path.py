# Udacity CS373 AI for Robotics - Ls4 - Search - Q10: Print Path
# Wayne H Nixalo  - 2017-Apr-22 15:42 - 18:18

# NOTE: the [x,y] index labeling used by Udacity should be replaced by [row,col]
# --> [[' ' for col in range(len(grid[0]))] for row in range(len(grid))]

# -----------
# User Instructions:
#
# Modify the the search function so that it returns
# a shortest path as follows:
#
# [['>', 'v', ' ', ' ', ' ', ' '],
#  [' ', '>', '>', '>', '>', 'v'],
#  [' ', ' ', ' ', ' ', ' ', 'v'],
#  [' ', ' ', ' ', ' ', ' ', 'v'],
#  [' ', ' ', ' ', ' ', ' ', '*']]
#
# Where '>', '<', '^', and 'v' refer to right, left,
# up, and down motions. Note that the 'v' should be
# lowercase. '*' should mark the goal cell.
#
# You may assume that all test cases for this function
# will have a path from init to goal.
# ----------

grid = [[0, 0, 1, 0, 0, 0],
        [0, 0, 0, 0, 1, 0],
        [0, 0, 1, 0, 1, 0],
        [0, 0, 1, 0, 1, 0],
        [0, 0, 1, 0, 1, 0]]
init = [0, 0]
goal = [len(grid)-1, len(grid[0])-1]
cost = 1

delta = [[-1, 0 ], # go up
         [ 0, -1], # go left
         [ 1, 0 ], # go down
         [ 0, 1 ]] # go right

delta_name = ['^', '<', 'v', '>']

def search(grid,init,goal,cost):
    # ----------------------------------------
    # modify code below
    # ----------------------------------------
    closed = [[0 for row in range(len(grid[0]))] for col in range(len(grid))]
    closed[init[0]][init[1]] = 1

    policy = [[' ' for col in xrange(len(grid[0]))] for \
                                                    row in xrange(len(grid))]
    action = [[-1 for col in xrange(len(grid[0]))] for row in xrange(len(grid))]

    x = init[0]
    y = init[1]
    g = 0

    open = [[g, x, y]]

    found = False  # flag that is set when search is complete
    resign = False # flag set if we can't find expand

    while not found and not resign:
        if len(open) == 0:
            resign = True
            return 'fail'
        else:
            open.sort()
            open.reverse()
            next = open.pop()
            x = next[1]
            y = next[2]
            g = next[0]

            if x == goal[0] and y == goal[1]:
                found = True
                policy[x][y] = '*'
            else:
                for d in range(len(delta)):
                    x2 = x + delta[d][0]
                    y2 = y + delta[d][1]
                    if x2 >= 0 and x2 < len(grid) and y2 >=0 and y2 < len(grid[0]):
                        if closed[x2][y2] == 0 and grid[x2][y2] == 0:
                            g2 = g + cost
                            open.append([g2, x2, y2])
                            closed[x2][y2] = 1
                            action[x2][y2] = d
    if found:
        x = goal[0]
        y = goal[1]
        while x != init[0] or y != init[1]:
            x2 = x - delta[action[x][y]][0]
            y2 = y - delta[action[x][y]][1]
            policy[x2][y2] = delta_name[action[x][y]]
            x = x2
            y = y2

    for i in xrange(len(action)):
        print action[i]

    # return expand # make sure you return the shortest path
    return policy

policy = search(grid, init, goal, cost)
for row in policy:
    print row




# NOTE: wow this was simple.
# #################################################################
# # First attemt (failed)
#     # brute-force way to print optimal policy: start from goal,
#     # if vector at adjacent coord points to it, delete all other
#     # neighbors, go to that coord, repeat until at start.
#     cursor = next
#     while cursor[0] != init[0] and cursor[1] != init[1]:
#         x = next[1]
#         y = next[2]
#
#         print (x, y)
#         # g = next[0]
#         for d in range(len(delta)):
#             x0 = x + delta[d][0]
#             y0 = y + delta[d][1]
#             print(x0,y0)
#             if x0 >= 0 and x0 < len(grid) and y0 >=0 and y0 < len(grid[0]):
#                 policy_at_coord = policy[x0][y0]
#                 if policy_at_coord == ' ':
#                     continue
#                 else:
#                     policy_at_coord = delta_name.index(policy_at_coord)
#                     x1 = x0 + delta[policy_at_coord][0]
#                     y1 = y0 + delta[policy_at_coord][1]
#                     if x1 == x and y1 == y:
#                         next[1] = x0
#                         next[2] = y0
#                     else:
#                         policy[x0][y0] = ' '

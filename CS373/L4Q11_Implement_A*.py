# Udacity CS373 AI for Robotics - Ls4 - Search - Q11: Implement A*
# Wayne H Nixalo  - 2017-Apr-22 19:02 - 19:42

# -----------
# User Instructions:
#
# Modify the the search function so that it becomes
# an A* search algorithm as defined in the previous
# lectures.
#
# Your function should return the expanded grid
# which shows, for each element, the count when
# it was expanded or -1 if the element was never expanded.
#
# If there is no path from init to goal,
# the function should return the string 'fail'
# ----------

grid = [[0, 1, 0, 0, 0, 0],
        [0, 1, 0, 0, 0, 0],
        [0, 1, 0, 0, 0, 0],
        [0, 1, 0, 0, 0, 0],
        [0, 0, 0, 0, 1, 0]]
heuristic = [[9, 8, 7, 6, 5, 4],
             [8, 7, 6, 5, 4, 3],
             [7, 6, 5, 4, 3, 2],
             [6, 5, 4, 3, 2, 1],
             [5, 4, 3, 2, 1, 0]]

init = [0, 0]
goal = [len(grid)-1, len(grid[0])-1]
cost = 1

delta = [[-1, 0 ], # go up
         [ 0, -1], # go left
         [ 1, 0 ], # go down
         [ 0, 1 ]] # go right

delta_name = ['^', '<', 'v', '>']

def search(grid,init,goal,cost,heuristic):
    # ----------------------------------------
    # modify the code below
    # ----------------------------------------
    closed = [[0 for col in range(len(grid[0]))] for row in range(len(grid))]
    closed[init[0]][init[1]] = 1

    expand = [[-1 for col in range(len(grid[0]))] for row in range(len(grid))]
    action = [[-1 for col in range(len(grid[0]))] for row in range(len(grid))]

    h = lambda r, c: heuristic[r][c]

    x = init[0]
    y = init[1]
    g = 0
    f = g + h(x, y)

    open = [[f, g, x, y]]

    found = False  # flag that is set when search is complete
    resign = False # flag set if we can't find expand
    count = 0

    while not found and not resign:
        if len(open) == 0:
            resign = True
            return "Fail"
        else:
            open.sort()
            open.reverse()
            next = open.pop()
            x = next[2]
            y = next[3]
            g = next[1]
            expand[x][y] = count
            count += 1

            if x == goal[0] and y == goal[1]:
                found = True
            # expand winning element and add to new open list
            else:
                for d in xrange(len(delta)):
                    x2 = x + delta[d][0]
                    y2 = y + delta[d][1]
                    if x2 >= 0 and x2 < len(grid) and y2 >=0 and y2 < len(grid[0]):
                        if closed[x2][y2] == 0 and grid[x2][y2] == 0:
                            g2 = g + cost
                            f2 = g2 + h(x2, y2)
                            open.append([f2, g2, x2, y2])
                            closed[x2][y2] = 1

    return expand

x = search(grid,init,goal,cost,heuristic)
for i in xrange(len(x)):
    print(x[i])

# my first attempt:
#   < ................ >
#             else:
#                 for d in xrange(len(delta)):
#                     x2 = x + delta[d][0]
#                     y2 = y + delta[d][1]
#                     if x2 >= 0 and x2 < len(grid) and y2 >=0 and y2 < len(grid[0]):
#                         if closed[x2][y2] == 0 and grid[x2][y2] == 0:
#                             g2 = g + cost
#                             move_stack.append([g2, x2, y2])
#                             # open.append([g2, x2, y2])
#                             # closed[x2][y2] = 1
#                 min_cost = [-1,-1]
#                 for i in xrange(len(move_stack)):
#                     g = move_stack[i][0]
#                     r = move_stack[i][1]
#                     c = move_stack[i][2]
#                     f = g + h(r,c)
#                     if f < min_cost[0] or min_cost[0] < 0:
#                         min_cost[0] = f
#                         min_cost[1] = i
#                 g2, x2, y2 = move_stack[i][0], move_stack[i][1], move_stack[i][2]
#                 open.append([g2, x2, y2])
#                 closed[x2][y2] = 1
#   < ................ >

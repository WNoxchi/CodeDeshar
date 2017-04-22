# Udacity CS373 AI for Robotics - Ls4 - Search - Q8: First Search Program
# Wayne H Nixalo  - 2017-Apr-21 23:35|2017-Apr-22 11:20-14:52

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

def print_grid(grid, visit):
    matrix = []
    for r in range(len(grid)):
        row = []
        for c in range(len(grid[0])):
            if grid[r][c] == 1:
                row.append(9)
            elif visit[(r,c)] == False:
                row.append(0)
            else:
                row.append(1)
        matrix.append(row)
    for r in range(len(matrix)):
        print(matrix[r])
    print

def search(grid,init,goal,cost):
    # ----------------------------------------
    # insert code here
    path = [[0, init[0], init[1]]]
    end = False
    visit = [[0 for col in xrange(len(grid[0]))] for row in xrange(len(grid))]
    visit[init[0]][init[1]] = 1

    while len(path) > 0 and not end:
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

            # check end
            if dy == goal[0] and dx == goal[1]:
                path = [ctgo,dy,dx]
                end = True
                break
    if len(path) == 0:
        path = 'FAIL'
    # ----------------------------------------

    return path

###############################################################################
# tests
# print search(grid, init, goal, cost)
# grid = [[0,1],[0,0]]
# goal = [0,1]
# print search(grid, init, goal, cost)
# grid = [[0, 1, 0, 1, 0, 0, 0],
#         [0, 1, 0, 1, 0, 0, 0],
#         [0, 1, 0, 1, 0, 0, 0],
#         [0, 1, 0, 1, 0, 0, 0],
#         [0, 0, 0, 1, 0, 0, 0]]
# goal = [4,6]
# print search(grid, init, goal, cost)
#
# # OUT:
# # [11, 4, 5]
# # [1, 0, 1]
# # FAIL


# staff solution -- main difference is sorting acc. to costs to iterate lowest
# cost path first. Will do that in future problems.
#
# def search():
#     # open list elements are of the type: [g, x, y]
#
#     closed = [[0 for row in range(len(grid[0]))] for col in range(len(grid))]
#     closed[init[0]][init[1]] = 1
#
#     x = init[0]
#     y = init[1]
#     g = 0
#
#     open = [[g,x,y]]
#
#     found = False # flag that is set when search complete
#     resign = False # flag set if we can't find expand
#
#     while found is False and resign is False:
#
#         # check if we still have elements on the open list
#         if len(open) == 0:
#             resign = True
#             print 'fail'
#
#         else:
#             # remove node from list
#             open.sort()
#             open.reverse()
#             next = open.pop()
#
#             x = next[1]
#             y = next[2]
#             g = next[0]
#
#             # check if we are done
#
#             if x == goal[0] and y == goal[1]:
#                 found = True
#                 print next
#
#             else:
#                 # expand winning element and add to new open list
#                 for i in range(len(delta)):
#                     x2 = x + delta[i][0]
#                     y2 = y + delta[i][1]
#                     if x2 >= 0 and x2 < len(grid) and y2 >= 0 and y2 < len(grid[0]):
#                         if closed[x2][y2] == 0 and grid[x2][y2] == 0:
#                             g2 = g + cost
#                             open.append([g2, x2, y2])
#                             closed[x2][y2] = 1


# my ver1 search():
# def search(grid,init,goal,cost):
#     # ----------------------------------------
#     # insert code here
#     from copy import copy
#     path = 'FAIL'
#
#     # hashtable keeps track of visited cells
#     visit = {}
#     for r in xrange(len(grid)):
#         for c in xrange(len(grid[0])):
#             visit[(r,c)] = False
#     visit[(init[0], init[1])] = True
#
#     # initial vector
#     path_vec = [[0,init[0],init[1]]]
#
#     # pathfinding/branching algorithm:
#     # for valid move available:
#     #     if first valid: move self there
#     #     else move copy of self there
#
#     while path == 'False' or len(path_vec) != 0:
#         print_grid(grid,visit)
#         # list of paths to remove each cycle
#         cleanup = []
#         for v in xrange(len(path_vec)):
#             # make copy of path vector
#             new_subvec = copy(path_vec[v])
#             # flag for path termination
#             moveflag = False
#             # run through decisions
#             for d in xrange(len(delta)):
#                 # check decision valid
#                 dy = path_vec[v][1] + delta[d][0]
#                 dx = path_vec[v][2] + delta[d][1]
#                 if dy >= 0 and dy < len(grid) and dx >= 0 and dx < len(grid) \
#                             and visit[(dy, dx)] == False and grid[dy][dx] == 0:
#                     new_subvec_copy = copy(new_subvec)
#                     new_subvec_copy[0] += 1
#                     new_subvec_copy[1] = dy
#                     new_subvec_copy[2] = dx
#
#                     # if first decision, send vector there
#                     if d == 0:
#                         path_vec[v] = new_subvec_copy
#                     # else, send copy of vectory there
#                     else:
#                         path_vec.append(new_subvec_copy)
#                     # mark coordinate
#                     visit[(dy,dx)] = True
#                     # check end
#                     if dy == goal[0] and dx == goal[1]:
#                         # return new_subvec_copy
#                         path = new_subvec_copy
#                     # set path-termination flag
#                     moveflag = True
#
#             # path termination
#             if not moveflag:
#                 cleanup.append(v)
#         # cleanup paths
#         c = len(cleanup)
#         for k in xrange(c):
#             path_vec.pop(c-1-cleanup[k])
#
#
#     # ----------------------------------------
#
#     return path

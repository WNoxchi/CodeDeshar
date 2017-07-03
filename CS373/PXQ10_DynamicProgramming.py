# Wayne Nixalo - 2017-Jul-03 01:15


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
grid = [[0, 0, 0, 0, 0],
        [0, 1, 0, 1, 0],
        [0, 0, 0, 0, 0],
        [1, 1, 0, 1, 1],
        [1, 1, 0, 1, 1]]

init = [4, 2, 0] # given in the form [row,col,direction]
                 # direction = 0: up
                 #             1: left
                 #             2: down
                 #             3: right

# A,B,C.D
goal_states = [[0,3],[2,1],[0,1],[2,3,]]

cost = [1, 1, 14] # cost has 3 values, corresponding to making
                  # a right turn, no turn, and a left turn

# NOTE: this took me actually forever. basically a copy from memory of Udacity's
# code iot wrap my head around a 3D policy matrix.

def optimum_policy2D(grid,init,goal,cost):

    # value matrix
    value = [[[999 for row in range(len(grid[0]))] for col in range(len(grid))] for plane in range(len(forward))]
    # 3D Policy Matrix
    policy3D = [[[' ' for row in range(len(grid[0]))] for col in range(len(grid))] for plane in range(len(forward))]
    # 2D Policy Matrix
    policy2D = [[' ' for row in range(len(grid[0]))] for col in range(len(grid))]

    change = True
    while change:
        change = False
        for r in range(len(grid)):
            for c in range(len(grid[0])):
                for orient in range(len(forward)):
                    if r == goal[0] and c == goal[1]:
                        if value[orient][r][c] > 0:
                            value[orient][r][c] = 0
                            policy3D[orient][r][c] = '*'
                            change = True
                    elif grid[r][c] == 0:
                        for a in range(len(action)):
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

    # calc of policy cost:
    policy_cost = 0
    r,c = init[0], init[1]
    cursor = policy2D[r][c]
    orient = 0
    while cursor != '*':
    	act_idx = action_name.index(cursor)
    	policy_cost += cost[act_idx]
    	if action_name[act_idx] != '#':
    		policy_cost += cost[1]
    	# update heading
    	orient += action[act_idx]
    	orient %= len(forward)
    	# move
    	r,c = r + forward[orient][0], c + forward[orient][1]
    	cursor = policy2D[r][c]


    return policy2D, policy_cost

print('-------------------------')
for goal in goal_states:
    policy2D, policy_cost = optimum_policy2D(grid, init, goal, cost)
    for row in policy2D:
        print (row)
    print('Cost: {}'.format(policy_cost))
    print('-------------------------')


# OUT:

Python 3.6.1 (default, Dec 2015, 13:05:11)
[GCC 4.8.2] on linux

-------------------------
[' ', ' ', 'R', '*', ' ']
[' ', ' ', '#', ' ', ' ']
[' ', ' ', '#', ' ', ' ']
[' ', ' ', '#', ' ', ' ']
[' ', ' ', '#', ' ', ' ']
Cost: 6
-------------------------
[' ', ' ', 'R', '#', 'R']
[' ', ' ', '#', ' ', '#']
[' ', '*', '#', '#', 'R']
[' ', ' ', '#', ' ', ' ']
[' ', ' ', '#', ' ', ' ']
Cost: 14
-------------------------
['R', '*', 'R', '#', 'R']
['#', ' ', '#', ' ', '#']
['R', '#', '#', '#', 'R']
[' ', ' ', '#', ' ', ' ']
[' ', ' ', '#', ' ', ' ']
Cost: 20
-------------------------
[' ', ' ', ' ', ' ', ' ']
[' ', ' ', ' ', ' ', ' ']
[' ', ' ', 'R', '*', ' ']
[' ', ' ', '#', ' ', ' ']
[' ', ' ', '#', ' ', ' ']
Cost: 4
-------------------------

import random


def get_sign(num):
    if num > 0: return 1
    elif num < 0: return -1
    else: return 0


# get_side(P,A,B) assigns +1 or -1 to a point P depending on which
# side P is with respect to a line going through A and B.
# Use the cross product,
# see http://stackoverflow.com/questions/1560492/how-to-tell-whether-a-point-is-to-the-right-or-left-side-of-a-line/1560510#1560510
# P, A and B are vectors of length 3. They have the form (1, x1, x2).
def get_side(P,A,B):
    det = (B[2]-A[2]) * (P[1]-A[1]) - (B[1]-A[1]) * (P[2]-A[2])
    return get_sign(det)


# hypothesis h
# point and weight_vector are vectors of length 3
def h(point, weight_vector):
    dot_product = sum(w*x for w,x in zip(weight_vector, point))
    return get_sign(dot_product)


# START PLA
iterations_avg = 0
ratio_avg = 0
RUNS = 1000

for _ in range(RUNS):

    # choose target function
    # initialize points A and B for target function
    A = (1, random.uniform(-1, 1), random.uniform(-1, 1))
    B = (1, random.uniform(-1, 1), random.uniform(-1, 1))


    # choose N random points and store in list
    N = 100
    points = [(1, random.uniform(-1, 1), random.uniform(-1, 1)) for _ in range(N)]


    # assign +1 or -1 to points and store assignments in the list 'signs'
    signs = [get_side(P,A,B) for P in points]


    # initially all points are misclassified since
    # weight_vector is initialized to zero
    weight_vector = [0, 0, 0]
    classifications = [get_sign(h(point, weight_vector)) for point in points]


    cnt = 0
    while 1:
        # collect missclassified points,
        # store their indices in a list 'missclassified_points',
        # e.g. missclassified_points = [2, 36, 57 ] means the
        # the 2nd, 36th and 57th point are missclassified
        missclassified_points = []
        cnt += 1
        for i in range(N):
            if signs[i] != classifications[i]:
                missclassified_points.append(i)

        # break loop if list of missclassified points is empty
        if not missclassified_points:
            break

        # select a random element from the missclassified points
        # recall that missclassified_points contains indices of points
        random_index = random.choice(missclassified_points)

        # update w via w = w + yn * xn
        yn = signs[random_index]
        xn = points[random_index]
        weight_vector[0] += yn * xn[0]
        weight_vector[1] += yn * xn[1]
        weight_vector[2] += yn * xn[2]

        classifications = [get_sign(h(point, weight_vector)) for point in points]


    iterations_avg += cnt

    # Determining the probability (ratio) that a point outside
    # of the given training set is missclassified.
    # The method below is similar to the Monte Carlo method.
    num_test_points = 1000
    test_points = [(1, random.uniform(-1, 1), random.uniform(-1, 1)) for _ in range(num_test_points)]
    signs_test_points = [get_side(P, A, B) for P in test_points]
    classifications_test_points = [get_sign(h(point, weight_vector)) for point in test_points]
    num_mismatches = sum(a != b for a,b in zip(signs_test_points, classifications_test_points))
    ratio = num_mismatches / num_test_points
    ratio_avg += ratio

iterations_avg = iterations_avg / RUNS
ratio_avg = ratio_avg / RUNS

print("average iterations : ", iterations_avg)
print("average ratio for f(x) =/= g(x) : ", ratio_avg)

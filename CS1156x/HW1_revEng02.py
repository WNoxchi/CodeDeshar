# -*- coding: utf-8 -*-
# A reverse engineering job - see how soln works, what I did wrong, then update

import random
import numpy as np

# globals:
vectors = [0, 0]  # to be used in function proportion_of_disagreements().


def make_target_f(n):
    """Creates a target function f ( a straight line), and use it to assign
     classes (sign) to randomly generated points in uniform 2D [-1, 1]x[-1, 1] plane.
    :param n: number of training points to create.
    :return: list of points where each point is a tuple(x1, y1, sign).
    """
    # make a line with two points in 2D  (target function f):
    x1, y1 = random.uniform(-1, 1), random.uniform(-1, 1)
    x2, y2 = random.uniform(-1, 1), random.uniform(-1, 1)

    # using equation of a line with two points x and y in 2D calculate weights:
    w0 = -(y2-y1)*x1 + (x2 - x1)*y1
    w1 = y2 - y1
    w2 = - (x2 - x1)
    w = np.array([w0, w1, w2])

    vectors[0] = w  # save vector of weights

    points = []

    for _ in range(n):
        point = random.uniform(-1, 1), random.uniform(-1, 1)
        x = np.array([1, point[0], point[1]])

        if np.sign((w.transpose()).dot(x)) > 0:
            points.append((point[0], point[1], 1))
        else:
            points.append((point[0], point[1], -1))

    return points


def perceptron(points):
    """Runs PLA to find a function g which correctly classifies all points if
    points are linearly separable.
    :param points: list of points created by make_target_f().
    :return: number of iteration it took to converge.
    """
    count = 0
    w = np.array([0, 0, 0])
    misclassified = 1

    while misclassified:
        count += 1
        misclassified = []
        for point in points:
            x = np.array([1, point[0], point[1]])
            if np.sign((w.transpose()).dot(x)) != point[2]:
                misclassified.append(point)

        if misclassified:
            point = random.choice(misclassified)
            w0 = w[0] + point[2]
            w1 = w[1] + point[0] * point[2]
            w2 = w[2] + point[1] * point[2]
            w = np.array([w0, w1, w2])

    vectors[1] = w  # save vector of weights

    return count


def num_iterations(N, n):
    """Finds approximate number of iterations for PLA to converge.
    :param N: number of points.
    :param n: number of simulations to run
    :return: number of iterations averaged over n simulations.
    """
    counts = []
    for _ in range(n):
        points = make_target_f(N)
        iterations = perceptron(points)
        counts.append(iterations)

    return sum(counts)/float(n)


def proportion_of_disagreements(N, n):
    """Finds approximate proportion of disagreements between f and g.
    :param N: number of points to run f and g.
    :param n: number of simulations to run.
    :return: approximate proportion of disagreements (prob. to be misclassified by g).
    """
    prob_list = []

    for _ in range(n):
        points = make_target_f(N)
        perceptron(points)

        count = 0
        for dummy_i in range(1000):
            point = random.uniform(-1, 1), random.uniform(-1, 1)
            x = np.array([1, point[0], point[1]])
            if np.sign((vectors[0].transpose()).dot(x)) != np.sign((vectors[1].transpose()).dot(x)):
                count += 1

        prob_list.append(count/1000.0)

    return sum(prob_list)/float(n)


print num_iterations(10, 1000)
print proportion_of_disagreements(10, 1000)

# Wayne Nixalo    -   19-Dec-2016 22:16 | 20-Dec-2016 22:05
# 6.00.2x - Intro to Computer Science & Programming with Python /
#                    Computational Thinking & Data Science
# ==============================================================================
# Problem 2
# ==============================================================================
import random, pylab
xVals = []
yVals = []
wVals = []
for i in range(1000):
    xVals.append(random.random())
    yVals.append(random.random())
    wVals.append(random.random())
xVals = pylab.array(xVals)
yVals = pylab.array(yVals)
wVals = pylab.array(wVals)
xVals = xVals + xVals
zVals = xVals + yVals
tVals = xVals + yVals + wVals
#pylab.plot(xVals, zVals)
#pylab.plot(xVals, yVals)
#pylab.plot(xVals, sorted(yVals))
#pylab.plot(sorted(xVals), yVals)
pylab.plot(sorted(xVals), sorted(yVals))
# pylab.show()

# ==============================================================================
# Problem 3 Write a Monte Carlo simulation to solve the above problem.
#           Feel free to write a helper function if you wish.
# ==============================================================================
import random
def drawing_without_replacement_sim(numTrials):
    '''
    Runs numTrials trials of a Monte Carlo simulation
    of drawing 3 balls out of a bucket containing
    4 red and 4 green balls. Balls are not replaced once
    drawn. Returns a float - the fraction of times 3
    balls of the same color were drawn in the first 3 draws.
    '''
    successes = 0.0
    for i in range(numTrials):
        bucket = ['c','b','c','b','c','b','c','b']
        random.shuffle(bucket)
        choice = random.choice(bucket)
        bucket.remove(choice)
        for i in range(2):
            tempchoice = random.choice(bucket)
            bucket.remove(tempchoice)
            if tempchoice != choice:
                break
            if i == 1:
                successes += 1
    return successes/numTrials

# ==============================================================================
# Problem 4 Write functions makeHistogram & getAverage
# ==============================================================================

import random, pylab

# You are given this function
def getMeanAndStd(X):
    mean = sum(X)/float(len(X))
    tot = 0.0
    for x in X:
        tot += (x - mean)**2
    std = (tot/len(X))**0.5
    return mean, std

# You are given this class
class Die(object):
    def __init__(self, valList):
        """ valList is not empty """
        self.possibleVals = valList[:]
    def roll(self):
        return random.choice(self.possibleVals)

# Implement this -- Coding Part 1 of 2
def makeHistogram(values, numBins, xLabel, yLabel, title=None):
    """
      - values, a sequence of numbers
      - numBins, a positive int
      - xLabel, yLabel, title, are strings
      - Produces a histogram of values with numBins bins and the indicated labels
        for the x and y axis
      - If title is provided by caller, puts that title on the figure and otherwise
        does not title the figure
    """
    pylab.hist(values, numBins)
    pylab.xlabel(xLabel)
    pylab.ylabel(yLabel)
    if title is not None:
        pylab.title(title)
    pylab.show()


# Implement this -- Coding Part 2 of 2
def getAverage(die, numRolls, numTrials):
    """
      - die, a Die
      - numRolls, numTrials, are positive ints
      - Calculates the expected mean value of the longest run of a number
        over numTrials runs of numRolls rolls.
      - Calls makeHistogram to produce a histogram of the longest runs for all
        the trials. There should be 10 bins in the histogram
      - Choose appropriate labels for the x and y axes.
      - Returns the mean calculated
    """
    longestRolls = []
    for i in range(numTrials):
        count, maxcount = 0,0
        vals = [die.roll() for v in range(numRolls)]

        for i in range(numRolls - 1):
            if vals[i] == vals[i+1]:
                count += 1
                if count > maxcount:
                    maxcount = count
            elif vals[i] != vals[i+1]:
                count = 0
        longestRolls.append(maxcount)
    mean, std = getMeanAndStd(longestRolls)
    makeHistogram(longestRolls, 10, 'longest run size', 'times', None)
    return mean
#    longestRolls, bins = [], 10
#    for trial in range(numTrials):
#        count, maxcount = 0, 0
#        mean = 0.0
#        diceRoll = []
#        for rollo in range(numRolls):
#            diceRoll.append(die.roll())
#        for i in range(numRolls - 1):
#            if diceRoll[i] == diceRoll[i+1]:
#                count += 1
#                if count > maxcount:
#                    maxcount = count
#            elif diceRoll[i] != diceRoll[i+1]:
#                count = 0
#        longestRolls.append(maxcount)
#        mean, std = getMeanAndStd(diceRoll)
#    makeHistogram(longestRolls, bins, "Longest Run", "Trials", "Longest Runs for All Trials")
#    return mean*1.2

    #sumcounts, mean = 0, 0
    #for trial in range(numTrials):
    #    count, maxcount = 0, 0
    #    diceRoll = []
    #    for roll in range(numRolls):
    #        diceRoll.append(random.choice(die))
    #    for x in range(len(diceRoll) - 1):
    #        if diceRoll[x] == diceRoll[x+1]:
    #            count += 1
    #            if count > maxcount:
    #                maxcount = count
    #        elif diceRoll[x] != diceRoll[x+1]:
    #            count = 0
    #    sumcounts += maxcount
    #mean = float(sumcounts)/numTrials

# One test case
print(getAverage(Die([1,2,3,4,5,6,6,6,7]), 500, 10000))

# ==============================================================================
# Problem X         [Niys Dac]
# ==============================================================================
# closest, furthest = 1.0, 0.0
# closepair, farpair = [], []
# for i in range(len(people)-1):
#     for j in range(len(people) - i - 1):
#         J = j + 1 + i
#         print("Comparing: [{}] & [{}]".format((i+1),(J+1)))
#         if np.abs((people[i][0]-people[J][0]) + (people[i][1]-people[J][1])) < closest:
#             closest = np.abs((people[i][0]-people[J][0]) + (people[i][1]-people[J][1]))
#             closepair = []
#             closepair.append([i+1, J+1])
#         if np.abs((people[i][0]-people[J][0]) + (people[i][1]-people[J][1])) > furthest:
#             furthest = np.abs((people[i][0]-people[J][0]) + (people[i][1]-people[J][1]))
#             farpair = []
#             farpair.append([i+1, J+1])
# print("Closest Pair: {}, Dist: {}\nFurthest Pair: {}, Dist: {}".format(closepair, closest, farpair, furthest))


# ==============================================================================
# Problem Z
# ==============================================================================


import random
import pylab

# Global Variables
MAXRABBITPOP = 1000
CURRENTRABBITPOP = 500
CURRENTFOXPOP = 30

def rabbitGrowth():
    """
    rabbitGrowth is called once at the beginning of each time step.

    It makes use of the global variables: CURRENTRABBITPOP and MAXRABBITPOP.

    The global variable CURRENTRABBITPOP is modified by this procedure.

    For each rabbit, based on the probabilities in the problem set write-up,
      a new rabbit may be born.
    Nothing is returned.
    """
    # you need this line for modifying global variables
    global CURRENTRABBITPOP

    for rabbit in range(CURRENTRABBITPOP):
        if random.random() <= 1.0 - (float(CURRENTRABBITPOP) / float(MAXRABBITPOP)):
            if CURRENTRABBITPOP < 1000:
                CURRENTRABBITPOP += 1

def foxGrowth():
    """
    foxGrowth is called once at the end of each time step.

    It makes use of the global variables: CURRENTFOXPOP and CURRENTRABBITPOP,
        and both may be modified by this procedure.

    Each fox, based on the probabilities in the problem statement, may eat
      one rabbit (but only if there are more than 10 rabbits).

    If it eats a rabbit, then with a 1/3 prob it gives birth to a new fox.

    If it does not eat a rabbit, then with a 1/10 prob it dies.

    Nothing is returned.
    """
    # you need these lines for modifying global variables
    global CURRENTRABBITPOP
    global CURRENTFOXPOP

    for fox in range(CURRENTFOXPOP):
        if random.random() <= float(CURRENTRABBITPOP) / float(MAXRABBITPOP):
            if CURRENTRABBITPOP > 10:
                CURRENTRABBITPOP -= 1
            if random.random() <= 1/3.0:
                CURRENTFOXPOP += 1
        else:
            if random.random() <= 10/100.0:
                if CURRENTFOXPOP > 10:
                    CURRENTFOXPOP -= 1


def runSimulation(numSteps):
    """
    Runs the simulation for `numSteps` time steps.

    Returns a tuple of two lists: (rabbit_populations, fox_populations)
      where rabbit_populations is a record of the rabbit population at the
      END of each time step, and fox_populations is a record of the fox population
      at the END of each time step.

    Both lists should be `numSteps` items long.
    """

    rabbit_pop, fox_pop = [], []
    for timestep in range(numSteps):
        rabbitGrowth()
        foxGrowth()
        rabbit_pop.append(CURRENTRABBITPOP)
        fox_pop.append(CURRENTFOXPOP)
    return (rabbit_pop, fox_pop)

# from: https://gist.github.com/slibbyprdxn/5562903
def rabbitGrowth():
    """
    rabbitGrowth is called once at the beginning of each time step.

    It makes use of the global variables: CURRENTRABBITPOP and MAXRABBITPOP.

    The global variable CURRENTRABBITPOP is modified by this procedure.

    For each rabbit, based on the probabilities in the problem set write-up, a new rabbit may be born.
    Nothing is returned.
    """
    global CURRENTRABBITPOP
    global MAXRABBITPOP

    for rabbit in range(CURRENTRABBITPOP):
        if random.random() <= 1.0 - (float(CURRENTRABBITPOP) / float(MAXRABBITPOP)):
            if CURRENTRABBITPOP < 1000:
                CURRENTRABBITPOP += 1

#     assert (10 <= CURRENTRABBITPOP <= 1000)

def foxGrowth():
    """
    foxGrowth is called once at the end of each time step.

    It makes use of the global variables: CURRENTFOXPOP and CURRENTRABBITPOP,
        and both may be modified by this procedure.

    Each fox, based on the probabilities in the problem statement, may eat
      one rabbit (but only if there are more than 10 rabbits).

    If it eats a rabbit, then with a 1/3 prob it gives birth to a new fox.

    If it does not eat a rabbit, then with a 1/10 prob it dies.

    Nothing is returned.
    """
    global CURRENTRABBITPOP
    global CURRENTFOXPOP

    for eachfox in range(CURRENTFOXPOP):
        if random.random() <= float(CURRENTRABBITPOP) / float(MAXRABBITPOP):
            # Fox dines, so remove a rabbit if we can.
            if CURRENTRABBITPOP > 10:
                CURRENTRABBITPOP -= 1

            # Fox dined, so we see if it breeds
            if random.random() <= 1.0 / 3.0:
                CURRENTFOXPOP += 1
        else:
            # Fox didn't eat, so it may die
            if random.random() <= 10.0 / 100.0:
                if CURRENTFOXPOP > 10:
                    CURRENTFOXPOP -= 1

#     assert (10 <= CURRENTFOXPOP)

def runSimulation(numSteps):
    """
    Runs the simulation for `numSteps` time steps.

    Returns a tuple of two lists: (rabbit_populations, fox_populations)
      where rabbit_populations is a record of the rabbit population at the
      END of each time step, and fox_populations is a record of the fox population
      at the END of each time step.

    Both lists should be `numSteps` items long.
    """
#     global CURRENTFOXPOP
#     global CURRENTRABBITPOP
#     global MAXRABBITPOP

    rabbit_populations = []
    fox_populations = []

    for day in range(numSteps):
        rabbitGrowth()
        foxGrowth()
        rabbit_populations.append(CURRENTRABBITPOP)
        fox_populations.append(CURRENTFOXPOP)

    return (rabbit_populations, fox_populations)

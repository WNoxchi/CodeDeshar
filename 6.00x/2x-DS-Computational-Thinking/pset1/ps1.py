###########################
# 6.00.2x Problem Set 1: Space Cows
# Wayne H Nixalo - 13-Nov-2016 16:20

from ps1_partition import get_partitions
import time

#================================
# Part A: Transporting Space Cows
#================================

def load_cows(filename):
    """
    Read the contents of the given file.  Assumes the file contents contain
    data in the form of comma-separated cow name, weight pairs, and return a
    dictionary containing cow names as keys and corresponding weights as values.

    Parameters:
    filename - the name of the data file as a string

    Returns:
    a dictionary of cow name (string), weight (int) pairs
    """

    cow_dict = dict()

    f = open(filename, 'r')

    for line in f:
        line_data = line.split(',')
        cow_dict[line_data[0]] = int(line_data[1])
    return cow_dict


# Problem 1 -   13-Nov-2016 17:13
def greedy_cow_transport(cows,limit=10):
    """
    Uses a greedy heuristic to determine an allocation of cows that attempts to
    minimize the number of spaceship trips needed to transport all the cows. The
    returned allocation of cows may or may not be optimal.
    The greedy heuristic should follow the following method:

    1. As long as the current trip can fit another cow, add the largest cow that will fit
        to the trip
    2. Once the trip is full, begin a new trip to transport the remaining cows

    Does not mutate the given dictionary of cows.

    Parameters:
    cows - a dictionary of name (string), weight (int) pairs
    limit - weight limit of the spaceship (an int)

    Returns:
    A list of lists, with each inner list containing the names of cows
    transported on a particular trip and the overall list containing all the
    trips
    """

    cowlist = list(cows.items())        # Python3: dict.items() returns Type:dict --> pass as list()
    manifest = []
    while len(cowlist) > 0:
        space = limit
        trip = []
        while True:
            cow = []
            maxCow = 0
            for i in range(len(cowlist)):
                if cowlist[i][1] > maxCow and cowlist[i][1] <= space:
                    maxCow = cowlist[i][1]
                    cow = cowlist[i]
            if not len(cow):
                break
            space -= maxCow
            cowlist.remove(cow)
            trip.append(cow)
        manifest.append(trip)
    return manifest


# Problem 2 -   13-Nov-2016 20:08 - 14-Nov-2016 14:34
def brute_force_cow_transport(cows,limit=10):
    """
    Finds the allocation of cows that minimizes the number of spaceship trips
    via brute force.  The brute force algorithm should follow the following method:

    1. Enumerate all possible ways that the cows can be divided into separate trips
    2. Select the allocation that minimizes the number of trips without making any trip
        that does not obey the weight limitation

    Does not mutate the given dictionary of cows.

    Parameters:
    cows - a dictionary of name (string), weight (int) pairs
    limit - weight limit of the spaceship (an int)

    Returns:
    A list of lists, with each inner list containing the names of cows
    transported on a particular trip and the overall list containing all the
    trips
    """
    minTrip = len(list(cows.items()))
    spaceCow = get_partitions(cows)
    # make a default trip of 1 trip per cow:
    howNowBrownCow = []
    for i in range(minTrip):
        cowCow = []
        cowCow.append(list(cows.items())[i][0])
        howNowBrownCow.append(cowCow)
    # go thru all combos & find shortest valid trip set:
    while True:
        try:
            spaceCowHow = spaceCow.__next__()   # Python3 requires .__next__() for generators
        except StopIteration:
            return howNowBrownCow
        for i in range(len(spaceCowHow)):
            space = limit
            for cow in spaceCowHow[i]:
                space -= cows[cow]
            if space < 0:
                break
        if space >= 0:
            if len(spaceCowHow) < minTrip:
                howNowBrownCow = spaceCowHow
                minTrip = len(howNowBrownCow)
    return howNowBrownCow
    # ------------------------------------------
    # Ver2:
    # minTrip = len(cows.items())
    # spaceCow = get_partitions(cows)
    # for j in range(len(list(cows.items()))**2):        # Python3: dict.items() returns Type:dict --> pass as list()
    #     spaceCowHow = spaceCow.__next__()                  # Python3 requires .__next__() for generators
    #     for i in range(len(spaceCowHow)):
    #         space = limit
    #         for cow in spaceCowHow[i]:
    #             space -= cows[cow]
    #         if space < 0:
    #             break
    #     if space >= 0:
    #         if len(spaceCowHow) < minTrip:
    #             howNowBrownCow = spaceCowHow
    #             minTrip = len(howNowBrownCow)
    # return howNowBrownCow
    # ------------------------------------------
    # Ver1:
    # spaceCow = get_partitions(cows)
    # while True:
    #     spaceCowHow = spaceCow.__next__()   # Python3 requires .__next__() for generators
    #     for i in range(len(spaceCowHow)):
    #         space = limit
    #         for cow in spaceCowHow[i]:
    #             space -= cows[cow]
    #         if space < 0:
    #             break
    #     if space >= 0:
    #         break
    # return spaceCowHow
    # ------------------------------------------

# Problem 3 -   14-Nov-2016 14:41
def compare_cow_transport_algorithms():
    """
    Using the data from ps1_cow_data.txt and the specified weight limit, run your
    greedy_cow_transport and brute_force_cow_transport functions here. Use the
    default weight limits of 10 for both greedy_cow_transport and
    brute_force_cow_transport.

    Print out the number of trips returned by each method, and how long each
    method takes to run in seconds.

    Returns:
    Does not return anything.
    """
    start = time.time()
    greedy_cow_transport(cows, limit)
    end = time.time()
    print("Greedy Space Cow Algorithm Runtime: {} seconds.".format(end - start))
    start = time.time()
    brute_force_cow_transport(cows, limit)
    end = time.time()
    print("Brute Force Cow Algorithm Runtime: {} seconds.".format(end - start))


"""
Here is some test data for you to see the results of your algorithms with.
Do not submit this along with any of your answers. Uncomment the last two
lines to print the result of your problem.
"""

cows = load_cows("ps1_cow_data.txt")
limit=100
print(cows)

print(greedy_cow_transport(cows, limit))
print(brute_force_cow_transport(cows, limit))
print()
compare_cow_transport_algorithms()

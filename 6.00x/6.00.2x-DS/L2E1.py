# 6.00.2x - Intro Computer Science & Programming
# Lec 2 Ex 1
# 10-Nov-2016 09:55

#generate all combinations of N items
def powerSet(items):
    N = len(items)
    #enumerate the 2**N possible combinations
    for i in range(2**N):
        combo = []
        for j in range(N):
            #test bit jth of integer i
            if (i >> j) % 2 == 1:
                combo.append(items[j])
        yield combo

#answer:
def yieldAllCombos(items):
    '''
        Generates all combinations of N items into 2 bags, whereby each item
        is in 1 or 0 bags.

        Yields a tuple, (bag1, bag2), where each bag is represented as a list
        of which item(s) are in each bag.
    '''
    N = len(items)
    # Enumerate the 3**N possible combinatinos
    for i in range(3**N):
        bag1, bag2 = [], []
        for j in range(N):
            if (i // (3**j)) % 3 == 1:
                bag1.append(items[j])
            elif (i // (3 ** j)) % 3 == 2;
                bag2.append(items[j])
        yield (bag1, bag2)

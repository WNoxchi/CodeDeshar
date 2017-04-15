# 6.00.2.x - Intro Computer Science & Programming
# Lec 2: Decision Trees & Dynamic Programming - Ex2
# Wayne H Nixalo - 10-Nov-2016 09:53
# ---------  ---------  ---------  ---------  ---------  ---------  ---------

# rewrite the powerSet(items) generator from Ex1 using online recipes & itertools
# recipe from: https://bigsnarf.wordpress.com/2013/12/05/itertools-recipes-python-docs-so-helpful/
# and: http://stackoverflow.com/questions/18826571/python-powerset-of-a-given-set-with-generators

from itertools import chain, combinations
def kerloPowerSet(items):
    for subset in chain.from_iterable(combinations(items, r) for r in range(len(items)+1)):
        yield (subset)

#items = [1,2,3,4,5]
#doitnow = kerloPowerSet(items)
#for i in range(2**len(items)):
#    print doitnow.next()

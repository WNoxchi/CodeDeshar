# 6.00.2x - WHNoxchi
# 18-Mar-2016 11:50

# L2P2
import random
def genEven():
    '''
    Returns a random even number x, where 0 <= x < 100
    '''
    # Your code here
    while True:
        x = random.randint(0, 99)
        if x % 2 == 0:
            return x

# 18-Mar-2016 11:54
# L2P3A
# Write a deterministic program, deterministicNumber, that returns an even number between 9 and 21.
import random
def deterministicNumber():
    '''
    Deterministically generates and returns an even number between 9 and 21
    '''
    # Your code here
    random.seed(1)
    return random.randint(9, 21)

# 18-Mar-2016 12:00
# L3P3B
# Write a uniformly distributed stochastic program, stochasticNumber, that returns an even number between 9 and 21.
import random
def stochasticNumber():
    '''
    Stochastically generates and returns a uniformly distributed even number between 9 and 21
    '''
    # Your code here
    random.seed()
    while True:
        x = random.randint(9, 21)
        if x % 2 == 0:
            return x

# 6.00.2.x Intro to Computational Thinking & Data Science
# Wayne H Nixalo - 23-Nov-2016 14:50
# ==============================================================================
# Unit 3 Exericse 3:    Write a function, stdDevOfLengths(L) that takes in a
# list of strings, L, and outputs the standard deviation of the lengths of the
# strings. Return float('NaN') if L is empty.
# ==============================================================================
def stdDevOfLengths(L):
    '''
        Takes a list of strings, L; outputs the standard deviation of the
        lengths of the strings. Returns float('NaN') if L empty.
    '''
    nX = len(L)
    if nX == 0:
        return float('NaN')
    lens = []
    for i in range(nX):
        lens.append(len(L[i]))
    u = sum(lens)/float(nX)
    sigma = 0
    for i in range(nX):
        sigma += (lens[i] - u)**2
    return(sigma / nX)**0.5

#L = ['hello', ' what', 'who\'s your daddy?', 'yeah no way jose']
#print(stdDevOfLengths(L))

def stdDevNums(X):
    '''
        in: X: list of numbers
        out: standard deviation of X, and mean u, or float(NaN) if X empty.
    '''
    nX = len(X)
    if nX == 0:
        return float('NaN')
    nums = []
    for i in range(nX):
        nums.append(X[i])
    u = sum(nums)/float(nX)
    sigma = 0
    for i in range(nX):
        sigma += (nums[i] - u)**2
    return (sigma / nX)**0.5, u

def coefVarNums(X):
    '''
        IN: X, list of numbers
        OUT: coefficient of variation of X, or float(NaN) if X empty
    '''
    if len(X) == 0:
        return float('NaN')
    sdX, u = stdDevNums(X)
    return sdX/u

#C =  [10, 4, 12, 15, 20, 5]
#print (coefVarNums(C))

A,B,G = [1,2,3],[11,12,13],[0.1,0.1,0.1]
THING = [A,B,G]
for smth in THING:
    print (coefVarNums(smth))
# 6.00.1x   -   PSet 3
# Wayne H. Noxchi | 29-Jan-2016 14:27
# --------------------------------------

# --------------------------------------
# 3.2: Hangman Part 1: Is the Word Guessed
# Start: 29-Jan-2016 15:29 | Stop: 16:13 - 19:57 | Fin: 29-Jan-2016 20:21
# --------------------------------------

def isWordGuessed(secretWord, lettersGuessed):
    '''
    secretWord: string, the word the user is guessing
    lettersGuessed: list, what letters have been guessed so far
    returns: boolean, True if all the letters of secretWord are in lettersGuessed;
      False otherwise
    '''
    # FILL IN YOUR CODE HERE...

# Method Cxa':
    if lettersGuessed == []:
        return False
    check = False
    for i in range(len(secretWord)):
        if secretWord[i] in lettersGuessed:
            check = True
        else:
            return False
    return check

# Method Shi':

    if lettersGuessed == []:
        return False

    for word in secretWord:
        resultList = []
        for letter in lettersGuessed:
            result = ( word == letter )     # result equals boolean outcome
            resultList.append(result)
        if True in resultList:
            continue
        else return False
    return True

# --------------------------------------
# 3.1: Radiation Exposure
# Start: 29-Jan-2016 14:28 | Finish: 29-Jan-2016 14:37
# --------------------------------------

# def f(x):         # use for testing
#     import math
#     return 10*math.e**(math.log(0.5)/5.27 * x)
    
def radiationExposure(start, stop, step):
    '''
    Computes and returns the amount of radiation exposed
    to between the start and stop times. Calls the 
    function f (defined for you in the grading script)
    to obtain the value of the function at any point.
 
    start: integer, the time at which exposure begins
    stop: integer, the time at which exposure ends
    step: float, the width of each rectangle. You can assume that
      the step size will always partition the space evenly.

    returns: float, the amount of radiation exposed to 
      between start and stop times.
    '''
    # FILL IN YOUR CODE HERE...
    exposure = 0
    while start < stop:
        stepExposure = f(start) * step
        exposure += stepExposure
        start += step
    print exposure

radiationExposure(start, stop, step)    # do not enter this line into grader

## Test Cases:
#radiationExposure(0, 5, 1)
#>>> 39.1031878433
#radiationExposure(40, 100, 1.5)
#>>> 0.434612356115

# 6.00.1x   -   PSet 3
# Wayne H. Noxchi | 29-Jan-2016 14:27
# --------------------------------------

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

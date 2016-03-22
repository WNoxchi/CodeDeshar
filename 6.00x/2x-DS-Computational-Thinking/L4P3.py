# 6.00.2x Intro to Data Science & Computational Thinking
# WNoxchi
# Lecture 4 Problem 3  -  22-Mar-2016 00:16

def stdDevOfLengths(L):
    """
    L: a list of strings

    returns: float, the standard deviation of the lengths of the strings,
      or NaN if L is empty.
    """
    if (len(L) == 0):
        return float('NaN')
    #compute mean
    tot = 0
    for i in L:
        tot += len(i)
    mu = tot / float(len(L))
    #computing variance (avg sqrd dev frm mean)
    sumu = 0
    for i in L:
        sumu += (len(i) - mu)**2
    variance = sumu / float(len(L))
    #std dev is sqrt of variance
    stdev = variance**(0.5)
    return stdev

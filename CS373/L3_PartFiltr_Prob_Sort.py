# CS373 - AI for Robotics
# WNixalo - 2017-Apr-14 11:10 - 2017-Apr-14 13:06

# extracts int value of specified digit in a float
def pulldigit(num, order=1e1):
    # print("--> ",num)
    return int(((num % order)/(order/10)) % 10)


# modified CountingSort Algo to sort floats in range [0,1]
def cs(a, d=1e0):
    n = len(a)
    k = 0
    for i in range(n):
        # print(pulldigit(a[i],d))
        t = pulldigit(a[i], d)
        if k < t: k = t
    pos = [0] * (k+1)
    for i in range(n):
        pos[pulldigit(a[i], d)] += 1
    s = n
    for i in range(k+1):
        pos[k-i] = s - pos[k-i]
        s = pos[k-i]
    # print(pos)
    out = [None] * n
    for i in range(n):
        out[pos[pulldigit(a[i], d)]] = a[i]
        pos[pulldigit(a[i], d)] += 1
    return out

# RadixSort for probabilities: [0,1]
def rdx(a,d=1):
    for digit in range(d):
        a = cs(a, 10**(-d + digit + 1))
    # reverse order
    for i in range(int(len(a)/2)):
        t = a[i]
        a[i] = a[len(a)-1-i]
        a[len(a)-1-i] = t
    return a

# NOTE: I wasn't able to get DEC order in CountingSort. Kept DEC overall, but
#       ASC ordering digits of the same value.. Need to figure that out.
#       Did a work-around: reverse order of final sorted array.

# CS373 - AI for Robotics
# WNixalo - 2017-Apr-13 16:23   -   2017-Apr-13 18:43   |   2017-Apr-14 11:10
# NOTE: this is the messy ~figuring it out~ version. Clean version in:
#       L3_PartFiltr_Prob_Sort.py        <<-- same code but cleaned up.

# writing a sorting algorithm for a particle filter. I want speed. ~O(n)
# --> RadixSort. Dealing w. probabilities as floats.. so I'll arbitrarily
# choose e-10 as resolution, and sort digits from e-10 to e0.

# Any sort would be fine for the quiz, but irl, If I have a robot that has to
# move fast, using a cloud of +1M particles refreshed ex{+X} times per second...
# I'll want the fasted sorting Algo I have.

# 2017-Apr-14 13:06
# NOTE: I wasn't able to get DEC order in CountingSort. Kept DEC overall, but
#       ASC ordering digits of the same value.. Need to figure that out.
#       Did a work-around: reverse order of final sorted array.

from random import uniform

# simple selection sort for testing radix   # NOTE: buggy --> fix
def selsort(a):
    n = len(a)
    for i in range(n):
        mindx = i
        for j in range(n-i):
            if a[i+j] > a[mindx]:
                mindx = i+j
        temp = a[i]
        a[i] = a[mindx]
        a[mindx] = temp
    return a

# to pull digit at 1e-3 from 1.09145:
#               digit = (a % 1e-3) / (1e-3 / 10) // 1 == 4.0
# to pull ones digit: (a % 1e1) / (1e1 / 10) // 1 == 1.0 ;for a = 1.09145
def pulldigit(num, order=1e1):
    x = ((num % order)/(order/10))
    return int(x%10)
    # return round((num % order)/(order/10))
    # NOTE: if you don't cast as int on return, must cast to int in cs() fn
    # NOTE No.2: you need to round the answer to the nearest int.
    # NOTE No.3: no, that doesn't catch digits preceded by anything ≤ 5..
    #            Mod by 10 and cast to an int. Looks like this works.

print(pulldigit(0.3, 1e0))

# CountingSort  O(n+k): k ≤ n   [modified]
def cs(a, d=1e0):
    n = len(a)
    # pull largest digit as max
    k = 0
    for i in range(n):
        t = pulldigit(a[i], d)
        # print(a[i], t)
        if k < t: k = t
    pos = [0] * (k+1)
    for i in range(n):
        # print(pulldigit(a[i],d))
        # print(a[i])
        pos[pulldigit(a[i],d)] += 1
    # print(pos)
    s = n
    # print(s)
    for i in range(k+1):
        pos[k-i] = s - pos[k-i]
        s = pos[k-i]
    # print(pos)
    # print("      ",pos)
    # print("      ",k)
    out = [None] * n
    for i in range(n):
        # print(n-1-i)
        out[pos[pulldigit(a[i],d)]] = a[i]    # ASC order
        # print(pulldigit(a[i],d))
        pos[pulldigit(a[i],d)] += 1
    # print(out)
    return out

# a[i] --> int(a[i]/(10**d)) ?

# RadixSort     O(n)  : k ≤ n^100
def rdx(a, d=1):
    for digit in range(d):
        # print("order: 10**(",-d," + ", digit, " + 1) = {} ==> {}".format(\
        #                             -d + digit + 1, 10**(-d + digit + 1)))
        a = cs(a, 10**(-d + digit + 1))
    # reverse order ASC->DEC
    for i in range(int(len(a)/2)):
        t = a[i]
        a[i] = a[len(a)-1-i]
        a[len(a)-1-i] = t
    return a

# NOTE: in Py2,3 you can mod floats by floats?? This makes life easier.

# array of 1000 dummy particles
n = 3
# p = []
# for i in range(n): p.append(uniform(0,1))
# # normalize
# s = sum(p)
# for i in range(n): p[i] /= s

# TEST 01
# p = [0.4,0.1,0.3,0.2,0.3]
# print("Original Array:\n",p)
# print("RadixSort:\n",rdx(p))
# p = [0.4,0.1,0.3,0.2,0.3]
# print("SelSort:\n",selsort(p))

# TEST 02
# p = [0.10109000743910271, 0.46617473417024685, 0.4327352583906505]
# print("Original Array:\n",p)
# print("RadixSort:\n",rdx(p,10))
# p = [0.10109000743910271, 0.46617473417024685, 0.4327352583906505]
# print("SelSort:\n",selsort(p))

# TEST 03
p = []
for i in range(10): p.append(uniform(0,1))
P = p
print("Original Array:\n",p)
print("RadixSort:\n",rdx(p,10))
p = P
print("SelSort:\n",selsort(p))

# NOTE: holy shit, my selection sort actually misplaced two items..
#       Radix got it right.


# print(p)
# print(cs(p, 1e-1))
# print()
# for i in range(n):
#     print(pulldigit(p[i], 1e-1))

################################################################################
# DEBUG STUFF:          << L3_PartFiltr_Prob_Sort >>

# TEST 00:
from random import uniform
# p = []
# for i in range(10): p.append(uniform(0,1))
# p =  [0.9366191143508402, 0.43157991963681974, 0.8131346005892705,
#       0.6505776519612257, 0.954948343046999, 0.4139567031425334,
#       0.2708370390544136, 0.15572008411881422, 0.8634179209863793,
#       0.5014665100925163]
# # print("Original Array:\n",p)
# print("RadixSorted Ar:\n",rdx(p,10))

# t = [0.001999000, 0.43157991963681974, 0.4139567031425334, 0.333]
# t = [.01,.43,.41,.33]
# print(t)
# t = rdx(t,10)
# print(t)

# correctly sorted:
# [0.954948343046999, 0.9366191143508402, 0.8634179209863793,
#  0.8131346005892705, 0.6505776519612257, 0.5014665100925163,
#  0.43157991963681974, 0.4139567031425334, 0.2708370390544136,
#  0.15572008411881422]

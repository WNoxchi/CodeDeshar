# 6.006 - Intro to Algorithms - Rec07 - Counting/Radix Sort
# Wayne H Nixalo - 2017-Mar-29 21:29 -- UPDATE: 2017-Apr-13 15:41

# UPDATE/CORRECTION:
a = [4,1,3,2,3]
A = [12, 2, 3, 2, 5, 13, 3, 11, 0]

# cleaned up version
def cs(A):
    k = max(A)
    n = len(A)
    C = [0] * (k+1)
    for i in range(n):
        C[A[i]] += 1
    sum = n
    for i in range(k+1):
        C[k-i] = sum - C[k-i]
        sum = C[k-i]
    B = [None] * n
    for i in range(n):
        B[C[A[i]]] = A[i]
        C[A[i]] += 1
    return B

# version learning from 6.006 Rec 7:
def countsort_R7(a):
    # a = [4,1,3,2,3]
    # A = [12, 2, 3, 2, 5, 13, 3, 11, 0]
    k = max(a)
    n = len(a)
    pos = [0] * (k+1)
    # pos_a = [0,0,0,0,0,0]
    for i in range(n):
        pos[a[i]] += 1
    # pos_a = [0,1,1,2,1,0]
    # pos_A = [1, 0, 2, 2, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1]
    print("pos0: ", pos)
    sum = n
    # for i in range(len(pos)):  # for i <-- n-1 to 0
    #     pos[len(pos)-1-i] = sum - pos[len(pos)-1-i]
    #     sum = pos[len(pos)-1-i]
    for i in range(k+1):
        pos[k-i] = sum - pos[k-i]
        sum = pos[k-i]
    # pos_a = [0,0,1,2,4,5]
    # pos_A = [0, 1, 1, 3, 5, 5, 6, 6, 6, 6, 6, 6, 7, 8]
    print("pos1: ", pos)
    out = [None] * n
    for i in range(n):
        out[pos[a[i]]] = a[i]
        pos[a[i]] += 1
    # out_a = [1,2,3,3,4]
    # out_A = [0, 2, 2, 3, 3, 5, 11, 12, 13]
    return out

# NOTE: I finally fixed this CountingSort Algo; version from 6.006 Rec 7.
#      >What went wrong before: in the summation step, I was iterating over n
#       instead of k+1. This gave correct output on IN = [4,1,3,2,3] but wrong
#       for IN = [12,2,3,2,5,13,3,11,0]. ie: if k ≠ n roughly.
#      >Solution: iterated over length of position array. pos array len = k+1,
#       iterating from end to 0, ==> instead of index[len(pos) - 1 - i], k is
#       already len(pos) - 1, ==> index[k - i]. This correctly updates the
#       position array (C[0..k], in CLRS), ready for final step.


print(a)
print(cs(a))
print(A)
print(cs(A))


# OLD/INCORRECT VERSION: #######################################################
# a = [4, 1, 3, 2, 3]
#
# # ascending order
# def cs(a):
#     # build initial pos array           pos0 = [0,1,1,2,1,0]
#     n = len(a)
#     pos = [0] * (n + 1)
#     for i in range(n):
#         pos[a[i]] += 1
#     # trsf pos into ptr pos array       pos1 = [0,0,1,2,4,5]
#     sum = n
#     for i in range(n):
#         pos[n-i] = sum - pos[n-i]
#         sum = pos[n-i]
#
#     # build output array    (how do I do this w/o new array?)
#     out = [None] * n
#     for i in range(len(a)):
#         out[pos[a[i]]] = a[i]
#         pos[a[i]] += 1
#
#     return out
#
# print(cs(a))
#
# # descending order
# def csr(a):
#         # build initial pos array           pos0 = [0,1,2,1,1,0]
#         n = len(a)
#         pos = [0] * (n + 1)
#         for i in range(n):
#             pos[a[n-1-i]] += 1
#         # trsf pos into ptr pos array       pos1 = [5,4,2,1,0,0]
#         sum = n
#         for i in range(n):
#             pos[i] = sum - pos[i]
#             sum = pos[i]
#
#         # build output array    (how do I do this w/o new array?)
#         out = [None] * n
#         for i in range(n):
#             out[pos[a[n-1-i]]] = a[n-1-i]
#             pos[a[n-1-i]] += 1
#
#         return out
#
# print(csr(a))

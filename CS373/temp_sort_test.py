a = [0.1234, 0.543, 1.22001, 1.221, -0.0034]
arr = [12, 2, 3, 2, 5, 13, 3, 11, 0]

def selsort(a):
    n = len(a)
    for i in range(n):
        mindx = i
        for j in range(n-i):
            if a[i+j] < a[mindx]:
                mindx = i+j
        temp = a[i]
        a[i] = a[mindx]
        a[mindx] = temp
    return a

# print(a)
# print(selsort(a))

a = [4,1,3,2,3]

def countsort_R7(a):
    # a = [4,1,3,2,3]
    k = max(a)
    n = len(a)
    pos = [0] * (k+1)
    # pos = [0,0,0,0,0]
    for i in range(n):
        pos[a[i]] += 1
    # pos = [0,1,1,2,1],0
    print("pos0: ", pos)
    sum = n
    # for i in range(len(pos)):  # for i <-- n-1 to 0
    #     pos[len(pos)-1-i] = sum - pos[len(pos)-1-i]
    #     sum = pos[len(pos)-1-i]
    for i in range(k+1):
        pos[k-i] = sum - pos[k-i]
        sum = pos[k-i]

    # pos = [0,0,1,2,4],5
    print("pos1: ", pos)
    out = [None] * n
    for i in range(n):
        out[pos[a[i]]] = a[i]
        pos[a[i]] += 1
    # out = [1,2,3,3,4]
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
print(countsort_R7(a))
print(arr)
print(countsort_R7(arr))

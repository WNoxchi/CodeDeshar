def insertion_sort(A):
  for j in range(len(A)):
    key = A[j]
    i = j - 1
    while i > -1 and A[i] > key:
      A[i+1] = A[i]
      i = i - 1
    A[i+1] = key
  return A

A = [5,0,1,4]

print("Original Array: {}".format(A))
print("Sorted Array: {}".format(insertion_sort(A)))

# python -m cProfile -s time program.py

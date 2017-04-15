# WNixaloy - 11-Aug-2016 23:15
# 6.003 - Signals & Systems - 1: Discrete Time Systems
# Supplemental Notes ch 2: Difference Equations & Modularity

# def f(n):
#     if n < 2 : return 1
#     return f(n-1) + f(n-2)
# print [f(i) for i in range(20)]

def f(n):
  if n < 2: return 1
  return f(n-1) + f(n-2)
#for i in range(20):
#  print(f(i))

# Ex8: Write Python code to find f[n] when the input signal is 1, 1, 1, ...
# What is f[17] ?


def x(n):
    if n == 0: return 1
    return 1 + x(n-1)
def fx(n):
    fa = 0
    fb = 0
    ff = 0
    x = 1
    for i in range(n):
        if i == 0:
            fa = x
            if n == 0:
                ff = fa
        if i == 1:
            fb = fa + x
            if n == 1:
                ff = fb
        if i == 2:
            ff = fb + fa + x
        if i > 2:
            fa = fb
            fb = ff
            ff = fb + fa + x
    return ff
for i in range(10):
    print(fx(i))

# Wayne H Nixalo  -   2017-Apr-12 13:36
# testing out Newton's Method of numerically computing square roots
y = lambda x : x**2 - 5
yp = lambda x : 2*x
sgn = lambda x : x >= 0
target = 5**(0.5)
x = 2
tol = 1e-6

# first attempt
def m1(x, target):
    while (abs(x - target) > tol):
        slope = sgn(x)*x**2
        b = y(x) - slope*x
        x = -b/slope
        print(x)

# actual method
def m2(x, target):
    while (abs(x - target) > tol):
        x = x - y(x)/yp(x)
        print(x)

# m1(x,target)
m2(x,target)

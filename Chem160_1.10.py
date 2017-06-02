# HarvardX Chem160 - Quantum World X
# Wayne H Nixalo - 2017-Jun-01 17:17

# 1. Programming Overview - Ex10: Build(almost) a square wave

# Assumptions: function square_component(x,omega,k) and variable omega and a
#     array x come pre-loaded from the previous exercise.
#
# Define a function square_approx(x,omega,n) that sums the first n
#     components of the square wave. You will probably want to use a for-loop and
#     square_component inside.
# Create an array y of shape `(6,len(t)) to save the approximations of the
#     square wave for several values of n.
# Iterate over the list [1, 2, 8, 32, 128,512] and in each iteration, use
#     square_approx to save a wave at each step.
# Plot each approximation overlayed on each other. Add some legends and
#     labels if you want to beautify that graph.

omega=2
x = np.linspace(0,1,500)

def square_approx(x, omega, n):
    """sums the first n compnts of the square wave"""
    valsum = 0
    for i in range(1, n+1): valsum += square_component(x, omega, i)
    return valsum

n = 6
t = np.arange(0,5, 0.01)

listy = [1, 2, 8, 32, 128, 512]

y = np.zeros((n, len(t)))

for idx, elem in enumerate(listy):
    y[idx,:] = square_approx(x, omega, elem)
    plt.plot(x, y[idx,:])

plt.show()



# Staff Soln:
import numpy as np
import matplotlib.pyplot as plt
def square_component(x,omega,k):
    val = (4.0/np.pi)*np.sin(2*np.pi*(2*k-1)*omega*x)/(2*k-1)
    return val
def square_approx(x,omega,n):
    val=np.zeros(len(x))
    for k in range(1,n+1):
        val = val + square_component(x,omega,k)
    return val

omega=2
x = np.linspace(0,1,500)
ns = [1,2,8,32,128,512]
y =np.zeros((6,len(x)))
for indx,n in enumerate(ns):
    y[indx,:] = square_approx(x,omega,n)
    plt.plot(x,y[indx,:],label='n='+str(n))

plt.legend()
plt.ylabel('$y$')
plt.xlabel('$x$')
plt.title('Square wave approximated')
plt.show()

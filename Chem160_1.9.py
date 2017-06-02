# HarvardX Chem160 - Quantum World X
# Wayne H Nixalo - 2017-Jun-01 17:17

# 1. Programming Overview - Ex9: Encapsulating Code via Functions

# Create an array x from [0,1][0,1] with 500 points, an array y of same length
#     filled with zeros.
# Create a function called square_component with three input variables x,omega
#     and k which returns the k-th term from the square wave approximation.
# Use square_component to save the first 5 components into an array y of shape
#     (5,500), for omega=2.
# Plot each component overlayed on each other.

import numpy as np
import matplotlib.pyplot.plt

def square_copmonent(x, omega, k):
    """returns kth term frm square_wave aprxmtn"""
    return (4.0/np.pi) * np.sin(2*np.pi * (2*k-1) * omega*x) / (2*k-1)

x = np.linspace(0, 1, 500)
y = np.zeros((5, len(x))

for k in range(5):
    y[k,:] = square_component(x, 2, k+1)
    plt.plot(x, y[k,:], label = 'k=' + str(k+1))
plt.legend()
plt.show()

# Staff Soln:
# import numpy as np
# import matplotlib.pyplot as plt
# def square_component(x,omega,k):
#     val = (4.0/np.pi)* np.sin(2*np.pi*(2*k-1)*omega*x)/(2*k-1)
#     return val
#
# omega=2
# x = np.linspace(0,1,500)
# ks = [1,2,3,4,5]
# y = np.zeros((5,len(x)))
#
# for indx,k in enumerate(ks):
#     y[indx,:]=square_component(x,omega,k)
#     plt.plot(x,y[indx,:],label='k='+str(k))
# plt.legend()
# plt.show()

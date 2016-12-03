# -*- coding: utf-8 -*-
# CS1156x: Learning from Data - HW4: VC Dimension, Bias & Variance
# Wayne H Nixalo - 03-Nov-2016 15:14 |Fin: 04-Nov-2016 12:44
# Reference: http://nbviewer.jupyter.org/github/tournami/Learning-From-Data-MOOC/blob/master/Homework%204.html

import numpy as np
K = 10000
n = 1000

# target fn f(x) = sin(пx)
def f(x):
    return np.sin(np.pi*x)

# H0: h(x) = b:
def H0x(K):
    ''' returns b_bar from h(x) = b '''
    b_hat_list = np.zeros(K)
    x1 = np.random.uniform(-1,1,K)
    x2 = np.random.uniform(-1,1,K)
    y1 = f(x1)
    y2 = f(x2)
    b_hat_list += (y2 + y1)/2.0
    return b_hat_list
    # return np.mean(b_hat_list)

# H1: h(x) = ax
def H1x(K):
    ''' returns a_bar from h(x) = ax '''
    a_hat_list = np.zeros(K)
    x1 = np.random.uniform(-1,1,K)
    x2 = np.random.uniform(-1,1,K)
    y1 = f(x1)
    y2 = f(x2)
    a_hat_list += (x1*y1 + x2*y2)/(x1**2 + x2**2)
    return a_hat_list
    # return np.mean(a_hat_list)

# H2: h(x) = ax + b
def H2x(K):
    ''' returns a_bar & b_bar from h(x) = ax + b '''
    a_hat_list = np.zeros(K)
    b_hat_list = np.zeros(K)
    x1 = np.random.uniform(-1,1,K)
    x2 = np.random.uniform(-1,1,K)
    y1 = f(x1)
    y2 = f(x2)
    a_hat_list += (y2 - y1)/(x2 - x1)
    b_hat_list += y2 - a_hat_list * x2
    # a_bar = np.mean(a_hat_list)
    # b_bar = np.mean(a_hat_list)
    return (a_hat_list, b_hat_list)
    # return (a_bar, b_bar)

# H3: h(x) = ax^2
def H3x(K):
    ''' returns a_bar from h(x) = ax^2 '''
    a_hat_list = np.zeros(K)
    x1 = np.random.uniform(-1,1,K)
    x2 = np.random.uniform(-1,1,K)
    y1 = f(x1)
    y2 = f(x2)
    a_hat_list += (x1**2 * y1 + x2**2 * y2)/(x1**4 + x2**4)
    # return np.mean(a_hat_list)
    return a_hat_list

# H4: h(x) = ax^2 + b
def H4x(K):
    ''' returns a_bar & b_bar from h(x) = ax^2 + b '''
    a_hat_list = np.zeros(K)
    b_hat_list = np.zeros(K)
    x1 = np.random.uniform(-1,1,K)
    x2 = np.random.uniform(-1,1,K)
    y1 = f(x1)
    y2 = f(x2)
    a_hat_list += (2*(x1**2*y1 + x2**2*y2) - (x1**2 + x2**2)*(y1 + y2))\
		  /(2*(x1**4 + x2**4) - (x1**2 + x2**2)**2)
    b_hat_list += ((x1**2 + x2**2)*(x1**2*y1 + x2**2*y2) - (x1**4 + x2**4)*(y1 + y2))\
		  /((x1**2 + x2**2)**2 - 2*(x1**4 + x2**4))

    # a_bar = np.mean(a_hat_list)
    # b_bar = np.mean(b_hat_list)
    # return (a_bar, b_bar)
    return (a_hat_list, b_hat_list)

# 4.4:  hu yu expected value g_bar(x) from H1: h(x) = ax?
a_hat_list = H1x(K)
a_bar = np.mean(a_hat_list)
print("[P4.4]: g_bar(x) = {}x".format(round(a_bar, 3)))

# 4.5:  hu yu closest value to bias in this case?
x_range = np.linspace(-1,1,n)
bias = np.mean((a_bar * x_range - f(x_range))**2)
print("[P4.5]: bias: {}".format(round(bias, 3)))

# 4.6:  hu yu closest value to variance in this case?
variance = np.mean((np.outer(a_hat_list, x_range) - a_bar * x_range)**2)
print("P[4.6]: variance: {}".format(round(variance, 3)))

# 4.7   Which learning model has least expected value of Eout?
print("P[4.7]:")
# H0x:  h(x) = b
print("H0: h(x) = b   ----------------------------------------------------------")
b_hat_list = H0x(K)
b_bar = np.mean(b_hat_list)
print("H0: g_bar(x) = {}".format(round(b_bar, 3)))
bias = np.mean((b_bar - f(x_range))**2)
#print("bias: {}".format(round(bias, 3)))
variance = np.mean((np.outer(b_hat_list, np.ones(len(b_hat_list))) - b_bar)**2)
#print("variance: {}".format(round(variance, 3)))
print("bias: {}    variance: {}".format(round(bias, 3), round(variance, 3)))
print("Eout = bias + variance = {}".format(round((bias + variance), 3)))

# H1x:
print("H1: h(x) = ax   ---------------------------------------------------------")
a_hat_list = H1x(K)
a_bar = np.mean(a_hat_list)
print("H1: g_bar(x) = {}x".format(round(a_bar, 3)))

bias = np.mean((a_bar * x_range - f(x_range))**2)
#print("bias: {}".format(round(bias, 3)))
variance = np.mean((np.outer(a_hat_list, x_range) - a_bar * x_range)**2)
#print("variance: {}".format(round(variance, 3)))

print("bias: {}    variance: {}".format(round(bias, 3), round(variance, 3)))
print("Eout = bias + variance = {}".format(round((bias + variance), 3)))

# H2x: h(x) = ax + b
print("H2: h(x) = ax + b   -----------------------------------------------------")

a_hat_list, b_hat_list = H2x(K)
a_bar, b_bar = np.mean(a_hat_list), np.mean(b_hat_list)
print("H2: g_bar(x) = " + repr(round(a_bar, 3)) + "x + " + repr(round(b_bar, 3)))

bias = np.mean((a_bar * x_range + b_bar - f(x_range))**2)
#print("bias: {}".format(round(bias, 3)))
variance = np.mean((np.outer(a_hat_list, x_range) + np.expand_dims(b_hat_list, 1)\
                    - (a_bar * x_range + b_bar))**2)
#print("variance: {}".format(round(variance, 3)))

print("bias: {}    variance: {}".format(round(bias, 3), round(variance, 3)))
print("Eout = bias + variance = {}".format(round((bias + variance), 3)))

# H3x: h(x) = ax^2
print("H3: h(x) = ax^2   -------------------------------------------------------")

a_hat_list = H3x(K)
a_bar = np.mean(a_hat_list)
print("H3: g_bar(x) = {}x^2".format(round(a_bar, 3)))

bias = np.mean((a_bar * x_range**2 - f(x_range))**2)
#print("bias: {}".format(round(bias, 3)))
variance = np.mean((np.outer(a_hat_list, x_range**2) - a_bar * x_range**2)**2)
#print("variance: {}".format(round(variance, 3)))

print("bias: {}    variance: {}".format(round(bias, 3), round(variance, 3)))
print("Eout = bias + variance = {}".format(round((bias + variance), 3)))

# H4x: h(x) = ax^2 + b
print("H4: h(x) = ax^2 + b   ---------------------------------------------------")
#K = 100000
a_hat_list, b_hat_list = H4x(K)
a_bar, b_bar = np.mean(a_hat_list), np.mean(b_hat_list)
print("H4: g_bar(x) = " + repr(round(a_bar, 3)) + "x^2 + " + repr(round(b_bar, 3)))

bias = np.mean((a_bar * x_range**2 + b_bar - f(x_range))**2)
#print("bias: {}".format(round(bias, 3)))
variance = np.mean((np.outer(a_hat_list, x_range**2) + np.expand_dims(b_hat_list, 1)\
                    - (a_bar * x_range**2 + b_bar))**2)
#print("variance: {}".format(round(variance, 3)))

print("bias: {}    variance: {}".format(round(bias, 3), round(variance, 3)))
print("Eout = bias + variance = {}".format(round((bias + variance), 3)))

print("-------------------------------------------------------------------------")
